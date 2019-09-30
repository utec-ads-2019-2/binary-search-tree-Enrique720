#ifndef BSTREE_H
#define BSTREE_H



#include "node.h"
#include "iterator.h"
#include <iostream>
using namespace std;
template <typename T>
class BSTree {
    Node<T> *root;
    size_t nodes;
private:
    int heigth(Node<T> *it) {
        if (nullptr == it)
            return 0;
        int h_left = height(it->left);
        int h_right = height(it->right);
        return max(h_left, h_right) + 1;
    }

    void inOrder(Node<T> *it) {
        if (it != nullptr) {
            inOrder(it->left);
            cout << it->data << " ";
            inOrder(it->right);
        }
    }

    void preOrder(Node<T> *it) {
        if (it != nullptr) {
            cout << it->data << " ";
            preOrder(it->left);
            preOrder(it->right);
        }
    }

    void postOrder(Node<T> *it) {
        if (it != nullptr) {
            postOrder(it->left);
            postOrder(it->right);
            cout << it->data << " ";
        }
    }

    void destroy(Node<T> *it) {
        if (it != nullptr) {
            destroy(it->left);
            destroy(it->right);
            delete it;
        }
    }

public:
    BSTree() : root{nullptr}, nodes{0} {};

    bool find(T data) {
        // Tienes mucho código repetido entre find/insert/remove, estaría bueno sacar el código (iteraciones) repetidas
        auto *temp = root;
        if(root == nullptr){
            return false;
        }
        else if (data == temp->data) {
            return true;
        } else {
            while (true) {
                if (data < temp->data) {
                    if(temp->left == nullptr){
                        return false;
                    }
                    if (temp->left->data == data) {
                        return true;
                    } else {
                        temp = temp->left;
                    }
                } else {
                    if(temp->right == nullptr){
                        return false;
                    }
                    if (temp->right->data == data) {
                        return true;
                    } else {
                        temp = temp->right;
                    }
                }
            }
        }
    }

    bool insert(T data) {
        auto *nuevo = new Node<T>(data);
        auto *temp = root;
        if (root != nullptr) {
            while (true) {
                if (nuevo->data <= temp->data) {
                    if (temp->left == nullptr) {
                        temp->left = nuevo;
                        nodes++;
                        return true;
                    } else {
                        temp = temp->left;
                    }
                } else {
                    if (temp->right == nullptr) {
                        temp->right = nuevo;
                        nodes++;
                        return true;
                    } else {
                        temp = temp->right;
                    }
                }
            }
        } else {
            root = nuevo;
            nodes++;
            return true;
        }
    }

    bool remove(T data) {
        if (root == nullptr) {
            return false;
        }
        auto *dad = root;
        auto *removed = root;
        while (removed->data != data) {
            if (data > removed->data) {
                if (removed->right != nullptr) {
                    dad = removed;
                    removed = removed->right;
                } else
                    return false;
            } else if (data < removed->data) {
                if (removed->left != nullptr) {
                    dad = removed;
                    removed = removed->left;
                } else
                    return false;
            }
        }
        auto *it = removed;
        if (removed == root) {
            if (nodes == 1) {
                root = nullptr;
            } else if (removed->right != nullptr) {
                if (removed->left == nullptr)
                    root = removed->right;
                else {
                    dad = removed;
                    removed = removed->left;
                    while (removed->right != nullptr) {
                        dad = removed;
                        removed = removed->right;
                    }
                    it->data = removed->data;
                    if (dad->right == removed){
                        dad->right = removed->left;}
                    else{
                        dad->left = removed->left;}
                }
            } else if (removed->left){
                root = removed->left;}
            delete removed;
            nodes--;
            return true;
        }
        if (removed->left== nullptr) {
            if (removed->right == nullptr) {
                if (dad != nullptr) {
                    if (dad->right == removed)
                        dad->right = nullptr;
                    else
                        dad->left = nullptr;
                }
                delete removed;
            } else {
                if (dad->right == removed)
                    dad->right = removed->right;
                else
                    dad->left = removed->right;
                delete removed;
            }
        } else {
            if ( removed->right == nullptr) {
                if (dad->right == removed)
                    dad->right = removed->left;
                else
                    dad->left = removed->left;
                delete removed;
            } else {
                dad = removed;
                removed = removed->left;
                while (removed->right != nullptr) {
                    dad = removed;
                    removed = removed->right;
                }
                it->data = removed->data;
                if (dad->right == removed)
                    dad->right = removed->left;
                else
                    dad->left = removed->left;
                delete removed;
            }
        }
        nodes--;
        return true;

    }
    size_t size() {
        return nodes;
    }

    size_t height() {
        return heigth(root);
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
        return {root,true};
    }

    Iterator<T> end() {

        return {root,false};
    }

    ~BSTree() {
        destroy(root);
    }

};

#endif
