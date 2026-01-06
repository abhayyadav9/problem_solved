#include <unordered_map>
using namespace std;

class LRUCache {
public:
    struct Node {
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int capacity;
    unordered_map<int, Node*> mp;

    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    // Add node right after head
    void addNode(Node* newNode) {
        Node* temp = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = temp;
        temp->prev = newNode;
    }

    // Remove a node
    void delNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        Node* node = mp[key];
        int val = node->val;

        // Move this node to front (MRU position)
        delNode(node);
        addNode(node);

        return val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // Update existing node
            Node* existing = mp[key];
            delNode(existing);
            mp.erase(key);
            delete existing;
        }

        if ((int)mp.size() == capacity) {
            // Remove LRU node (node before tail)
            Node* lru = tail->prev;
            delNode(lru);
            mp.erase(lru->key);
            delete lru;
        }

        // Insert new node at front
        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
    }
};
