/*!
    \file main.cpp
    \brief Main file
    \author Mathias GAGNEPAIN, Maxime CARBON
*/

#include <iostream>
#include <string>
#include <fstream>
#include "data-structure/tree.hpp"

using namespace std;

#define DATA_SET_FILE "../formatted-data/actressDataSet.csv"

int main()
{
    char option;

    while (true)
    {
        cout << "Welcome to the Actress Binary Search Tree!" << endl;
        cout << "Select an option:" << endl;
        cout << "1. Print data set" << endl;
        cout << "2. Sort by rank" << endl;
        cout << "3. Sort by number of videos" << endl;
        cout << "4. Sort by number of views" << endl;
        cout << "5. Search by rank" << endl;
        cout << "6. Search by number of videos" << endl;
        cout << "7. Search by number of views" << endl;
        cout << "8. Remove by name" << endl;
        cout << "9. Remove by rank" << endl;
        cout << "q. Exit" << endl;
        cout << "Enter an option: ";
        cin >> option;
        cin.ignore();

        string row;
        ifstream input(DATA_SET_FILE);
        string separator = ",";
        switch (option)
        {
            case '1': {
                cout << "List Actress: " << endl;
                
                ifstream input(DATA_SET_FILE);  // Moved inside the block
                if (!input)
                {
                    cout << "Error: file \'" << DATA_SET_FILE << "\' doesn't exist or is not accessible" << endl;
                    return 1;
                }

                for (string line; getline(input, line);)
                {
                    cout << line << endl;
                }
                cout << endl;
                break;
            }
            case '2': {
                cout << "Actress sorted by rank: " << endl;
                
                ifstream input(DATA_SET_FILE);  // Moved inside the block
                if (!input)
                {
                    cout << "Error: file \'" << DATA_SET_FILE << "\' doesn't exist or is not accessible" << endl;
                    return 1;
                }

                bool firstLine = true;
                Tree* tree = nullptr;
                for (string line; getline(input, line);)
                {
                    size_t pos = 0;
                    size_t tokenNb = 0;
                    string token;
                    string nodeName;
                    int nodeRank;
                    int nodevideoNb;
                    unsigned long nodeviews;

                    while ((pos = line.find(separator)) != std::string::npos || tokenNb < 4)
                    {
                        token = line.substr(0, pos);
                        switch (tokenNb)
                        {
                        case 0:
                            nodeName = token;
                            break;
                        case 1:
                            nodeRank = stoi(token);
                            break;
                        case 2:
                            nodevideoNb = stoi(token);
                            break;
                        case 3:
                            nodeviews = stoul(token);
                            break;
                        default:
                            break;
                        }
                        line.erase(0, pos + 1);
                        ++tokenNb;
                    }

                    if (firstLine)
                    {
                        tree = new Tree(nodeRank, nodeName);
                        firstLine = false;
                    } else {
                        tree->insert(nodeRank, nodeName);
                    }
                }
                tree->display();
                delete tree;
                break;
            }
            case 'q': {
                cout << "Goodbye!" << endl;
                return 0;
            }
        }

    }
    return 0;
}