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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* dummy = new ListNode(0, head);
        ListNode* front = dummy;
        for(int i = 1; i < n + 1; i++)
        front = front->next;
        ListNode* back_prev = dummy;
        while(front->next)
        {
            front = front->next;
            back_prev = back_prev->next;
        }
        back_prev->next = back_prev->next->next;

        return dummy->next;
    }
};