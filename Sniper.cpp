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
    int damege_attack=attack->getdamage();
    int index_i;
    int index_j;
    int team = attack->getnum();
    pair<int, int> target;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            if(board[i][j]!=nullptr) {
                if (board[i][j]->getnum() != team) {
                    if (board[i][j]->getCurrHP() > max_health) {
                        max_health = board[i][j]->getCurrHP();
                        index_i = i;
                        index_j = j;
                    }
                }
            }
        }
    }
    cout<<index_i<<endl;
    cout<<index_j<<endl;
    board[index_i][index_j]->set_HP((board[index_i][index_j]->getCurrHP()-damege_attack));
    cout<<"life is:"<<board[index_i][index_j]->getCurrHP()<<endl;
    if (board[index_i][index_j]->getCurrHP()<=0){
        board[index_i][index_j]= nullptr;
        delete board[index_i][index_j];
    }

}

