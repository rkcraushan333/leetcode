// use hashmap and DLL
struct node{
    pair<int,int> val;
    node* next;
    node* prev;
    node(){
        val={0,0};
        prev = NULL;
        next = NULL;
    }
};
class LRUCache {
public:
    int n;
    unordered_map<int,node*>m;
    node* head=new node();
    node* tail= new node();
    LRUCache(int capacity) {
        n = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()) {
            node* temp = m[key];
            node* temp1 = temp->prev;
            node* temp2 = temp->next;
            temp1->next = temp2;
            temp2->prev = temp1;
            node* temp3 = head->next;
            head->next = temp;
            temp->prev = head;
            temp3->prev = temp;
            temp->next = temp3;
            return m[key]->val.second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            node* temp = m[key];
            node* temp2 = temp->prev;
            node* temp3 = temp->next;
            temp2->next = temp3;
            temp3->prev = temp2;
            temp->val.second = value;
            node* temp4 = head->next;
            head->next = temp;
            temp->prev = head;
            temp4->prev = temp;
            temp->next = temp4;
            return;
        }
        if(m.size()==n){
            node* temp = tail->prev;
            node* temp2 = temp->prev;
            temp2->next = tail;
            tail->prev = temp2;
            m.erase(temp->val.first);
            node* temp3 = new node();
            temp3->val = {key,value};
            node* temp4 = head->next;
            head->next = temp3;
            temp3->prev = head;
            temp3->next = temp4;
            temp4->prev = temp3;
            m[key] = temp3;
            return;
        }
        
            node* temp3 = new node();
            temp3->val = {key,value};
            node* temp4 = head->next;
            head->next = temp3;
            temp3->prev = head;
            temp3->next = temp4;
            temp4->prev = temp3;
            m[key] = temp3;        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */