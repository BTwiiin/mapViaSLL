#include "linked_list.h"
#include <iostream>


template <typename Key, typename Info>
bool LinkedList<Key, Info>::isEmpty() const{
    return head==nullptr;
}


/***************************COPINGELEMENTS***************************/
template <typename Key, typename Info>
void LinkedList<Key, Info>::copyElements(const LinkedList<Key, Info>& x) {
    Node* xtr = x.head;
    Node* ptr = head;

    while(ptr){
        if(!ptr->next){
            break;
        }
        ptr = ptr->next;
    }

    while(xtr){
        Node* ntr = new Node;
        if(!ntr){
            std::cerr << "Allocation memory failure!" << std::endl;
            break;
        }
        ntr->info = xtr->info;
        ntr->key = xtr->key;
        ntr->next = nullptr;

        if(!head){
            head = ntr;
        }else{
            ptr->next =ntr;
        }

        ptr = ntr;
        xtr = xtr->next;
    }
}
/***************************OPERATORS***************************/
template <typename Key, typename Info>
LinkedList<Key, Info>& LinkedList<Key, Info>::operator=(const LinkedList<Key, Info> &x) {
    if(this == &x){
        return *this;
    }
    removeAll();
    copyElements(x);
    return *this;
}
/***************************END-OPERATORS***************************/


/***************************CONSTRUCTOR-DESTRUCTOR***************************/
template <typename Key, typename Info>
LinkedList<Key, Info>::LinkedList(){
    head = nullptr;
    rear = nullptr;
}

template <typename Key, typename Info>
LinkedList<Key, Info>::~LinkedList(){
    removeAll();
}
/***************************END-CONSTRUCTOR-DESTRUCTOR***************************/


/***************************PRINTING***************************/
template <typename Key, typename Info>
void LinkedList<Key, Info>::printList() const{
    Node* temp = head;

    std::cout << "Printing list:" << std::endl;

    if(isEmpty()){
        std::cout << "List is empty" << std::endl;
        return;
    }

    auto it = this->constBegin();
    while(it != this->constEnd()){
        std::cout << "Key[" << it->key << "] - " <<  it->info << ";";
        if(it->next){
            std::cout << std::endl;
        }
        ++it;
    }

    std::cout << std::endl;

}

template <typename Key, typename Info>
void LinkedList<Key, Info>::printGivenKey(const Key &givenKey) const {

    Node* curr = nullptr;
    Node* prev = nullptr;
    bool flag = find(givenKey, curr, prev);

    if(flag){
        std::cout << "Info that stores in a key " << givenKey << " is " << curr->info << std::endl;
        return;
    }else{
        std::cout << "There is no such a key!" << std::endl;
    }
}
/***************************END-PRINTING***************************/


/***************************INSERTING***************************/
template <typename Key, typename Info>
void LinkedList<Key, Info>::pushBack(const Key& newKey, const Info& newInfo){
    Node* newNode = new Node;
    if(newNode == nullptr){
        std::cerr << "Function insert - Allocation memory failure!" << std::endl;
        return;
    }

    if(isEmpty()){
        head = newNode;
    }
    else{
        rear->next = newNode;
    }

    newNode->key = newKey;
    newNode->info = newInfo;
    newNode->next = nullptr;
    rear = newNode;

}

template <typename Key, typename Info>
void LinkedList<Key, Info>::pushFront(const Key& newKey, const Info& newInfo){
    Node* newNode = new Node;
    if(newNode == nullptr){
        std::cerr << "Function pushFront - Allocation memory failure!" << std::endl;
        return;
    }

    if(isEmpty()){
        rear = newNode;
    }

    newNode->key = newKey;
    newNode->info = newInfo;
    newNode->next = head;
    head = newNode;
}

