#pragma once

#include "Soldier.hpp"

using namespace std;

const int MAX_HP_P = 100;
const int ACTION_P = 100;
// namespace WarGame {
class Paramedic : public Soldier
{
public:
    Paramedic(uint pNUM): Soldier(MAX_HP_P,ACTION_P,pNUM ) {}
    Paramedic(uint pNUM,uint hp,uint act):Soldier(hp,act,pNUM) {}
    void Fight(vector<vector<Soldier*>> &board,pair<int,int> dest);
};
