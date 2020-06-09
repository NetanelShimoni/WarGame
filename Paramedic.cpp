#include "Paramedic.hpp"

// namespace WarGame
// {









//



// Created by netanel & Or on 25/05/2020.
//

#include "Paramedic.hpp"
#include "FootSoldier.hpp"
#include "Sniper.hpp"
#include "FootCommander.hpp"
#include "SniperCommander.hpp"
#include "ParamedicCommander.hpp"
//
//
//Soldier* chackType(Soldier *pSoldier) {
//if (dynamic_cast<FootSoldier*>(pSoldier)){
//    return  new FootSoldier(pSoldier->get_num_player());
//
//}
//    if (dynamic_cast<FootCommander*>(pSoldier)){
//        return new FootCommander(pSoldier->get_num_player());
//        //return  new FootCommander::Soldier(150,20,pSoldier->get_num_player());
//
//    }
//    if (dynamic_cast<Sniper*>(pSoldier)){
//        return  new Sniper(pSoldier->get_num_player());
//
//    }
//    if (dynamic_cast<SniperCommander*>(pSoldier)){
//        return  new SniperCommander(pSoldier->get_num_player());
//
//    }
//    if (dynamic_cast<Paramedic*>(pSoldier)){
//        return  new Paramedic(pSoldier->get_num_player());
//
//    }
//    if (dynamic_cast<ParamedicCommander*>(pSoldier)){
//        return  new ParamedicCommander(pSoldier->get_num_player());
//    }
//
//
//}

void Paramedic::Fight(vector<vector<Soldier *>> &board, pair<int, int> location) {
    int i = location.first;
    int j = location.second;
    int team = board[i][j]->get_num_player();
    if (i >= board.size() && j >= board[0].size()) {
        throw exception();
    }

    if (board[i + 1][j] != nullptr && (i + 1) < board.size() && j < board[0].size()) {
        Soldier *s = board[i + 1][j];
        if (s->get_num_player() == team) {
            s->set_health(s->max);
            board[i + 1][j] = s;
        }
    }
    if (board[i][j + 1] != nullptr && (i) < board.size() && (j + 1) < board[0].size()) {
        Soldier *s = board[i][j + 1];
        if (s->get_num_player() == team) {
            s->set_health(s->max);
            board[i][j + 1] = s;
        }

    }
    if (board[i + 1][j + 1] != nullptr && (i + 1) < board.size() && (j + 1) < board[0].size()) {
        Soldier *s = board[i + 1][j + 1];
        if (s->get_num_player() == team) {
            s->set_health(s->max);
            board[i + 1][j + 1] = s;
        }

    }
    if (board[i - 1][j] != nullptr && 0 <= (i - 1)) {
        Soldier *s = board[i - 1][j];
        if (s->get_num_player() == team) {
            s->set_health(s->max);
            board[i - 1][j] = s;
        }
    }
    if (board[i][j - 1] != nullptr && 0 <= (j - 1)) {
        Soldier *s = board[i][j - 1];
        if (s->get_num_player() == team) {
            s->set_health(s->max);
            board[i][j - 1] = s;
        }
    }
    if (board[i - 1][j - 1] != nullptr && 0 <= (j - 1) && 0 <= (i - 1)) {
        Soldier *s = board[i - 1][j - 1];
        if (s->get_num_player() == team) {
            s->set_health(s->max);
            board[i - 1][j - 1] = s;
        }
    }
    if (board[i - 1][j + 1] != nullptr && 0 <= (i - 1) && (j + 1) < board[0].size()) {
        Soldier *s = board[i - 1][j + 1];
        if (s->get_num_player() == team) {
            s->set_health(s->max);
            board[i - 1][j + 1] = s;
        }
    }
    if (board[i + 1][j - 1] != nullptr && (i + 1) < board.size() && (j - 1) >= 0) {
        Soldier *s = board[i + 1][j - 1];
        if (s->get_num_player() == team) {
            s->set_health(s->max);
            board[i + 1][j - 1] = s;
        }
    }
}

