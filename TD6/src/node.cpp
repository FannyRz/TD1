#include "node.hpp"

#include <iostream>
#include <vector>


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
            this->left->insert(value);
        }
    }else{
        if(this->right == nullptr){
            this->right = nouveau;
        }else{
            this->right->insert(value);
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
    if(this->is_leaf() && !(this->is_root)){  //il ne faut pas que ce soit notre racine
        delete this;
    }else if(left==nullptr){
        right->delete_childs();
        right = nullptr;
    }else if(right==nullptr){
        left->delete_childs();
        left = nullptr;
    }else{
        left->delete_childs();
        right->delete_childs();
        left = nullptr;
        right = nullptr;
    }
}

void Node::display_infixe() const{
    if(this->is_leaf()){
        std::cout << this->value << " " ;
    }else if(left==nullptr){
        std::cout << this->value << " " ;
        this->right->display_infixe();
    }else if(right==nullptr){
        this->left->display_infixe();
        std::cout << this->value << " " ;
    }else{
        this->left->display_infixe();
        std::cout << this->value << " " ;
        this->right->display_infixe();
    }
}

std::vector<Node const*> Node::prefixe() const{
    std::vector<Node const*> res {};
    if(this->is_leaf()){
        res.push_back(this);
    }else if(left==nullptr){
        auto right_res {right->prefixe()};
        res.push_back(this);
        res.insert(res.end(), right_res.begin(), right_res.end());
    }else if(right==nullptr){
        auto left_res {left->prefixe()};
        res.insert(res.end(), left_res.begin(), left_res.end());
        res.push_back(this);
    }else{
        auto left_res {left->prefixe()};
        auto right_res {right->prefixe()};
        res.insert(res.end(), left_res.begin(), left_res.end());
        res.push_back(this);
        res.insert(res.end(), right_res.begin(), right_res.end());
    }
    return res;
}

void display_vector(std::vector<Node const*> tab){
    std::cout << "[";
    for(Node const* nodes : tab){
        std::cout << nodes->value << ",";
    }
    std::cout << "]" << std::endl;
    std::cout << std::endl;
}

Node*& most_left(Node*& node){
    if(node->is_leaf() || node->left==nullptr){
        std::cout << node->value << std::endl;
        return node;
    }else{
        while(!(node->is_leaf())){
            node = node->left;
        }
        std::cout << node->value << std::endl;
        return node;
    }
}

bool remove(Node*& node, int value){

    if(node->value > value){
        return remove(node->left,value);
    } else if(node->value < value){
        return remove(node->right,value);
    } else if (value == node->value && node->is_leaf()) {
        delete node;
        node = nullptr;
        return true;
    } else if(value == node->value && node->left == nullptr){
        Node* tmp = node->right;
        delete node;
        node = tmp;
        return true;
    } else if(value == node->value && node->right == nullptr){
        Node* tmp = node->left;
        delete node;
        node = tmp;
        return true;
    } else if(value == node->value){
        Node* tmp {};
        tmp = most_left(node->right);
        node->value = tmp->value;
        return remove(node->right,node->value);
    } else {
        std::cout << "PB : remove impossible" << std::endl;
        return false;
    }

}

void delete_tree(Node* node){
    node->delete_childs();
    delete node;
    node = nullptr;
}

