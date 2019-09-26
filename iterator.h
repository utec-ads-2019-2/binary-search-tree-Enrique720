#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <stack>
#include <stdexcept>
using namespace std;
template <typename T>
class Iterator {
    private:
        Node<T> *current;
        stack <Node<T>*> nodos;
    public:
        Iterator():current{nullptr} {}

        Iterator(Node<T> *node,bool be): current{node} {
            if(!be){
                while(node){
                    nodos.push(node);
                    node=node->left;
                }
            }
            else
            {
                while(node){
                    node=node->right;
                }
            }
            this->current=node;

        }

        Iterator<T>& operator=(const Iterator<T> &other) {          
            this->current = other.current;
            return *this;
        }

        bool operator!=(Iterator<T> other) {
            return current != other.current;
        }

        Iterator<T>& operator++() {
            auto * temp=nodos.top();
            nodos.pop();
            if(temp->right){
                nodos.push(temp->right);
                while(nodos.top()->left){
                    nodos.push(nodos.top()->left);
                }
            }
            if(!nodos.empty())
                current=nodos.top();
            else
                current=nullptr;

            return *this;
        }

        /*Iterator<T>& operator--() {
            // TODO
        }*/

        T operator*() {
            if(current != nullptr){
            return current->data;}
            else{
                throw out_of_range("Passed index!");
            }
        }
};

#endif