template <typename Key, typename Info>
void LinkedList<Key, Info>::insertAfter(const Key& newKey, const Info& newInfo, const Key& givenKey, int occ){
    Node* newNode = new Node;
    if(newNode == nullptr){
        std::cerr << "Function insertAfter - Allocation memory failure!" << std::endl;
        return;
    }

    newNode->key = newKey;
    newNode->info = newInfo;

    if(isEmpty()){
        rear = newNode;
        head = newNode;
        newNode->next = nullptr;
    }
    else{
        Node* temp = head;
        Node* prev = nullptr;

        int occur;

        while(temp){
            if(temp->key == givenKey){
                occur++;
                if(occur == occ){
                    if(temp->next == nullptr){
                        rear = newNode;
                    }
                    newNode->next = temp->next;
                    temp->next = newNode;
                    return;
                }

            }
            prev = temp;
            temp = temp->next;
        }

        prev->next = newNode;
        newNode->next = nullptr;
        rear = newNode;

    }
}

template <typename Key, typename Info>
void LinkedList<Key, Info>::insert(const Key& newKey, const Info& newInfo){
    Node* newNode = new Node;
    if(newNode == nullptr){
        std::cerr << "Function insertAfter - Allocation memory failure!" << std::endl;
        return;
    }

    newNode->key = newKey;
    newNode->info = newInfo;

    if(isEmpty()){
        rear = newNode;
        head = newNode;
        newNode->next = nullptr;
        return;
    }
    else{
        if(newKey > rear->key){
            rear->next = newNode;
            rear = newNode;
            newNode->next = nullptr;
            return;
        }
        if(newKey < head->key){
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* curr = head->next;
        Node* prev = head;

        while(curr){
            if(curr->key > newKey){
                prev->next = newNode;
                newNode->next = curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }

    }
}

template <typename Key, typename Info>
bool LinkedList<Key, Info>::assign(const Key &givenKey, const Info &newInfo) {
    Node* curr = nullptr;
    Node* prev = nullptr;

    bool flag = find(givenKey, curr, prev);

    if(flag){
        curr->info = newInfo;
        return flag;
    }else{
        std::cout << "A given Key[" << givenKey << "] wasn't found!" << std::endl;
        return flag;
    }
}
/***************************END-INSERTING***************************/


/***************************REMOVING***************************/
template <typename Key, typename Info>
void LinkedList<Key, Info>::removeAll(){
    Node* temp = head;
    while(temp){
        temp = temp->next;
        delete head;
        head = temp;
    }

}

template <typename Key, typename Info>
void LinkedList<Key, Info>::popFront(){
    if(isEmpty()){
        std::cout << "List is empty, cannot delete anything!" << std::endl;
        return;
    }

    Node* temp = head;

    temp = temp->next;
    delete head;
    head = temp;
}

template <typename Key, typename Info>
void LinkedList<Key, Info>::popBack(){
    if(isEmpty()){
        std::cout << "List is empty, cannot delete anything!" << std::endl;
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    while(temp->next){
        prev = temp;
        temp = temp->next;
    }

    prev->next = nullptr;
    delete rear;
    rear = prev;
}

template <typename Key, typename Info>
bool LinkedList<Key, Info>::removeByKey(const Key &givenKey){
    Node* curr = nullptr;
    Node* prev = nullptr;
    bool flag = find(givenKey, curr, prev);

    if(flag){
        if(prev == nullptr){
            head = curr->next;
        } else{
            prev->next = curr->next;
        }
        delete curr;
    }
    return flag;
}
/***************************END-REMOVING***************************/


/***************************FINDING***************************/
template <typename Key, typename Info>
bool LinkedList<Key, Info>::find(const Key& givenKey) const{
    Node* curr = nullptr;
    Node* prev = nullptr;
    return find(givenKey, curr, prev);
}

template <typename Key, typename Info>
bool LinkedList<Key, Info>::find(const Key &givenKey, Node *&curr, Node *&prev) const {
    curr = head;
    prev = nullptr;

    while (curr){
        if(curr->key == givenKey){
            return true;
        }
        prev = curr;
        curr = curr->next;

    }
    return false;
}
/***************************END-FINDING***************************/


