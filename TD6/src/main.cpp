#include <iostream>
#include "node.hpp"

int main()
{

    /*EXERCICE 1 */
    // Node root {10, nullptr, nullptr };
    // root.insert(9);
    // Node root2 {8, nullptr, nullptr};
    // root2.insert(9);
    // root2.insert(4);
    // root2.insert(6);
    // root2.insert(5);
    // root2.insert(7);
    // root2.insert(3);
    // root2.insert(2);
    // // if (root.is_leaf()==true){
    //     std::cout << "Le noeud est une feuille." << std::endl;
    // }else{
    //     std::cout << "Le noeud n'est pas une feuille." << std::endl;
    // }

    // std::cout << "La hauteur de l'arbre est : " << root2.height() << std::endl;
    // root2.display_infixe();
    // display_vector(root2.prefixe());
    // most_left(root.left);
    // remove(root2.left,4);

    /*EXERCICE 2 */
    Node* rootexo2 {create_node(5)};
    rootexo2->insert(3);
    rootexo2->insert(7);
    rootexo2->insert(2);
    rootexo2->insert(4);
    rootexo2->insert(6);
    rootexo2->insert(8);
    rootexo2->insert(1);
    rootexo2->insert(9);
    rootexo2->insert(0);

    std::cout << "valeur minimale : " << rootexo2->min() << std::endl;
    std::cout << "valeur maximale : " << rootexo2->max() << std::endl;

    std::vector<Node const*> tab {rootexo2->prefixe()};
    int somme {0};
    for(Node const* n : tab){
        somme = somme + n->value;
    }
    std::cout << "La somme des valeurs de l'arbre vaut " << somme << std::endl;

    std::cout << "La hauteur de l'arbre est " << rootexo2->height() << std::endl;
    
    return 0;
}