#include "header.h"

/**
 * Don't be too scared, first implement some basic functions, like: 
 * addToHead, removeNode.etc
 * then start to implement some more complicated functions.  
 */



/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode* > cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

    void addToHead(DLinkedNode* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = nullptr;
        node->prev = nullptr;
    }
    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
        
    }
    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
public:
    LRUCache(int _capacity): capacity(_capacity), size(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!cache.count(key)){
            return -1;
        }
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            DLinkedNode * node =  new DLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            ++size;
            if(size > capacity){
                DLinkedNode* removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                --size;
            }
        }
    }
};

