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
    void reorderList(ListNode* head) {
        vector<ListNode*> arr;
        ListNode* temp = head;
        while(temp){
            arr.push_back(temp);
            temp = temp -> next;
        }
        int start = 0;
        int end = arr.size() - 1;
        while(start < end){
            arr[start] -> next = arr[end];
            start++;
            if(start == end) break;
            arr[end] -> next = arr[start];
            end--;
        }
        arr[start] -> next = nullptr;
    }
};
