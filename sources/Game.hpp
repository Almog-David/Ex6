#include <iostream>
#include "Team.hpp"
#include <string>
using namespace std;

class Game
{
private:
    Team *home_team;
    Team *guest_team;
    std::string winner;

public:
    Game();
    Game(Team *H, Team *G);
    void active_game();
    Team *get_home() const;
    Team *get_guest() const;
    std::string get_winner() const;
};
