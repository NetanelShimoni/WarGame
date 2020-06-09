#pragma once

#include "Sniper.hpp"

using namespace std;

const int MAX_HP_SC = 120;
const int ACTION_SC = 100;
// namespace WarGame {
class SniperCommander : public Sniper {

public:
    SniperCommander(uint pNUM): Sniper(pNUM, MAX_HP_SC, ACTION_SC) {}
    void Fight(vector<vector<Soldier*>> &board,pair<int,int> dest);
};

// }