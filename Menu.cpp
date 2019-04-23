#include "Menu.h"
#include "Actor.h"
#include "Picture.h"
#include "BSTree.hpp"
#include <iostream>
#include <fstream>

using namespace std;

void addActor(list<Actor> &holderList)  //Asks user for multiple inputs, and then adds the resulting Actor to the linked list
{
    Actor newActor;
    string inputStr;
    int inputInt;
    cout << "Please enter a few details on the actor/actress you wish to add:\n";
    cout << "Name: ";
    cin.ignore();
    getline(cin, inputStr);
    newActor.setName(inputStr);
    cout << "\n" << "Award:";
    getline(cin, inputStr);
    newActor.setAward(inputStr);
    cout << "\n" << "Did they win? 1 for yes, 0 for no.\n";
    cin >> inputInt;
    newActor.setWinner(inputInt);
    cout << "What year were they nominated?\n";
    cin >> inputInt;
    newActor.setYear(inputInt);
    cout << "What film were they nominated for?\n";
    cin.ignore();
    getline(cin, inputStr);
    newActor.setFilm(inputStr);

    holderList.push_front(newActor);

    cout << "Thank you, the actor/actress has been added to the database.\n";
}

void addFilm(list<Picture> &filmList) //Asks the user for multiple inputs, then adds the resulting Picture to the linked list
{
    Picture newFilm;
    string inputStr;
    int inputInt;
    double inputDbl;

    cout << "Please enter some information on the film to be added.\n";
    cout << "What is the title?\n";
    cin.ignore();
    getline(cin, inputStr);
    newFilm.setName(inputStr);

    cout << "What year did it come out?\n";
    cin >> inputInt;
    newFilm.setYear(inputInt);

    cout << "How many nominations did it receive?\n";
    cin >> inputInt;
    newFilm.setNominations(inputInt);

    cout << "What is its average rating?\n";
    cin >> inputDbl;
    newFilm.setRating(inputDbl);

    cout << "What is its runtime?\n";
    cin >> inputInt;
    newFilm.setDuration(inputInt);

    cout << "What genre is it mainly considered?\n";
    cin.ignore();
    getline(cin, inputStr);
    newFilm.setGenre1(inputStr);

    cout << "What is another genre that it could be considered?\n";
    getline(cin, inputStr);
    newFilm.setGenre2(inputStr);

    cout << "What month was it released in?\n";
    getline(cin, inputStr);
    newFilm.setRelease(inputStr);

    cout << "What is its Metacritic score?\n";
    cin >> inputInt;
    newFilm.setMetacritic(inputInt);

    cout << "Write a brief synopsis of the movie.\n";
    cin.ignore();
    getline(cin, inputStr);
    newFilm.setSynopsis(inputStr);

    filmList.push_front(newFilm);

    cout << "Thank you, your film has been added to the database.\n";
}

void sortActorByName(BSTree<Actor, string> &inputDB, list<Actor> holderList)    //iterates through the master list, adding each Actor to the BST that is sorted by names
{
    list<Actor>::iterator fillCheck = holderList.begin();

    while (fillCheck != holderList.end())
    {
        inputDB.addNode(fillCheck -> getName(), *fillCheck);
        fillCheck++;
    }
}

void sortActorByYear(BSTree<Actor, int> &inputDB, list<Actor> holderList)   //iterates through the master list, adding each Actor to the BST that is sorted by years
{
    list<Actor>::iterator fillCheck = holderList.begin();

    while (fillCheck != holderList.end())
    {
        inputDB.addNode(fillCheck->getYear(), *fillCheck);
        fillCheck++;
    }

}

void sortActorByFilm(BSTree<Actor, string> &inputDB, list<Actor> holderList)    //iterates through the master list, adding each Actor to the BST that is sorted by films
{
    list<Actor>::iterator fillCheck = holderList.begin();

    while (fillCheck != holderList.end())
    {
        inputDB.addNode(fillCheck -> getFilm(), *fillCheck);
        fillCheck++;
    }
}

void sortFilmByName(BSTree<Picture, string> &inputDB, list<Picture> &inputList)
{
    list<Picture>::iterator fillCheck = inputList.begin();

    while (fillCheck != inputList.end())
    {
        inputDB.addNode(fillCheck -> getName(), *fillCheck);
        fillCheck++;
    }
}

void sortFilmByYear(BSTree<Picture, int> &inputDB, list<Picture> &inputList)
{
    list<Picture>::iterator fillCheck = inputList.begin();

    while (fillCheck != inputList.end())
    {
        inputDB.addNode(fillCheck -> getYear(), *fillCheck);
        fillCheck++;
    }
}

void sortFilmByRating(BSTree<Picture, double> &inputDB, list<Picture> &inputList)
{
    list<Picture>::iterator fillCheck = inputList.begin();

    while (fillCheck != inputList.end())
    {
        inputDB.addNode(fillCheck -> getRating(), *fillCheck);
        fillCheck++;
    }
}

void sortFilmByDuration(BSTree<Picture, int> &inputDB, list<Picture> &inputList)
{
    list<Picture>::iterator fillCheck = inputList.begin();

    while (fillCheck != inputList.end())
    {
        inputDB.addNode(fillCheck -> getDuration(), *fillCheck);
        fillCheck++;
    }
}

void sortFilmByGenre1(BSTree<Picture, string> &inputDB, list<Picture> &inputList)
{
    list<Picture>::iterator fillCheck = inputList.begin();

    while (fillCheck != inputList.end())
    {
        inputDB.addNode(fillCheck -> getGenre1(), *fillCheck);
        fillCheck++;
    }
}

void sortFilmByGenre2(BSTree<Picture, string> &inputDB, list<Picture> &inputList)
{
    list<Picture>::iterator fillCheck = inputList.begin();

    while (fillCheck != inputList.end())
    {
        inputDB.addNode(fillCheck -> getGenre2(), *fillCheck);
        fillCheck++;
    }
}

void sortFilmByRelease(BSTree<Picture, string> &inputDB, list<Picture> &inputList)
{
    list<Picture>::iterator fillCheck = inputList.begin();

    while (fillCheck != inputList.end())
    {
        inputDB.addNode(fillCheck -> getRelease(), *fillCheck);
        fillCheck++;
    }
}

void sortFilmByMetacritic(BSTree<Picture, int> &inputDB, list<Picture> &inputList)
{
    list<Picture>::iterator fillCheck = inputList.begin();

    while (fillCheck != inputList.end())
    {
        inputDB.addNode(fillCheck -> getMetacritic(), *fillCheck);
        fillCheck++;
    }
}

