//
// Created by netanel & Or on 25/05/2020.
//

#ifndef WARGAME_SNIPERCOMMANDER_HPP
#define WARGAME_SNIPERCOMMANDER_HPP

#include "Soldier.hpp"
#include "Sniper.hpp"
#include <vector>
using  namespace std;
class SniperCommander:public Sniper{
public:
    SniperCommander(int num_p):Sniper(num_p){
        this->health=120;
        this->damage=100;
    }
     void Fight(vector<vector<Soldier *>> &board, pair<int, int> location) ;

    };



#endif //WARGAME_SNIPERCOMMANDER_HPP
