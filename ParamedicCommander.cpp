//
// Created by netanel on 25/05/2020.
//

#include "ParamedicCommander.hpp"
#include "Paramedic.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"

#include <vector>
#include <math.h>
using  namespace std;

void help_heal(vector<vector<Soldier *>> &board, pair<int, int> location){
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


void ParamedicCommander::Fight(vector<vector<Soldier *>> &board, pair<int, int> location){
    help_heal(board,location);
    Soldier *attack = board[location.first][location.second];
    int team = attack->get_num_player();
    pair<int, int> solider;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            Soldier *ps = board[i][j];
            Soldier *check =dynamic_cast<ParamedicCommander *>(ps);

            if (check== nullptr &&dynamic_cast<Paramedic *>(ps) && ps->get_num_player() == team) {
                solider.first = i;
                solider.second = j;
                help_heal(board,solider);
            }
        }
    }

  /*  for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            Soldier *s = board[i][j];
            if (s != nullptr)
            {
                if (Paramedic *fs = dynamic_cast<Paramedic *>(s))
                {

                    ParamedicCommander *fc = dynamic_cast<ParamedicCommander *>(s);
                    if ((fc == nullptr) || (i == dest.first && j == dest.second))
                    {
                        if (fs->get_num_player() == board[dest.first][dest.second]->get_num_player())
                        {
                            fs->Paramedic::Fight(board, make_pair(i, j));
                        }
                    }
                }
            }
        }
    }*/

}