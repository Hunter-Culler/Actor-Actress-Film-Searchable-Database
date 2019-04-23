//
// Created by hunte on 10/28/2018.
//

#include "Picture.h"
#include <iostream>

using namespace std;

string Picture::getName()
{
    return name;
}

void Picture::setName(string inputName)
{
    name = inputName;
}

int Picture::getYear()
{
    return year;
}

void Picture::setYear(int inputYear)
{
    year = inputYear;
}

int Picture::getNominations()
{
    return nominations;
}

void Picture::setNominations(int inputNoms)
{
    nominations = inputNoms;
}

double Picture::getRating()
{
    return rating;
}

void Picture::setRating(double inputRating)
{
    rating = inputRating;
}

int Picture::getDuration()
{
    return duration;
}

void Picture::setDuration(int inputDur)
{
    duration = inputDur;
}

string Picture::getGenre1()
{
    return genre1;
}

void Picture::setGenre1(string inputGenre)
{
    genre1 = inputGenre;
}

string Picture::getGenre2()
{
    return genre2;
}

void Picture::setGenre2(string inputGenre)
{
    genre2 = inputGenre;
}

string Picture::getRelease()
{
    return release;
}

void Picture::setRelease(string inputRelease)
{
    release = inputRelease;
}

int Picture::getMetacritic()
{
    return metacritic;
}

void Picture::setMetacritic(int inputMeta)
{
    metacritic= inputMeta;
}

string Picture::getSynopsis()
{
    return synopsis;
}

void Picture::setSynopsis(string inputSyn)
{
    synopsis = inputSyn;
}

void Picture::print()
{
    cout << "Film: " << name << "\n";
    cout << "Released: " << release << ", " << year << "\n";
    cout << "Nominations: " << nominations << "\n";
    cout << "Runtime: " << duration << "\n";
    cout << "Rating: " << rating << "\n";
    cout << "Genres: " << genre1 << ", " << genre2 << "\n";
    cout << "Metacritic Score: " << metacritic << "\n";
    cout << "Synopsis: " << synopsis << "\n";
}