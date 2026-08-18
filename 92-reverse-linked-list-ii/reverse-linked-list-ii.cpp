class Solution 
{
public:
    ListNode* reverse(ListNode* head, int c)
    {
        if(c == 0)
        return head;

        ListNode* prev = nullptr;
        int a = 0;
        while(head)
        {
            ++a;
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;

            if(a == c)
            break;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        ListNode* start = new ListNode(0, head);
        ListNode* s = start;
        for(int i = 0; i < left - 1; i++)
        s = s->next;
        ListNode* e = s->next;
        for(int i = 0; i < right - left + 1; i++)
        e = e->next;
        ListNode* r = reverse(s->next, right - left + 1);
        ListNode* re = r;

        while(re && re->next)
        re = re->next;
        s->next = r;
        re->next = e;
        return start->next;
    }
};