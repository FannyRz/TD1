#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <iterator>
#include <cctype>


enum class Operator { ADD, SUB, MUL, DIV, OPEN_PAREN, CLOSE_PAREN};
enum class TokenType { OPERATOR, OPERAND };
struct Token {
  TokenType type;
  float value;
  Operator op;
};

Token make_token(float value){
    return Token {TokenType::OPERAND, value};
}

Token make_token(Operator op){
    return Token {TokenType::OPERATOR, NULL, op};
}

bool est_flottant(std::string const& s){

    for(char c : s){
        if(!(std::isdigit(c)  || c=='.')){
            return false;
        }
    }
    return true;
    
}

std::vector<Token> tokenize(std::vector<std::string> const& words){
    std::vector<Token> result {};

    for(std::string str : words){
        if(est_flottant(str)){
            result.push_back(make_token(std::stof(str)));
        }else if(str==std::string{'+'}){
            result.push_back(make_token(Operator::ADD));
        }else if(str==std::string{'-'}){
            result.push_back(make_token(Operator::SUB));
        }else if(str==std::string{'*'}){
            result.push_back(make_token(Operator::MUL));
        }else if(str==std::string{'/'}){
            result.push_back(make_token(Operator::DIV));
        }else if(str==std::string{'('}){
            result.push_back(make_token(Operator::OPEN_PAREN));
        }else if(str==std::string{')'}){
            result.push_back(make_token(Operator::CLOSE_PAREN));
        }
    }
    return result;

}

std::string saisie_utilisateur(){

    std::string saisie {};
    std::cout << "Entrez votre expression arithmetique" << std::endl;
    std::getline(std::cin, saisie);
    return saisie;

}

std::vector<std::string> separation_saisie(std::string const& s){

    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>());

}

float calcule (float rightOperand,float leftOperand,Operator op){
    if(op == Operator::ADD){
        return leftOperand+rightOperand;
    }else if(op == Operator::SUB){
        return leftOperand-rightOperand;
    }else if(op == Operator::MUL){
        return leftOperand*rightOperand;
    }else if(op == Operator::DIV){
        return leftOperand/rightOperand;
    }else{
        std::cout << "operateur inconnu" << std::endl;
        return -1.f;
    }
}

float npi_evaluate(std::vector<Token> const& tokens){

    std::stack<float> stack;

    for(Token t : tokens){

        if(t.type == TokenType::OPERAND){
            stack.push(t.value);
        }else{
            // Je récupère l'élément en haut de la pile
            float rightOperand { stack.top() };
            // Je l'enlève de la stack (la méthode top ne fait que lire l’élément en dessus de la pile)
            stack.pop();
            float leftOperand { stack.top() };
            stack.pop();

            // Il faut ensuite en fonction de l'opérateur calculer le résultat pour le remettre dans la pile
            float result {calcule(rightOperand,leftOperand,t.op) };
            stack.push(result);
        }        
    }
    return stack.top();

}

int main()
{
    std::string saisie {saisie_utilisateur()};
    std::vector<std::string> tab {separation_saisie(saisie)};
    std::vector<Token> tabToken {tokenize(tab)};
    float result {npi_evaluate(tabToken)};
    std::cout << "Le resultat de " << saisie << " est : " << result << std::endl;

}