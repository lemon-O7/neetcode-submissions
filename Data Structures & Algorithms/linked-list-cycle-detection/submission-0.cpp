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
    bool hasCycle(ListNode *head) {
        ListNode *p,*q;
        p=head;
        q=head;
        while(p!=NULL && q!=NULL && q->next) {
            p=p->next;
            q=q->next->next;
            if(p==q) {
                return true;
            }
        }
    
        return false;
    }
};
