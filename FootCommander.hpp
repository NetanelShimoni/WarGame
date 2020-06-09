#pragma once

#include "FootSoldier.hpp"

using namespace std;

const int MAX_HP_C = 150;
const int ACTION_C = 20;
// namespace WarGame {
class FootCommander : public FootSoldier {

public:
    FootCommander(uint pNUM): FootSoldier(pNUM, MAX_HP_C, ACTION_C) {}
    void Fight(vector<vector<Soldier*>> &board,pair<int,int> dest);
};