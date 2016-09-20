/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /**
  * construct a virtual head pointer to
  * simplify insert element defore head.
  */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
      if (head == nullptr || head->next == nullptr) {
        return head;
      }
      ListNode* t_head = new ListNode(0);
      t_head->next = head;
      ListNode* first = t_head;
      ListNode* second = t_head->next;
      ListNode* pre = second;
      ListNode* cur = pre->next;
      while (cur) {
        while (second != cur && cur->val > second->val) {
          second = second->next;
          first = first->next;
        }
        if (second == cur) {
          first = t_head;
          second = first->next;
          pre = pre->next;
          cur = cur->next;
        } else {
          pre->next = cur->next;
          cur->next = second;
          first->next = cur;
          cur = pre->next;
          first = t_head;
          second = first->next;
        }
      }
      head = t_head->next;
      delete t_head;
      return head;
    }
};
