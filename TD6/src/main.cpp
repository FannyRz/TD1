#include <iostream>
#include "node.hpp"

int main()
{
    Node root {10, nullptr, nullptr };
    root.insert(9);
    Node root2 {8, nullptr, nullptr};
    root2.insert(9);
    root2.insert(4);
    root2.insert(6);
    root2.insert(5);
    root2.insert(7);
    root2.insert(3);
    root2.insert(2);
    // if (root.is_leaf()==true){
    //     std::cout << "Le noeud est une feuille." << std::endl;
    // }else{
    //     std::cout << "Le noeud n'est pas une feuille." << std::endl;
    // }

    // std::cout << "La hauteur de l'arbre est : " << root2.height() << std::endl;
    // root2.display_infixe();
    // display_vector(root2.prefixe());
    // most_left(root.left);
    // remove(root2.left,4);

    return 0;
}