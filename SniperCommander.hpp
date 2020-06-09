//
// Created by netanel & Or on 25/05/2020.
//

#ifndef WARGAME_SNIPERCOMMANDER_HPP
#define WARGAME_SNIPERCOMMANDER_HPP

#include "Soldier.hpp"
#include "Sniper.hpp"
#include <vector>
using  namespace std;
class SniperCommander:public Soldier{
public:
    SniperCommander(int num_p):Soldier(120,100,num_p,120){
    }
     void Fight(vector<vector<Soldier *>> &board, pair<int, int> location) override;

    };



#endif //WARGAME_SNIPERCOMMANDER_HPP
