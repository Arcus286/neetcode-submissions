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
    bool hasCycle(ListNode* head) {
        ListNode* temp = head;
        unordered_set<ListNode*> currElements;
        int index = -1;
        while(temp){
            if(currElements.contains(temp)){
                index = 1;
                break;
            }
            currElements.insert(temp);
            temp = temp -> next;
        }
        if(index != -1){
            return true;
        } else {
            return false;
        }
    }
};
