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
        if(lists.empty()) return NULL;
        return mergehelper(lists, 0, lists.size()-1);
    }

private:
    ListNode* mergehelper(vector<ListNode*> & lists, int start, int end){
        if(start>end) return NULL;
        if(start == end) return lists[start];

        int mid = start +(end - start) /2;

        ListNode* left = mergehelper(lists, start, mid);
        ListNode* right = mergehelper(lists, mid+1, end);

        return merger(left, right);

    }
    ListNode* merger(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;

        if(l1->val < l2->val){
            l1->next = merger(l1->next, l2);
            return l1;
        }
        else{
            l2->next = merger(l2->next, l1);
            return l2;
        }
    }
};