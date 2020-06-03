//
// Created by netanel & Or on 25/05/2020.
//

#ifndef WARGAME_PARAMEDICCOMMANDER_HPP
#define WARGAME_PARAMEDICCOMMANDER_HPP

#include "Soldier.hpp"
#include "Parmedic.hpp"
#include <vector>
using  namespace std;
class ParmedicCommander:public Parmedic {
public:
    ParmedicCommander(int num_p):Parmedic(num_p){
        this->health=200;
    }
     void Fight(vector<vector<Soldier *>> &board, pair<int, int> location);
};


#endif //WARGAME_PARAMEDICCOMMANDER_HPP
