#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<time.h>
#include"functions.h"

#define life_total 10

struct position*first_stairs=NULL;
struct position*last_stairs=NULL;

void border()
{
    int i,j,k;
    for(i=0;i<49;i++)   //y
    {
        for(j=0;j<80;j++)      //x
        {
            if(i==1&&j==1)
            {
                for(k=0;k<39;k++)
                {
                    printf("\033[1m¡¿");
                }
                printf("\33[44m  ");
                break;
            }
            if(i==0||i==48)
            {
                for(k=0;k<82;k++)
                {
                    printf("\33[44m \33[m");
                }
                break;
            }
            else
            {
                if(j==0||j==79)
                {
                    printf("\33[44m  \33[m");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

void life(int life_number)
{
    int i;
    COORD xy;
    xy.X=85;
    xy.Y=40;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy);
    printf("\033[1mLife: [ \033[m");
    if(life_number>5)
    {
        for(i=0;i<life_number;i++)
        {
            printf("\033[1m\033[32m¢p ");    //green
        }
    }
    else if(life_number<=5&&life_number>=3)
    {
        for(i=0;i<life_number;i++)
        {
            printf("\033[1m\033[33m¢p ");    //yellow
        }
    }
    else if(life_number<3)
    {
        for(i=0;i<life_number;i++)
        {
            printf("\033[1m\033[31m¢p ");    //red
        }
    }
    for(i=life_number;i<life_total;i++) //covered
    {
        printf("\033[0m\033[30m¢p ");    //black
    }
    printf("\033[1m\033[37m ]");
}

void stairs_level(int current_stairs)
{
    COORD xy;
    xy.X=85;
    xy.Y=35;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy);
    printf("\33[1mLevel: %d\33[0m",current_stairs);
}

void show_score(int s)
{
    COORD xy;
    xy.X=85;
    xy.Y=33;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy);
    printf("\033[1mScore: %d \033[0m",s);
}

void time_show(time_t t1,time_t t2)
{
    int t=t2-t1;
    COORD xy;
    xy.X=85;
    xy.Y=37;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy);
    printf("\33[1mTime: %d (sec)\33[0m",t);
}

void information()
{
    int i;
    COORD xy;
    xy.X=86;
    xy.Y=8;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy);
    printf("\33[1m\33[45m Stairs Type \33[0m");
    xy.X=103;
    xy.Y=8;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy);
    printf("\33[1m\33[43m Property \33[0m");
    xy.X=85;
    xy.Y=11;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy);
    normal_stairs();
    printf("\33[1m    Normal \33[0m");
    xy.X=85;
    xy.Y=14;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy);
    sharp_stairs(xy);
    xy.X=102;
    xy.Y=14;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy);
    printf("\33[1m Life Minus 3 \33[0m");
    xy.X=85;
    xy.Y=17;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy);
    movingR_stairs(xy);
    xy.X=102;
    xy.Y=17;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy);
    printf("\33[1m Moving Right \33[0m");
    xy.X=85;
    xy.Y=20;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy);
    movingL_stairs(xy);
    xy.X=102;
    xy.Y=20;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy);
    printf("\33[1m Moving Left \33[0m");
    xy.X=87;
    xy.Y=23;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy);
    for(i=0;i<6;i++)
    {
        printf("\033[1m¡¿\33[0m");
    }
    xy.X=102;
    xy.Y=23;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy);
    printf("\33[1m Life Minus 3 \33[0m");
}

void normal_stairs()
{
    printf("\033[1m\033[33m¢p ¢p ¢p ¢p ¢p ¢p ¢p \033[m");  //red
}

void sharp_stairs(COORD xy)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy);
    printf("\033[1m\033[31m|¡¶¡¶¡¶¡¶¡¶¡¶|\033[0m");
    xy.Y--;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy);
    printf("\033[1m\033[35m______________\033[0m");
}

void movingR_stairs(COORD xy)   //right
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy);
    printf("\033[1m\033[36m| -> -> -> -> |\033[0m");
    xy.Y--;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy);
    printf("\033[1m\033[36m_______________\033[0m");
}

void movingL_stairs(COORD xy)   //left
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy);
    printf("\033[1m\033[32m| <- <- <- <- |\033[0m");
    xy.Y--;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy);
    printf("\033[1m\033[32m_______________\033[0m");
}

void cover_stairs()
{
    printf("\033[40m               \033[0m");
}

