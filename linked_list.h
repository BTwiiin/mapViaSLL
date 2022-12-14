#ifndef LINKED_LIST
#define LINKED_LIST
#include <iostream>



template <typename Key, typename Info>
class LinkedList{
private:
    struct Node{
        Key key;
        Info info;
        Node* next;
    };
    Node* head; //pointer to the first node
    Node* rear; //pointer to the last node

    bool find(const Key& givenKey, Node*& curr, Node*& prev) const;
    void copyElements(const LinkedList<Key, Info>&);

public:

    template<typename K, typename I>
    class iterator {
    private:
        Node* current;

        iterator(Node* curr) : current(curr) {};
    public:
        iterator() : current(nullptr) {};

        iterator(const iterator& obj) : current(obj.current) {};

        //Operators
        iterator& operator++() {
            if (current) {
                current = current->next;
            }
            return *this;
        }

        iterator& operator++(int) {
            if (current) {
                current = current->next;
            }
            return *this;
        }

        iterator& operator= (const iterator& source) {
            current = source.current;
            return *this;
        }

        Node& operator* () {
            return *current;
        }

        Node* operator->() {
            return current;
        }

        bool operator==(const iterator& source) {
            return current == source.current;
        }

        bool operator!=(const iterator& source) {
            return current != source.current;
        }

        //Methods
        K getKey() const {
            return current->key;
        }

        I getInfo() const {
            return current->info;
        }

        I& getValRef() {
            return current->info;
        }

        friend class LinkedList;
    };
    typedef iterator<Key, Info> Iterator;
    typedef iterator<const Key, const Info> Const_Iterator;

    //default iterators
    Iterator begin() { return Iterator(head); }
    Iterator end() { return nullptr; }

    //constant iterators
    Const_Iterator constBegin() const { return Const_Iterator(head); }
    Const_Iterator constEnd() const { return nullptr; }

    LinkedList();
    ~LinkedList();

    LinkedList<Key, Info>& operator=(const LinkedList<Key, Info>& x);

    bool isEmpty() const;

    /****PRINTING*****/
    void printList() const; //prints the whole list
    void printGivenKey(const Key& givenKey) const; //prints nodes with a given key
    void printGivenKey(const Key& givenKey, int occ) const; //prints node with a given key on a given occurrence

    /****INSERTION*****/
    void pushBack(const Key& newKey, const Info& newInfo);
    void pushFront(const Key& newKey, const Info& newInfo);
    void insertAfter(const Key& newKey, const Info& newInfo, const Key& givenKey, int occ);
    void insert(const Key& newKey, const Info& newInfo);
    bool assign(const Key& givenKey, const Info& newInfo);// assigns new info to an existing key value

    /****DELETING*****/
    void removeAll(); //removes everything
    void popFront(); //removes the first node
    void popBack(); //removes the last node
    bool removeByKey(const Key& givenKey); //removes a node by a key

    Node* getHead(){ //GETTER
        return head;
    }

    Info infoByKey(const Key& key) const{ //returns info by a key
        Node* curr = nullptr;
        Node* prev = nullptr;
        if(find(key, curr, prev)){
            return curr->info;
        }
        return NULL;
    }

    Node* pointer(const Key& key){ //returns a pointer to a given key
        Node* curr = nullptr;
        Node* prev = nullptr;
        find(key, curr, prev);
        if(find(key, curr, prev)){
            return curr;
        }
        return nullptr;

    }

    bool find(const Key& givenKey) const; //finds a node by a key
};

#endif