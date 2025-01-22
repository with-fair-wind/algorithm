#include <Demo/demo_list.h>

namespace Demo_List
{
    using namespace Algo_List;
    void demo_v1()
    {
        std::shared_ptr<SinglyList<int>> head = std::make_shared<SinglyList<int>>(1);
        // std::shared_ptr<SinglyList<int>> head(new SinglyList<int>(0), [](SinglyList<int> *node)
        //                                       { std::cout << "delete node"; delete node; });
        head->_next = std::make_shared<SinglyList<int>>(2);
        head->_next->_next = std::make_shared<SinglyList<int>>(3);
        head->_next->_next->_next = std::make_shared<SinglyList<int>>(4);
        head->_next->_next->_next->_next = std::make_shared<SinglyList<int>>(5);

        printSinglyList(head);
        head = reverseSinglyList(head);
        printSinglyList(head);
    }

    void demo_v2()
    {
        std::shared_ptr<DoublyList<int>> head = std::make_shared<DoublyList<int>>(1);
        head->_next = std::make_shared<DoublyList<int>>(2);
        head->_next->_next = std::make_shared<DoublyList<int>>(3);
        head->_next->_next->_next = std::make_shared<DoublyList<int>>(4);
        head->_next->_next->_next->_next = std::make_shared<DoublyList<int>>(5);

        head->_next->_last = head;
        head->_next->_next->_last = head->_next;
        head->_next->_next->_next->_last = head->_next->_next;
        head->_next->_next->_next->_next->_last = head->_next->_next->_next;

        printDoublyList(head);
        head = reverseDoublyList(head);
        printDoublyList(head);
    }
} // namespace Demo_List
