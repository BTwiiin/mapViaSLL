#include "dictionary.h"
#include <iostream>


template <typename Key, typename Info>
dictionary<Key, Info>::~dictionary(){
    dict.removeAll();
}

template <typename Key, typename Info>
dictionary<Key, Info>::dictionary(){
    LinkedList<Key, Info> dict;
}

template <typename Key, typename Info>
bool dictionary<Key, Info>::empty() const {
    return dict.isEmpty();
}

template <typename Key, typename Info>
void dictionary<Key, Info>::insert(const Key &newKey, const Info &newInfo) {
    if(dict.find(newKey)){
        std::cout << "This key is already used!" << std::endl;
        return;
    }
    dict.insert(newKey, newInfo);
}

template <typename Key, typename Info>
Info& dictionary<Key, Info>::operator[](const Key& key){

    if(dict.find(key)){
        return dict.pointer(key)->info;
    }else{
        Info temp;
        dict.insert(key, temp);
        return dict.pointer(key)->info;
    }
}
