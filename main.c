#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include"functions.h"

int main()
{
    system("mode con cols=120 lines=50");
    system("title Go Down Stairs");
    border();
    game_start();
    game_over();
    system("PAUSE");
    return 0;
}
