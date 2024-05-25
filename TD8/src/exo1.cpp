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

std::string reverseRunLenghtEncoding(std::string str){
    std::string res {};
    for(int i {0}; i<str.size();i=i+2){
        for(char j {'0'}; j<str[i]; j++){
            res.push_back(str[i+1]);
        }
    }
    return res;
}

std::string runLengthEncodingSpecial (std::string str){
    std::string res {};
    char compte {'1'};
    char courant {str[0]};

    for(int i{1}; i<str.size();i++){
        if(courant != str[i]){
            if(compte != '1'){
                res.push_back('*');
                res.push_back(static_cast<int>(compte));
                res.push_back(courant);
                compte = '1';
                courant = str[i];
            }else{                 // si on n'a qu'un seul caractere
                res.push_back(courant);
                courant = str[i];
            }

        }else{
            compte ++;
        }  
    }
    res.push_back('*');
    res.push_back(static_cast<int>(compte));
    res.push_back(courant);

    return res;
}

std::string betterRunLengthEncodingSpecial (std::string str){

    char c {};
    std::cout << "Rentrez le caractere special que vous souhaitez : " << std::endl;
    std::cin >> c ;

    std::string res {};
    char compte {'1'};
    char courant {str[0]};

    for(int i{1}; i<str.size();i++){
        if(courant != str[i]){
            if(compte != '1'){
                res.push_back(c);
                res.push_back(static_cast<int>(compte));
                res.push_back(courant);
                compte = '1';
                courant = str[i];
            }else{                 // si on n'a qu'un seul caractere
                res.push_back(courant);
                courant = str[i];
            }

        }else{
            compte ++;
        }  
    }
    res.push_back(c);
    res.push_back(static_cast<int>(compte));
    res.push_back(courant);

    if(res.size()>str.size()){
        return str;
    }else{
        return res;
    }
    
}

// std::string betterReverseRunLenghtEncoding(std::string str){
//     std::string res {};
//     int courant {0};
//     char occurence {};
//     for(int i {0}; i<str.size();i++){
//         if(str[i]>=49 && str[i]<=57){   // i compris entre 0 et 9 en ASCII
//             courant ++;
//             occurence += str[i];
//             std::cout << occurence << std::endl;
//             continue;
//         }
        
//         for(char j {'0'}; j< occurence; j++){
//             res.push_back(str[i+1]);
//         }
//     }
//     return res;
// }


void displayString(std::string str){
    std::cout << "[" ;
    for(char c : str){
        std::cout << c << ", ";
    }
    std::cout << "]" << std::endl;
}


int main(){
    std::string str {"AAAABBBCCDAA"};
    std::string str2 {"AAAAAA"};
    std::string str_encoding {runLengthEncoding(str)};
    std::string str_unencoding {reverseRunLenghtEncoding(str_encoding)};
    std::string str_encodingSpecial {betterRunLengthEncodingSpecial(str2)};

    
    displayString(str);
    displayString(str_encodingSpecial);

}