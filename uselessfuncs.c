#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<time.h>
#include"functions.h"

void control_stairs_generate(struct position**first)    //bug exists
{
    struct position*check=*first;
    COORD current_xy,check_xy;
    while(check)
    {
        if(check->pnext==NULL)   //if there is only one stairs exists
        {
            break;
        }
        check_xy=check->pos;

        while(*first)
        {
            if(check==*first)   //don't check itself
            {
                *first=(*first)->pnext;
                continue;
            }
            current_xy=(*first)->pos;
            if(current_xy.Y-check_xy.Y<3)   //two stairs' y axis are less than 3
            {
                if((current_xy.X-8<check_xy.X)||(current_xy.X+8>check_xy.X))
                {
                    struct position*free_bad_stairs=*first;
                    if((*first)->pnext==NULL)
                    {
                        free(free_bad_stairs);
                        //*first=NULL;
                        break;
                    }
                    else
                    {
                        (*first)->pformer->pnext=(*first)->pnext;
                        *first=(*first)->pnext;
                        free(free_bad_stairs);
                        printf("\033[0mXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
                    }
                }
            }
            else
            {
                *first=(*first)->pnext;
            }
        }
        check=check->pnext;
    }
}

void follow_stairs(COORD *current_xy,struct position*first)
{
    while(first)
    {
        if(first->if_stand==1)
        {
            //current_xy->Y=first->pos.Y-1;
            current_xy->Y--;
            break;
        }
        else
        {
            first=first->pnext;
        }
    }
    current_xy->Y++;
}

void man_crash_stairs(struct position*first,COORD *man_xy,COORD detect_xy)   //if man and stairs(if two floors,only bottom one) overlap
{
    int left_head=man_xy->Y;
    int left_arm=man_xy->Y+1;
    int left_foot=man_xy->Y+2;
    int z=0;
    while(first)
    {
        if(left_head==first->pos.Y)   //touched by head
        {
            if(man_xy->X+1>=first->pos.X&&man_xy->X+1<=first->pos.X+14)   //left head
            {
                z=1;
                break;
            }
            else if(man_xy->X+2>=first->pos.X&&man_xy->X+2<=first->pos.X+14)  //right head
            {
                z=1;
                break;
            }
        }
        else if(left_arm==first->pos.Y)   //touched by hands
        {
            if(man_xy->X>=first->pos.X&&man_xy->X<=first->pos.X+14)   //left arm
            {
                z=1;
                break;
            }
            else if(man_xy->X+3>=first->pos.X&&man_xy->X+3<=first->pos.X+14)
            {
                z=1;
                break;
            }
        }
        else if(left_foot==first->pos.Y)   //touched by feet
        {
            if(man_xy->X+1>=first->pos.X&&man_xy->X+1<=first->pos.X+14)   //left foot
            {
                z=1;
                break;
            }
            else if(man_xy->X+2>=first->pos.X&&man_xy->X+2<=first->pos.X+14)  //right foot
            {
                z=1;
                break;
            }
        }
        first=first->pnext;
    }
    if(z==1)
    {
        *man_xy=detect_xy;
        cover_man(detect_xy,*man_xy);
        man(detect_xy);
    }
}
