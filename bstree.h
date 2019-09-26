#ifndef BSTREE_H
#define BSTREE_H



#include "node.h"
//#include "iterator.h"
#include <iostream>
using namespace std;
template <typename T>
class BSTree {
    Node<T> *root;
    int nodes;
private:
    int heigth(Node <T>  *it){
        if (nullptr == it)
            return 0;
        int h_left = height(it->left);
        int h_right = height(it->right);
        return max(h_left, h_right) + 1;
    }
    void inOrder(Node <T> * it){
        if (it != nullptr) {
            inOrder(it->left);
            cout<<it->data<<" ";
            inOrder(it->right);
        }
    }
    void preOrder(Node <T>* it){
        if (it != nullptr) {
            cout<<it->data<<" ";
            preOrder(it->left);
            preOrder(it->right);
        }
    }
    void postOrder(Node <T> * it){
        if (it != nullptr) {
            postOrder(it->left);
            postOrder(it->right);
            cout<<it->data<<" ";
        }
    }
    void destroy(Node <T>* it){
        if(it!= nullptr){
            destroy(it->left);
            destroy(it->right);
            delete it;
        }
    }
    Node <T>* find_node(T data){
        if(root!= nullptr) {
            auto *temp = root;
            while (true) {
                if (data < temp->data) {
                    if (temp->left != nullptr && temp->left->data == data) {
                        return temp;
                    } else {
                        temp = temp->left;
                    }
                } else {
                    if (temp->right != nullptr && temp->right->data == data) {
                        return temp;
                    } else {
                        temp = temp->right;
                    }
                }
                if (temp->right == nullptr && temp->left == nullptr)
                    return nullptr;
            }
        }
    }
    Node <T>* maximoIzquierda(Node<T>* it){
        while(it->right != nullptr){
            it = it->right;
        }
        return it;
    }
public:
    BSTree() : root{nullptr}, nodes{0} {};

    bool find(T data) {
        auto *temp = root;
        if (data == temp->data) {
            return temp;
        } else {
            while (true) {
                if (data < temp->data) {
                    if (temp->left->data == data) {
                        return true;
                    } else {
                        temp = temp->left;
                    }
                } else {
                    if( temp->right->data== data ){
                        return true;
                    }
                    else{
                        temp  = temp->right;
                    }
                }
                if( temp ->right == nullptr && temp->left == nullptr)
                    return false;
            }
        }
    }

    bool insert(T data) {
        auto* nuevo = new Node<T>(data);
        auto * temp = root;
        if(root != nullptr){
            while (true){
                if( nuevo->data <=  temp->data){
                    if(temp->left == nullptr){
                        temp->left =  nuevo;
                        nodes++;
                        return true;
                    }
                    else{
                        temp=temp->left;
                    }
                }
                else{
                    if(temp->right == nullptr){
                        temp->right = nuevo;
                        nodes++;
                        return true;
                    }
                    else{
                        temp = temp->right;
                    }
                }
            }
        }
        else{
            root = nuevo;
            nodes++;
            return true;
        }
    }

    bool remove(T data) {
        if(find(data)){
            if(nodes == 1){
                delete root;
                root = nullptr;
                return true;
            }
            else if(root->data == data){
                auto* nodo = maximoIzquierda(root->left);
                auto *padre = find_node(nodo->data);
                if(root->left != nodo){
                    if(nodo->left != nullptr) {
                     padre->right = nodo->left;
                        swap(nodo->data,root->data);
                        delete nodo;
                        nodes--;
                        return true;
                    }
                    else {
                        swap(nodo->data, root->data);
                        delete nodo;
                        padre->right = nullptr;
                        nodes--;
                        return true;
                    }
                }
                else{
                    root->left = nodo->left;
                    swap(root->data,nodo->data);
                    delete nodo;
                    nodes--;
                    return true;
                }

            }
            else{
                auto* dad = find_node(data);
                Node<T>* removed;
                bool left_right;
                if(dad-> data > data){
                    removed = dad->left;
                    left_right = true;
                }
                else{
                    removed = dad->right;
                    left_right = false;
                }
                if(removed->right == nullptr && removed->left == nullptr){
                    delete removed;
                    if(left_right){
                        dad->left = nullptr;
                    }
                    else{
                        dad->right = nullptr;
                    }
                    nodes--;
                    return true;
                } else if(removed->right == nullptr && removed->left != nullptr){
                    if(left_right){
                        dad->left = removed->left;
                        delete removed;
                        nodes--;
                        return true;
                    }
                    else {
                        dad->right = removed->left;
                        delete removed;
                        nodes--;
                        return true;
                    }
                }
                else if(removed->right != nullptr && removed->left == nullptr){
                    if(left_right){
                        dad->left = removed->right;
                        delete removed;
                        nodes--;
                        return true;
                    }
                    else {
                        dad->right = removed->right;
                        delete removed;
                        nodes--;
                        return true;
                    }
                }
                else{
                    auto* nodo = maximoIzquierda(removed->left);
                    auto* padre = find_node(nodo->data);
                    if(removed->left == nodo){
                        if(nodo->left != nullptr){
                            removed->left = nodo->left;
                            swap(nodo->data,removed->data);
                            delete nodo;
                            nodes--;
                            return true;
                        }
                        else{
                            swap(nodo->data,removed->data);
                            delete nodo;
                            removed->left == nullptr;
                            nodes--;
                            return true;
                        }
                    }
                    else if(nodo->left != nullptr){
                        padre->right = nodo->left;
                        swap(nodo->data,removed->data);
                        delete nodo;
                        nodes--;
                        return true;
                    }
                    else{
                        delete nodo;
                        padre->right = nullptr;
                        nodes--;
                        return true;
                    }

                }
            }
        }
        return false;
    }

    size_t size() {
        return nodes;
    }

    size_t height() {
        heigth(root);
    }
    void traversePreOrder() {
        preOrder(root);
    }

    void traverseInOrder() {
        inOrder(root);
    }

    void traversePostOrder() {
        postOrder(root);
    }

    Iterator<T> begin() {
            return root;
         }

    Iterator<T> end() {
             // TODO
           }

    ~BSTree() {
        destroy(root);
    }

    //iterador inOrder
};

#endif
