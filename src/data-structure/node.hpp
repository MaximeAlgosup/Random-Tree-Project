/*!
    \file node.hpp
    \brief Node class declaration
    \author Mathias GAGNEPAIN, Maxime Carbon
*/
#pragma once

class Node
{
private:
    int value;
    Node *left;
    Node *right;

public:

    /*!
        \brief Constructor
        \param value The value of the node
    */
    Node(int value);

    /*!
        \brief Getter for the value
        \return The value of the node
    */
    int getValue() const;

    /*!
        \brief Setter for the value
        \param value The new value of the node
        \return True if the value has been set, false otherwise
    */
    bool setValue(int value);

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