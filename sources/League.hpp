#include <iostream>
#include "Team.hpp"
#include <vector>
#include <unordered_map>
using namespace std;

class League
{
private:
    std::unordered_map<std::string, Team *> league;

public:
    League(vector<Team *> teams = {});
    std::unordered_map<std::string, Team *> get_league();
};