void man(COORD current_xy)
{
    int j=current_xy.Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),current_xy);
    printf(" ¡´");
    current_xy.Y=j+1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),current_xy);
    printf("/¢p \\");
    current_xy.Y=j+2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),current_xy);
    printf(" /\\");
}

void cover_man(COORD current_xy,COORD last_xy)
{
    if(current_xy.X!=last_xy.X||current_xy.Y!=last_xy.Y)
    {
        if(current_xy.X>last_xy.X)    //right and down
        {
            last_xy.Y-=1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),last_xy);
            printf("\033[40m    \33[0m");
            last_xy.Y-=1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),last_xy);
            printf("\033[40m    \33[0m");
            last_xy.Y+=2;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),last_xy);
            printf("\033[40m \33[0m");
            last_xy.Y+=1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),last_xy);
            printf("\033[40m \33[0m");
            last_xy.Y+=1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),last_xy);
            printf("\033[40m \33[0m");
        }
        else if(current_xy.X<last_xy.X)   //left and down
        {
            last_xy.Y-=1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),last_xy);
            printf("\033[40m    \33[0m");
            last_xy.Y-=1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),last_xy);
            printf("\033[40m    \33[0m");
            last_xy.Y+=2;
            last_xy.X+=2;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),last_xy);
            printf("\033[40m \33[0m");
            last_xy.X+=1;
            last_xy.Y+=1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),last_xy);  //right hand
            printf("\033[40m  \33[0m");
            last_xy.X-=1;
            last_xy.Y+=1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),last_xy);
            printf("\033[40m \33[0m");
        }
    }
    if(current_xy.X!=last_xy.X&&current_xy.Y==last_xy.Y)    //horizontal
    {
        if(current_xy.X>last_xy.X)  //moving right
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),last_xy);
            printf("\033[40m \33[0m");
            last_xy.Y+=1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),last_xy);
            printf("\033[40m \33[0m");
            last_xy.Y+=1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),last_xy);
            printf("\033[40m \33[0m");
        }
        else if(current_xy.X<last_xy.X) //moving left
        {
            last_xy.X+=2;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),last_xy);
            printf("\033[40m \33[0m");
            last_xy.X+=1;
            last_xy.Y+=1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),last_xy);  //right hand
            printf("\033[40m  \33[0m");
            last_xy.X-=1;
            last_xy.Y+=1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),last_xy);
            printf("\033[40m \33[0m");
        }
    }
    else if(current_xy.X==last_xy.X&&current_xy.Y!=last_xy.Y)   //vertical
    {
        if(current_xy.Y>last_xy.Y)  //moving down
        {
            last_xy.Y-=1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),last_xy);
            printf("\033[40m    \33[0m");
            last_xy.Y+=1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),last_xy);
            printf("\033[40m    \33[0m");
            last_xy.Y+=1;
            last_xy.X+=3;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),last_xy);  //right hand
            printf("\033[40m \33[0m");
        }
        else if(current_xy.Y<last_xy.Y) //moving up
        {
            last_xy.Y+=2;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),last_xy);
            printf("\033[40m    \33[0m");
            last_xy.Y-=1;
            last_xy.X+=3;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),last_xy);  //right hand
            printf("\033[40m \33[0m");
        }
    }
}

int exceed_Hborder(COORD xy)
{
    if(xy.X<2)
    {
        return 1;
    }
    if(xy.X>75)
    {
        return 1;
    }
    return 0;
}

int exceed_Vborder(COORD *man_xy,int *life)
{
    if(man_xy->Y+2>=48)    //arrive bottom border
    {
        return 1;
    }
    else if(man_xy->Y<=2)    //arrive top border
    {
        *life-=3;
        if(*life<=0)
        {
            *life=0;
        }
        man_xy->Y+=3;
        return 2;
    }
    return 0;
}

int direction(COORD *current_xy)    //keyboard control
{
    if(GetAsyncKeyState(0x41))  //a(left)
    {
        current_xy->X-=1;
        if(exceed_Hborder(*current_xy))
        {
            current_xy->X+=1;
        }
        return 0;
    }
    if(GetAsyncKeyState(0x44))  //d(right)
    {
        current_xy->X+=1;
        if(exceed_Hborder(*current_xy))
        {
            current_xy->X-=1;
        }
        return 0;
    }
    return 0;
}

