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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *p,*q;
        p=head;
        
        ListNode dummy(0,head);
        q=&dummy;
        while(p) {
            if(p->val == val) {
                q->next = p->next;
            }
            else{
                q=p;
            }
            p=p->next;
        }
        return dummy.next;
    }
};