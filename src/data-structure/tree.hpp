/*!
    \file tree.hpp
    \brief Node class declaration
    \author Mathias GAGNEPAIN, Maxime Carbon
*/

#pragma once

#include "node.hpp"

class Tree
{
private:
    Node *root;

    /*!
        \brief Remove a node from the tree
        \param node The root of the tree
        \param value The value of the node to remove
        \return The new root of the tree
    */
    Node *treeRemovePartial(Node *node, int value);

public:

    /*!
        \brief Constructor
        \param value The value of the root node
    */
    Tree(int value);

    /*!
        \brief Destructor
    */
    ~Tree();

    /*!
        \brief Getter for the root
        \return The root of the tree
    */
    Node *getRoot() const;

    /*!
        \brief Insert a new node in the tree
        \param value The value of the new node
        \return True if the node has been inserted, false otherwise
    */
    bool insert(int value);

    /*!
        \brief Search a node in the tree
        \param value The value of the node to search
        \return The node if it has been found, nullptr otherwise
    */
    Node *search(int value) const;

    /*!
        \brief Remove a node from the tree
        \param value The value of the node to remove
        \return True if the node has been removed, false otherwise
    */
    bool remove(int value);

    /*!
        \brief Display the tree
    */
    void display() const;

    /*!
        \brief Display the tree in a file
        \param filename The name of the file
    */
    void display(const char *filename) const;

    /*!
        \brief Destructor
    */
    ~Tree();
};