int generate_stairs(int type)  //stairs length=14
{
    srand(time(NULL));
    struct position* stairs=(struct position*)malloc(sizeof(struct position));
    struct position*check=first_stairs;
    int a,b,z;
    while(1)
    {
         a=rand()%7;
         b=rand()%9;
         z=10*a+b;
         if(z>2&&z<66)
         {
             break;
         }
    }

    while(check)        //control stairs generate,seperate any two stairs which stick together
    {
        if(check->pnext==NULL)  //if there is only one stairs exists
        {
            break;
        }
        if(47-check->pos.Y<4)
        {
            if((z-8<check->pos.X)||(z+8>check->pos.X))  //stop generating this stairs
            {
                return 1;
            }
        }
        check=check->pnext;
    }

    stairs->pos.Y=47;       //initialize the stairs,where the stairs generated from
    stairs->pos.X=z;
    stairs->stairs_type=type;
    stairs->pnext=NULL;
    stairs->if_stand=0;

    if(first_stairs==NULL)
    {
        first_stairs=stairs;
        last_stairs=stairs;
    }
    else
    {
        stairs->pformer=last_stairs;
        last_stairs->pnext=stairs;      //the last struct point to next struct, means current struct
        last_stairs=stairs;             //assume the current struct is the last struct
    }
    return 0;
}

void print_stairs(struct position*first)
{
    struct position*current_stairs=first;    //a pointer to run all data from beginning
    COORD old_stairs;

    while(1)
    {
        old_stairs=current_stairs->pos;

        if(old_stairs.Y==47)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), old_stairs);
        }
        else
        {
            old_stairs.Y+=1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), old_stairs);  //remove old stairs
            cover_stairs();
            old_stairs.Y-=1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), old_stairs);  //create new stairs
        }

        switch(current_stairs->stairs_type)
        {
        case 1:
            normal_stairs();
            break;
        case 2:
            sharp_stairs(old_stairs);
            break;
        case 3:
            movingR_stairs(old_stairs);
            break;
        case 4:
            movingL_stairs(old_stairs);
        }
        if(current_stairs->pnext==NULL)
        {
            break;
        }
        current_stairs=current_stairs->pnext;
    }
}

void update_stairs_position(struct position*first)
{
    struct position*current_stairs=first;
    while(1)
    {
        if(current_stairs==NULL)
        {
            break;
        }
        else
        {
            current_stairs->pos.Y-=1;
            current_stairs=current_stairs->pnext;
        }
    }
}

void free_stairs_struct(struct position**first)     //free the memory and cover up the remain stairs
{
    while(1)
    {
        int z;
        if((*first)->stairs_type==1)
        {
            z=3;
        }
        else
        {
            z=4;
        }
        if((*first)->pos.Y<z)   //arrive the top border
        {
            struct position*free_stairs_position=NULL;
            free_stairs_position=*first;
            if((*first)->pnext==NULL)
            {
                *first=NULL;
                break;
            }
            else
            {
                if((*first)->stairs_type==1)   //clean the stairs which is at the top of the border
                {
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(*first)->pos);
                    cover_stairs();
                }
                else
                {
                    (*first)->pos.Y-=1;
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(*first)->pos);
                    cover_stairs();
                    (*first)->pos.Y+=1;
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(*first)->pos);
                    cover_stairs();
                }
                *first=(*first)->pnext;
                (*first)->pformer=NULL;
                free(free_stairs_position);
            }
        }
        else
        {
            break;
        }
    }
}

void man_on_stairs(COORD man_xy,struct position*first) //find out the man standing on which stairs
{
    int y=man_xy.Y+2;
    int x1=man_xy.X+1; //left foot
    int x2=man_xy.X+2; //right foot
    while(first)
    {
        if(y==first->pos.Y-1)
        {
            if((x1>=first->pos.X)&&(x1<=first->pos.X+14))
            {
                first->if_stand=1;
            }
            else if((x2>=first->pos.X)&&(x2<=first->pos.X+14))
            {
                first->if_stand=1;
            }
            else
            {
                first->if_stand=0;
            }
        }
        first=first->pnext;
    }
}

int stairs_static(struct position*first)    //if the man is standing on the stairs
{
    int z=0;
    while(first)
    {
        if(first->if_stand==1)
        {
            z=first->stairs_type;
            break;
        }
        first=first->pnext;
    }
    if(z!=0)    //stand
    {
        return z;
    }
    else if(z==0)   //not stand
    {
        return 0;
    }
    return 0;
}

