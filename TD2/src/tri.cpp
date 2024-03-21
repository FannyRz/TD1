#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

//Le tableau est trié
bool is_sorted(std::vector<int> const& vec) {
    return std::is_sorted(vec.begin(), vec.end()); 
}

//afficher un tableau de int
void display(std::vector<int> const& vec){
    std::cout << "[";
    for(int i=0 ; i<vec.size(); i++){
        std::cout << vec[i] << ", " ;
    }
    std::cout << "]" << std::endl;
}

//afficher un tableau de float
void display(std::vector<float> const& vec){
    std::cout << "[";
    for(int i=0 ; i<vec.size(); i++){
        std::cout << vec[i] << ", " ;
    }
    std::cout << "]" << std::endl;
}

//tri par selection
void selection_sort(std::vector<int> & vec){
    if(!vec.empty()){

        for( int j=0; j<vec.size(); j++){

                int min {vec[j]};
                int indice_min {j};

                //on cherche le plus petit element
                for(int i=j; i < vec.size(); i++){
                    if(vec[i]<min){
                        min = vec[i];
                        indice_min = i;
                    }
                }

                //on switch si besoin
                if(min != vec[j]){
                    vec[indice_min] = vec[j];
                    vec[j] = min;
                }
        }

    }else{
        std::cout << "Probleme : tableau vide" << std::endl;
    }
}


//tri fusion

void merge_sort_merge(std::vector<float> & vec, size_t const left, size_t const middle, size_t const right) {
    // On crée deux vecteurs temporaires pour stocker les copies des deux sous-parties à fusionner
    size_t const left_size { middle - left + 1 };
    size_t const right_size { right - middle };
    std::vector<float> left_vec(vec.begin() + left, vec.begin() + middle + 1);
    std::vector<float> right_vec(vec.begin() + middle + 1, vec.begin() + right + 1);

    // Deux index pour parcourir les deux sous-parties et remplir le vecteur original
    size_t left_index {0};
    size_t right_index {0};

    size_t index {left};

    // Tant que nous avons pas parcouru tout les éléments d'au moins une des deux sous-parties
    while (left_index < left_size && right_index < right_size) {
        // On compare les éléments des deux sous-parties et on place le plus petit dans le vecteur original
        // on met à jour les index pour parcourir les sous-parties en conséquence
        if (left_vec[left_index] < right_vec[right_index]) {
            vec[index] = left_vec[left_index];
            left_index ++;
        } else {
            vec[index] = right_vec[right_index];
            right_index ++;
        }
        index ++;
    }

    // // S'il reste des éléments dans une des deux sous-parties, on les place dans le vecteur original
    while (left_index < left_size) {
        vec[index] = left_vec[left_index];
        left_index ++;
        index ++;
    }
    while (right_index < right_size) {
        vec[index] = right_vec[right_index];
        right_index ++;
        index ++;
    }
}

void merge_sort(std::vector<float> & vec, size_t const left, size_t const right) {
    if (left >= right) {
        return;
    }

    size_t middle {0};
    middle = (right + left)/2;
    merge_sort(vec,left,middle);
    merge_sort(vec,middle+1,right);
    merge_sort_merge(vec,left,middle,right);

    // 1. Choix de l'index au milieu de la partition
    // 2. Appels récursifs sur les deux sous-parties
    // 3. Fusion des deux sous-parties
}

// Même mécanisme que pour le tri rapide
void merge_sort(std::vector<float> & vec) {
    merge_sort(vec, 0, vec.size() - 1);
}

//tableau aléatoire
std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}


//dichotomie
int search(std::vector<int> vec, int entier){
    int left_index {0};
    int right_index = vec.size()-1 ;
    int middle {0};

    while(left_index <= right_index){
        middle = (left_index + right_index)/2;
        if(vec[middle]==entier){
            return middle;
        }
        else if (vec[middle] < entier){
            left_index = middle + 1;
        }else{
            right_index = middle - 1;
        }
    }
    return -1;
}