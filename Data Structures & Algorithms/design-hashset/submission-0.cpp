class MyHashSet {
public:
    vector<bool> arr;
    MyHashSet() {
        arr.assign(10000000,false);
    }
    
    void add(int key) {
        if(contains(key)) return;
        arr[key] = true;
    }
    
    void remove(int key) {
        if(!contains(key)) return;
        arr[key] = false;
    }
    
    bool contains(int key) {
        return arr[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */