/*!
    \file node.hpp
    \brief Declaration of the Node class, representing a binary tree node.
    \author Mathias GAGNEPAIN, Maxime CARBON
*/

#pragma once
#include <string>

/*!
    \class Node
    \brief A class representing a node in a binary tree.
*/
class Node
{
private:
    std::string name; /*!< The name of the node */
    int value;        /*!< The value of the node */
    Node *left;       /*!< Pointer to the left child node */
    Node *right;      /*!< Pointer to the right child node */

public:
    /*!
        \brief Constructs a Node with a given value and name.
        \param value The value of the node.
        \param name The name of the node.
    */
    Node(int value, std::string name);

    /*!
        \brief Gets the value of the node.
        \return The value of the node.
    */
    int getData() const;

    /*!
        \brief Gets the name of the node.
        \return The name of the node.
    */
    std::string getName() const;

    /*!
        \brief Sets the value of the node.
        \param value The new value of the node.
        \return True if the value is successfully set, false otherwise.
    */
    bool setValue(int value);

    /*!
        \brief Sets the name of the node.
        \param name The new name of the node.
        \return True if the name is successfully set, false otherwise.
    */
    bool setValue(std::string name);

    /*!
        \brief Sets both the value and the name of the node.
        \param value The new value of the node.
        \param name The new name of the node.
        \return True if both the value and name are successfully set, false otherwise.
    */
    bool setValue(int value, std::string name);

    /*!
        \brief Gets the left child of the node.
        \return A pointer to the left child node, or nullptr if no left child exists.
    */
    Node *getLeft() const;

    /*!
        \brief Sets the left child of the node.
        \param left A pointer to the new left child node.
        \return True if the left child is successfully set, false otherwise.
    */
    bool setLeft(Node *left);

    /*!
        \brief Gets the right child of the node.
        \return A pointer to the right child node, or nullptr if no right child exists.
    */
    Node *getRight() const;

    /*!
        \brief Sets the right child of the node.
        \param right A pointer to the new right child node.
        \return True if the right child is successfully set, false otherwise.
    */
    bool setRight(Node *right);

    /*!
        \brief Displays the node's value and name.
        \details This function prints the node's value and name to the standard output.
    */
    void display() const;

    /*!
        \brief Destructor.
        \details Cleans up any dynamically allocated resources (if applicable).
    */
    ~Node();
};
