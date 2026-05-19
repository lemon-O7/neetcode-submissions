class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) {
            return NULL;
        }
        struct ListNode* first=new ListNode(head->val);
        head=head->next;
        while(head) {
            struct ListNode* temp=new ListNode(head->val,first);
            first=temp;
            head=head->next;
        }
        return first;
    }
};