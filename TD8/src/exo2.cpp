#include <iostream>
#include <string>
#include <unordered_map>

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

void display_unordered_map(std::unordered_map<char, size_t> map){
    for(std::unordered_map<char,size_t>::iterator it {map.begin()}; it != map.end(); it++){
        std::cout << it->first << " : " << it->second << std::endl ;
    }
}


int main(){
    std::string str {"coucou les copains"};
    display_unordered_map(frequency(str));

    return 0;

}