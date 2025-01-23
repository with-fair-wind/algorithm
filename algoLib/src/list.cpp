#include <List/list.h>

namespace Algo_List
{
    std::shared_ptr<SinglyList<int>> addLists(std::shared_ptr<SinglyList<int>> head1, std::shared_ptr<SinglyList<int>> head2)
    {
        std::shared_ptr<SinglyList<int>> ans = nullptr, cur = nullptr;
        int carry = 0;
        while (head1 || head2)
        {
            int sum = (head1 ? head1->_val : 0) + (head2 ? head2->_val : 0) + carry;
            carry = sum / 10;
            int val = sum % 10;
            if (!ans)
            {
                ans = std::make_shared<SinglyList<int>>(val);
                cur = ans;
            }
            else
            {
                cur->_next = std::make_shared<SinglyList<int>>(val);
                cur = cur->_next;
            }
            head1 = head1 ? head1->_next : nullptr;
            head2 = head2 ? head2->_next : nullptr;
        }
        if (carry)
            cur->_next = std::make_shared<SinglyList<int>>(1);

        return ans;
    }
} // namespace Algo_l
