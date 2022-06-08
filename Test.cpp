#include <iostream>
#include "doctest.h"
#include <stdexcept>
#include <string>
#include <vector>
#include "Team.hpp"
#include "Schedule.hpp"
using namespace std;

TEST_CASE("test Ex5")
{
    Team A = Team("A", 0.3);
    CHECK(A.get_name() == "A");
    Team B = Team("B", 0.36);
    CHECK(B.get_talent_level() == 0.36);
    Team C = Team("C", 0.8);
    CHECK(C.get_points() == 0);
    Team D = Team("D", 0.76);
    CHECK(D.get_numOfWinning() == 0);
    Team E = Team("E", 0.44);
    CHECK_FALSE(E.get_talent_level() == 0.45);
    Team F = Team("F", 0.81);
    CHECK_FALSE(F.get_name() == "D");
    Team G = Team("G", 0.90);
    CHECK_FALSE(G.get_name() == F.get_name());
    Team H = Team("H", 0.11);
    Team I = Team("I", 0.28);
    Team J = Team("J", 0.17);
    Team K = Team("K", 0.93);
    Team L = Team("L", 0.05);
    Team M = Team("M", 0.67);
    Team N = Team("N", 0.55);
    Team O = Team("O", 0.39);
    Team P = Team("P", 0.28);
    Team Q = Team("Q", 0.70);
    Team R = Team("R", 0.63);
    Team S = Team("S", 0.42);
    Team T = Team("T", 0.82);
    Team U = Team("U", 0.59);
    vector<Team *> my_teams = {&A, &B, &C, &D, &E, &F, &G, &H, &I, &J, &K, &L, &M, &N, &O, &P, &Q, &R, &S, &T, &U};
    CHECK_NOTHROW(League());
    League l = League(my_teams);
    CHECK_NOTHROW(Schedule());
    Schedule s = Schedule(l);
    CHECK_THROWS(Game(&A, &A));
    CHECK_THROWS(Game(&D, &D));
    CHECK_THROWS(Team("almog", 1.33));
    CHECK_THROWS(Team("david", -0.22));
    CHECK_THROWS(Team("test", 4));
    CHECK_THROWS(Team("test2", -0.3));
    Team temp = Team("new_team", 0.8);
    CHECK_THROWS(Team(" ", 0.7));
    CHECK_THROWS(Team("\n", 0.5));
    CHECK_THROWS(Team("\r", 0.3));
    CHECK_THROWS(Team("", 0.11));
}
