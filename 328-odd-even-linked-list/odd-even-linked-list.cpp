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
    ListNode* oddEvenList(ListNode* head) 
    {
        if(!head || !head->next)
        return head;
        ListNode* odd_start = new ListNode(0);
        ListNode* even_start = new ListNode(0);
        ListNode* odd = odd_start;
        ListNode* even = even_start;
        bool flag = true;
        while(head)
        {
            if(flag)
            {
                odd->next = head;
                odd = odd->next;
            }
            else
            {
                even->next = head;
                even = even->next;
            }
            head = head->next;
            flag = !flag;
        }
        even->next = nullptr;
        odd->next = even_start->next;
        return odd_start->next;
    }
};