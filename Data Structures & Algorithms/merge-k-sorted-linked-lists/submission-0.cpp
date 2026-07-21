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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int,int> map;
        for(int i = 0;i<lists.size();i++){
            ListNode* temp = lists[i];
            while(temp){
                map[temp -> val]++;
                temp = temp -> next;
            }
        }

        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;

        for(auto pair : map){
            int number = pair.first;
            int frequency = pair.second;

            while(frequency > 0){
                current -> next = new ListNode(number);
                current = current -> next;
                frequency--;
            }
        }

        return dummyHead -> next;
    }
};
