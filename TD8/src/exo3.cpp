#include <iostream>

bool palindrome (std::string const & str){
    return std::equal(str.begin(), str.end(),str.rbegin());
}

int main(){

    std::string str;
    std::cout << "Entrez un mot : " << std::endl;
    std::cin >> str;

    if(palindrome(str)){
        std::cout << "Ce mot est un palindrome." << std::endl;
    }else{
        std::cout << "Ce mot n'est pas un palindrome." << std::endl;
    }

    return 0;
}