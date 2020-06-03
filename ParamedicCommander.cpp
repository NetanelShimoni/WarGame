//
// Created by netanel on 25/05/2020.
//

#include "ParamedicCommander.hpp"
#include "Parmedic.hpp"

#include <vector>
#include <math.h>
using  namespace std;


void ParmedicCommander::Fight(vector<vector<Soldier *>> &board, pair<int, int> location){
    dynamic_cast<Parmedic *>(board[location.first][location.second])->Fight(board,location);
    Soldier *attack = board[location.first][location.second];
    int team = attack->get_num_player();
    pair<int, int> solider;
    for (int y = 0; y < board.size(); ++y) {
        for (int x = 0; x < board[0].size(); ++x) {
            Soldier *ps = board[y][x];
            if (dynamic_cast<Parmedic *>(ps) && ps->get_num_player() == team) {
                solider.first = x;
                solider.second = y;
                dynamic_cast<Parmedic *>(ps)->Fight(board, solider);
            }
        }
    }

}