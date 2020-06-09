//
// Created by netanel on 25/05/2020.
//

#include "SniperCommander.hpp"
#include <vector>
#include <math.h>
#include "Sniper.hpp"

void help_atack(vector<vector<Soldier *>> &board, pair<int, int> location) {


    int max_health = 0;
    int power = 0;

    Soldier *attack = board[location.first][location.second];
    int damege_attack = attack->get_damage();
    int index_i;
    int index_j;
    int team = attack->get_num_player();
    pair<int, int> target;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            if (board[i][j] != nullptr && board[i][j]->get_num_player() != team) {
                if (board[i][j]->get_health() > max_health) {
                    max_health = board[i][j]->get_health();
                    index_i = i;
                    index_j = j;
                }
            }

        }
    }
    board[index_i][index_j]->set_health(board[index_i][index_j]->get_health() - damege_attack);
    if (board[index_i][index_j]->get_health() <= 0) {
        board[index_i][index_j] = nullptr;
        delete board[index_i][index_j];
    }
}

void SniperCommander::Fight(vector<vector<Soldier *>> &board, pair<int, int> dest) {
//
//    help_atack(board,location);
//    int inf = INFINITY;
//    int dist = 0;
//    Soldier *attack = board[location.first][location.second];
//    int damege_attack = attack->get_damage();
//    int team = attack->get_num_player();
//    pair<int, int> solider;
//    for (int i = 0; i < board.size(); ++i) {
//        for (int j = 0; j < board[0].size(); ++j) {
//            if (board[i][j]!= nullptr){
//            Soldier *ps = board[i][j];
//                Soldier *check =dynamic_cast<SniperCommander *>(ps);
//
//                if ( check== nullptr && dynamic_cast<Sniper *>(ps) && ps->get_num_player() == team) {
//                solider.first = i;
//                solider.second = j;
//                dynamic_cast<Sniper *>(ps)->Fight(board,solider);
//                help_atack(board,solider);
//            }
//        }}

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            Soldier *s = board[i][j];
            if (s != nullptr) {
                if (Sniper *fs = dynamic_cast<Sniper *> (s)) {

                    SniperCommander *fc = dynamic_cast<SniperCommander *> (s);
                    if ((fc == nullptr) || (i == dest.first && j == dest.second)) {
                        if (fs->get_num_player() == board[dest.first][dest.second]->get_num_player()) {
                            fs->Sniper::Fight(board, make_pair(i, j));

                        }
                    }


                }
            }
        }
    }}
