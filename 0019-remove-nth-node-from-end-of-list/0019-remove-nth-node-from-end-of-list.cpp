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
        ListNode* prev = NULL;
        ListNode* temp = head;
        int size = 0;

        while(temp != NULL){
            temp = temp->next;
            size++;
        }
        

        if(size == n){
            ListNode* newhead = head->next;
            delete head;
            return newhead;
        }

        temp = head;

        for(int i = 0;i<size-n-1;i++){
            temp = temp->next;
        }

        ListNode* nodedel = temp->next;
        temp ->next = temp->next->next;
        delete nodedel;
        return head;
    }
};