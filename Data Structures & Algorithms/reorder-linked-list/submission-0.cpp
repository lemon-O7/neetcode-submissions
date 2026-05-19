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
        //finding halfway of list to divide it into 2 parts
        ListNode *p=head;
        float x=0;
        while(p) {
            x++;
            p=p->next;
        }
        x=ceil(x/2);
        ListNode *q=head;
        while(x>1) {
            q=q->next;
            x--;
        }
        ListNode *r=q;
        q=q->next;
        r->next=NULL;
        //reverse function to reverse the last part of list
        ListNode *a,*b,*c;
        a=q;
        b=NULL;
        c=NULL;
        while(a) {
            c = a->next;   
            a->next = b;   
            b = a;         
            a = c; 
        }
        q=b;
        //merging both the parts
        p=head;
        while(q) {
            ListNode *temp1=p->next;
            ListNode *temp2=q->next;

            p->next=q;
            q->next=temp1;

            p=temp1;
            q=temp2;
            
        }
    }
};