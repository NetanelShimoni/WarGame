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


void Paramedic::Fight(vector<vector<Soldier *>> &board, pair<int, int> location) {
    int i = location.first;
    int j = location.second;
    int team = board[i][j]->getnum();
    if (i >= board.size() && j >= board[0].size()) {
        throw exception();
    }

    if (board[i + 1][j] != nullptr && (i + 1) < board.size() && j < board[0].size()) {
        Soldier *s = board[i + 1][j];
        if (s->getnum() == team) {
            s->set_HP(s->getMaxHP());
            board[i + 1][j] = s;
        }
    }
    if (board[i][j + 1] != nullptr && (i) < board.size() && (j + 1) < board[0].size()) {
        Soldier *s = board[i][j + 1];
        if (s->getnum() == team) {
            s->set_HP(s->getMaxHP());
            board[i][j + 1] = s;
        }

    }
    if (board[i + 1][j + 1] != nullptr && (i + 1) < board.size() && (j + 1) < board[0].size()) {
        Soldier *s = board[i + 1][j + 1];
        if (s->getnum() == team) {
            s->set_HP(s->getMaxHP());
            board[i + 1][j + 1] = s;
        }

    }
    if (board[i - 1][j] != nullptr && 0 <= (i - 1)) {
        Soldier *s = board[i - 1][j];
        if (s->getnum() == team) {
            s->set_HP(s->getMaxHP());
            board[i - 1][j] = s;
        }
    }
    if (board[i][j - 1] != nullptr && 0 <= (j - 1)) {
        Soldier *s = board[i][j - 1];
        if (s->getnum() == team) {
            s->set_HP(s->getMaxHP());
            board[i][j - 1] = s;
        }
    }
    if (board[i - 1][j - 1] != nullptr && 0 <= (j - 1) && 0 <= (i - 1)) {
        Soldier *s = board[i - 1][j - 1];
        if (s->getnum() == team) {
            s->set_HP(s->getMaxHP());
            board[i - 1][j - 1] = s;
        }
    }
    if (board[i - 1][j + 1] != nullptr && 0 <= (i - 1) && (j + 1) < board[0].size()) {
        Soldier *s = board[i - 1][j + 1];
        if (s->getnum() == team) {
            s->set_HP(s->getMaxHP());
            board[i - 1][j + 1] = s;
        }
    }
    if (board[i + 1][j - 1] != nullptr && (i + 1) < board.size() && (j - 1) >= 0) {
        Soldier *s = board[i + 1][j - 1];
        if (s->getnum() == team) {
            s->set_HP(s->getMaxHP());
            board[i + 1][j - 1] = s;
        }
    }
}

