//
// Created by netanel on 25/05/2020.
//

#include "ParamedicCommander.hpp"
#include "Parmedic.hpp"

#include <vector>
#include <math.h>
using  namespace std;

//
//void to_heal_Cperamdic(vector<vector<Soldier *>> &board, pair<int, int> location){
//    Parmedic::to_heal_peramdic(board,location);
//    Soldier *attack = board[location.first][location.second];
//    int team = attack->get_num_player();
//    pair<int, int> solider;
//    for (int y = 0; y < board.size(); ++y) {
//        for (int x = 0; x < board[0].size(); ++x) {
//            Soldier *ps = board[y][x];
//            if (dynamic_cast<Parmedic *>(ps) && ps->get_num_player() == team) {
//                solider.first = x;
//                solider.second = y;
//                Parmedic::to_heal_peramdic(board, solider);
//            }
//        }
//    }
//
//}