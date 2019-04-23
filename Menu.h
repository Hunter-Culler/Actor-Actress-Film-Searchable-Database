#ifndef FINAL_PROJECT_FUNCTIONS_H
#define FINAL_PROJECT_FUNCTIONS_H
#include "BSTree.h"
#include "Actor.h"
#include "Picture.h"

using namespace std;


void displayMenu(BSTree<Actor, string> &ActorDB, BSTree<Picture, string> &FilmDB);
void fillActorDB(BSTree<Actor, string>&);
void fillFilmDB(BSTree<Picture, string>&);
void sortActorByName(BSTree<Actor, string> &, list<Actor>);
void sortActorByYear(BSTree<Actor, int> &, list<Actor>);
void sortActorByFilm(BSTree<Actor, string> &, list<Actor>);
void sortFilmByName(BSTree<Picture, string> &, list<Picture> &);
void sortFilmByYear(BSTree<Picture, int> &, list<Picture> &);
void sortFilmByRating(BSTree<Picture, double> &, list<Picture> &);
void sortFilmByDuration(BSTree<Picture, int> &, list<Picture> &);
void sortFilmByGenre1(BSTree<Picture, string> &, list<Picture> &);
void sortFilmByGenre2(BSTree<Picture, string> &, list<Picture> &);
void sortFilmByRelease(BSTree<Picture, string> &, list<Picture> &);
void sortFilmByMetacritic(BSTree<Picture, int> &, list<Picture> &);
void addActor(list<Actor> &);
void addFilm(list<Picture> &);
void completeSearchActor(list<Actor> &);
void partialSearchActor(list<Actor> &);
void completeSearchFilm(list<Picture> &);
void partialSearchFilm(list<Picture> &);
void outputActorDB(list<Actor>);
void outputFilmDB(list<Picture>);




#endif //FINAL_PROJECT_FUNCTIONS_H