void completeSearchActor(list<Actor> &inputList)        //Performs an exact search of the database using BSTs
{
    list<Actor>::iterator currentChecked = inputList.begin();
    bool selected = false;
    bool again = true;
    bool removed = false;
    int field, repeat, modifyOrDelete, newYear, winLose;
    string newName, newFilm, newAward;

    //Loops through this menu until user selects a valid option
    while(!selected) {
        cout << "Which field do you want to search by?\n";
        cout << "1. Name\n";
        cout << "2. Film\n";
        cout << "3. Year\n";

        cin >> field;

        switch (field) {
            case 1:{
                again = true;
                BSTree<Actor, string> searchTree;       //Tree to be used in search to reduce complexity
                sortActorByName(searchTree, inputList); //Fills the BST using the actor list
                string nameToFind;

                cout << "What name are you looking for?\n";
                cin.ignore();
                getline(cin, nameToFind);

                Node<Actor, string> * searchResult;     //Pointer to node containing the result of the search
                searchResult = searchTree.findNode(nameToFind);     //Searches for the appropriate node

                if(searchResult == nullptr)     //If the search reaches a leaf without finding the desired Actor
                {
                    cout << nameToFind << " not found in the database.\n";
                }

                else        //If node is found
                {
                    cout << nameToFind << " found.\n";
                    searchResult -> Data().print();     //Prints the actor

                    bool chooseModOrDel = true;

                    //Asks the user if they want to modify/delete the record
                    while (chooseModOrDel) {
                        cout << "What would you like to do with the record?\n";
                        cout << "1. Modify the record\n";
                        cout << "2. Delete the record\n";
                        cout << "3. Nothing\n";

                        cin >> modifyOrDelete;

                        switch (modifyOrDelete) {
                            case 1: {
                                list<Actor>::iterator toRemove = inputList.begin();
                                while(!removed) //Iterates through the master list
                                {
                                    if(toRemove -> getName() == nameToFind)     //Removes the desired node
                                    {
                                        inputList.erase(toRemove);
                                        removed = true;
                                    }
                                    toRemove++;     //Increments the iterator
                                }

                                addActor(inputList);        //Adds a new actor to the list, representing the "new" data for the record

                                chooseModOrDel = false;

                                break;
                            }

                            //Just deletes the node
                            case 2:{
                                searchTree.deleteNode(nameToFind);

                                list<Actor>::iterator toRemove = inputList.begin();
                                while(!removed)
                                {
                                    if(toRemove -> getName() == nameToFind)
                                    {
                                        inputList.erase(toRemove);
                                        removed = true;
                                    }
                                    toRemove++;
                                }

                                chooseModOrDel = false;

                                break;
                            }

                            case 3:{
                                chooseModOrDel = false;
                                break;
                            }

                            default:{
                                cout << "Unrecognized input.\n";
                                break;
                            }
                        }
                    }
                }


                //Allows the user to repeat search if desired
                while (again) {
                    cout << "Do you want to search again?\n";
                    cout << "1. Yes\n";
                    cout << "2. No\n";

                    cin >> repeat;

                    switch (repeat) {
                        case 1: {
                            again = false;
                            break;
                        }

                        case 2: {
                            selected = true;
                            again = false;
                            break;
                        }
                        default:{
                            cout << "Unrecognized input, try again.\n";
                            break;
                        }
                    }
                }
                break;
            }

            //Similar to case 1, but looking for featured films instead of name of actor
            case 2:{
                again = true;
                BSTree<Actor, string> searchTree;
                string filmToFind;
                sortActorByFilm(searchTree, inputList);

                cout << "What film are you looking for?\n";
                getline(cin, filmToFind);

                Node<Actor, string> * searchResult;
                searchResult = searchTree.findNode(filmToFind);

                if(searchResult == nullptr)
                {
                    cout << filmToFind << " not found in the database.\n";
                }

                else
                {
                    cout << filmToFind << " found.\n";
                    searchResult -> Data().print();

                    bool chooseModOrDel = true;

                    while (chooseModOrDel) {
                        cout << "What would you like to do with the record?\n";
                        cout << "1. Modify the record\n";
                        cout << "2. Delete the record\n";
                        cout << "3. Nothing\n";

                        cin >> modifyOrDelete;

                        switch (modifyOrDelete) {
                            case 1: {
                                searchTree.deleteNode(filmToFind);

                                list<Actor>::iterator toRemove = inputList.begin();
                                while(!removed)
                                {
                                    if(toRemove -> getFilm() == filmToFind)
                                    {
                                        inputList.erase(toRemove);
                                        removed = true;
                                    }
                                    toRemove++;
                                }

                                addActor(inputList);

                                chooseModOrDel = false;

                                break;
                            }

                            case 2:{
                                searchTree.deleteNode(filmToFind);

                                list<Actor>::iterator toRemove = inputList.begin();
                                while(!removed)
                                {
                                    if(toRemove -> getFilm() == filmToFind)
                                    {
                                        inputList.erase(toRemove);
                                        removed = true;
                                    }
                                    toRemove++;
                                }

                                chooseModOrDel = false;

                                break;
                            }

                            case 3:{
                                chooseModOrDel = false;
                                break;
                            }

                            default:{
                                cout << "Unrecognized input.\n";
                                break;
                            }
                        }
                    }
                }

                while (again) {
                    cout << "Do you want to search again?\n";
                    cout << "1. Yes\n";
                    cout << "2. No\n";

                    cin >> repeat;

                    switch (repeat) {
                        case 1: {
                            again = false;
                            break;
                        }

                        case 2: {
                            selected = true;
                            again = false;
                            break;
                        }
                        default:{
                            cout << "Unrecognized input, try again.\n";
                            break;
                        }
                    }
                }
                break;
            }

            //Similar to other cases, but searching for year nominated instead of name of actor
            case 3:{
                again = true;
                BSTree<Actor, int> searchTree;
                int yearToFind;
                sortActorByYear(searchTree, inputList);

                cout << "What year are you looking for?\n";
                cin >> yearToFind;

                Node<Actor, int> * searchResult;
                searchResult = searchTree.findNode(yearToFind);

                if(searchResult == nullptr)
                {
                    cout << yearToFind << " not found in the database.\n";
                }

                else
                {
                    cout << yearToFind << " found.\n";
                    searchResult -> Data().print();

                    bool chooseModOrDel = true;

                    while (chooseModOrDel) {
                        cout << "What would you like to do with the record?\n";
                        cout << "1. Modify the record\n";
                        cout << "2. Delete the record\n";
                        cout << "3. Nothing\n";

                        cin >> modifyOrDelete;

                        switch (modifyOrDelete) {
                            case 1: {
                                searchTree.deleteNode(yearToFind);

                                list<Actor>::iterator toRemove = inputList.begin();
                                while(!removed)
                                {
                                    if(toRemove -> getYear() == yearToFind)
                                    {
                                        inputList.erase(toRemove);
                                        removed = true;
                                    }
                                    toRemove++;
                                }
                                cin.ignore();
                                addActor(inputList);
                                chooseModOrDel = false;

                                break;
                            }

                            case 2:{
                                searchTree.deleteNode(yearToFind);

                                list<Actor>::iterator toRemove = inputList.begin();
                                while(!removed)
                                {
                                    if(toRemove -> getYear() == yearToFind)
                                    {
                                        inputList.erase(toRemove);
                                        removed = true;
                                    }
                                    toRemove++;
                                }

                                chooseModOrDel = false;

                                break;
                            }

                            case 3:{
                                chooseModOrDel = false;
                                break;
                            }

                            default:{
                                cout << "Unrecognized input.\n";
                                break;
                            }
                        }
                    }
                }

                while (again) {
                    cout << "Do you want to search again?\n";
                    cout << "1. Yes\n";
                    cout << "2. No\n";

                    cin >> repeat;

                    switch (repeat) {
                        case 1: {
                            again = false;
                            break;
                        }

                        case 2: {
                            selected = true;
                            again = false;
                            break;
                        }
                        default:{
                            cout << "Unrecognized input, try again.\n";
                            break;
                        }
                    }
                }
                break;
            }

            default:{
                cout << "Unrecognized input.\n";
                break;
            }
        }
    }

}

void partialSearchActor(list<Actor> &inputList)     //Performs a partial search. Only allows on Names and Films, as others don't seem logical
{
    list<Actor>::iterator partialChecked = inputList.begin();
    bool selected = false;
    bool again = true;
    bool chooseModOrDel = true;
    int field, repeat, modifyOrDelete;
    string nameToFind, filmToFind;

    //Loops until a valid option is chosen, AND user no longer wants to search
    while(!selected) {
        cout << "Which field do you want to search by?\n";
        cout << "1. Name\n";
        cout << "2. Film\n";

        cin >> field;

        switch (field) {
            case 1: {
                cout << "What name are you looking for?\n";
                cin.ignore();
                getline(cin, nameToFind);

                while(partialChecked != inputList.end())
                {
                    if (partialChecked -> getName().find(nameToFind) != string::npos) //exits search loop if the substring is found
                    {
                        break;
                    }

                    partialChecked++;
                }

                if (partialChecked -> getName().find(nameToFind) == string::npos) //If not found
                {
                    cout << "No results found.\n";
                }

                else
                {
                    cout << "Result found.\n";
                    partialChecked -> print();      //Prints found actor

                    //Asks if they want to modify or delete record
                    while(chooseModOrDel)
                    {
                        cout << "What do you want to do with this record?\n";
                        cout << "1. Modify record\n";
                        cout << "2. Delete record\n";
                        cout << "3. Nothing\n";

                        cin >> modifyOrDelete;

                        switch (modifyOrDelete) {
                            case 1: {
                                inputList.erase(partialChecked); //Removes old node, and adds a new node to represent modifying the old one
                                addActor(inputList);

                                chooseModOrDel = false;
                                break;
                            }

                            case 2:{
                                inputList.erase(partialChecked);    //Just deletes the record

                                chooseModOrDel = false;
                                break;
                            }

                            case 3:{
                                chooseModOrDel = false;
                                break;
                            }

                            default:{
                                cout << "Unrecognized input.\n";
                                break;
                            }
                        }
                    }
                }

                //Allows repeat searches
                while (again) {
                    cout << "Do you want to search again?\n";
                    cout << "1. Yes\n";
                    cout << "2. No\n";

                    cin >> repeat;

                    switch (repeat) {
                        case 1: {
                            again = false;
                            break;
                        }

                        case 2: {
                            selected = true;
                            again = false;
                            break;
                        }
                        default:{
                            cout << "Unrecognized input, try again.\n";
                            break;
                        }
                    }
                }
                break;
            }

            //Same as case 1, but for films
            case 2:{
                cout << "What film are you looking for?\n";
                cin.ignore();
                getline(cin, filmToFind);

                while(partialChecked != inputList.end())
                {
                    if (partialChecked -> getName().find(filmToFind) != string::npos)
                    {
                        break;
                    }

                    partialChecked++;
                }

                if (partialChecked -> getName().find(filmToFind) == string::npos)
                {
                    cout << "No results found.\n";
                }

                else
                {
                    cout << "Result found.\n";
                    partialChecked -> print();

                    while(chooseModOrDel)
                    {
                        cout << "What do you want to do with this record?\n";
                        cout << "1. Modify record\n";
                        cout << "2. Delete record\n";
                        cout << "3. Nothing\n";

                        cin >> modifyOrDelete;

                        switch (modifyOrDelete) {
                            case 1: {
                                inputList.erase(partialChecked);
                                addActor(inputList);

                                chooseModOrDel = false;
                                break;
                            }

                            case 2:{
                                inputList.erase(partialChecked);

                                chooseModOrDel = false;
                                break;
                            }

                            case 3:{
                                chooseModOrDel = false;
                                break;
                            }

                            default:{
                                cout << "Unrecognized input.\n";
                                break;
                            }
                        }
                    }
                }

                while (again) {
                    cout << "Do you want to search again?\n";
                    cout << "1. Yes\n";
                    cout << "2. No\n";

                    cin >> repeat;

                    switch (repeat) {
                        case 1: {
                            again = false;
                            break;
                        }

                        case 2: {
                            selected = true;
                            again = false;
                            break;
                        }
                        default:{
                            cout << "Unrecognized input, try again.\n";
                            break;
                        }
                    }
                }
                break;
            }

            default:{
                cout << "Unrecognized input.\n";
                break;
            }
        }
    }
}

void completeSearchFilm(list<Picture> &inputList)
{
    list<Picture>::iterator currentChecked = inputList.begin();
    bool selected = false;
    bool again = true;
    bool removed = false;
    int field, repeat, modifyOrDelete;
    string newName, newFilm, newAward;

    //Loops until user is finished
    while(!selected)
    {
        cout << "What field do you want to search by?\n";
        cout << "1. Name\n";
        cout << "2. Year\n";
        cout << "3. Rating\n";
        cout << "4. Duration\n";
        cout << "5. Primary genre\n";
        cout << "6. Secondary Genre\n";
        cout << "7. Release month\n";
        cout << "8. Metacritic score\n";
        cout << "9. Return to previous menu\n";

        cin >> field;

        switch (field)
        {
            case 1:{
                BSTree<Picture, string> searchTree;
                sortFilmByName(searchTree, inputList);
                string filmToFind;

                cout << "Which film are you looking for?\n";
                cin.ignore();
                getline(cin, filmToFind);

                Node<Picture, string> *searchResult;        //Node to store the result of the search
                searchResult = searchTree.findNode(filmToFind);     //Searches the tree for the desired record

                if (searchResult == nullptr)        //If desired record doesn't exist
                {
                    cout << filmToFind << " not found in the database.\n";
                }

                else        //Otherwise if record is found
                {
                    cout << filmToFind << " found\n";
                    searchResult -> Data().print();     //Prints the found record

                    bool chooseModOrDel = true;

                    while(chooseModOrDel)       //User chooses to modify or delete the record
                    {
                        cout << "What do you want to do with the record?\n";
                        cout << "1. Modify\n";
                        cout << "2. Delete\n";
                        cout << "3. Nothing\n";

                        cin >> modifyOrDelete;

                        switch (modifyOrDelete)
                        {
                            case 1:{
                                list<Picture>::iterator toRemove = inputList.begin();
                                while(!removed) //Iterates through the master list
                                {
                                    if(toRemove -> getName() == filmToFind)     //Removes the desired node
                                    {
                                        inputList.erase(toRemove);
                                        removed = true;
                                    }
                                    toRemove++;     //Increments the iterator
                                }

                                addFilm(inputList);        //Adds a new film to the list, representing the "new" data for the record

                                chooseModOrDel = false;
                                break;
                            }

                            case 2:{
                                list<Picture>::iterator toRemove = inputList.begin();
                                while(!removed) //Iterates through the master list
                                {
                                    if(toRemove -> getName() == filmToFind)     //Removes the desired node
                                    {
                                        inputList.erase(toRemove);
                                        removed = true;
                                    }
                                    toRemove++;     //Increments the iterator
                                }

                                chooseModOrDel = false;
                                break;
                            }

                            case 3:{
                                chooseModOrDel = false;
                                break;
                            }

                            default:{
                                cout << "Unrecognized input.\n";
                                break;
                            }
                        }
                    }
                }

                //Allows repeated searches
                while (again) {
                    cout << "Do you want to search again?\n";
                    cout << "1. Yes\n";
                    cout << "2. No\n";

                    cin >> repeat;

                    switch (repeat) {
                        case 1: {
                            again = false;
                            break;
                        }

                        case 2: {
                            selected = true;
                            again = false;
                            break;
                        }
                        default:{
                            cout << "Unrecognized input, try again.\n";
                            break;
                        }
                    }
                }

                break;
            }

            case 2:{
                BSTree<Picture, int> searchTree;
                sortFilmByYear(searchTree, inputList);
                int yearToFind;

                cout << "Which film are you looking for?\n";
                cin >> yearToFind;

                Node<Picture, int> *searchResult;               //Stores the result of the search
                searchResult = searchTree.findNode(yearToFind);

                if (searchResult == nullptr)        //If not found
                {
                    cout << yearToFind << " not found in the database.\n";
                }

                else        //If record is found
                {
                    cout << yearToFind << " found\n";
                    searchResult -> Data().print();     //Print the data

                    bool chooseModOrDel = true;

                    while(chooseModOrDel)       //User chooses to modify or delete
                    {
                        cout << "What do you want to do with the record?\n";
                        cout << "1. Modify\n";
                        cout << "2. Delete\n";
                        cout << "3. Nothing\n";

                        cin >> modifyOrDelete;

                        switch (modifyOrDelete)
                        {
                            case 1:{
                                list<Picture>::iterator toRemove = inputList.begin();
                                while(!removed) //Iterates through the master list
                                {
                                    if(toRemove -> getYear() == yearToFind)     //Removes the desired node
                                    {
                                        inputList.erase(toRemove);
                                        removed = true;
                                    }
                                    toRemove++;     //Increments the iterator
                                }

                                addFilm(inputList);        //Adds a new film to the list, representing the "new" data for the record

                                chooseModOrDel = false;
                                break;
                            }

                            case 2:{
                                list<Picture>::iterator toRemove = inputList.begin();
                                while(!removed) //Iterates through the master list
                                {
                                    if(toRemove -> getYear() == yearToFind)     //Removes the desired node
                                    {
                                        inputList.erase(toRemove);
                                        removed = true;
                                    }
                                    toRemove++;     //Increments the iterator
                                }

                                chooseModOrDel = false;
                                break;
                            }

                            case 3:{
                                chooseModOrDel = false;
                                break;
                            }

                            default:{
                                cout << "Unrecognized input.\n";
                                break;
                            }
                        }
                    }
                }

                //Allows repeated searches
                while (again) {
                    cout << "Do you want to search again?\n";
                    cout << "1. Yes\n";
                    cout << "2. No\n";

                    cin >> repeat;

                    switch (repeat) {
                        case 1: {
                            again = false;
                            break;
                        }

                        case 2: {
                            selected = true;
                            again = false;
                            break;
                        }
                        default:{
                            cout << "Unrecognized input, try again.\n";
                            break;
                        }
                    }
                }

                break;
            }

            case 3:{
                BSTree<Picture, double> searchTree;
                sortFilmByRating(searchTree, inputList);
                double ratingToFind;

                cout << "Which film are you looking for?\n";
                cin >> ratingToFind;

                Node<Picture, double> *searchResult;                //Stores the search result
                searchResult = searchTree.findNode(ratingToFind);

                if (searchResult == nullptr)        //If not found
                {
                    cout << ratingToFind << " not found in the database.\n";
                }

                else        //If found
                {
                    cout << ratingToFind << " found\n";
                    searchResult -> Data().print();     //Prints record

                    bool chooseModOrDel = true;

                    while(chooseModOrDel)       //User chooses to modify or delete
                    {
                        cout << "What do you want to do with the record?\n";
                        cout << "1. Modify\n";
                        cout << "2. Delete\n";
                        cout << "3. Nothing\n";

                        cin >> modifyOrDelete;

                        switch (modifyOrDelete)
                        {
                            case 1:{
                                list<Picture>::iterator toRemove = inputList.begin();
                                while(!removed) //Iterates through the master list
                                {
                                    if(toRemove -> getRating() == ratingToFind)     //Removes the desired node
                                    {
                                        inputList.erase(toRemove);
                                        removed = true;
                                    }
                                    toRemove++;     //Increments the iterator
                                }

                                addFilm(inputList);        //Adds a new film to the list, representing the "new" data for the record

                                chooseModOrDel = false;
                                break;
                            }

                            case 2:{
                                list<Picture>::iterator toRemove = inputList.begin();
                                while(!removed) //Iterates through the master list
                                {
                                    if(toRemove -> getRating() == ratingToFind)     //Removes the desired node
                                    {
                                        inputList.erase(toRemove);
                                        removed = true;
                                    }
                                    toRemove++;     //Increments the iterator
                                }

                                chooseModOrDel = false;
                                break;
                            }

                            case 3:{
                                chooseModOrDel = false;
                                break;
                            }

                            default:{
                                cout << "Unrecognized input.\n";
                                break;
                            }
                        }
                    }
                }

                //Allows repeated searches
                while (again) {
                    cout << "Do you want to search again?\n";
                    cout << "1. Yes\n";
                    cout << "2. No\n";

                    cin >> repeat;

                    switch (repeat) {
                        case 1: {
                            again = false;
                            break;
                        }

                        case 2: {
                            selected = true;
                            again = false;
                            break;
                        }
                        default:{
                            cout << "Unrecognized input, try again.\n";
                            break;
                        }
                    }
                }

                break;
            }

            case 4:{
                BSTree<Picture, int> searchTree;
                sortFilmByDuration(searchTree, inputList);
                int durToFind;

                cout << "Which film are you looking for?\n";
                cin >> durToFind;

                Node<Picture, int> *searchResult;               //Stores search result
                searchResult = searchTree.findNode(durToFind);

                if (searchResult == nullptr)        //If not found
                {
                    cout << durToFind << " not found in the database.\n";
                }

                else        //If found
                {
                    cout << durToFind << " found\n";
                    searchResult -> Data().print();

                    bool chooseModOrDel = true;

                    while(chooseModOrDel)       //User chooses to modify or delete
                    {
                        cout << "What do you want to do with the record?\n";
                        cout << "1. Modify\n";
                        cout << "2. Delete\n";
                        cout << "3. Nothing\n";

                        cin >> modifyOrDelete;

                        switch (modifyOrDelete)
                        {
                            case 1:{
                                list<Picture>::iterator toRemove = inputList.begin();
                                while(!removed) //Iterates through the master list
                                {
                                    if(toRemove -> getDuration() == durToFind)     //Removes the desired node
                                    {
                                        inputList.erase(toRemove);
                                        removed = true;
                                    }
                                    toRemove++;     //Increments the iterator
                                }

                                addFilm(inputList);        //Adds a new film to the list, representing the "new" data for the record

                                chooseModOrDel = false;
                                break;
                            }

                            case 2:{
                                list<Picture>::iterator toRemove = inputList.begin();
                                while(!removed) //Iterates through the master list
                                {
                                    if(toRemove -> getDuration() == durToFind)     //Removes the desired node
                                    {
                                        inputList.erase(toRemove);
                                        removed = true;
                                    }
                                    toRemove++;     //Increments the iterator
                                }

                                chooseModOrDel = false;
                                break;
                            }

                            case 3:{
                                chooseModOrDel = false;
                                break;
                            }

                            default:{
                                cout << "Unrecognized input.\n";
                                break;
                            }
                        }
                    }
                }

                //Allows repeated searches
                while (again) {
                    cout << "Do you want to search again?\n";
                    cout << "1. Yes\n";
                    cout << "2. No\n";

                    cin >> repeat;

                    switch (repeat) {
                        case 1: {
                            again = false;
                            break;
                        }

                        case 2: {
                            selected = true;
                            again = false;
                            break;
                        }
                        default:{
                            cout << "Unrecognized input, try again.\n";
                            break;
                        }
                    }
                }

                break;
            }

            case 5:{
                BSTree<Picture, string> searchTree;
                sortFilmByGenre1(searchTree, inputList);
                string genreToFind;

                cout << "Which film are you looking for?\n";
                cin.ignore();
                getline(cin, genreToFind);

                Node<Picture, string> *searchResult;                //Stores result of the search
                searchResult = searchTree.findNode(genreToFind);

                if (searchResult == nullptr)        //If not found
                {
                    cout << genreToFind << " not found in the database.\n";
                }

                else        //If found
                {
                    cout << genreToFind << " found\n";
                    searchResult -> Data().print();

                    bool chooseModOrDel = true;

                    while(chooseModOrDel)
                    {
                        cout << "What do you want to do with the record?\n";
                        cout << "1. Modify\n";
                        cout << "2. Delete\n";
                        cout << "3. Nothing\n";

                        cin >> modifyOrDelete;

                        switch (modifyOrDelete)
                        {
                            case 1:{
                                list<Picture>::iterator toRemove = inputList.begin();
                                while(!removed) //Iterates through the master list
                                {
                                    if(toRemove -> getGenre1() == genreToFind)     //Removes the desired node
                                    {
                                        inputList.erase(toRemove);
                                        removed = true;
                                    }
                                    toRemove++;     //Increments the iterator
                                }

                                addFilm(inputList);        //Adds a new film to the list, representing the "new" data for the record

                                chooseModOrDel = false;
                                break;
                            }

                            case 2:{
                                list<Picture>::iterator toRemove = inputList.begin();
                                while(!removed) //Iterates through the master list
                                {
                                    if(toRemove -> getGenre1() == genreToFind)     //Removes the desired node
                                    {
                                        inputList.erase(toRemove);
                                        removed = true;
                                    }
                                    toRemove++;     //Increments the iterator
                                }

                                chooseModOrDel = false;
                                break;
                            }

                            case 3:{
                                chooseModOrDel = false;
                                break;
                            }

                            default:{
                                cout << "Unrecognized input.\n";
                                break;
                            }
                        }
                    }
                }

                //Allows repeated searches
                while (again) {
                    cout << "Do you want to search again?\n";
                    cout << "1. Yes\n";
                    cout << "2. No\n";

                    cin >> repeat;

                    switch (repeat) {
                        case 1: {
                            again = false;
                            break;
                        }

                        case 2: {
                            selected = true;
                            again = false;
                            break;
                        }
                        default:{
                            cout << "Unrecognized input, try again.\n";
                            break;
                        }
                    }
                }

                break;
            }

            case 6:{
                BSTree<Picture, string> searchTree;
                sortFilmByGenre2(searchTree, inputList);
                string genreToFind;

                cout << "Which film are you looking for?\n";
                cin.ignore();
                getline(cin, genreToFind);

                Node<Picture, string> *searchResult;            //Stores result of search
                searchResult = searchTree.findNode(genreToFind);

                if (searchResult == nullptr)        //If not found
                {
                    cout << genreToFind << " not found in the database.\n";
                }

                else        //If found
                {
                    cout << genreToFind << " found\n";
                    searchResult -> Data().print();     //Print record

                    bool chooseModOrDel = true;

                    while(chooseModOrDel)       //User chooses to modify or delete
                    {
                        cout << "What do you want to do with the record?\n";
                        cout << "1. Modify\n";
                        cout << "2. Delete\n";
                        cout << "3. Nothing\n";

                        cin >> modifyOrDelete;

                        switch (modifyOrDelete)
                        {
                            case 1:{
                                list<Picture>::iterator toRemove = inputList.begin();
                                while(!removed) //Iterates through the master list
                                {
                                    if(toRemove -> getGenre2() == genreToFind)     //Removes the desired node
                                    {
                                        inputList.erase(toRemove);
                                        removed = true;
                                    }
                                    toRemove++;     //Increments the iterator
                                }

                                addFilm(inputList);        //Adds a new film to the list, representing the "new" data for the record

                                chooseModOrDel = false;
                                break;
                            }

                            case 2:{
                                list<Picture>::iterator toRemove = inputList.begin();
                                while(!removed) //Iterates through the master list
                                {
                                    if(toRemove -> getGenre2() == genreToFind)     //Removes the desired node
                                    {
                                        inputList.erase(toRemove);
                                        removed = true;
                                    }
                                    toRemove++;     //Increments the iterator
                                }

                                chooseModOrDel = false;
                                break;
                            }

                            case 3:{
                                chooseModOrDel = false;
                                break;
                            }

                            default:{
                                cout << "Unrecognized input.\n";
                                break;
                            }
                        }
                    }
                }

                while (again) {
                    cout << "Do you want to search again?\n";
                    cout << "1. Yes\n";
                    cout << "2. No\n";

                    cin >> repeat;

                    switch (repeat) {
                        case 1: {
                            again = false;
                            break;
                        }

                        case 2: {
                            selected = true;
                            again = false;
                            break;
                        }
                        default:{
                            cout << "Unrecognized input, try again.\n";
                            break;
                        }
                    }
                }

                break;
            }

            case 7:{
                BSTree<Picture, string> searchTree;
                sortFilmByRelease(searchTree, inputList);
                string releaseToFind;

                cout << "Which film are you looking for?\n";
                cin.ignore();
                getline(cin, releaseToFind);

                Node<Picture, string> *searchResult;
                searchResult = searchTree.findNode(releaseToFind);

                if (searchResult == nullptr)
                {
                    cout << releaseToFind << " not found in the database.\n";
                }

                else
                {
                    cout << releaseToFind << " found\n";
                    searchResult -> Data().print();

                    bool chooseModOrDel = true;

                    while(chooseModOrDel)
                    {
                        cout << "What do you want to do with the record?\n";
                        cout << "1. Modify\n";
                        cout << "2. Delete\n";
                        cout << "3. Nothing\n";

                        cin >> modifyOrDelete;

                        switch (modifyOrDelete)
                        {
                            case 1:{
                                list<Picture>::iterator toRemove = inputList.begin();
                                while(!removed) //Iterates through the master list
                                {
                                    if(toRemove -> getRelease() == releaseToFind)     //Removes the desired node
                                    {
                                        inputList.erase(toRemove);
                                        removed = true;
                                    }
                                    toRemove++;     //Increments the iterator
                                }

                                addFilm(inputList);        //Adds a new film to the list, representing the "new" data for the record

                                chooseModOrDel = false;
                                break;
                            }

                            case 2:{
                                list<Picture>::iterator toRemove = inputList.begin();
                                while(!removed) //Iterates through the master list
                                {
                                    if(toRemove -> getRelease() == releaseToFind)     //Removes the desired node
                                    {
                                        inputList.erase(toRemove);
                                        removed = true;
                                    }
                                    toRemove++;     //Increments the iterator
                                }

                                chooseModOrDel = false;
                                break;
                            }

                            case 3:{
                                chooseModOrDel = false;
                                break;
                            }

                            default:{
                                cout << "Unrecognized input.\n";
                                break;
                            }
                        }
                    }
                }

                while (again) {
                    cout << "Do you want to search again?\n";
                    cout << "1. Yes\n";
                    cout << "2. No\n";

                    cin >> repeat;

                    switch (repeat) {
                        case 1: {
                            again = false;
                            break;
                        }

                        case 2: {
                            selected = true;
                            again = false;
                            break;
                        }
                        default:{
                            cout << "Unrecognized input, try again.\n";
                            break;
                        }
                    }
                }

                break;
            }

            case 8:{
                BSTree<Picture, int> searchTree;
                sortFilmByMetacritic(searchTree, inputList);
                int metaToFind;

                cout << "Which film are you looking for?\n";
                cin >> metaToFind;

                Node<Picture, int> *searchResult;
                searchResult = searchTree.findNode(metaToFind);

                if (searchResult == nullptr)
                {
                    cout << metaToFind << " not found in the database.\n";
                }

                else
                {
                    cout << metaToFind << " found\n";
                    searchResult -> Data().print();

                    bool chooseModOrDel = true;

                    while(chooseModOrDel)
                    {
                        cout << "What do you want to do with the record?\n";
                        cout << "1. Modify\n";
                        cout << "2. Delete\n";
                        cout << "3. Nothing\n";

                        cin >> modifyOrDelete;

                        switch (modifyOrDelete)
                        {
                            case 1:{
                                list<Picture>::iterator toRemove = inputList.begin();
                                while(!removed) //Iterates through the master list
                                {
                                    if(toRemove -> getMetacritic() == metaToFind)     //Removes the desired node
                                    {
                                        inputList.erase(toRemove);
                                        removed = true;
                                    }
                                    toRemove++;     //Increments the iterator
                                }

                                addFilm(inputList);        //Adds a new film to the list, representing the "new" data for the record

                                chooseModOrDel = false;
                                break;
                            }

                            case 2:{
                                list<Picture>::iterator toRemove = inputList.begin();
                                while(!removed) //Iterates through the master list
                                {
                                    if(toRemove -> getMetacritic() == metaToFind)     //Removes the desired node
                                    {
                                        inputList.erase(toRemove);
                                        removed = true;
                                    }
                                    toRemove++;     //Increments the iterator
                                }

                                chooseModOrDel = false;
                                break;
                            }

                            case 3:{
                                chooseModOrDel = false;
                                break;
                            }

                            default:{
                                cout << "Unrecognized input.\n";
                                break;
                            }
                        }
                    }
                }

                while (again) {
                    cout << "Do you want to search again?\n";
                    cout << "1. Yes\n";
                    cout << "2. No\n";

                    cin >> repeat;

                    switch (repeat) {
                        case 1: {
                            again = false;
                            break;
                        }

                        case 2: {
                            selected = true;
                            again = false;
                            break;
                        }
                        default:{
                            cout << "Unrecognized input, try again.\n";
                            break;
                        }
                    }
                }

                break;
            }

            case 9:{
                break;
            }

            default:{
                cout << "Unrecognozed input.\n";
                break;
            }
        }
    }
}

