#ifndef UNTITLED1_DICTIONARY_H
#define UNTITLED1_DICTIONARY_H
#include "linked_list.h"
#include <iostream>
#include <map>

template <typename Key, typename Info>
class dictionary{
private:
    LinkedList<Key, Info> dict;
public:
    typename LinkedList<Key, Info>::Iterator begin() { return dict.begin(); }
    typename LinkedList<Key, Info>::Iterator end() { return dict.end(); }

    typename LinkedList<Key, Info>::Const_Iterator constBegin() const { return dict.constBegin(); }
    typename LinkedList<Key, Info>::Const_Iterator constEnd() const { return dict.constEnd(); }

    dictionary();
    ~dictionary();

    dictionary<Key, Info>& operator=(const dictionary<Key, Info>& x){
        this->dict = x.dict;
        return *this;
    }


    bool empty() const;
    void removeAll(){ dict.removeAll(); }
    void copyElements(const dictionary<Key, Info>& x){ copyElements(x);}
    void insert(const Key& newKey, const Info& newInfo);
    bool remove(const Key& key){ return dict.removeByKey(key); }
    void print() const{ dict.printList(); }
    Info& operator[](const Key& key);

};

//function to join to dictionaries
template <typename Key, typename Info>
dictionary<Key, Info> join(const dictionary<Key, Info>& first, const dictionary<Key, Info>& second){

    dictionary<Key, Info> res;
    auto it1 = first.constBegin();
    auto it2 = second.constBegin();

    std::map<Key, Info> hashMap;
    for (it1; it1 != first.constEnd(); it1++) {
        hashMap[it1.getKey()] += it1.getInfo();
    }

    for (it2; it2 != second.constEnd(); it2++) {
        hashMap[it2.getKey()] += it2.getInfo();
    }

    for (const auto& i : hashMap) {
        res.insert(i.first, i.second);
    }

    return res;
}

#endif //UNTITLED1_DICTIONARY_H