int stairs_vs_life(struct position*first,int *life) //condition between life and stairs
{
    while(first)
    {
        if(first->if_stand==1)
        {
            if(first->stairs_type==2)   //sharp stairs
            {
                (*life)-=3;
                if((*life)<=0)
                {
                    (*life)=0;
                }
                return 2;
            }
            else if(first->stairs_type==1)  //normal stairs
            {
                (*life)++;
                if((*life)>10)
                {
                    (*life)=10;
                }
                return 1;
            }
            else if(first->stairs_type==3)  //moving right stairs
            {
                (*life)++;
                if((*life)>10)
                {
                    (*life)=10;
                }
                return 3;
            }
            else if(first->stairs_type==4)  //moving left stairs
            {
                (*life)++;
                if((*life)>10)
                {
                    (*life)=10;
                }
                return 4;
            }
        }
        first=first->pnext;
    }
    return 0;
}

void game_start()
{
    srand(time(NULL));
    int life_number=10;
    int current_level=0;
    int score=0;
    int stairs_freq=1;      //stairs_freq can not equal update_freq,bug will occur
    int update_freq=11;
    int drop_speed=5;       //drop speed smaller than update_freq
    int switch_stairs=0;    //static variable
    COORD current_xy,last_xy;
    time_t t1,t2;

    current_xy.X=rand()%74+2;
    current_xy.Y=rand()%20+3;
    last_xy.X=current_xy.X;
    last_xy.Y=current_xy.Y;

    t1=time(NULL);
    information();
    while(1)
    {
        t2=time(NULL);
        time_show(t1,t2);
        show_score(score++);
        life(life_number);
        stairs_level(current_level);

        last_xy.X=current_xy.X;
        last_xy.Y=current_xy.Y;
        direction(&current_xy);     //control direction by keyboard

        if(score%stairs_freq==0)
        {
            generate_stairs(rand()%4+1);    //formula(rand()%(most-less+1)+less)
        }

        man_on_stairs(current_xy,first_stairs); //detect the man if on which stairs
        if(stairs_static(first_stairs)==0)
        {
            if(score%drop_speed==0)
            {
                current_xy.Y+=1;
            }
        }
        else
        {
            if(score%update_freq==0)
            {
                current_xy.Y--;
            }
        }

        if(stairs_static(first_stairs)==3)  //right moving stairs' affect
        {
            if(score%2==0)
            {
                current_xy.X++;
                if(exceed_Hborder(current_xy))
                {
                    current_xy.X--;
                }
                cover_man(current_xy,last_xy);
                man(current_xy);
            }
        }
        else if(stairs_static(first_stairs)==4) //left moving stairs' affect
        {
            if(score%2==0)
            {
                current_xy.X--;
                if(exceed_Hborder(current_xy))
                {
                    current_xy.X++;
                }
                cover_man(current_xy,last_xy);
                man(current_xy);
            }
        }

        if(first_stairs!=NULL)
        {
            if(switch_stairs==0)
            {
                if(stairs_static(first_stairs))
                {
                    stairs_vs_life(first_stairs,&life_number);
                    switch_stairs=1;
                    current_level++;
                }
            }
            else if(stairs_static(first_stairs)==0)
            {
                switch_stairs=0;
            }

            cover_man(current_xy,last_xy);
            print_stairs(first_stairs);
            man(current_xy);
            free_stairs_struct(&first_stairs);
        }

        if(score%update_freq==0)
        {
            update_stairs_position(first_stairs);
        }

        if(exceed_Vborder(&current_xy,&life_number)==1)
        {
            life(0);
            break;
        }
        else if(exceed_Vborder(&current_xy,&life_number)==2)
        {
            cover_man(current_xy,last_xy);
            man(current_xy);
        }

        if(current_level>0)     //adjust game difficulty
        {
            if(current_level%7==0)
            {
                if(update_freq>2&&((update_freq-1)>drop_speed)&&((update_freq-1)%drop_speed!=0))
                {
                    update_freq--;
                }
            }
            if(current_level%13==0&&(update_freq%(drop_speed-1)!=0))
            {
                if(drop_speed>1)
                {
                    drop_speed--;
                }
            }
        }

        if(life_number==0)  //gameover
        {
            life(life_number);
            break;
        }

        Sleep(10);
    }
}

void game_over()
{
    int i,j;
    COORD xy;
    xy.X=0;
    xy.Y=0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy);
    for(i=0;i<49;i++)
    {
        for(j=0;j<82;j++)
        {
            printf("\33[1m\033[46m \033[0m");
        }
        printf("\n");
        Sleep(10);
    }
    xy.X=34;
    xy.Y=24;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy);
    printf("\33[1m\33[43m\33[37m Game Over \33[0m\n");
    xy.X=0;
    xy.Y=49;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy);
}

