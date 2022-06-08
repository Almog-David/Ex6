#include <iostream>
#include <stdexcept>
#include <vector>
#include "Team.hpp"
#include "Schedule.hpp"
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string continued;
    string name;
    double talent;
    vector<Team *> my_teams = {};
    std::cout << "welcome to the basketball league!" << std::endl;
    std::cout << "you can enter your own team to the league or the system will generate teams for you" << std::endl;
    std::cout << "if you want to create your own teams - write yes. if you want to generate random teams - write no" << std::endl;
    std::cin >> continued;
    while (continued == "yes")
    {
        bool legit = false;
        std::cout << "Enter the name of the team: " << std::endl;
        std::cin >> name;
        std::cout << "Enter the talent level - a number between 0 to 1: " << std::endl;
        std::cin >> talent;
        while (!legit)
        {
            if (0 <= talent && talent <= 1)
            {
                legit = true;
            }
            else
            {
                std::cout << "the talent level is a number between 0 to 1! Enter a new number" << std::endl;
                std::cin >> talent;
            }
        }
        Team t = Team(name, talent);
        my_teams.push_back(&t);
        std::cout << "if you want to keep create your own teams - write yes. if you want to generate random teams - write no" << std::endl;
        std::cin >> continued;
    }
    League my_league = League(my_teams);
    Schedule *schedule = new Schedule(my_league);
}