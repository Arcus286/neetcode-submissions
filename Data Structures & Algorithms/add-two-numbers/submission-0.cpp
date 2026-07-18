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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* current = head;
        int sum = 0;
        while(l1 || l2 || carry > 0){
            ListNode* temp = new ListNode(0);
            int val1 = l1 == nullptr ? 0 : l1 -> val;
            int val2 = l2 == nullptr ? 0 : l2 -> val;

            sum = val1 + val2 + carry;

            temp -> val = sum % 10;
            carry = sum / 10;
            current -> next = temp;
            current = current -> next;

            if(l1 != nullptr) l1 = l1 -> next;
            if(l2 != nullptr) l2 = l2 -> next;
        }
        return head->next;
    }
};
