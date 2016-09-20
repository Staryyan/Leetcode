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
    ListNode* swapPairs(ListNode* head) {
    	if (head == nullptr) {
    		return head;
    	}
        ListNode* head_val = new ListNode(0);
        head_val->next = head;
        ListNode* slow = head_val;
        ListNode* fast = head->next;
        while(fast != nullptr) {
            slow->next->next = fast->next;
            fast->next = slow->next;
            slow->next = fast;
            if (fast->next->next != nullptr) {
                fast = fast->next->next->next;
                slow = slow->next->next;
            } else {
                break;
            }
        }
        head = head_val->next;
        delete head_val;
        return head;
    }
}; 