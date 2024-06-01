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

std::string betterReverseRunLenghtEncoding(std::string str){
    size_t count {0};
    std::string res {};
    for(int i {0}; i<str.size(); i++){
        if(str[i]>=49 && str[i]<=57){   // str[i] est un chiffre
            count = str[i] - '0';    //conversion du chiffre avec sa valeur ASCII pour avoir un chiffre entre 0 et 9)
            
            while(str[i+1]>=49 && str[i+1]<=57){
            i += 1;
            count *= 10;    // on multiplie par 10 car les unites deviennent les dizaines etc.
            count += str[i]-'0';
            }
        }else{
            // j'ajoute autant de fois qu'il faut la lettre pour la répétition 
            for(int j {0}; j < count; j++){
                res += str[i];
            }
            // reset le compteur à 1 
            count = 0;
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
    

    
    // displayString(str);
    // displayString(betterReverseRunLenghtEncoding("12A3B2C1D2A"));
    // displayString(str_encodingSpecial);

    return 0;
}