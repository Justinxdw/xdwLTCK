#include "allfunc.h"

int keyboard_coordinate[16][6] = {
    {750,621,796,672,0,0},
    {816,621,862,672,0,0},
    {882,621,928,672,0,0},
    {948,621,994,672,0,0},
    {750,555,796,606,0,0},
    {816,555,862,606,0,0},
    {882,555,928,606,0,0},
    {948,555,994,606,0,0},
    {750,489,796,540,0,0},
    {816,489,862,540,0,0},
    {882,489,928,540,0,0},
    {948,489,994,540,0,0},
    {750,423,796,474,0,0},
    {816,423,862,474,0,0},
    {882,423,928,474,0,0},
    {948,423,994,474,0,0}
}; // МќХЬзјБъ


void key_press(){
    int i;
    for(i=0;i<16;i++){
        if(mouse_press(keyboard_coordinate[i][0]-4,keyboard_coordinate[i][1]-4,keyboard_coordinate[i][2]+4,keyboard_coordinate[i][3])==1){
            replace_color(keyboard_coordinate[i][0]-4,keyboard_coordinate[i][1]-4,keyboard_coordinate[i][2]+4,keyboard_coordinate[i][3], 0x66ff66, 0xff00ff);
            if(keyboard_coordinate[i][4] == 0){
                keyboard_coordinate[i][4] = 1;
            }else{
                keyboard_coordinate[i][4] = 0;
            }
        }
    }
}