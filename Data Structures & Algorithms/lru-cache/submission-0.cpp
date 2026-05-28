class Node {
public:
    int key;
    int value;

    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        next = prev = NULL;

    }
};

class LRUCache {
public:
    int cap;

    unordered_map<int,Node*> map;
    Node *head;
    Node *tail;
    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(0,0);
        tail = new Node(0,0);

        head->next = tail;
        head->prev =NULL;
        tail->prev = head;
        tail->next =NULL;
        
    }
    
    int get(int key) {
        // Check if Node exists
        Node *temp;
        if(map.find(key) == map.end()) {
            return -1;
        }
        temp = map[key];

        //if it exists then move it to front
        if(temp->prev == head) {
            return temp->value;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        temp->next = head->next;
        temp->prev = head;

        head->next->prev = temp;
        head->next = temp;


        return temp->value;
    }
    
    void put(int key, int value) {
        Node *temp;


        if(map.find(key) == map.end()) {
            temp = new Node(key,value);
            
            map[key] = temp;
        }
        else {
            temp = map[key];
            temp->value = value;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        temp->next = head->next;
        temp->prev = head;

        head->next->prev = temp;
        head->next = temp;

        if(map.size() > cap) {
            Node* lru = tail->prev;
            lru->prev->next = lru->next;
            lru->next->prev = lru->prev;
            map.erase(lru->key);
            delete lru;
        }
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */