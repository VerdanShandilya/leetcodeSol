struct node {
    int key;
    int val;
    node* next;
    node* prev;
    node (int _key,int _val){
        key=_key;
        val=_val;
        prev=nullptr;
        next=nullptr;
    }
};


class LRUCache{
private: 
    int cap;
    node* head;
    node* tail;
    unordered_map<int,node*> m;

public:

    LRUCache(int capacity) {
        cap=capacity;
        head=new node(-1,-1);
        tail=new node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            auto val=m[key];
            remove(val);
            insert(val);
            return val->val;
        }
        return -1;
    }
    void remove(node* key){
        key->prev->next=key->next;
        key->next->prev=key->prev;
    }
    void insert(node* key){
        key->next=head->next;
        head->next=key;
        key->prev=head;
        key->next->prev=key;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            remove(m[key]);
        }
        node* newnode=new node(key,value);
        m[key]=newnode;
        insert(newnode);
        if(m.size()>cap){
            auto temp=tail->prev;
            remove(temp);
            m.erase(temp->key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */