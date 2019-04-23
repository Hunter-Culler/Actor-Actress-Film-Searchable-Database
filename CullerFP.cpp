#include <iostream>
#include "Actor.h"
#include "Picture.h"
#include "Menu.h"
#include "BSTree.hpp"

using namespace std;

int main()
{
    BSTree<Actor,string> ActorDB;       //Creates the initial database for Actors
    BSTree<Picture, string> FilmDB;     //Creates the initial database for Pictures

    fillActorDB(ActorDB);               //Fills the trees
    fillFilmDB(FilmDB);

    displayMenu(ActorDB, FilmDB);       //Displays the menu for the remainder of the program

    return 0;
}