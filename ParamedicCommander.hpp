//
// Created by netanel & Or on 25/05/2020.
//

#ifndef WARGAME_PARAMEDICCOMMANDER_HPP
#define WARGAME_PARAMEDICCOMMANDER_HPP

#include "Soldier.hpp"
using  namespace std;
class ParmedicCommander:public Soldier{
public:
    ParmedicCommander(int num_p):Soldier(200,0,100,num_p){}
};


#endif //WARGAME_PARAMEDICCOMMANDER_HPP
