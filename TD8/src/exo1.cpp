#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdlib>


std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

//afficher un tableau de int
void display(std::vector<int> const& vec){
    std::cout << "[";
    for(int i=0 ; i<vec.size(); i++){
        std::cout << vec[i] << ", " ;
    }
    std::cout << "]" << std::endl;
}


int main()
{
    // std::vector<int> array {generate_random_vector(10)};
    // std::vector<int> array2 {1,2,3,4,5,3,2,6,4,5};
    // display(array);


    // /* Parcours du vecteur avec l'itérateur */
    // for (std::vector<int>::iterator it { array.begin() }; it != array.end(); ++it) {
    //     std::cout << *it << std::endl;
    // }


    // int saisie {0};
    // std::cout << "Entrez la valeur que vous recherche : " << std::endl;
    // std::cin >> saisie;

    // /* Recherche de l'élément saisi dans le vecteur array */
    // auto itFind { std::find(array.begin(), array.end(), saisie) };

    // /* On compare l'itérateur avec l'itérateur sur le dernier élément du vecteur */
    // if (itFind != array.end())
    // {
    //     std::cout << "La valeur " << *itFind << " est presente dans le tableau." << std::endl;
    // }
    // else
    // {
    //     std::cout << "Element not found" << std::endl;
    // }


    // /* Nombre d'occurrence de l'élément saisie dans le vecteur array */
    // auto itCount { std::count(array2.begin(), array2.end(), saisie) };
    // std::cout << "La valeur " << saisie << " apparait " << itCount << " fois dans le vecteur." << std::endl;


    // /* Tri du vecteur array */
    // std::sort(array.begin(), array.end());

    // /* Parcours du vecteur avec l'itérateur */
    // for (int element : array)
    // {
    //     std::cout << element << std::endl;
    // }

    // /* Cumul des valeurs du vecteur */
    // int somme {std::accumulate(array.begin(), array.end(),0)};
    // std::cout << "La somme de toutes les valeurs du vecteur vaut : " << somme << std::endl;
}