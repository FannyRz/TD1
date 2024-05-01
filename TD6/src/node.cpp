#include "node.hpp"

#include <iostream>


/* Permet d'afficher une representation ACSII dans la console d'un arbre binaire */
void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left) {
    if (node.right) {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left) {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const& node) {
    pretty_print_left_right(node, "", true);
}

Node* create_node(int value){
    Node* root { new Node {value, nullptr, nullptr}};
    return root;
}

void Node::insert(int value){
    Node* nouveau {create_node(value)};
    if(value < this->value){
        if(this->left == nullptr){
            this->left = nouveau;
        }else{
            left->insert(value);
        }
    }else{
        if(this->right == nullptr){
            this->right = nouveau;
        }else{
            right->insert(value);
        }
    }
}

int Node::height() const{
    if(this->is_leaf()){
        return 1;
    }else if(left==nullptr){
        return right->height()+1;
    }else if(right==nullptr){
        return left->height()+1;
    }else{
        return std::max(left->height()+1,right->height()+1);
    }
}

void Node::delete_childs(){
    if(this->is_leaf()){
        delete this;
    }else if(left==nullptr){
        right->delete_childs();
    }else if(right==nullptr){
        left->delete_childs();
    }else{
        left->delete_childs();
        right->delete_childs();
    }
}

void Node::display_infixe() const{
    
}