class node {
public:
    int key;
    int val;

    node* next;
    node* prev;
    node(int _key, int _val) {
        key = _key;
        val = _val;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
public:
    int cap;
    unordered_map<int, node*> mp;
    node* head = new node(1, -1);
    node* tail = new node(1, -1);
    LRUCache(int capacity) {

        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node* newnode) {
        node* temp = head;
        node* temp_next = head->next;
        newnode->next = temp_next;
        newnode->prev = temp;
        head->next = newnode;
        temp_next->prev = newnode;
    }

    void deletenode(node* newnode) {
        node* newnode_next = newnode->next;
        node* newnode_prev = newnode->prev;

        newnode_next->prev = newnode_prev;
        newnode_prev->next = newnode_next;
    }

    int get(int key) {

        if (mp.find(key) != mp.end()) {
            node* x = mp[key];
            int y = x->val;
            mp.erase(key);
            deletenode(x);
            addnode(x);
            mp[key] = head->next;

            return y;
        }
        return -1;
    }

    void put(int key, int value) {

        if (mp.find(key) != mp.end()) {
            node* l = mp[key];
            mp.erase(key);
            deletenode(l);
        }

        if (mp.size() >= cap) {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        node* x = new node(key, value);
        mp[key] = x;
        addnode(x);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
