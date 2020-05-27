//
// Created by netanel on 25/05/2020.
//

#ifndef WARGAME_SNIPER_HPP
#define WARGAME_SNIPER_HPP

#include "Soldier.hpp"
#include <vector>
using  namespace std;
class Sniper:public Soldier{
public:
    Sniper(int num_p):Soldier(100,50,num_p){}
    void  Fight(vector<vector<Soldier *>> &board, pair<int, int> location);
};


#endif //WARGAME_SNIPER_HPP
