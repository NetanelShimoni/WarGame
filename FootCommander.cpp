//
// Created by netanel & Or on 25/05/2020.
//
//



#include <cmath>
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include <iostream>







#include "FootCommander.hpp"
#include "FootSoldier.hpp"
#include <stdio.h>
#include <iostream>
#include <math.h>
//#include <zconf.h>
void help_attack(vector<vector<Soldier *>> &board, pair<int, int> location){
    int inf = 1000000000;
    int dist = 0;
    int index_i;
    //cout<<"i am in fight footsolder"<<endl;
    // sleep(5);
    int index_j;
    Soldier *attack= board[location.first][location.second];
    int damege_attack=attack->get_damage();
    int team = attack->get_num_player();
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            if(board[i][j]!=nullptr && board[i][j]->get_num_player()!=team){
                dist = sqrt(pow((location.first - i), 2) + pow((location.second - j), 2));
                if (dist < inf){
                    inf=dist;
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
void FootCommander::Fight(vector<vector<Soldier *>> &board, pair<int, int> dest) {
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                Soldier *s = board[i][j];
                if(s!=nullptr)
                {
                    if(FootSoldier *fs = dynamic_cast<FootSoldier*> (s))
                    {

                        FootCommander *fc = dynamic_cast<FootCommander*> (s);
                        if((fc == nullptr) || (i == dest.first && j==dest.second))
                        {
                            if(fs->get_num_player() == board[dest.first][dest.second]->get_num_player())
                            {
                                fs->FootSoldier::Fight(board,make_pair(i,j));

                            }
                        }


                    }
                }
            }
        }
    }
}







