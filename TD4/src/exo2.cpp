#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdlib>

int firstWord (std::string const & str){
    int longueur {0};

    // Permet de savoir si un element est un espace
    auto const is_space = [](char letter){ return letter == ' '; };

    // Recherche de l'élément " " dans str
    auto it {std::find_if(str.begin(),str.end(), is_space)};
    if(it == str.end()){
        return str.size();
    }else{
        return std::distance(str.begin(),it);
    }
}

std::vector<std::string> split_string(std::string const& str){

    // Permet de savoir si un element est un espace
    auto const is_space = [](char letter){ return letter == ' '; };

    std::vector<std::string> tab {};
    auto it_begin {str.begin()};
    auto it_end {std::find_if(str.begin(),str.end(), is_space)};
    while(it_begin != str.end()){
        std::string mot {};
        std::copy(it_begin, it_end, std::back_inserter(mot));
        tab.push_back(mot);
        if(it_end == str.end()){
            break;
        }
        it_begin = it_end + 1;
        it_end = std::find_if(it_begin,str.end(), is_space);
    }
    return tab;
}


int main(){

    std::string const str {"bonjour je suis fanny"};
    // std::cout << "Le premier mot de la phrase est de longueur : " << firstWord(str) << std::endl;
    
    std::vector<std::string> result {split_string(str)};
    for(std::string mot : result){
        std::cout << mot << std::endl;
    }

}