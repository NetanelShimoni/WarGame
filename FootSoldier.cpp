//
// Created by netanel & Or on 25/05/2020.
//
#include "FootSoldier.hpp"
#include <stdio.h>
#include <iostream>
#include <math.h>

void Fight(vector<vector<Soldier *>> &board, pair<int, int> location) {

    int inf = INFINITY;
    int dist = 0;
    Soldier *attack= board[location.first][location.second];
    int damege_attack=attack->get_damage();
    int team = attack->get_num_player();
    pair<int, int> target;
    for (int y = 0; y < board.size(); ++y) {
        for (int x = 0; x < board[0].size(); ++x) {
            if (x != location.first && y != location.second) {
                dist = sqrt(pow((location.first - x), 2) + pow((location.second - y), 2));
                int team_target = board[y][x]->get_num_player();
                if (dist < inf && team!=team_target) {
                    inf = dist;
                    target.first = x;
                    target.second = y;
                }
            }
        }
    }
    Soldier* tar= board[target.first][target.second];
    tar->set_health(tar->get_health()-damege_attack);
    if (tar->get_health()<=0){
        delete tar;
    }

}





