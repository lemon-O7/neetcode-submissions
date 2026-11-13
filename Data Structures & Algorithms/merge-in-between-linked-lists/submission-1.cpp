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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int i = b-a+1;
        ListNode *head = list1;
        while(a>1) {
            head = head->next;
            a--;        
        }
        ListNode *temp = head->next;
        while(i>0) {
            ListNode *del = temp;
            temp = temp->next;
            delete(del);
            i--;
        }
        head->next = list2;
        while(head->next) {
            head = head->next;
        }
        head->next = temp;
        return list1;
    }
};