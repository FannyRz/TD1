#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::string saisie_utilisateur(std::string saisie){

    std::string saisie;
    std::cout << "Entrez votre expression arithmétique" << std::endl;
    std::getline(std::cin, saisie);
    return saisie;

}

std::vector<std::string> separation_saisie(std::string const& saisie){

    std::istringstream in(saisie); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
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


float npi_evaluate(std::vector<std::string> const& tokens){


}


int main()
{


}