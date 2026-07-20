class Node{
    int data;
    Node* next;

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

class LRUCache {
public:
    class Node{
        public:
            int key;
            int val;
            Node* next;
            Node* prev;

            Node(int key1, int val1){
                key = key1;
                val = val1;
            }
        };

    int cap = 0;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    unordered_map<int,Node*> map;

    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void addNode(Node* newNode){
        Node* currNode = head -> next;
        newNode -> next = currNode;
        newNode -> prev = head;
        head -> next = newNode;
        currNode -> prev = newNode;
    }

    void deleteNode(Node* delNode){
        Node* nextNode = delNode -> next;
        Node* prevNode = delNode -> prev;
        prevNode -> next = nextNode;
        nextNode -> prev = prevNode;
    }
    
    int get(int key) {
        if(map.find(key) != map.end()){
            Node* resNode = map[key];
            int result = resNode -> val;
            map.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            map[key] = head -> next;
            return result;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()){
            Node* existingNode = map[key];
            map.erase(key);
            deleteNode(existingNode);
        }

        if(map.size() == cap){
            map.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
        }

        addNode(new Node(key,value));
        map[key] = head -> next;
    }
};
