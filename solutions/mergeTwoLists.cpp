#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]
//return head of merged list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1){
            return list2;
        } else if (!list2)
        {
            return list1;
        }
                
        ListNode* head = (list1->val < list2->val) ? list1 : list2;

        ListNode* l1curr = list1;
        ListNode* l2curr = list2;

        ListNode* curr;
        ListNode* prev = head;

        while (1)
        {

            if (l1curr == nullptr)
            {
                prev->next = l2curr;
                break;
            }
            else if (l2curr == nullptr)
            {
                prev->next = l1curr;
                break;
            }

            if (l1curr->val < l2curr->val)
            {
                curr = l1curr;
                l1curr = l1curr->next;
                prev->next = curr;
                prev = curr;

            }
            else 
            {
                curr = l2curr;
                l2curr = l2curr->next;
                prev->next = curr;
                prev = curr;
            }
        }
        return head;
    }
};

int main()
{
    Solution sol;

    ListNode *l1c = new ListNode(4, nullptr);
    ListNode *l1b = new ListNode(2, l1c);
    ListNode *l1a = new ListNode(1, l1b);

    ListNode *l2c = new ListNode(4, nullptr);
    ListNode *l2b = new ListNode(3, l2c);
    ListNode *l2a = new ListNode(1, l2b);

    ListNode *ans = sol.mergeTwoLists(l1a, l2a);

    for (int i = 0; i < 6; ++i)
    {
        cout << "Ans: " << ans->val << endl;
        ans = ans->next;
    }
    

    return 0;
}