//
// Created by netanel on 25/05/2020.
//

#ifndef WARGAME_FOOTCOMMANDER_HPP
#define WARGAME_FOOTCOMMANDER_HPP

#include "Soldier.hpp"
#include "FootSoldier.hpp"
#include <vector>

using namespace std;

class FootCommander : public Soldier {
public:
    FootCommander(int num_p) :Soldier(150,20,num_p,150) {}

    void Fight(vector<vector<Soldier *>> &board, pair<int, int> location) override;

};


#endif //WARGAME_FOOTCOMMANDER_HPP
