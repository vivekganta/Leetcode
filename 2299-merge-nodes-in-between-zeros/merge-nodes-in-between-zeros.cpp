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
    ListNode* mergeNodes(ListNode* head) 
    {
        ListNode* start = new ListNode(0);
        ListNode* s = start;
        ListNode* cur = head;
        while(cur)
        {
            if(cur->val == 0)
            {
                while(cur && (cur->val == 0))
                cur = cur->next;
                
                if (cur == nullptr)
                break;
                long long val = 0;
                while(cur && cur->val != 0)
                {
                    val += cur->val;
                    cur = cur->next;
                }

                s->next = new ListNode(val);
                s = s->next;
            }
            else
            cur = cur->next;
        }
        s->next = nullptr;
        return start->next;
    }
};