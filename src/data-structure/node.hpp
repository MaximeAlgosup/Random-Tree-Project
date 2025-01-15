/*!
    \file node.hpp
    \brief Node class declaration
    \author Mathias GAGNEPAIN, Maxime Carbon
*/
#pragma once
#include <string>

class Node
{
private:
    std::string name;
    int value;
    Node *left;
    Node *right;

public:

    /*!
        \brief Constructor
        \param value The value of the node
        \param name The name of the node
    */
    Node(int value, std::string name);

    /*!
        \brief Getter for the value
        \return The value of the node
    */
    int getData() const;

    /*!
        \brief Getter for the name
        \return The name of the node
    */
    std::string getName() const;

    /*!
        \brief Setter for the value
        \param value The new value of the node
        \return True if the value has been set, false otherwise
    */
    bool setValue(int value);

    /*!
        \brief Setter for the name
        \param name The new name of the node
        \return True if the name has been set, false otherwise
    */
    bool setValue(std::string name);

    /*!
        \brief Setter for the value and the name
        \param value The new value of the node
        \param name The new name of the node
        \return True if the value and the name have been set, false otherwise
    */
    bool setValue(int value, std::string name);

    /*!
        \brief Getter for the left child
        \return The left child of the node
    */
    Node *getLeft() const;

    /*!
        \brief Setter for the left child
        \param left The new left child of the node
        \return True if the left child has been set, false otherwise
    */
    bool setLeft(Node *left);

    /*!
        \brief Getter for the right child
        \return The right child of the node
    */
    Node *getRight() const;

    /*!
        \brief Setter for the right child
        \param right The new right child of the node
        \return True if the right child has been set, false otherwise
    */
    bool setRight(Node *right);

    /*!
        \brief Display the node
    */
    void display() const;

    /*!
        \brief Destructor
    */
    ~Node();
};