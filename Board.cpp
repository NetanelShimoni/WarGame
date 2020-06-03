//
// Created by netanel & Or on 26/05/2020.
//

#include "FootCommander.hpp"
#include "FootSoldier.hpp"
#include "Sniper.hpp"
#include "Parmedic.hpp"
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
         if (dynamic_cast<Parmedic *>(pSoldier)) {
             dynamic_cast<Parmedic *>(pSoldier)->Fight(this->board,p);
         }
         if (dynamic_cast<ParmedicCommander *>(pSoldier)) {
         dynamic_cast<ParmedicCommander *>(pSoldier)->Fight(this->board,p);
     }}

Soldier*& WarGame::Board::operator[](std::pair<int,int> location){
             return board[location.first][location.second];



     }
Soldier* WarGame::Board::operator[](std::pair<int,int> location) const{
        return board[location.first][location.second];
   }

void WarGame::Board::move(uint player_number, std::pair<int, int> source, Board::MoveDIR direction) {
         Soldier *s = WarGame::Board::board[source.first][source.second];
         int source_x = source.first;
         int source_y = source.second;
         switch (direction) {
             case WarGame::Board::Up:
                 if ((source.first + 1) < Board::board.size()) {
                     Board::board[source_x][source_y] = nullptr;
                     Board::board[source_x + 1][source_y] = s;
                     pair<int, int> point;
                     point.first = source_x + 1;
                     point.second = source_y;
                     chack_type_AND_action(s, point);

                 }
                 break;
             case WarGame::Board::Down:
                 if ((source.first - 1) < Board::board.size()) {
                     Board::board[source_x][source_y] = nullptr;
                     Board::board[source_x - 1][source_y] = s;
                     pair<int, int> point;
                     point.first = source_x - 1;
                     point.second = source_y;
                     chack_type_AND_action(s, point);
                 }
                 break;
             case WarGame::Board::Left:
                 if ((source.second + 1) < Board::board.size()) {
                     Board::board[source_x][source_y] = nullptr;
                     Board::board[source_x][source_y + 1] = s;
                     pair<int, int> point;
                     point.first = source_x;
                     point.second = source_y + 1;
                     chack_type_AND_action(s, point);
                 }
                 break;
             case WarGame::Board::Right:
                 if ((source.second - 1) < Board::board.size()) {
                     Board::board[source_x][source_y] = nullptr;
                     Board::board[source_x][source_y - 1] = s;
                     pair<int, int> point;
                     point.first = source_x;
                     point.second = source_y - 1;
                     chack_type_AND_action(s, point);
                 }
                 break;
         }
     }
     bool  WarGame::Board::has_soldiers(uint player_number) const {
         for (int i = 0; i < Board::board.size(); ++i) {
             for (int j = 0; j < Board::board[0].size(); ++j) {
                 if (Board::board[i][j] != nullptr && Board::board[i][j]->get_num_player() == player_number) {
                     return true;
                 }

             }
         }
         return true;
     }
