#pragma once

#include "Paramedic.hpp"

using namespace std;

const int MAX_HP_PC = 200;
const int ACTION_PC = 100;

// namespace WarGame
// {
class ParamedicCommander : public Paramedic
{
public:
    ParamedicCommander(uint pNUM): Paramedic(pNUM, MAX_HP_PC, ACTION_PC) {}
    void Fight(vector<vector<Soldier*>> &board,pair<int,int> dest);
};