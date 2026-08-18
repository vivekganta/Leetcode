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
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* ans = new ListNode(0, list1);
        ListNode* an = ans;
        ListNode* last = list1;
        int c = -1;
        while(last)
        {
            ++c;
            last = last->next;
            if(c == b)
            break;
        }
        ListNode* l2 = list2;
        while(l2->next)
        l2 = l2->next;
        l2->next = last;
        int c1 = 0;
        while(an)
        {
            ++c1;
            an = an->next;
            if(c1 == a)
            break;
        }
        an->next = list2;
        return ans->next;
    }
};