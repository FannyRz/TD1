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
    std::vector<std::string> str {};
}


int main(){

    std::string const str {"bonjour je suis fanny"};
    std::cout << "Le premier mot de la phrase est de longueur : " << firstWord(str) << std::endl;

}