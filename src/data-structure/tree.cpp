/*!
    \file tree.cpp
    \brief Node class implementation
    \author Mathias GAGNEPAIN, Maxime CARBON
*/

#include "tree.hpp"

#include <iostream>
#include <fstream>

using namespace std;

Tree::Tree(int value, string name)
{
    this->root = new Node(value, name);
}

Tree::~Tree()
{
    delete this->root;
}

Node *Tree::getRoot() const
{
    return this->root;
}

bool Tree::treeInsertPartial(Node *node, int value, std::string name){

    if(value < node->getData()){
        if(node->getLeft() == NULL){
            node->setLeft(new Node(value, name));
            return true;
        }
        return treeInsertPartial(node->getLeft(), value, name);
    }else if(value > node->getData()){
        if(node->getRight() == NULL){
            node->setRight(new Node(value, name));
            return true;
        }
        return treeInsertPartial(node->getRight(), value, name);
    }else{
        return false;
    }
}


bool Tree::insert(int value, string name)
{
    Node *node = this->root;
    if(node == NULL){
        this->root = new Node(value, name);
        return true;
    }
    return treeInsertPartial(node, value, name);
}


Node *Tree::search(int value) const
{
    Node *node = this->root;
    while (node != NULL)
    {
        if (value < node->getData())
        {
            node = node->getLeft();
        }
        else if (value > node->getData())
        {
            node = node->getRight();
        }
        else
        {
            return node;
        }
    }
    return NULL;
}

Node **Tree::searchAll(int value) const {
    Node **nodes = new Node*[100];
    Node *node = this->root;
    int i = 0;
    while(node != NULL){
        if(value < node->getData()){
            node = node->getLeft();
        }else if(value > node->getData()){
            node = node->getRight();
        }else{
            nodes[i] = node;
            i++;
            node = node->getRight();
        }
    }
    return nodes;
}

Node *Tree::treeRemovePartial(Node *node, int value){
    if(node == NULL){
        return NULL;
    }
    if(value < node->getData()){
        node->setLeft(treeRemovePartial(node->getLeft(), value));
    }else if(value > node->getData()){
        node->setRight(treeRemovePartial(node->getRight(), value));
    }else{
        if(node->getLeft() == NULL){
            Node *right = node->getRight();
            delete node;
            return right;
        }else if(node->getRight() == NULL){
            Node *left = node->getLeft();
            delete node;
            return left;
        }else{
            Node *min = node->getRight();
            while(min->getLeft() != NULL){
                min = min->getLeft();
            }
            node->setValue(min->getData());
            node->setRight(treeRemovePartial(node->getRight(), min->getData()));
        }
    }
    return node;
}

bool Tree::remove(int value)
{
    if(this->search(value) == NULL){
        return false;
    }
    Node *node = this->root;
    this->root = treeRemovePartial(node, value);
    return true;
}

bool Tree::removeAll(int value)
{
    if(this->search(value) == NULL){
        return false;
    }
    Node *node = this->root;
    while(node != NULL){
        if(node->getData() == value){
            this->root = treeRemovePartial(node, value);
        }
        if(value < node->getData()){
            node = node->getLeft();
        }else if(value > node->getData()){
            node = node->getRight();
        }
    }
    return true;
}

void Tree::display() const
{
    this->root->display();
}

void Tree::display(const char *filename) const {
    ofstream file;
    file.open(filename);
    if(file.is_open()){
        this->root->display();
        file.close();
    }
}

void Tree::displayInOrder(Node *node) const
{
    if (node != NULL)
    {
        displayInOrder(node->getLeft());
        cout << node->getData() << ", " << node->getName() << endl;
        displayInOrder(node->getRight());
    }
}