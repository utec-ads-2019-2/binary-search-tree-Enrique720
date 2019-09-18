#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"

template <typename T> 
class BSTree {
    Node<T> *root;

    public:
        BSTree() : root(nullptr) {};

        bool find(T data) { 
           Node *temp = root;
    if (position_id == temp->data.get_pos()) {
        return temp;
    } else {
        while (1 == 1) {
            if (position_id < temp->data.get_pos()) {
                if (temp->left->data.get_pos() == position_id) {
                    return true;
                } else {
                    temp = temp->left;
                }
            } else {
               if( temp->right->data.get_pos() == position_id ){
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
             Node* nuevo = new Node(data);
             Node* temp = root;
             if(root != nullptr){
                while ( 1 == 1 ){
                if( nuevo->data.get_pos() <  temp->data.get_pos()){
                //menor
                   if(temp->left == nullptr){
                    temp->left =  nuevo;
                    break;
                }
                else{
                    temp=temp->left;
                }
            }
            else{
                //Mayor
                if(temp->right == nullptr){
                    temp->right = nuevo;
                    break;
                }
                else{
                    temp = temp->right;
                }
            }
        }
    }
    else{
    root = nuevo;}
        }

        bool remove(T data) {
            // TODO
        }

        size_t size() {
            // TODO
        }

        size_t height() {
            // TODO
        }

        void traversePreOrder() {
            // TODO
        }

        void traverseInOrder() {
            // TODO
        }

        void traversePostOrder() {
            // TODO
        }

        Iterator<T> begin() {
            // TODO
        }

        Iterator<T> end() { 
            // TODO
        }

        ~BSTree() {
            // TODO
        }
    //Iterador inOrder
};

#endif
