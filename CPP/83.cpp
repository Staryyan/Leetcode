#include <iostream>
using namespace std;
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
    ListNode* deleteDuplicates(ListNode* head) {
    	if (head == nullptr) {
    		return head;
    	}
        ListNode* temp = head;
        while(temp->next != nullptr) {
        	if (temp->val == temp->next->val) {
        		ListNode* del = temp->next;
        		temp->next = del->next;
        		delete del;
        	} else {
        		temp = temp->next;
        	}

        }
        return head;
    }
};
int main() {
	std::cout << (1 ^ 1) << std::endl;
}