//
// Created by netanel on 25/05/2020.
//

#ifndef WARGAME_SNIPERCOMMANDER_HPP
#define WARGAME_SNIPERCOMMANDER_HPP

#include "Soldier.hpp"
using  namespace std;
class SniperCommander:public Soldier{
public:
    SniperCommander(int num_p):Soldier(120,100,num_p){}
};



#endif //WARGAME_SNIPERCOMMANDER_HPP
