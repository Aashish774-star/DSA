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
    ListNode* getKthNode(ListNode* temp, int k) {
        k -= 1;
        while (temp != nullptr && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }
    
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = nullptr;

        while (temp != nullptr) {
            ListNode* kthNode = getKthNode(temp, k);
            if (kthNode == nullptr) {
                if (prevLast) prevLast->next = temp;
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = nullptr;

            ListNode* newHead = reverseLinkedList(temp);

            if (temp == head) {
                head = newHead;
            } else {
                prevLast->next = newHead;
            }

            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};