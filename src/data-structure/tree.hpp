/*!
    \file tree.hpp
    \brief Tree class declaration and functionality for binary tree operations.
    \author Mathias GAGNEPAIN, Maxime CARBON
*/

#pragma once

#include "node.hpp"
#include <string>

/*!
    \class Tree
    \brief A class representing a binary tree structure.
*/
class Tree
{
private:
    Node *root; /*!< Pointer to the root node of the tree. */

    /*!
        \brief Removes a node from the tree recursively.
        \param node Pointer to the current root of the subtree.
        \param value The value of the node to remove.
        \return A pointer to the new root of the subtree after removal.
    */
    Node *treeRemovePartial(Node *node, int value);

public:
    /*!
        \brief Constructor to initialize the tree with a root node.
        \param value The value of the root node.
        \param name The name of the root node.
    */
    Tree(int value, std::string name);

    /*!
        \brief Destructor to clean up tree resources.
    */
    ~Tree();

    /*!
        \brief Gets the root node of the tree.
        \return A pointer to the root node.
    */
    Node *getRoot() const;

    /*!
        \brief Inserts a new node into the tree.
        \param value The value of the new node.
        \param name The name of the new node.
        \return True if the node is successfully inserted, false otherwise.
    */
    bool insert(int value, std::string name);

    /*!
        \brief Searches for a node in the tree by its value.
        \param value The value of the node to search for.
        \return A pointer to the node if found, or nullptr if not found.
    */
    Node *search(int value) const;

    /*!
        \brief Removes a node from the tree.
        \param value The value of the node to remove.
        \return True if the node is successfully removed, false otherwise.
    */
    bool remove(int value);

    /*!
        \brief Displays the tree structure to the console.
    */
    void display() const;

    /*!
        \brief Exports the tree structure to a file for visualization.
        \param filename The name of the output file.
    */
    void display(const char *filename) const;
};
