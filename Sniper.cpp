//
// Created by netanel&Or on 25/05/2020.
//

#include "Sniper.hpp"
#include <vector>
#include <math.h>


 void  Sniper::Fight(vector<vector<Soldier *>> &board, pair<int, int> location) {

    int max_health = 0;
    int power = 0;

    Soldier *attack= board[location.first][location.second];
    int damege_attack=attack->get_damage();
    int index_i;
    int index_j;
    int team = attack->get_num_player();
    pair<int, int> target;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            if(board[i][j]!=nullptr && board[i][j]->get_num_player()!=team){
                if(board[i][j]->get_health()>max_health){
                    max_health=board[i][j]->get_health();
                    index_i=i;
                    index_j=j;
                }
            }

        }
    }
    board[index_i][index_j]->set_health(board[index_i][index_j]->get_health()-damege_attack);
    if (board[index_i][index_j]->get_health()<=0){
        board[index_i][index_j]= nullptr;
        delete board[index_i][index_j];
    }

}

