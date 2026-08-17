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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        vector<int>critical;
        int index = 1;
        ListNode* prev = head;
        ListNode* cur = head->next;
        while(cur && cur->next)
        {
            ++index;
            ListNode* next = cur->next;
            if ((cur->val < prev->val && cur->val < next->val) || (cur->val > prev->val && cur->val > next->val))
            critical.push_back(index);
            prev = cur;
            cur = cur->next;
        }
        if (critical.size() < 2)
        return {-1, -1};
        if(critical.size() == 2)
        {
            int ans = critical[1] - critical[0];
            return {ans, ans};
        }
        int maxi = critical[critical.size() - 1] - critical[0];
        int mini = INT_MAX;
        for (int i = 1; i < critical.size(); i++)
        mini = min(mini, critical[i] - critical[i - 1]);
        return {mini, maxi};
    }
};