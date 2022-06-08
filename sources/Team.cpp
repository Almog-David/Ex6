#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include "Team.hpp"
#include <string>

Team::Team()
{
    std::string name;
    int random;
    // srand(time(NULL)); // initialize the random number generator

    for (int i = 0; i < 5; i++)
    {
        random = (rand() % 26); // generate a random number
        name += 'a' + random;   // Convert to a character from a-z
    }
    this->name = name;                                 // the name of the team build from 5 random letters - make it unique
    this->talent_level = (double(rand() % 100)) / 100; // generate a number between 0 to 1 with 2 decimals
    this->total_points = 0;                            // how many point the team had total
    this->loss_points = 0;                             // how many points they get from the second team - lost points
    this->winning = 0;                                 // how many games the team won
    this->total_winning = 0;                           // the total amount of winning in the schedule
    this->longest_win = 0;                             // the longest Sequence of victories
    this->lossing = 0;                                 // how many games the team losses
    this->longest_loss = 0;                            // the longest sequence of losses
}
Team::Team(std::string name, double level)
{
    if (name.size() == 0)
    {
        throw std::invalid_argument("this name is not a valid name!");
    }
    for (size_t i = 0; i < name.size(); i++)
    {
        if (name.at(i) == '\n' || name.at(i) == '\r' || name.at(i) == '\t' || std::isspace(name.at(i)))
        {
            throw std::invalid_argument("this name is not a valid name!");
        }
    }

    this->name = name;
    if (0 > level || 1 < level)
    {
        throw std::invalid_argument("the talent level is a number between 0 to 1!");
    }
    this->talent_level = level;
    this->total_points = 0;
    this->loss_points = 0;
    this->winning = 0;
    this->total_winning = 0;
    this->longest_win = 0;
    this->lossing = 0;
    this->longest_loss = 0;
}
std::string Team::get_name() const
{
    return this->name;
}
double Team::get_talent_level() const
{
    return this->talent_level;
}
int Team::get_points() const
{
    return this->total_points;
}
void Team::set_points(int points)
{
    this->total_points += points;
}
int Team::get_loss_points() const
{
    return this->loss_points;
}
void Team::set_loss_points(int points)
{
    this->loss_points += points;
}
int Team::get_numOfWinning() const
{
    return this->total_winning;
}
void Team::win()
{
    if (this->lossing > this->longest_loss)
    {
        this->longest_loss = this->lossing;
    }
    this->lossing = 0;
    this->winning += 1;
    this->total_winning += 1;
}
void Team::lose()
{
    if (this->winning > this->longest_win)
    {
        this->longest_win = this->winning;
    }
    this->winning = 0;
    this->lossing += 1;
}
int Team::get_longest_win() const
{
    return this->longest_win;
}
int Team::get_longest_loss() const
{
    return this->longest_loss;
}
