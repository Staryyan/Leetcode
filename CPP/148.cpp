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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode* head = nullptr;
      ListNode* tail = nullptr;
      while (l1 != nullptr && l2 != nullptr) {
          if (l1->val <= l2->val) {
              if (head == nullptr) {
                  head=l1;
                  tail=l1;
              } else {
                  tail->next = l1;
                  tail = tail->next;
              }
              l1 = l1->next;
          } else {
              if(head == nullptr){
                  head=l2;
                  tail=l2;
              } else {
                  tail->next=l2;
                  tail=tail->next;
              }
              l2 = l2->next;
          }
      }
      while (l1 != nullptr) {
        tail->next = l1;
        l1 = l1->next;
        tail = tail->next;
      }
      while (l2 != nullptr) {
        tail->next = l2;
        l2 = l2->next;
        tail = tail->next;
      }
      return head;
    }
    ListNode* sort(ListNode* left, ListNode* right) {
      if (left == nullptr || left == right) {
        left->next = nullptr;
        return left;
      }
      ListNode* fast = left;
      ListNode* slow = left;
      ListNode* cur;
      while (fast != right->next && fast != right) {
        fast = fast->next->next;
        cur = slow;
        slow = slow->next;
      }
      ListNode* l_pointer = sort(left, cur);
      ListNode* r_pointer = sort(slow, right);
      return mergeTwoLists(l_pointer, r_pointer);
    }
    ListNode* sortList(ListNode* head) {
      if (head == nullptr || head->next == nullptr) {
        return head;
      }
      ListNode* tail = head;
      while (tail->next != nullptr) {
        tail = tail->next;
      }
      return sort(head, tail);
    }
};
