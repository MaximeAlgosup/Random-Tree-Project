/*!
    \file node.cpp
    \brief Node class implementation
    \author Mathias GAGNEPAIN, Maxime Carbon
*/

#include "node.hpp"

#include <stdlib.h>
#include <iostream.h>

using namespace std;

Node::Node(int value)
{
    this->value = value;
    this->left = NULL;
    this->right = NULL;
}
int Node::getValue() const{
    return this->value;
}

bool Node::setValue(int value){
    this->value = value;
    return true;
}

Node *Node::getLeft() const{
    return this->left;
}

bool Node::setLeft(Node *left){
    if(left->getValue() < this->value){
        return false;
    }
    this->left = left;
    return true;
}

Node *Node::getRight() const{
    return this->right;
}

bool Node::setRight(Node *right){
    if(right->getValue() > this->value){
        return false;
    }
    this->right = right;
    return true;
}

void Node::display() const
{
    cout << this->value << endl;
    if (this->left != NULL)
    {
        cout << "Left: ";
        this->left->display();
    }
    if (this->right != NULL)
    {
        cout << "Right: ";
        this->right->display();
    }
}

Node::~Node(){
    delete this->left;
    delete this->right;
}