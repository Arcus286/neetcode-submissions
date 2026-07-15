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
        int length = 0;
        ListNode* temp = head;
        while(temp){
            length++;
            temp = temp -> next;
        }
        int targetIndex = length - n;

        if(targetIndex == 0){
            return head -> next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        int count = 0;

        while(curr != nullptr){
            if(count == targetIndex){
                prev -> next = curr -> next;
                break;
            }
            prev = curr;
            curr = curr -> next;
            count++;
        }

        return head;
    }
};
