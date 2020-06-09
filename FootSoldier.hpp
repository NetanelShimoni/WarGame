#pragma once

#include "Soldier.hpp"

using namespace std;

const int MAX_HP = 100;
const int ACTION = 10;
// namespace WarGame
// {
class FootSoldier : public Soldier
{

public:
    FootSoldier(int pNUM) : Soldier(MAX_HP, ACTION, pNUM) {}
    FootSoldier(int pNUM, int hp, int act) : Soldier(hp, act, pNUM) {}
    void Fight(vector<vector<Soldier *>> &board, pair<int, int> dest);
};