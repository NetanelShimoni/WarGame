//
// Created by netanel & Or on 25/05/2020.
//

#ifndef WARGAME_PARAMEDICCOMMANDER_HPP
#define WARGAME_PARAMEDICCOMMANDER_HPP

#include "Soldier.hpp"
#include "Paramedic.hpp"
#include <vector>
using  namespace std;
class ParamedicCommander: public Soldier {
public:
    ParamedicCommander(int num_p): Soldier(200,0,num_p,200){
    }
     void Fight(vector<vector<Soldier *>> &board, pair<int, int> location) override;
};


#endif //WARGAME_PARAMEDICCOMMANDER_HPP
