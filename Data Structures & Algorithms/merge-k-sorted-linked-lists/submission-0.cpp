
class Solution {
public:
    ListNode* MergeTwoLists(ListNode *p,ListNode *q) {
        ListNode head(0);
        ListNode *curr = &head;

        while(p && q) {
            if(p->val>q->val) {
                curr->next = q;
                q = q->next;
            }
            else {
                curr->next = p;
                p = p->next;
            }
            curr = curr->next;
        }

        curr->next = p ? p : q;

        return head.next;
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
       int k = lists.size();
       int step = 1;
       if (lists.empty()) return NULL;
       while (step < k) {
           for (int i = 0; i + step < k; i += step * 2) {
               lists[i] = MergeTwoLists(lists[i], lists[i + step]);
           }
           step *= 2;
       }
       return lists[0];

    }
};