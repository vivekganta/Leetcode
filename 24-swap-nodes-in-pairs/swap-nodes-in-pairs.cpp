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
class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        while(prev->next && prev->next->next)
        {
            ListNode* a = prev->next;
            ListNode* b = a->next;
            ListNode* nextpair = b->next;
            prev->next = b;
            a->next = nextpair;
            b->next = a;
            prev = a;
        }
        return dummy->next;
    }
};