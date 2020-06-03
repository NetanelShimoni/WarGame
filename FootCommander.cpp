//
// Created by netanel & Or on 25/05/2020.
//

#include "FootCommander.hpp"
#include "FootSoldier.hpp"
#include <stdio.h>
#include <iostream>
#include <math.h>

void FootCommander::Fight(vector<vector<Soldier *>> &board, pair<int, int> location) {
    //FootSoldier::Fight_foot(board, location);
     dynamic_cast<FootSoldier *>(board[location.first][location.second])->Fight(board,location);


    int inf = INFINITY;
    int dist = 0;
    Soldier *attack = board[location.first][location.second];
    int damege_attack = attack->get_damage();
    int team = attack->get_num_player();
    pair<int, int> solider;
    for (int y = 0; y < board.size(); ++y) {
        for (int x = 0; x < board[0].size(); ++x) {
            // Soldier *ps = ;
            if (board[y][x] != nullptr) {
                Soldier *ps=board[y][x];
                if (dynamic_cast<FootSoldier *>(ps) && ps->get_num_player() == team) {
                    solider.first = y;
                    solider.second = x;
                    dynamic_cast<FootSoldier *>(ps)->Fight(board, solider);
                    //cout << "i am here" << endl;

                }
            }
        }
    }
}







