#include <iostream>
#include "linked_list.cpp"
#include "dictionary.cpp"

int main(){

    dictionary<int, std::string> dict1;
    dictionary<int, std::string> dict2;

    std::cout << "Dict1:" << std::endl;
    dict1.insert(1, "a");

    dict1[2] = "b";
    dict1[3] = "c";
    dict1[4] = "e";
    dict1[5] = "f";

    dict2[1] = "A";
    dict2[2] = "B";
    dict2[3] = "C";
    dict2[6] = "G";

    dict1.print();
    std::cout << "Dict 2:" << std::endl;
    dict2.print();

    std::cout << "Joined dict:" << std::endl;
    join(dict1, dict2).print();



    return 0;
}