void partialSearchFilm(list<Picture> &inputList) //For this partial search, the only field that I find logical to search for a substring in is the film's name, so that is all I allow.
{
    list<Picture>::iterator partialChecked = inputList.begin();
    bool chooseModOrDel = true;
    bool again = true;
    bool selected = false;
    string nameToFind;
    int modifyOrDelete, repeat;

    while(!selected) {
        cout << "What film are you looking for?\n";
        cin.ignore();
        getline(cin, nameToFind);

        while (partialChecked != inputList.end()) {
            if (partialChecked->getName().find(nameToFind) !=
                string::npos) //exits search loop if the substring is found
            {
                break;
            }

            partialChecked++;
        }

        if (partialChecked->getName().find(nameToFind) == string::npos) //If not found
        {
            cout << "No results found.\n";
        }

        else
        {
            cout << "Result found.\n";
            partialChecked->print();      //Prints found film

            //Asks if they want to modify or delete record
            while (chooseModOrDel) {
                cout << "What do you want to do with this record?\n";
                cout << "1. Modify record\n";
                cout << "2. Delete record\n";
                cout << "3. Nothing\n";

                cin >> modifyOrDelete;

                switch (modifyOrDelete) {
                    case 1: {
                        inputList.erase(partialChecked); //Removes old node, and adds a new node to represent modifying the old one
                        addFilm(inputList);

                        chooseModOrDel = false;
                        break;
                    }

                    case 2: {
                        inputList.erase(partialChecked);    //Just deletes the record

                        chooseModOrDel = false;
                        break;
                    }

                    case 3: {
                        chooseModOrDel = false;
                        break;
                    }

                    default: {
                        cout << "Unrecognized input.\n";
                        break;
                    }
                }
            }
        }

        //Allows repeat searches
        while (again) {
            cout << "Do you want to search again?\n";
            cout << "1. Yes\n";
            cout << "2. No\n";

            cin >> repeat;

            switch (repeat) {
                case 1: {
                    again = false;
                    break;
                }

                case 2: {
                    selected = true;
                    again = false;
                    break;
                }
                default: {
                    cout << "Unrecognized input, try again.\n";
                    break;
                }
            }
        }
    }
}

