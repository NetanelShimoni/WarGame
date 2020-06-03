//
// Created by netanel & Or on 25/05/2020.
//
#include "FootSoldier.hpp"
#include <stdio.h>
#include <iostream>
#include <math.h>

void FootSoldier::Fight(vector<vector<Soldier *>> &board, pair<int, int> location) {
    int inf = 1000000000;
    int dist = 0;
    Soldier *attack= board[location.first][location.second];
    int damege_attack=attack->get_damage();
    int team = attack->get_num_player();
    pair<int, int> target;

    for (int y = 0; y < board.size(); ++y) {
        for (int x = 0; x < board[0].size(); ++x) {
            if ((x != location.first && y != location.second) && board[y][x]!= nullptr ) {
                dist = sqrt(pow((location.first - x), 2) + pow((location.second - y), 2));
                int team_target = board[y][x]->get_num_player();
               // cout<<"dist is: " <<dist<<"\n"<<endl;
               // cout<<team_target<<endl;
                if (dist < inf && team!=team_target) {
                   // cout<<"team target: "<<team_target<<"\n"<<endl;
                    inf = dist;
                   // cout<<"distanc minimum  "<<inf<<endl;
                    target.first = x;
                    target.second = y;
                }
            }
        }
    }
    Soldier* tar= board[target.second][target.first];
    tar->set_health(tar->get_health()-damege_attack);


    if (tar->get_health()<=0){
        delete tar;
    }

}





