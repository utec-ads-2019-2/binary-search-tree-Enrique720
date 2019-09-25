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

        }
        void postOrder(Node <T> * it){
            
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
                if( nuevo->data <  temp->data){
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

        }

        size_t size() {
            return nodes;
        }

        size_t height() {
            heigth(root);
        }
    //   void traversePreOrder() {
    //       // TODO
    //   }

        void traverseInOrder() {
            inOrder(root);
        }

  //     void traversePostOrder() {
  //         // TODO
  //     }

  //     Iterator<T> begin() {
  //         // TODO
  //     }

  //     Iterator<T> end() {
  //         // TODO
  //     }

  //     ~BSTree() {
  //         // TODO
  //     }
    //Iterador inOrder
};

#endif