void outputActorDB(list<Actor> outputList)
{
    ofstream myfile;
    string filename;

    cout << "What is the output file name?\n";      //Asks the user for file name
    cin.ignore();
    getline(cin, filename);

    if (filename.find(".csv") == string::npos)      //If the user didn't add .csv as the file extension, it will be added
    {
        filename.append(".csv");
    }

    myfile.open(filename);
    list<Actor>::iterator outputChecked = outputList.begin();       //Used to step through the linked list

    myfile << "Year,Award,Winner,Name,Film,\n";

    while(outputChecked!= outputList.end())     //Loops through the linked list until the end is reached, writing the relevant data to the file
    {
        myfile << outputChecked -> getYear() << ",";
        myfile << outputChecked -> getAward() << ",";
        myfile << outputChecked -> getWinner() << ",";
        myfile << outputChecked -> getName() << ",";
        myfile << outputChecked -> getFilm() << ",\n";      //Next line (aka next actor) once all of the data has been written for the current one
        outputChecked++;
    }

    cout << "Data has been written to " << filename << ".\n";

    myfile.close();
}

void outputFilmDB(list<Picture> outputList)
{
    ofstream myfile;
    string filename;

    cout << "What is the output file name?\n";      //Asks user for file to write to. If it doesn't exist,  new file will be made
    cin.ignore();
    getline(cin, filename);

    if (filename.find(".csv") == string::npos)      //If the user did not put .csv as the file extension, it will be added
    {
        filename.append(".csv");
    }

    myfile.open(filename);
    list<Picture>::iterator outputChecked = outputList.begin();     //Iterator to step through the list

    myfile << "Year,Award,Winner,Name,Film,\n";     //Writes the key to the file, then moves to the next line

    while(outputChecked!= outputList.end())     //Loops through the linked list, writing the information to the file until the end of the list is reached
    {
        myfile << outputChecked -> getName() << ",";
        myfile << outputChecked -> getYear() << ",";
        myfile << outputChecked -> getNominations() << ",";
        myfile << outputChecked -> getRating() << ",";
        myfile << outputChecked -> getDuration() << ",";
        myfile << outputChecked -> getGenre1() << ",";
        myfile << outputChecked -> getGenre2() << ",";
        myfile << outputChecked -> getRelease() << ",";
        myfile << outputChecked -> getMetacritic() << ",";
        myfile << outputChecked -> getSynopsis() << ",\n";      //Moves to next line (aka next Picture) after writing the synopsis
        outputChecked++;
    }

    cout << "Data has been written to " << filename << ".\n";

    myfile.close();
}

