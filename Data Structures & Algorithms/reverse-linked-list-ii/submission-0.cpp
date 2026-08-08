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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *prev,*temp,*next;
        temp = head;
        prev = NULL;
        int i = left;
        while(i>1) {
            prev = temp;
            temp = temp->next;
            i--;
        }
        ListNode *curr,*revprev,*revnext;
        revprev = NULL;
        curr = temp;
        for(i=0;i<=right-left;i++) {
            revnext = curr->next;
            curr->next = revprev;
            revprev = curr;
            curr = revnext; 
        }
        if(prev == NULL) {
            head = revprev;
        }
        else {
            prev->next = revprev;
        }
        temp->next = curr;

        return head;
    }
};