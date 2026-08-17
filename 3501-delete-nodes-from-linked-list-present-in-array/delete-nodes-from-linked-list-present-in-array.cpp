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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) 
    {
        unordered_set<int>st;
        for (int i = 0; i < nums.size(); i++)
        st.insert(nums[i]);
        ListNode* start = new ListNode(0);
        ListNode* s = start;
        while(head)
        {
            int value = head->val;
            if(!st.count(value))
            {
                s->next = new ListNode(value);
                s = s->next;
            }
            head = head->next;
        }    
        return start->next;
    }
};