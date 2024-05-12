#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_map>

std::string random_name(size_t size) {
    std::string name {""};
    // Optimisation pour que la chaîne de caractère ne réalloue pas de la mémoire à chaque caractère ajouté
    // https://cplusplus.com/reference/string/string/reserve/
    name.reserve(size);
    for(size_t i {0}; i < size; ++i) {
        name.push_back('A' + std::rand() % 26);
    }
    return name;
}

std::vector<std::pair<std::string, float>> get_robots_fix(size_t size) {
    std::vector<std::pair<std::string, float>> robots_fix {};
    // Meme optimisation que dans random_name()
    // https://cplusplus.com/reference/vector/vector/reserve/
    robots_fix.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        // random name 
        std::string robotName { random_name(2) };
        // random cost
        float cost {static_cast<float>(std::rand()) / RAND_MAX * 1000.0f};
        robots_fix.push_back(std::make_pair(robotName, cost));
    }
    return robots_fix;
}

bool robotDejaPresent(std::unordered_map<std::string, std::vector<float>> const& robots, std::string const& str){
    return !(robots.find(str)==robots.end());
}

std::unordered_map<std::string, std::vector<float>> robots_fixes_map(std::vector<std::pair<std::string, float>> const& robots_fixes){

    std::unordered_map<std::string, std::vector<float>> myMap {};

    for(int i {0}; i<robots_fixes.size(); i++){
        std::string nom_courant {robots_fixes[i].first};

        if(!(robotDejaPresent(myMap,nom_courant))){
            std::pair<std::string, std::vector<float>> robot {};
            robot.first = nom_courant;
            for(int j{i}; j<robots_fixes.size();j++){
                if(robot.first == robots_fixes[j].first){
                    robot.second.push_back(robots_fixes[j].second);
                }
            }
            myMap.insert(robot);
        }
    }

    return myMap;

}

float sommeVecteur (std::vector<float> vec){
    float somme {0.f};
    for(int i{0}; i<vec.size();i++){
        somme = somme + vec[i];
    }
    return somme;
}

std::unordered_map<std::string, float> sommeReparationEffectue(std::vector<std::pair<std::string, float>> robot){
    std::unordered_map<std::string, float> resultat {};
    std::unordered_map<std::string, std::vector<float>> robot_regroupe {robots_fixes_map(robot)};
    for(std::pair<std::string, std::vector<float>> element : robot_regroupe ){
        std::pair<std::string, float> robot_courant {element.first,sommeVecteur(element.second)};
        resultat.insert(robot_courant);
    } 
    return resultat;
}

int main(){
    
}