#include <Test/test_thread_combine_sharedptr.h>

using namespace std::chrono_literals;

namespace Test_Thread_Combine_SharedPtr
{
    struct X
    {
        int val = 0;
    };

    void test_v1()
    {
        std::shared_ptr<X> p(new X{4});
        std::thread t1{[p]()
                       {
                           std::this_thread::sleep_for(1s);
                           std::cout << "thread t1: " << p.use_count() << std::endl;
                           std::cout << "underlying address: " << p.get() << ", val: " << p->val << std::endl;
                       }};
        std::thread t2{
            [p]()
            {
                X *pX = p.get();
                delete pX;
                std::cout << "underlying address: " << pX << "\nthread t2: " << p.use_count() << std::endl;
            }};
        t1.join();
        t2.join();
        std::cout << "main: " << p.use_count() << std::endl;
    }
} // namespace Test_Thread_Combine_SharedPtr