void displayMenu(BSTree<Actor, string> &ActorDB, BSTree<Picture, string> &FilmDB) {
    int databaseChoice, menuChoice;
    bool notDone = true;
    bool menu1 = true;
    bool menu2 = true;
    bool searchSelect = false;
    list<Actor> actorList;
    ActorDB.inOrderTransfer(actorList);
    list<Picture> filmList;
    FilmDB.inOrderTransfer(filmList);

    while (notDone)     //Loops until user is finished with the databases
    {
        //Asks which database to work with
        cout << "Which database do you want to work with?\n";
        cout << "1. Actors and Actresses\n";
        cout << "2. Films\n";
        cout << "3. Exit\n";

        cin.clear();        //Had an issue where occasionally would skip user input, so I put this here to prevent carried over inputs
        cin >> databaseChoice;

        //Options for previous menu
        switch (databaseChoice) {
            case 1: {
                cout << "Actors and Actresses database selected.\n";

                menu1 = true;

                //Loops until user is done
                while(menu1) {
                    //Asks which function to perform
                    cout << "What would you like to do?\n";
                    cout << "1. Add a record\n";
                    cout << "2. Search the database\n";
                    cout << "3. Export the database\n";
                    cout << "4. Return to database selection.\n";

                    cin.clear();
                    cin >> menuChoice;

                    switch (menuChoice) {
                        case 1: {
                            cout << "Add record selected.\n";
                            addActor(actorList);        //Calls addActor function
                            break;
                        }

                        case 2:{
                            //Asks for which search to perform
                            cout << "Search database selected.\n";
                            searchSelect = false;

                            while(!searchSelect)
                            {
                                cout << "Would you like to search for an exact match, or a partial match?\n";
                                cout << "1. Exact match\n";
                                cout << "2. Partial match\n";

                                cin >> menuChoice;

                                switch (menuChoice) {
                                    case 1: {
                                        completeSearchActor(actorList);     //Exact search on most fields
                                        searchSelect = true;
                                        break;
                                    }

                                    case 2: {
                                        partialSearchActor(actorList);      //Contains search on the Name and Film fields
                                        searchSelect = true;
                                        break;
                                    }

                                    default:{
                                        cout << "Unrecognized input.\n";
                                        break;
                                    }
                                }
                            }
                            break;
                        }

                        case 3:{
                            cout << "Export database selected.\n";
                            outputActorDB(actorList);       //Exports the
                            break;
                        }

                        case 4:{
                            cout << "Return selected.\n";
                            menu1 = false;
                            break;
                        }

                        default:{
                            cout << "Unrecognized input.\n";
                            break;
                        }
                    }
                    break;
                }
                break;
            }

            case 2: {
                cout << "Films database selected.\"";

                menu2 = true;

                //Asks which function to perform
                while (menu2) {
                    cout << "What would you like to do?\n";
                    cout << "1. Add a record\n";
                    cout << "2. Search for a record\n";
                    cout << "3. Export the database\n";
                    cout << "4. Return to database selection\n";

                    cin.clear();
                    cin >> menuChoice;

                    switch (menuChoice) {
                        case 1: {
                            cout << "Add record selected\n";
                            addFilm(filmList);
                            break;
                        }

                        case 2: {
                            cout << "Search selected\n";
                            searchSelect = false;

                            //Asks which search to perform
                            while(!searchSelect)
                            {
                                cout << "What kind of search do you want to perform?\n";
                                cout << "1. Exact search\n";
                                cout << "2. Contains search\n";

                                cin >> menuChoice;

                                switch (menuChoice) {
                                    case 1: {
                                        completeSearchFilm(filmList);
                                        searchSelect = true;
                                        break;
                                    }

                                    case 2: {
                                        partialSearchFilm(filmList);
                                        searchSelect = true;
                                        break;
                                    }

                                    default: {
                                        cout << "Unrecognized input.\n";
                                        break;
                                    }
                                }
                            }
                            break;
                        }

                        case 3: {
                            cout << "Export selected\n";
                            outputFilmDB(filmList);
                            break;
                        }

                        case 4: {
                            cout << "Exit selected\n";
                            menu2 = false;
                            break;
                        }
                    }

                    break;
                }
                break;
            }

            case 3: {
                cout << "exit selected.\n";
                notDone = false;
                break;
            }

            default:{
                cout << "Unrecognized selection. Please try again.\n";
                break;
            }
        }
    }
}

