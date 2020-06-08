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
Soldier* chack_Type(Soldier *pSoldier) {
    if (dynamic_cast<FootSoldier*>(pSoldier)){
        return  new FootSoldier(pSoldier->get_num_player());

    }
    if (dynamic_cast<FootCommander*>(pSoldier)){
        return new FootCommander(pSoldier->get_num_player());
        //return  new FootCommander::Soldier(150,20,pSoldier->get_num_player());

    }
    if (dynamic_cast<Sniper*>(pSoldier)){
        return  new Sniper(pSoldier->get_num_player());

    }
    if (dynamic_cast<SniperCommander*>(pSoldier)){
        return  new SniperCommander(pSoldier->get_num_player());

    }
    if (dynamic_cast<Paramedic*>(pSoldier)){
        return  new Paramedic(pSoldier->get_num_player());

    }
    if (dynamic_cast<ParamedicCommander*>(pSoldier)){
        return  new ParamedicCommander(pSoldier->get_num_player());
    }


}
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
            s = chack_Type(s);
            board[i + 1][j] = s;
        }
    }
    if (board[i][j + 1] != nullptr && (i) < board.size() && (j + 1) < board[0].size()) {
        Soldier *s = board[i][j + 1];
        if (s->get_num_player() == team) {
            s = chack_Type(s);
            board[i][j + 1] = s;
        }

    }
    if (board[i + 1][j + 1] != nullptr && (i + 1) < board.size() && (j + 1) < board[0].size()) {
        Soldier *s = board[i + 1][j + 1];
        if (s->get_num_player() == team) {
            s = chack_Type(s);
            board[i + 1][j + 1] = s;
        }

    }
    if (board[i - 1][j] != nullptr && 0 <= (i - 1)) {
        Soldier *s = board[i - 1][j];
        if (s->get_num_player() == team) {
            s = chack_Type(s);
            board[i - 1][j] = s;
        }
    }
    if (board[i][j - 1] != nullptr && 0 <= (j - 1)) {
        Soldier *s = board[i][j - 1];
        if (s->get_num_player() == team) {
            s = chack_Type(s);
            board[i][j - 1] = s;
        }
    }
    if (board[i - 1][j - 1] != nullptr && 0 <= (j - 1) && 0 <= (i - 1)) {
        Soldier *s = board[i - 1][j - 1];
        if (s->get_num_player() == team) {
            s = chack_Type(s);
            board[i - 1][j - 1] = s;
        }
    }
    if (board[i - 1][j + 1] != nullptr && 0 <= (i - 1) && (j + 1) < board[0].size()) {
        Soldier *s = board[i - 1][j + 1];
        if (s->get_num_player() == team) {
            s = chack_Type(s);
            board[i - 1][j + 1] = s;
        }
    }
    if (board[i + 1][j - 1] != nullptr && (i + 1) < board.size() && (j - 1) >= 0) {
        Soldier *s = board[i + 1][j - 1];
        if (s->get_num_player() == team) {
            s = chack_Type(s);
            board[i + 1][j - 1] = s;
        }
    }
}


void ParamedicCommander::Fight(vector<vector<Soldier *>> &board, pair<int, int> dest){
//    help_heal(board,location);
//    Soldier *attack = board[location.first][location.second];
//    int team = attack->get_num_player();
//    pair<int, int> solider;
//    for (int y = 0; y < board.size(); ++y) {
//        for (int x = 0; x < board[0].size(); ++x) {
//            Soldier *ps = board[y][x];
//            if (dynamic_cast<Paramedic *>(ps) && ps->get_num_player() == team) {
//                solider.first = x;
//                solider.second = y;
//                help_heal(board,solider);
//            }
//        }
//    }

    for (int i = 0; i < board.size(); i++)
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
    }

}