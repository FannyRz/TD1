#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdlib>


size_t folding_string_hash(std::string const& s, size_t max){
    size_t somme {0};
    for(char c : s){
        somme += c;
    }
    return somme%max;
}

size_t folding_string_ordered_hash(std::string const& s, size_t max){
    size_t somme {0};
    for(int i {0}; i<s.size(); i++){
        somme += (i+1)*s[i];  //pour eviter que pour un tab a un character, le resultat soit nul
    }
    return somme%max;
}

size_t puissance(size_t entier, int indice){
    size_t result {1};
    if(indice==0){
        return 1;
    }else{
        while(indice>0){
            result *= entier;
            indice -= 1;
        }
        return result;
    }
}

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m){
    size_t somme {0};
    for(int i {0}; i<s.size(); i++){
        somme += s[i]*puissance(p,i);  //pour eviter que pour un tab a un character, le resultat soit nul
    }
    return somme%m;
}


int main()
{
    std::string str1 {"anti"};
    std::string str2 {"jourbon"};

    std::cout << "Le hach de " << str1 << " est "<< folding_string_hash(str1,1024) << std::endl;
    std::cout << "Le hach de " << str2 << " est "<< folding_string_hash(str2,1024) << std::endl;

    std::cout << "Le hach ordonne de " << str1 << " est "<< folding_string_ordered_hash(str1,1024) << std::endl;
    std::cout << "Le hach ordonne de " << str2 << " est "<< folding_string_ordered_hash(str2,1024) << std::endl;
    
    std::cout << "Le hach polynomial de " << str1 << " est "<< polynomial_rolling_hash(str1,10,1024) << std::endl;
    std::cout << "Le hach polynomial de " << str2 << " est "<< polynomial_rolling_hash(str2,10,1024) << std::endl;

}