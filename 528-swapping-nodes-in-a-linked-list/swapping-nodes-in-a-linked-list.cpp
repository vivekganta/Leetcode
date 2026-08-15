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
    ListNode* swapNodes(ListNode* head, int k) 
    {
        vector<int>nums;
        while(head)
        {
            nums.push_back(head->val);
            head = head->next;
        }
        int n = nums.size();
        int front_idx = k - 1;
        int back_idx = n - k;
        swap(nums[front_idx], nums[back_idx]);
        
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        for (int i = 0; i < n; i++)
        {
            cur->next = new ListNode(nums[i]);
            cur = cur->next;
        }
        cur->next = nullptr;
        return dummy->next;
    }
};