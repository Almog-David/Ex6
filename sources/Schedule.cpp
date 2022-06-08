#include <iostream>
#include <unordered_map>
#include <vector>
#include "Schedule.hpp"
constexpr auto MAX_GAMES = 10;
constexpr auto MAX_TEAMS = 20;
constexpr auto MAX_ROUNDS = 38;
using namespace std;

Schedule::Schedule()
{
    this->league = new League();
    manage_Schedule();
}
Schedule::Schedule(League l)
{
    this->league = &l;
    manage_Schedule();
}
std::unordered_map<int, vector<Game *>> Schedule::get_board()
{
    return this->board;
}
vector<Team *> Schedule::get_ranking()
{
    return this->ranking;
}

void Schedule::manage_Schedule()
{
    for (auto &team : this->league->get_league())
    {
        this->ranking.push_back(team.second);
    }
    for (int i = 1; i <= MAX_ROUNDS; i++)
    {
        vector<Game *> round;
        this->get_board().insert({i, round});
    }
    for (auto &home : this->league->get_league())
    {
        for (auto &guest : this->league->get_league())
        {
            if (home.first != guest.first)
            {
                bool add = false;
                int num_of_rounds = 1;
                Game g = Game(home.second, guest.second);
                while (!add)
                {
                    std::vector<Game *> check = this->board[num_of_rounds];
                    if (check.empty())
                    {
                        add = true;
                        this->board[num_of_rounds].push_back(&g);
                    }
                    if (check.size() < MAX_GAMES)
                    {
                        bool exist = false;
                        for (Game *current : check)
                        {
                            if (current->get_home()->get_name() == home.first || current->get_home()->get_name() == guest.first || current->get_guest()->get_name() == home.first || current->get_guest()->get_name() == guest.first)
                            {
                                exist = true;
                                break;
                            }
                        }
                        if (!exist)
                        {
                            add = true;
                            this->board[num_of_rounds].push_back(&g);
                        }
                    }
                    num_of_rounds++;
                }
            }
        }
    }
    score_board();
}

void Schedule::score_board()
{
    cout << this->get_ranking().size() << endl;
    for (size_t i = 0; i < MAX_TEAMS; i++)
    {
        for (size_t j = i + 1; j < MAX_TEAMS; j++)
        {
            if (this->ranking[j]->get_numOfWinning() == this->ranking[i]->get_numOfWinning())
            {
                double j_calculate = (this->ranking[j]->get_points() - this->ranking[j]->get_loss_points());
                double i_calculate = (this->ranking[i]->get_points() - this->ranking[i]->get_loss_points());
                if (j_calculate > i_calculate)
                {
                    Team *temp = this->ranking[i];
                    this->ranking[i] = this->ranking[j];
                    this->ranking[j] = temp;
                }
            }
            else if (this->ranking[j]->get_numOfWinning() > this->ranking[i]->get_numOfWinning())
            {
                Team *temp = this->ranking[i];
                this->ranking[i] = this->ranking[j];
                this->ranking[j] = temp;
            }
        }
    }
    print_statistics();
}

void Schedule::print_statistics()
{
    int index = 1;
    int num_of_groups = 0;
    for (Team *t : this->ranking)
    {
        cout << index << ".   " << t->get_name() << "   "
             << "Score: " << t->get_points() << endl;
        index++;
    }
    cout << "\n";
    cout << "Please enter the number of groups you would like to watch their statistics: ";
    cin >> num_of_groups;
    if (num_of_groups > MAX_TEAMS)
    {
        throw std::invalid_argument("THERE ARE 20 TEAMS IN THE LEAGUE!");
    }
    cout << "The Top " << num_of_groups << "groups are:" << endl;
    for (size_t k = 1; k <= num_of_groups; k++)
    {
        Team *current = this->ranking[k];
        cout << k << ".   " << current->get_name() << endl;
    }
    cout << "\n";
    more_statistics();
}
void Schedule::more_statistics()
{
    Team *longest_win = nullptr;
    int win_sequence = 0;
    Team *longest_loss = nullptr;
    int loss_sequence = 0;
    Team *biggest_different = nullptr;
    int difference = 0;
    Team *higher_talent = nullptr;
    double talent = 0;
    Team *most_win = nullptr;
    int winner = 0;
    Team *most_loss = nullptr;
    int loser = MAX_ROUNDS;
    for (Team *t : this->ranking)
    {
        if (t->get_longest_win() > win_sequence)
        {
            win_sequence = t->get_longest_win();
            longest_win = t;
        }
        if (t->get_longest_loss() > loss_sequence)
        {
            loss_sequence = t->get_longest_loss();
            longest_loss = t;
        }
        if (t->get_points() - t->get_loss_points() > difference)
        {
            difference = t->get_points() - t->get_loss_points();
            biggest_different = t;
        }
        if (t->get_talent_level() > talent)
        {
            talent = t->get_talent_level();
            higher_talent = t;
        }
        if (t->get_numOfWinning() > winner)
        {
            winner = t->get_numOfWinning();
            most_win = t;
        }
        if (t->get_numOfWinning() < loser)
        {
            loser = t->get_numOfWinning();
            most_loss = t;
        }
    }
    cout << "longest win sequence: " << longest_win->get_name() << " with " << win_sequence << " win sequence!" << endl;
    cout << "longest loss sequence: " << longest_loss->get_name() << " with " << loss_sequence << " loss sequence!" << endl;
    cout << "biggest points difference: " << biggest_different->get_name() << " with " << difference << " points!" << endl;
    cout << "team with highet talent: " << higher_talent->get_name() << " with " << talent << " talent level score!" << endl;
    cout << "biggest number of winning: " << most_win->get_name() << " in " << winner << " games!" << endl;
    cout << "biggest number of lossing: " << most_loss->get_name() << " in " << MAX_ROUNDS - loser << " games!" << endl;
}
