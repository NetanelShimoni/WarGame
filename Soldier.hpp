//
// Created by netanel & Or on 25/05/2020.
//

#ifndef WARGAME_SOLDIER_HPP
#define WARGAME_SOLDIER_HPP
#include <vector>
class Soldier{
public:
    int health;
    int damage;
    int num_player;
    int hp;
    int max;

public:
    Soldier(int h,int d,int num_p,int max):health(h),damage(d),num_player(num_p), max(max){}
    //Soldier(int h,int d,int hp,int num_p):health(h),damage(d),num_player(num_p) , hp(hp){}
    int get_health(){return health;}
   // virtual void Fight(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> location)=0;
    void set_health(int health){this->health=health;}
    int get_damage(){return damage;}
    int get_num_player(){return num_player;}
    virtual void Fight(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> dest)=0;

    virtual ~Soldier(){
    }
};





#endif //WARGAME_SOLDIER_HPP
