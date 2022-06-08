#pragma once
#include <iostream>
#include "League.hpp"
#include "Game.hpp"
#include <unordered_map>
using namespace std;

class Schedule
{
private:
    League *league;
    std::unordered_map<int, vector<Game *>> board;
    vector<Team *> ranking;

public:
    Schedule();
    Schedule(League l);
    std::unordered_map<int, vector<Game *>> get_board();
    vector<Team *> get_ranking();
    void manage_Schedule();
    void score_board();
    void print_statistics(); // prints the scores and the statistics of the schedule.
    void more_statistics();
};
