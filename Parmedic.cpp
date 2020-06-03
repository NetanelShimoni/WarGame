//



// Created by netanel & Or on 25/05/2020.
//

#include "Parmedic.hpp"
#include "FootSoldier.hpp"
#include "Sniper.hpp"
#include "FootCommander.hpp"
#include "SniperCommander.hpp"
#include "ParamedicCommander.hpp"


Soldier* chack_type(Soldier *pSoldier) {
if (dynamic_cast<FootSoldier*>(pSoldier)){
    return  new FootSoldier::Soldier(100,10,pSoldier->get_num_player());

}
    if (dynamic_cast<FootCommander*>(pSoldier)){
        return  new FootCommander::Soldier(150,20,pSoldier->get_num_player());

    }
    if (dynamic_cast<Sniper*>(pSoldier)){
        return  new Sniper::Soldier(100,50,pSoldier->get_num_player());

    }
    if (dynamic_cast<SniperCommander*>(pSoldier)){
        return  new SniperCommander::Soldier(120,100,pSoldier->get_num_player());

    }
    if (dynamic_cast<Parmedic*>(pSoldier)){
        return  new Parmedic::Soldier(100,0,50,pSoldier->get_num_player());

    }
    if (dynamic_cast<ParmedicCommander*>(pSoldier)){
        return  new ParmedicCommander::Soldier(100,0,50,pSoldier->get_num_player());
    }


}

void Parmedic::Fight(vector<vector<Soldier *>> &board, pair<int, int> location) {
    int i = location.first;
    int j = location.second;
    int team = board[i][j]->get_num_player();
    if (i >= board.size() && j >= board[0].size()) {
        throw exception();
    }

    if (board[i + 1][j] != nullptr && (i + 1) < board.size() && j < board[0].size()) {
        Soldier *s = board[i + 1][j];
        if (s->get_num_player() == team) {
            s = chack_type(s);
            board[i + 1][j] = s;
        }
    }
    if (board[i][j + 1] != nullptr && (i) < board.size() && (j + 1) < board[0].size()) {
        Soldier *s = board[i][j + 1];
        if (s->get_num_player() == team) {
            s = chack_type(s);
            board[i][j + 1] = s;
        }

    }
    if (board[i + 1][j + 1] != nullptr && (i + 1) < board.size() && (j + 1) < board[0].size()) {
        Soldier *s = board[i + 1][j + 1];
        if (s->get_num_player() == team) {
            s = chack_type(s);
            board[i + 1][j + 1] = s;
        }

    }
    if (board[i - 1][j] != nullptr && 0 <= (i - 1)) {
        Soldier *s = board[i - 1][j];
        if (s->get_num_player() == team) {
            s = chack_type(s);
            board[i - 1][j] = s;
        }
    }
    if (board[i][j - 1] != nullptr && 0 <= (j - 1)) {
        Soldier *s = board[i][j - 1];
        if (s->get_num_player() == team) {
            s = chack_type(s);
            board[i][j - 1] = s;
        }
    }
    if (board[i - 1][j - 1] != nullptr && 0 <= (j - 1) && 0 <= (i - 1)) {
        Soldier *s = board[i - 1][j - 1];
        if (s->get_num_player() == team) {
            s = chack_type(s);
            board[i - 1][j - 1] = s;
        }
    }
    if (board[i - 1][j + 1] != nullptr && 0 <= (i - 1) && (j + 1) < board[0].size()) {
        Soldier *s = board[i - 1][j + 1];
        if (s->get_num_player() == team) {
            s = chack_type(s);
            board[i - 1][j + 1] = s;
        }
    }
    if (board[i + 1][j - 1] != nullptr && (i + 1) < board.size() && (j - 1) >= 0) {
        Soldier *s = board[i + 1][j - 1];
        if (s->get_num_player() == team) {
            s = chack_type(s);
            board[i + 1][j - 1] = s;
        }
    }
}

