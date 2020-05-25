//
// Created by netanel & Or on 25/05/2020.
//

#ifndef WARGAME_SOLDIER_HPP
#define WARGAME_SOLDIER_HPP
class Soldier{
public:
    int health;
    int damage;
    int num_player;
    int hp;

public:
    Soldier(int h,int d,int num_p):health(h),damage(d),num_player(num_p){}
    Soldier(int h,int d,int hp,int num_p):health(h),damage(d),num_player(num_p) , hp(hp){}
    int get_health(){return health;}
    void set_health(int health){this->health=health;}
    int get_damage(){return damage;}
    int get_num_player(){return num_player;}

    virtual ~Soldier(){
    }
};





#endif //WARGAME_SOLDIER_HPP
