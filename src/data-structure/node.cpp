/*!
    \file node.cpp
    \brief Node class implementation
    \author Mathias GAGNEPAIN, Maxime Carbon
*/

#include "node.hpp"

#include <stdlib.h>
#include <iostream>

using namespace std;

Node::Node(int value, std::string name)
{
    this->name = name;
    this->value = value;
    this->left = NULL;
    this->right = NULL;
}
int Node::getData() const{
    return this->value;
}

std::string Node::getName() const{
    return this->name;
}

bool Node::setValue(int value){
    this->value = value;
    return true;
}

bool Node::setValue(std::string name){
    this->name = name;
    return true;
}

bool Node::setValue(int value, std::string name){
    this->value = value;
    this->name = name;
    return true;
}


Node *Node::getLeft() const{
    return this->left;
}

bool Node::setLeft(Node *left){
    if(left->getData() < this->value){
        return false;
    }
    this->left = left;
    return true;
}

Node *Node::getRight() const{
    return this->right;
}

bool Node::setRight(Node *right){
    if(right->getData() > this->value){
        return false;
    }
    this->right = right;
    return true;
}

void Node::display() const
{
    cout << this->value << endl;
    cout << this->name << endl;
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