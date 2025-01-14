/*!
    \file tree.cpp
    \brief Node class implementation
    \author Mathias GAGNEPAIN, Maxime Carbon
*/

#include "tree.hpp"

#include <iostream>
#include <fstream>

using namespace std;

Tree::Tree(int value)
{
    this->root = new Node(value);
}

Tree::~Tree()
{
    delete this->root;
}

Node *Tree::getRoot() const
{
    return this->root;
}

bool Tree::insert(int value)
{
    Node *node = this->root;
    while (node != NULL)
    {
        if (value < node->getValue())
        {
            if (node->getLeft() == NULL)
            {
                node->setLeft(new Node(value));
                return true;
            }
            node = node->getLeft();
        }
        else if (value > node->getValue())
        {
            if (node->getRight() == NULL)
            {
                node->setRight(new Node(value));
                return true;
            }
            node = node->getRight();
        }
        else
        {
            return false;
        }
    }
    return false;
}

Node *Tree::search(int value) const
{
    Node *node = this->root;
    while (node != NULL)
    {
        if (value < node->getValue())
        {
            node = node->getLeft();
        }
        else if (value > node->getValue())
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

Node *Tree::treeRemovePartial(Node *node, int value){
    if(node == NULL){
        return NULL;
    }
    if(value < node->getValue()){
        node->setLeft(treeRemovePartial(node->getLeft(), value));
    }else if(value > node->getValue()){
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
            node->setValue(min->getValue());
            node->setRight(treeRemovePartial(node->getRight(), min->getValue()));
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