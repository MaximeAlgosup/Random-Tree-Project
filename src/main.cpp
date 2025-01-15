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

    Tree* treeRank = nullptr;
    Tree* treeVids = nullptr;
    Tree* treeViews = nullptr;
    while (true)
    {
        cout << "------------------------------------------" << endl;
        cout << "Welcome to the Actress Binary Search Tree!" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Select an option:" << endl;
        cout << "1. Print data set" << endl;
        cout << "2. Sort by rank" << endl;
        cout << "3. Sort by number of videos" << endl;
        cout << "4. Sort by number of views" << endl;
        cout << "5. Search by rank" << endl;
        cout << "6. Search by number of videos" << endl;
        cout << "7. Search by number of views" << endl;
        cout << "8. Remove by rank" << endl;
        cout << "9. Remove by number of videos" << endl;
        cout << "0. Remove by number of views" << endl;
        cout << "q. Exit" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Enter an option: ";
        cin >> option;
        cin.ignore();
        cout << "------------------------------------------" << endl;

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
                for (string line; getline(input, line);)
                {
                    size_t pos = 0;
                    size_t tokenNb = 0;
                    string token;
                    string nodeName;
                    int nodeRank;

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
                        default:
                            break;
                        }
                        line.erase(0, pos + 1);
                        ++tokenNb;
                    }

                    if (firstLine)
                    {
                        treeRank = new Tree(nodeRank, nodeName);
                        firstLine = false;
                    } else {
                        treeRank->insert(nodeRank, nodeName);
                    }
                }
                treeRank->displayInOrder(treeRank->getRoot());
                break;
            }
            case '3': {
                cout << "Actress sorted by videos: " << endl;
                
                ifstream input(DATA_SET_FILE);  // Moved inside the block
                if (!input)
                {
                    cout << "Error: file \'" << DATA_SET_FILE << "\' doesn't exist or is not accessible" << endl;
                    return 1;
                }

                bool firstLine = true;
                for (string line; getline(input, line);)
                {
                    size_t pos = 0;
                    size_t tokenNb = 0;
                    string token;
                    string nodeName;
                    int nodevideoNb;

                    while ((pos = line.find(separator)) != std::string::npos || tokenNb < 4)
                    {
                        token = line.substr(0, pos);
                        switch (tokenNb)
                        {
                        case 0:
                            nodeName = token;
                            break;
                        case 2:
                            nodevideoNb = stoi(token);
                            break;
                        default:
                            break;
                        }
                        line.erase(0, pos + 1);
                        ++tokenNb;
                    }

                    if (firstLine)
                    {
                        treeVids = new Tree(nodevideoNb, nodeName);
                        firstLine = false;
                    } else {
                        treeVids->insert(nodevideoNb, nodeName);
                    }
                }
                treeVids->displayInOrder(treeVids->getRoot());
                break;
            }
            case '4': {
                cout << "Actress sorted by views: " << endl;
                
                ifstream input(DATA_SET_FILE);  // Moved inside the block
                if (!input)
                {
                    cout << "Error: file \'" << DATA_SET_FILE << "\' doesn't exist or is not accessible" << endl;
                    return 1;
                }

                bool firstLine = true;
                for (string line; getline(input, line);)
                {
                    size_t pos = 0;
                    size_t tokenNb = 0;
                    string token;
                    string nodeName;
                    int nodeviews;

                    while ((pos = line.find(separator)) != std::string::npos || tokenNb < 4)
                    {
                        token = line.substr(0, pos);
                        switch (tokenNb)
                        {
                        case 0:
                            nodeName = token;
                            break;
                        case 3:
                            nodeviews = stoi(token.substr(0, 7)); // number are cutted beacuse we store int only
                            break;
                        default:
                            break;
                        }
                        line.erase(0, pos + 1);
                        ++tokenNb;
                    }

                    if (firstLine)
                    {
                        treeVids = new Tree(nodeviews, nodeName);
                        firstLine = false;
                    } else {
                        treeVids->insert(nodeviews, nodeName);
                    }
                }
                treeVids->displayInOrder(treeVids->getRoot());
                break;
            }
            case '5': {
                int rank;
                cout << "------------------------------------------" << endl;
                cout << "Enter a rank: ";
                cin >> rank;
                cin.ignore();
                cout << "------------------------------------------" << endl;
                if(treeRank->search(rank)!= NULL) {
                    cout << "Actress found: " << treeRank->search(rank)->getName() << endl;
                } else {
                    cout << "Actress not found" << endl;
                }
                break;
            }
            case '6': {
                int videoNb;
                cout << "------------------------------------------" << endl;
                cout << "Enter a number of video: ";
                cin >> videoNb;
                cin.ignore();
                cout << "------------------------------------------" << endl;
                if(treeVids->search(videoNb) != NULL) {
                    cout << "Actress found: " << treeVids->search(videoNb)->getName() << endl;
                } else {
                    cout << "Actress not found" << endl;
                }
                break;
            }
            case '7': {
                int viewNb;
                cout << "------------------------------------------" << endl;
                cout << "Enter a number of views: ";
                cin >> viewNb;
                cin.ignore();
                cout << "------------------------------------------" << endl;
                if (treeViews->search(viewNb)!= NULL) {
                    cout << "Actress found: " << treeViews->search(viewNb)->getName() << endl;
                } else {
                    cout << "Actress not found" << endl;
                }
                break;
            }
            case '8': {
                int rank;
                cout << "------------------------------------------" << endl;
                cout << "Enter a rank: ";
                cin >> rank;
                cin.ignore();
                cout << "------------------------------------------" << endl;
                if(treeRank->remove(rank)) {
                    cout << "Actress removed" << endl;
                } else {
                    cout << "Actress not found" << endl;
                }
                break;
            }
            case '9': {
                int videoNb;
                cout << "------------------------------------------" << endl;
                cout << "Enter a number of video: ";
                cin >> videoNb;
                cin.ignore();
                cout << "------------------------------------------" << endl;
                if(treeVids->remove(videoNb)) {
                    cout << "Actress removed" << endl;
                } else {
                    cout << "Actress not found" << endl;
                }
                break;
            }
            case '0': {
                int viewNb;
                cout << "------------------------------------------" << endl;
                cout << "Enter a number of views: ";
                cin >> viewNb;
                cin.ignore();
                cout << "------------------------------------------" << endl;
                if(treeViews->remove(viewNb)) {
                    cout << "Actress removed" << endl;
                } else {
                    cout << "Actress not found" << endl;
                }
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