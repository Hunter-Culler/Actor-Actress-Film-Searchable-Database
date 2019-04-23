//
// Created by hunte on 10/28/2018.
//

#include "Actor.h"
#include <iostream>
using namespace std;

string Actor::getName()
{
    return name;
}

void Actor::setName(string inputName)
{
    name = inputName;
}

int Actor::getYear()
{
    return year;
}

void Actor::setYear(int inputYear)
{
    year = inputYear;
}

string Actor::getAward()
{
    return award;
}

void Actor::setAward(string inputAward)
{
    award = inputAward;
}

string Actor::getFilm()
{
    return film;
}

void Actor::setFilm(string inputFilm)
{
    film = inputFilm;
}

int Actor::getWinner()
{
    return winner;
}

void Actor::setWinner(int inputWinner)
{
    winner = inputWinner;
}

void Actor::print()
{
    cout << year << ", " << award << ", " << winner << ", " << name << ", " << film << "\n";
}