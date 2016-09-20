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
      if (head == nullptr) {
        return nullptr;
      }
      ListNode* fast = head; ListNode* slow =head;
      while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
          ListNode* t_head = head;
          while (t_head != fast) {
            t_head = t_head->next;
            fast = fast->next;
          }
          return fast;
        }
      }
      return nullptr;
    }
};