void fillActorDB(BSTree<Actor, string> &inputDB)
{
    string filename, award, name, film;
    int year, winner;
    Actor tempActor;

    cout << "What is the name of the file you are reading in?\n";
    getline(cin, filename);
    ifstream infile;
    infile.open(filename);

    infile.ignore(500, '\n');       //Ignores the cells dictating the columns

    while (infile >> year)      //Loops through getting information from the cells and using them to set the Actor's information
    {
        infile.ignore(1, ',');
        getline(infile, award, ',');
        infile >> winner;
        infile.ignore(1, ',');
        getline(infile, name, ',');
        getline(infile, film);

        tempActor.setYear(year);
        tempActor.setName(name);
        tempActor.setAward(award);
        tempActor.setWinner(winner);
        tempActor.setFilm(film);


        inputDB.addNode(tempActor.getName(), tempActor);        //Adds the actor to the database
    }


}

void fillFilmDB(BSTree<Picture, string> &inputDB)
{
    string filename, name, genre1, genre2, release, synopsis;
    int year, winner, nominations, metacritic, duration;
    double rating;
    Picture tempFilm;

    cout << "What is the name of the file you are reading in?\n";
    getline(cin, filename);
    ifstream infile;
    infile.open(filename);

    infile.ignore(500, '\n');       //Ignores cells dictating the columns


    while (getline(infile, name, ','))      //Loops through using the cells' information to set the Film data
    {
        infile >> year;
        infile.ignore(1, ',');
        infile >> nominations;
        infile.ignore(1, ',');
        infile >> rating;
        infile.ignore(1, ',');
        infile >> duration;
        infile.ignore(1, ',');
        getline(infile, genre1, ',');
        getline(infile, genre2, ',');
        getline(infile, release, ',');
        infile >> metacritic;
        infile.ignore(1, ',');
        getline(infile, synopsis);

        tempFilm.setName(name);
        tempFilm.setYear(year);
        tempFilm.setNominations(nominations);
        tempFilm.setRating(rating);
        tempFilm.setDuration(duration);
        tempFilm.setGenre1(genre1);
        tempFilm.setGenre2(genre2);
        tempFilm.setRelease(release);
        tempFilm.setMetacritic(metacritic);
        tempFilm.setSynopsis(synopsis);

        inputDB.addNode(tempFilm.getName(), tempFilm);  //Adds the film to the database


    }

}




