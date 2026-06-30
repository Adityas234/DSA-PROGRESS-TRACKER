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
    ListNode *getIntersectionNode(ListNode *heada, ListNode *headb) {
        if(heada == NULL || headb == NULL) return NULL;

        ListNode* pa = heada;
        ListNode* pb = headb;

        while(pa!=pb){
            
            pa = (pa == NULL) ? headb : pa->next;

            pb = (pb == NULL) ? heada : pb->next;
        }
        return pa;
    }
};