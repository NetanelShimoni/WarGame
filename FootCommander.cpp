#include "FootCommander.hpp"
// namespace WarGame{
void FootCommander::Fight(vector<vector<Soldier *> > &board, pair<int, int> dest) {
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[i].size();j++)
        {
            Soldier *s = board[i][j];
            if(s!=nullptr)
            {
                if(FootSoldier *fs = dynamic_cast<FootSoldier*> (s))
                {

                    FootCommander *fc = dynamic_cast<FootCommander*> (s);
                    if((fc == nullptr) || (i == dest.first && j==dest.second))
                    {
                        if(fs->getnum() == board[dest.first][dest.second]->getnum())
                        {
                            fs->FootSoldier::Fight(board,make_pair(i,j));

                        }
                    }


                }
            }
        }
    }
}