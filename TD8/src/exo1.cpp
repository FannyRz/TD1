#include <iostream>
#include <string>

std::string runLengthEncoding (std::string str){
    std::string res {};
    char compte {'1'};
    char courant {str[0]};

    for(int i{1}; i<str.size();i++){
        if(courant != str[i]){
            res.push_back(static_cast<int>(compte));
            res.push_back(courant);
            compte = '1';
            courant = str[i];
        }else{
            compte ++;
        }  
    }
    res.push_back(static_cast<int>(compte));
    res.push_back(courant);

    return res;
}


void displayString(std::string str){
    std::cout << "[" ;
    for(char c : str){
        std::cout << c << ", ";
    }
    std::cout << "]" << std::endl;
}


int main(){
    std::string str {"AAAABBBCCDAA"};
    std::string res {runLengthEncoding(str)};
    
    displayString(str);
    displayString(res);

}