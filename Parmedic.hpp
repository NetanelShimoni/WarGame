//
// Created by netanel on 25/05/2020.
//

#ifndef WARGAME_PARMEDIC_HPP
#define WARGAME_PARMEDIC_HPP

#include "Soldier.hpp"
#include <vector>
using  namespace std;
class Parmedic:public Soldier{
public:
    Parmedic(int num_p):Soldier(100,0,num_p){}
    void Fight(vector<vector<Soldier *>> &board, pair<int, int> location);
};



#endif //WARGAME_PARMEDIC_HPP
