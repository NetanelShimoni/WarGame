#include "FootSoldier.hpp"
#include "math.h"
// namespace WarGame
// {
void FootSoldier::Fight(vector<vector<Soldier *> > &board, pair<int, int> dest) {

    double closest = board.size() * board.size();
    int ci, cj;
    int found = 0;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            Soldier *s;
            s = board[i][j];
            if (s != nullptr && (s->getnum() != board[dest.first][dest.second]->getnum())) {
                double dist = sqrt((i - dest.first) * (i - dest.first) + (j - dest.second) * (j - dest.second));
                if (dist < closest) {
                    closest = dist;
                    ci = i;
                    cj = j;
                    found = 1;
                }
            }
        }
    }
    if (found) {
        Soldier *s = board[ci][cj];
        int hp = s->getCurrHP() - board[dest.first][dest.second]->getdamage();
        if (hp <= 0) {
            board[ci][cj] = nullptr;
        } else {
            s->set_HP(hp);
        }

        // s->setHP(s->getCurrHP() - board[dest.first][dest.second]->getact());
        //     if (s->getCurrHP() <= 0)
        //     {
        //         board[ci][cj] = nullptr;
        //     }
    }
}