#pragma once
#include <iostream>
#include <vector>

using namespace std;
// namespace WarGame
// {
class Soldier
{

private:
    int HP;
    int max_HP;
    int damage;
    int num;

public:
    Soldier(int max, int damage, int num) : max_HP(max),HP(max), damage(damage), num(num) {}
    virtual ~Soldier() {};
    virtual void Fight(vector<vector<Soldier *>> &board, pair<int, int> dest) = 0;
    uint getnum() { return this->num; };
    void set_HP(int num) { this->HP = num; };
    uint getCurrHP() { return this->HP; };
    uint getdamage() { return this->damage; };
    uint getMaxHP() { return this->max_HP;};
};