//controlling stairs position
struct position
{
    COORD pos;
    int stairs_type;
    int if_stand;       //1=stand,0=not stand
    struct position*pnext;
    struct position*pformer;
};

//background setting
void border();
void life(int life_number);
void stairs_level(int current_stairs);
void show_score(int s);
void time_show(time_t t1,time_t t2);
void information();

//objects
void man(COORD current_xy);
void cover_man(COORD current_xy,COORD last_xy);

void normal_stairs();
void sharp_stairs();
void movingR_stairs(COORD xy);  //moving right
void movingL_stairs(COORD xy);  //moving left
void cover_stairs();

//processing function
int exceed_Hborder(COORD xy);   //horizontal
int exceed_Vborder(COORD *man_xy,int *life);   //vertical
int direction(COORD *current_xy);

int generate_stairs(int type);
void update_stairs_position(struct position*first);
void print_stairs(struct position*first_stairs);
void free_stairs_struct(struct position**first);
int stairs_vs_life(struct position*first,int *life);
void man_on_stairs(COORD man_xy,struct position*first);
int stairs_static(struct position*first);
void man_crash_stairs(struct position*first,COORD *man_xy,COORD detect_xy);
void game_start();
void game_over();
//void control_stairs_generate(struct position**first);
//void follow_stairs(COORD *current_xy,struct position*first);


