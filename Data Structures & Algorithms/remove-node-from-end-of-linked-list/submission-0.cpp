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
        ListNode *count=head;
        int x=0;
        while(count) {
            x++;
            count=count->next;
        }
        x=x-n;
        if(x==0) {
            count=head;
            head=head->next;
            delete(count);
        }
        else {
            count=head;
            ListNode *prev=head;
            while(x>0) {
                prev=count;
                count=count->next;
                x--;
            }
            prev->next=count->next;
            delete(count);
        }
        
        
        return head;
    }
};