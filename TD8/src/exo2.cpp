#include <iostream>
#include <string>
#include <unordered_map>

struct Node {
    char character;
    size_t frequency;
    Node* left { nullptr };
    Node* right { nullptr };
};

/*Q1*/
std::unordered_map<char, size_t> frequency(std::string str){
    std::unordered_map<char, size_t> res {};
    for(char c : str){
        std::pair<char, size_t> courant {};
        if(res.find(c) == res.end()){
            courant.first = c;
            int compteur {0};
            for(int i{0}; i<str.size();i++){
                if(str[i]==c){
                    compteur++;
                }
            }
            courant.second = compteur;
            res.insert(courant);            
        }
    }
    return res;
}

/*Q2*/
bool operator<(Node node1, Node node2){
    return (node1.left->frequency < node2.right->frequency);
}

/*Q3*/

void display_unordered_map(std::unordered_map<char, size_t> map){
    for(std::unordered_map<char,size_t>::iterator it {map.begin()}; it != map.end(); it++){
        std::cout << it->first << " : " << it->second << std::endl ;
    }
}


int main(){
    std::string str {"coucou les copains"};
    // display_unordered_map(frequency(str));

    Node node1 {'c',static_cast<size_t>(10),new Node {'f',static_cast<size_t>(30)},new Node {'m',static_cast<size_t>(20)}};
    Node node2 {'c',static_cast<size_t>(50),new Node {'f',static_cast<size_t>(20)},new Node {'m',static_cast<size_t>(40)}}; 

    return 0;

}