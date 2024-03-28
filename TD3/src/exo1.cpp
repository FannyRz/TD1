#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <iterator>
#include <cctype>

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

bool est_flottant(std::string const& s){

    for(char c : s){
        if(!(std::isdigit(c)  || c=='.')){
            return false;
        }
    }
    return true;
    
}


float calcule (float rightOperand,float leftOperand,std::string const s){
    if(s==std::string{'+'}){
        return leftOperand+rightOperand;
    }else if(s==std::string{'-'}){
        return leftOperand-rightOperand;
    }else if(s==std::string{'*'}){
        return leftOperand*rightOperand;
    }else if(s==std::string{'/'}){
        return leftOperand/rightOperand;
    }else if(s==std::string{'^'}){
        return pow(leftOperand,rightOperand);
    }else{
        std::cout << "operateur inconnu" << std::endl;
        return -1.f;
    }
}

float npi_evaluate(std::vector<std::string> const& tokens){

    std::stack<float> stack;

    for(std::string s : tokens){

        if(est_flottant(s)){
            stack.push(std::stof(s));
        }else{
            // Je récupère l'élément en haut de la pile
            float rightOperand { stack.top() };
            // Je l'enlève de la stack (la méthode top ne fait que lire l’élément en dessus de la pile)
            stack.pop();
            float leftOperand { stack.top() };
            stack.pop();

            // Il faut ensuite en fonction de l'opérateur calculer le résultat pour le remettre dans la pile
            float result {calcule(rightOperand,leftOperand,s) };
            stack.push(result);
        }        
    }
    return stack.top();

}

int main()
{
    std::string saisie {saisie_utilisateur()};
    std::vector<std::string> tab {separation_saisie(saisie)};
    float result {npi_evaluate(tab)};
    std::cout << "Le resultat de " << saisie << " est : " << result << std::endl;

}