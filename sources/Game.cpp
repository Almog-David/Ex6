#include <iostream>
#include "Game.hpp"
#include <string>
constexpr auto MAX_SCORE = 100;
constexpr auto MIN_HOME_SCORE = 55;
constexpr auto MIN_GUEST_SCORE = 50;

Game::Game()
{
    this->home_team = new Team();
    this->guest_team = new Team();
    active_game();
}

Game::Game(Team *H, Team *G)
{
    if (H->get_name() == G->get_name())
    {
        throw std::invalid_argument("the game is between different teams!");
    }
    this->home_team = H;
    this->guest_team = G;
    active_game();
}

void Game::active_game()
{
    int home_score = rand() % (MAX_SCORE - MIN_HOME_SCORE + 1) + MIN_HOME_SCORE;
    int home_bonus = (int)10 * this->get_home()->get_talent_level() + 1;
    this->home_team->set_points(home_score + home_bonus);
    int guest_bonus = (int)10 * this->get_guest()->get_talent_level() + 1;
    int guest_score = rand() % (MAX_SCORE - MIN_GUEST_SCORE + 1) + MIN_GUEST_SCORE;
    this->guest_team->set_points(guest_score + guest_bonus);
    if (home_score + home_bonus == guest_score + guest_bonus)
    {
        double home_calculate = (this->home_team->get_points() - this->home_team->get_loss_points()) * this->home_team->get_talent_level();
        double guest_calculate = (this->guest_team->get_points() - this->guest_team->get_loss_points()) * this->guest_team->get_talent_level();
        if (home_calculate > guest_calculate)
        {
            this->winner = this->home_team->get_name();
            this->home_team->win();
            this->guest_team->lose();
        }
        else
        {
            this->winner = this->guest_team->get_name();
            this->guest_team->win();
            this->home_team->lose();
        }
    }
    else
    {
        if (home_score + home_bonus > guest_score + guest_bonus)
        {
            this->winner = this->home_team->get_name();
            this->home_team->win();
            this->guest_team->lose();
        }
        else
        {
            this->winner = this->guest_team->get_name();
            this->guest_team->win();
            this->home_team->lose();
        }
    }
    this->home_team->set_loss_points(guest_score + guest_bonus);
    this->guest_team->set_loss_points(home_score + home_bonus);
}

Team *Game::get_home() const
{
    return this->home_team;
}
Team *Game::get_guest() const
{
    return this->guest_team;
}
std::string Game::get_winner() const
{
    return this->winner;
}