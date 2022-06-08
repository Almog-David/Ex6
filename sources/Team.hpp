#pragma once
#include <iostream>
#include <string>
#include <time.h>
class Team
{
private:
    std::string name;
    double talent_level;
    int total_points;  // how many point the team had total
    int loss_points;   // how many points they get from the second team - lost points
    int winning;       // how many games the team won
    int total_winning; // the total amount of winning in the schedule
    int longest_win;   // the longest Sequence of victories
    int lossing;       // how many games the team losses
    int longest_loss;  // the longest sequence of losses

public:
    Team();
    Team(std::string name, double level);
    std::string get_name() const;
    double get_talent_level() const;
    int get_points() const;
    void set_points(int points);
    int get_loss_points() const;
    void set_loss_points(int points);
    int get_numOfWinning() const;
    void win();
    void lose();
    int get_longest_win() const;
    int get_longest_loss() const;
};
