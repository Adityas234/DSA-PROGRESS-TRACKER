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
    ListNode* middleNode(ListNode* head) {
        int n = 0;

        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            n++;
        }
        ListNode* curr = head;
        if(n%2 == 0){
            for(int i = 0;i<(n+1) /2;i++){
                curr = curr->next;
            }
        }else{
            for(int i = 0; i<n/2;i++){
                curr = curr->next;
            }
        }

        return curr;
    }
};