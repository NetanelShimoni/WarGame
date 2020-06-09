#include "Board.hpp"

using namespace std;

namespace WarGame {
    Soldier *&Board::operator[](std::pair<int, int> location) {
        return board[location.first][location.second];
    }

    Soldier *Board::operator[](std::pair<int, int> location) const {
        return board[location.first][location.second];
    }

    void Board::move(uint player_number, std::pair<int, int> source, MoveDIR direction) {
        Soldier *src = board[source.first][source.second];
        if (src == nullptr) {
            throw invalid_argument("No player on source");
        }
        if (src->get_num_player() != player_number) {
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
    }

    bool Board::has_soldiers(uint player_number) const {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                Soldier *s = board[i][j];
                if (s != nullptr) {
                    if (s->get_num_player() == player_number) {
                        return true;
                    }

                }
            }
        }
        return false;
    }

}