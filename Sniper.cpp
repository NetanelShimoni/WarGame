//
// Created by netanel&Or on 25/05/2020.
//

#include "Sniper.hpp"
#include <vector>
#include <math.h>

//
// void static Fight_sniper(vector<vector<Soldier *>> &board, pair<int, int> location) {
//
//    int max_health = 0;
//    int power = 0;
//
//    Soldier *attack= board[location.first][location.second];
//    int damege_attack=attack->get_damage();
//    int team = attack->get_num_player();
//    pair<int, int> target;
//    for (int y = 0; y < board.size(); ++y) {
//        for (int x = 0; x < board[0].size(); ++x) {
//            if (x != location.first && y != location.second) {
//                power= board[y][x]->get_health();
//                int team_target = board[y][x]->get_num_player();
//                if (power > max_health && team!=team_target) {
//                    max_health = power;
//                    target.first = x;
//                    target.second = y;
//                }
//            }
//        }
//    }
//    Soldier* tar= board[target.first][target.second];
//    tar->set_health(tar->get_health()-damege_attack);
//    if (tar->get_health()<=0){
//        delete tar;
//    }
//
//}

