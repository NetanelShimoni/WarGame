//
// Created by netanel & Or on 26/05/2020.
//

#include "FootCommander.hpp"
#include "FootSoldier.hpp"
#include "Sniper.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include "SniperCommander.hpp"
#include "Board.hpp"
#include <stdio.h>
#include <iostream>
#include <math.h>


     void WarGame::Board::chack_type_AND_action(Soldier *&pSoldier, pair<int, int> p) {
         if (dynamic_cast<FootSoldier *>(pSoldier)) {
             dynamic_cast<FootSoldier *>(pSoldier)->Fight(this->board,p);
         }
         if (dynamic_cast<FootCommander *>(pSoldier)) {
             dynamic_cast<FootCommander *>(pSoldier)->Fight(this->board,p);
         }
         if (dynamic_cast<Sniper *>(pSoldier)) {
             dynamic_cast<Sniper *>(pSoldier)->Fight(this->board,p);
         }
         if (dynamic_cast<SniperCommander *>(pSoldier)) {
             dynamic_cast<SniperCommander *>(pSoldier)->Fight(this->board,p);
         }
         if (dynamic_cast<Paramedic *>(pSoldier)) {
             dynamic_cast<Paramedic *>(pSoldier)->Fight(this->board, p);
         }
         if (dynamic_cast<ParamedicCommander *>(pSoldier)) {
         dynamic_cast<ParamedicCommander *>(pSoldier)->Fight(this->board, p);
     }
}

Soldier*& WarGame::Board::operator[](std::pair<int,int> location){
//    if(this->board[location.first][location.second]== nullptr){
//        throw nullptr;
//    }

        return board[location.first][location.second];

     }
Soldier* WarGame::Board::operator[](std::pair<int,int> location) const{
        return board[location.first][location.second];
   }
void WarGame::Board::printboard() {
    for (int i = 0; i < this->board.size(); i++) {
        for (int j = 0; j < this->board[i].size(); j++) {
            if (this->board[i][j])  //!=NULL

                cout <<"  "<<this->board[i][j]->num_player <<"  "<< this->board[i][j]->health ;
            else
                cout << "  ------  " ;

        }
        cout<<""<<endl;

    }
    cout<<"   "<<endl;
    cout<<"   "<<endl;

    cout<<"   "<<endl;
    cout<<"   "<<endl;

}

//void WarGame::Board::move(uint player_number, std::pair<int, int> source, Board::MoveDIR direction) {
//    cout<< "pair first: " << source.first<<endl;
//    cout<< "pair secend: " << source.second<<endl;
//    if(board[source.first][source.second]== nullptr ||
//    board[source.first][source.second]->get_num_player()!=player_number){
//        cout<<"exption"<<endl;
//        throw exception();
//    }
//
//         Soldier *s = WarGame::Board::board[source.first][source.second];
//         int source_x = source.first;
//         int source_y = source.second;
//    pair<int, int> point;
//
//    switch (direction) {
//             case WarGame::Board::Up:
//                 if (((source.first + 1) < Board::board.size() )&&
//                 board[source_x+1][source_y]== nullptr) {
//                     Board::board[source_x][source_y] = nullptr;
//                     Board::board[source_x + 1][source_y] = s;
//                     //pair<int, int> point;
//                     point.first = source_x + 1;
//                     point.second = source_y;
//                  //  s->Fight(board,point);
//                    // chack_type_AND_action(s, point);
//                 }else{
//                     throw exception();
//                 }
//                 break;
//             case WarGame::Board::Down:
//                 if (((source.first - 1) < Board::board.size()) &&
//                 ( board[source_x-1][source_y]== nullptr)) {
//                     Board::board[source_x][source_y] = nullptr;
//                     Board::board[source_x - 1][source_y] = s;
//                    // pair<int, int> point;
//                     point.first = source_x - 1;
//                     point.second = source_y;
//                    // s->Fight(board,point);
//                 }else{
//                     throw exception();
//                 }
//                 break;
//             case WarGame::Board::Left:
//                 if (((source.second -1) < Board::board[0].size()) &&
//                 board[source_x][source_y-1]== nullptr) {
//                     Board::board[source_x][source_y] = nullptr;
//                     Board::board[source_x][source_y-1 ] = s;
//                    // pair<int, int> point;
//                     point.first = source_x;
//                     point.second = source_y-1;
//                    // s->Fight(board,point);
//                 }else{
//                     throw exception();
//                 }
//                 break;
//             case WarGame::Board::Right:
//                 if (((source.second + 1) < Board::board[0].size()) &&
//                         board[source_x][source_y+1]== nullptr) {
//                     Board::board[source_x][source_y] = nullptr;
//                     Board::board[source_x][source_y+1] = s;
//                     point.first = source_x;
//                     point.second = source_y+1;
//                    // s->Fight(board,point);
//                 }else{
//                     throw exception();
//                 }
//                 break;
//         }
//         board[point.first][point.second]->Fight(board,point);
//     }

void WarGame::Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction)
{
    Soldier *src = board[source.first][source.second];
    if(src == nullptr)
    {
        throw invalid_argument("No player on source");
    }
    if(src->get_num_player() != player_number)
    {
        throw invalid_argument("Wrong player number");
    }
    // Up, Down, Right, Left
    pair<int,int> dest;
    switch(direction)
    {
        case Up : dest = make_pair(source.first+1,source.second);
            break;
        case Down : dest = make_pair(source.first-1,source.second);
            break;
        case Right : dest = make_pair(source.first,source.second+1);
            break;
        case Left : dest = make_pair(source.first,source.second-1);
            break;

    }
    if(dest.first < 0 || dest.second < 0 || dest.first >= board.size() || dest.second >= board[dest.first].size())
    {
        throw invalid_argument("out of bounds");
    }
    if(board[dest.first][dest.second] != nullptr)
    {
        throw invalid_argument("trying to move to a allocated space");
    }
    board[dest.first][dest.second] = src;
    board[source.first][source.second]= nullptr;
    src->Fight(board,dest);
}



static int count_1=0;
static int count_2=0;

     bool  WarGame::Board::has_soldiers(uint player_number) const {
//    if(player_number==1){
//        if (count_1>0){
//            return true;
//        }
//    }else{
//        if (count_2>0){
//            return true;
//        }
//    }
//         return false;

int count=0;
         for (int i = 0; i < Board::board.size(); ++i) {
             for (int j = 0; j < Board::board[0].size(); ++j) {
                 if (Board::board[i][j] != nullptr && Board::board[i][j]->get_num_player() == player_number) {
                    count++;
                 }

             }
         }
         cout<<count<<"this is count"<<endl;
         if(count==0) {
             return false;
         }
         if(count>0){
             return true;
         }
     }
