//
// Created by netanel on 25/05/2020.
//

#ifndef WARGAME_PARAMEDIC_HPP
#define WARGAME_PARAMEDIC_HPP

#include "Soldier.hpp"
#include <vector>
using  namespace std;
class Paramedic: public Soldier{
public:
    Paramedic(int num_p): Soldier(100, 0, num_p,100){

    }
    void Fight(vector<vector<Soldier *>> &board, pair<int, int> location) override;
};



#endif //WARGAME_PARAMEDIC_HPP
