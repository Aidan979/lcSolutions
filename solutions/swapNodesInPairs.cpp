#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        ListNode* nextPair = head;
        ListNode* first = head;
        
        ListNode* lastPair = nullptr;
        ListNode* second;

        if (!head)
            return head;
        if (!head->next)
            return head;

        ListNode* newHead = head->next;
        
        while (nextPair) {
            
            if (!nextPair->next){
                break;
            }
            nextPair = first->next->next;
            first->next->next = first;
            second = first->next;
            first->next = nextPair;
            
            if (lastPair) {
                lastPair->next = second;
            }
            lastPair = first;
            first = nextPair;
        }
        return newHead;
    }
};

int main()
{
    Solution sol;

    ListNode *l1f = new ListNode(6, nullptr);
    ListNode *l1e = new ListNode(5, l1f);
    ListNode *l1d = new ListNode(4, l1e);
    ListNode *l1c = new ListNode(3, nullptr);
    ListNode *l1b = new ListNode(2, l1c);
    ListNode *l1a = new ListNode(1, l1b);

    ListNode *ans = sol.swapPairs(l1a);

    for (int i = 0; i < 6; ++i)
    {
        cout << "Ans: " << ans->val << endl;
        ans = ans->next;
    }
    return 0;
}