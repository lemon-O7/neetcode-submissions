/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;

        Node *temp = head->next;
        Node *New, *temp2, *temp3;

        // Create first node
        New = new Node(head->val);
        temp3 = New;

        // Create rest of list
        while(temp) {
            Node* newNode = new Node(temp->val);
            temp3->next = newNode;
            temp3 = newNode;
            temp = temp->next;
        }

        // Assign random pointers
        temp = New;
        temp2 = head;

        while(temp) {
            if(temp2->random == NULL) {
                temp->random = NULL;
            }
            else {
                // 🔹 Step 1: find position of random node
                int pos = 0;
                Node* t = head;
                while(t != temp2->random) {
                    t = t->next;
                    pos++;
                }

                // 🔹 Step 2: go to same position in new list
                temp3 = New;
                while(pos--) {
                    temp3 = temp3->next;
                }

                // 🔹 Step 3: assign
                temp->random = temp3;
            }

            temp = temp->next;
            temp2 = temp2->next;
        }

        return New;
    }
};
