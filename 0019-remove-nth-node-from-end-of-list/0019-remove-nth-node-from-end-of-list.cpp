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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* tail = head;
        int count = 0;
        int total = 0;

        while (tail != nullptr) {
            tail = tail->next;
            total++;
        }
        ListNode* toDelete = head;
         if (n == total) {
            head = head->next;
            toDelete->next = nullptr;
            delete toDelete;
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (total - count != n) {
            prev = curr;
            curr = curr->next;
            count++;
        }

        prev->next = curr->next;

        delete curr;
        return head;
    }
};