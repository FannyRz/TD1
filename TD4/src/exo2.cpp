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
    auto it { std::find(str.begin(), str.end(), is_space) };

    // On compare l'itérateur avec l'itérateur sur le dernier élément du vecteur
    if (it != str.end())
    {
        longueur = std::distance(str.begin(),it);
        return longueur;
    }
    else
    {
        std::cout << "Element not found" << std::endl;
        return -1;
    }

}

int main(){

    std::string const str {"bonjour je suis fanny"};
    std::cout << "Le premier mot de la phrase est de longueur : " << firstWord(str) << std::endl;

}