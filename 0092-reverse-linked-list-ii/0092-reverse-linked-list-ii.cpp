class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Empty list
        if(head == NULL)
        {
            return NULL;
        }

        // Agar sirf ek hi node reverse karna hai
        if(left == right)
            return head;

        ListNode* t = head;
        ListNode* before = NULL;
        int pos = 1;

        // Left position tak pahuchna
        while(t != NULL)
        {
            if(pos < left)
            {
                before = t;
                t = t->next;
                pos++;
                continue;
            }

            // Reverse karne ke liye pointers
            ListNode* curr = t;
            ListNode* prev = NULL;

            // Kitne nodes reverse karne hain
            int times = right - left + 1;

            while(times--)
            {
                ListNode* nex = curr->next;

                // Current node ko reverse direction me point karna
                curr->next = prev;

                prev = curr;
                curr = nex;
            }

            // Reversed part ke last node ko remaining list se connect
            t->next = curr;

            // Agar left = 1 hai, to prev new head hoga
            if(before)
            {
                // Reversed part ko previous part se connect
                before->next = prev;
                return head;
            }
            else
            {
                // left = 1, isliye prev new head banega
                return prev;
            }
        }

        return head;
    }
};