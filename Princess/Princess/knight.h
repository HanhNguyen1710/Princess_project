#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "main.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue);
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue);
void inputline(int array[], string line, int& count);
void outputline(int array[], int& count);
void id_knight(int array[], int count, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown);
float baseDamage(int road_to_koopa, float& baseIndex);
int save_princess(int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue, int& remain_HP,
int road_to_koopa[], int count2);
void levelO(int round, int& level_competitor);
int fight(int& level, int& level_competitor, int HP, int& remain_HP, int road_to_koopa);

#endif // __KNIGHT_H__
