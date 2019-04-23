#ifndef FINAL_PROJECT_ACTOR_H
#define FINAL_PROJECT_ACTOR_H

#include <string>

using namespace std;


class Actor {
private:
    string name;
    int year;
    string award;
    string film;
    int winner;

public:
    string getName();
    void setName(string);
    int getYear();
    void setYear(int);
    string getAward();
    void setAward(string);
    string getFilm();
    void setFilm(string);
    int getWinner();
    void setWinner(int);
    void print();

};


#endif //FINAL_PROJECT_ACTOR_H
