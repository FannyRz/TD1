#include <iostream>
#include "node.hpp"

int main()
{
    Node root {10, nullptr, nullptr };
    Node root2 {10, nullptr, nullptr};
    root2.insert(5);
    root2.insert(4);
    root2.insert(15);
    root2.insert(11);
    root2.insert(1);
    root.insert(5);
    // if (root.is_leaf()==true){
    //     std::cout << "Le noeud est une feuille." << std::endl;
    // }else{
    //     std::cout << "Le noeud n'est pas une feuille." << std::endl;
    // }

    // std::cout << "La hauteur de l'arbre est : " << root2.height() << std::endl;
    // root2.display_infixe();
    // display_vector(root2.prefixe());
    // most_left(root.left);


    return 0;
}