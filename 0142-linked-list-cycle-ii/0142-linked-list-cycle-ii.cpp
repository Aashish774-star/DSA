/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if (head == NULL)
            return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect cycle
        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;          // 1 step
            fast = fast->next->next;    // 2 steps

            if (slow == fast) {

                // Step 2: Find starting node of cycle
                slow = head;

                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;  // cycle starting node
            }
        }

        return NULL; // no cycle
    }
};