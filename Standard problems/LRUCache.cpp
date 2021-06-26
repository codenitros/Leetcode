class LRUCache{
    
    class node{
        public:
            int val;
            int key;
            node* next;
            node* prev;

            //constructor
            node(int _key,int _val){
                key = _key;
                val = _val;
            }
    };

    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);

    int cap;
    unordered_map<int, node*> m;

    //constructor
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next=tail;
        tail->prev=head;
    }

    // adds at first
    void addnode(node* newnode)
    {
        node* temp = head->next;
        newnode->next = temp;
        temp->prev = newnode;
        head->next = newnode;
        newnode->prev = head;
    }

    void deletenode(node* delnode)
    {
        node* prevNode = delnode->prev;
        node* nextNode = delnode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void get(int key_)
    {
        // if key exists, get its value and make it least recent used
        if(m.find(key_) != m.end())
        {
            node* resnode = m[key_];
            int res = resnode->val;
            m.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            m[key_] = head->next;
            return res;
        }
        return -1;

    }

    void put(int key_, int val_)
    {
        // if key is already there erase it
        if(m.find(key_) != m.end())
        {
            node* existingnode = m[key_];
            m.erase(key_);
            deletenode(existingnode);
        }

        // if capacity reached, delete
        if(m.size() == cap)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        // call add node and make it new head
        addnode(new node(key_,val_));
        m[key_] = head->next;
    }
};

