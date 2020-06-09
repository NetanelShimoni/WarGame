#include "Board.hpp"

using namespace std;

namespace WarGame {
    Soldier *&Board::operator[](std::pair<int, int> location) {
        return board[location.first][location.second];
    }

    Soldier *Board::operator[](std::pair<int, int> location) const {
        return board[location.first][location.second];
    }
void WarGame::Board::move(uint player_number, std::pair<int, int> source, Board::MoveDIR direction) {
    cout<< "pair first: " << source.first<<endl;
    cout<< "pair secend: " << source.second<<endl;
    if(board[source.first][source.second]== nullptr ||
    board[source.first][source.second]->getnum()!=player_number){
        cout<<"exption"<<endl;
        throw exception();
    }

         Soldier *s = WarGame::Board::board[source.first][source.second];
         int source_x = source.first;
         int source_y = source.second;
    pair<int, int> point;

    switch (direction) {
             case WarGame::Board::Up:
                 if (((source.first + 1) < Board::board.size() )&&
                 board[source_x+1][source_y]== nullptr) {
                     Board::board[source_x][source_y] = nullptr;
                     Board::board[source_x + 1][source_y] = s;
                     //pair<int, int> point;
                     point.first = source_x + 1;
                     point.second = source_y;
                  //  s->Fight(board,point);
                    // chack_type_AND_action(s, point);
                 }else{
                     throw exception();
                 }
                 break;
             case WarGame::Board::Down:
                 if (((source.first - 1) < Board::board.size()) &&
                 ( board[source_x-1][source_y]== nullptr)) {
                     Board::board[source_x][source_y] = nullptr;
                     Board::board[source_x - 1][source_y] = s;
                    // pair<int, int> point;
                     point.first = source_x - 1;
                     point.second = source_y;
                    // s->Fight(board,point);
                 }else{
                     throw exception();
                 }
                 break;
             case WarGame::Board::Left:
                 if (((source.second -1) < Board::board[0].size()) &&
                 board[source_x][source_y-1]== nullptr) {
                     Board::board[source_x][source_y] = nullptr;
                     Board::board[source_x][source_y-1 ] = s;
                    // pair<int, int> point;
                     point.first = source_x;
                     point.second = source_y-1;
                    // s->Fight(board,point);
                 }else{
                     throw exception();
                 }
                 break;
             case WarGame::Board::Right:
                 if (((source.second + 1) < Board::board[0].size()) &&
                         board[source_x][source_y+1]== nullptr) {
                     Board::board[source_x][source_y] = nullptr;
                     Board::board[source_x][source_y+1] = s;
                     point.first = source_x;
                     point.second = source_y+1;
                    // s->Fight(board,point);
                 }else{
                     throw exception();
                 }
                 break;
         }
    cout<<"asdasdas"<<endl;
    cout<<"point first: "<<point.first<<endl;
    cout<<"point secend: "<<point.second<<endl;

    board[point.first][point.second]->Fight(board,point);
     }
    void Board::printboard() {
        for (int i = 0; i < this->board.size(); i++) {
            for (int j = 0; j < this->board[i].size(); j++) {
                if (this->board[i][j])  //!=NULL

                    cout <<"  "<<this->board[i][j]->getnum() <<"  "<< this->board[i][j]->getCurrHP() ;
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
    /*void Board::move(uint player_number, std::pair<int, int> source, MoveDIR direction) {
        Soldier *src = board[source.first][source.second];
        if (src == nullptr) {
            throw invalid_argument("No player on source");
        }
        if (src->getnum() != player_number) {
            throw invalid_argument("Wrong player number");
        }
        // Up, Down, Right, Left
        pair<int, int> dest;
        switch (direction) {
            case Up :
                dest = make_pair(source.first + 1, source.second);
                break;
            case Down :
                dest = make_pair(source.first - 1, source.second);
                break;
            case Right :
                dest = make_pair(source.first, source.second + 1);
                break;
            case Left :
                dest = make_pair(source.first, source.second - 1);
                break;

        }
        if (dest.first < 0 || dest.second < 0 || dest.first >= board.size() ||
            dest.second >= board[dest.first].size()) {
            throw invalid_argument("out of bounds");
        }
        if (board[dest.first][dest.second] != nullptr) {
            throw invalid_argument("trying to move to a allocated space");
        }
        board[dest.first][dest.second] = src;
        board[source.first][source.second] = nullptr;
        src->Fight(board, dest);
    }*/

    bool Board::has_soldiers(uint player_number) const {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                Soldier *s = board[i][j];
                if (s != nullptr) {
                    if (s->getnum() == player_number) {
                        return true;
                    }

                }
            }
        }
        return false;
    }

}