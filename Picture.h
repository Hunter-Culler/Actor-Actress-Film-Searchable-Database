#ifndef FINAL_PROJECT_PICTURE_H
#define FINAL_PROJECT_PICTURE_H

#include <string>

using namespace std;

class Picture {
private:
    string name;
    int year;
    int nominations;
    double rating;
    int duration;
    string genre1;
    string genre2;
    string release;
    int metacritic;
    string synopsis;

public:
    string getName();
    void setName(string);
    int getYear();
    void setYear(int);
    int getNominations();
    void setNominations(int);
    double getRating();
    void setRating(double);
    int getDuration();
    void setDuration(int);
    string getGenre1();
    void setGenre1(string);
    string getGenre2();
    void setGenre2(string);
    string getRelease();
    void setRelease(string);
    int getMetacritic();
    void setMetacritic(int);
    string getSynopsis();
    void setSynopsis(string);
    void print();

};


#endif //FINAL_PROJECT_PICTURE_H
