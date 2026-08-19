struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
};
class MyCircularQueue {
public:
    int count,size;
    ListNode *head,*tail;
    MyCircularQueue(int k) {
        size = k;
        head = new ListNode();
        count=0;
        head->val = -1;
        tail = head;
        for(int i=1;i<size;i++) {
            tail->next = new ListNode();
            tail = tail->next;
            tail->val = -1;
        }
        tail->next = head;
        
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        ListNode *temp = head;  
        
        while(temp->val!= -1) {
            temp = temp->next;
        }
        temp->val=value;
        count++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        ListNode* freed = head;
        head = head->next;
        freed->val = -1;      
        tail->next = freed;   
        freed->next = head;   
        tail = freed;          
        count--;
        return true;
    }
    
    int Front() {
        return head->val;
    }
    
    int Rear() {
        ListNode *temp = head;
        int i=count-1;
        while(i>0) {
            temp=temp->next;
            i--;
        }
        return temp->val;
    }
    
    bool isEmpty() {
        
        return count == 0;
    }
    
    bool isFull() {
        
        return count==size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */