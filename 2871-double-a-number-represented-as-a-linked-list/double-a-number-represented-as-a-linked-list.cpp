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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = nullptr;
        while(head)
        {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head= next;
        }
        return prev;
    }

    ListNode* doubleIt(ListNode* head) 
    {
        ListNode* nums = reverse(head);
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        int carry = 0;
        while(nums || carry)
        {
            int sum = carry;
            if(nums)
            {
                sum += (nums->val * 2);
                nums = nums->next;
            }
            carry = sum / 10;
            sum = sum % 10;
            cur->next = new ListNode(sum);
            cur = cur->next;
        }
        return reverse(dummy->next);
    }
};