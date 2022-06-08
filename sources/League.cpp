#include <iostream>
#include "League.hpp"
#include <vector>
#include <unordered_map>
constexpr auto MAX_TEAMS = 20;
using namespace std;

League::League(vector<Team *> teams)
{
    if (teams.size() > MAX_TEAMS)
    {
        throw std::invalid_argument("the max number of teams in the league is 20!");
    }
    int amount = 0;
    if (!teams.empty())
    {
        for (Team *t : teams)
        {
            if (!this->league.contains(t->get_name()))
            {
                this->league[t->get_name()] = t;
                amount++;
            }
        }
    }
    for (int i = amount; i < MAX_TEAMS; i++)
    {
        Team *temp = new Team();
        if (!this->league.contains(temp->get_name()))
        {
            this->league[temp->get_name()] = temp;
        }
    }
}
std::unordered_map<std::string, Team *> League::get_league()
{
    return this->league;
}
