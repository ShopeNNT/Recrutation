//CODED BY DAWID KRAWCZYK
#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

//prototypy funkcji
int ShowMap();
int Move(int dir);
int LoadMap();
int GetDir(char key);
void PrintInfo();
void PrintHelp();

int map_size=25;
char map_level[25];
bool game_status; //true - game in progress | false - game stopped
char key_input;
int player_position;
int exit_position;
int direction;
int counter_moves;
bool quit=false;


int main()
{
    cout << "Welcome in Maze!" << endl;
    cout << "Press any key to continue" <<endl;
    getch();
    while(!quit)
    {
        game_status=true;
        counter_moves=0;
        if((LoadMap())==0)
        {
            while(game_status)
            {
                system("cls");
                if(player_position==exit_position)
                {
                    game_status=false;
                    cout<<"Game completed. Congratulations!!!"<<endl;
                    break;
                }
                ShowMap();
                cout<<"Moves:"<<counter_moves<<endl;
                cout<<"Press H for help."<<endl;
                key_input=getch();
                if(GetDir(key_input)==0)
                {
                    if(Move(direction)==0)
                    {
                        counter_moves++;
                    }
                }

                //PrintInfo();
            }
        }
    }
    cout<<"THANKS FOR PLAYING"<<endl;
    cout<<"MADE BY DAWID KRAWCZYK"<<endl;
    getch();
    return 0;
}

int LoadMap()
{
    int stage;
    cout<<"Please, enter map's number (1 or 2, 0 to quit)"<<endl;
    cin>>stage;

    char stage_1[map_size]={'#','#','#','#','#',
                            '#','O','#','X','#',
                            '#',' ','#',' ','#',
                            '#',' ',' ',' ','#',
                            '#','#','#','#','#'};
    char stage_2[map_size]={'#','#','#','#','#',
                            '#','O',' ',' ','#',
                            '#','#','#',' ','#',
                            '#','X',' ',' ','#',
                            '#','#','#','#','#'};

    switch(stage)
    {
    case 0:
        quit=true;
        return 1;
    case 1:
        for(int i=0;i<map_size;i++)
        {
            map_level[i]=stage_1[i];
        }
        player_position=6;
        exit_position=8;
        break;
    case 2:
        for(int i=0;i<map_size;i++)
        {
            map_level[i]=stage_2[i];
        }
        player_position=6;
        exit_position=16;
        break;
    default:
        cout<<"Map's number is incorrect"<<endl;
        return 1;
    }
    return 0;
}

int ShowMap()
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<map_level[i*5+j];
        }
        cout<<endl;
    }
    return 0;
}

int Move(int dir)
{
    switch(dir)
    {
    case 0: //W
        if(map_level[player_position-5]!='#')
        {
            map_level[player_position]=' ';
            map_level[player_position-5]='O';
            player_position=player_position-5;
        }
        else return 1;
        break;
    case 1: //S
        if(map_level[player_position+5]!='#')
        {
            map_level[player_position]=' ';
            map_level[player_position+5]='O';
            player_position=player_position+5;
        }
        else return 1;
        break;
    case 2: //A
        if(map_level[(player_position-1)]!='#')
        {
            map_level[player_position]=' ';
            map_level[(player_position-1)]='O';
            player_position=player_position-1;
        }
        else return 1;
        break;
    case 3: //D
        if(map_level[player_position+1]!='#')
        {
            map_level[player_position]=' ';
            map_level[player_position+1]='O';
            player_position=player_position+1;
        }
        else return 1;
        break;
    default:
        return 1;
    }
    return 0;

}
int GetDir(char key)
{
    if(key=='w'||key=='W'||key=='Ó')
    {
     direction=0;
     return 0;
    }
    if(key=='s'||key=='S')
    {
     direction=1;
     return 0;
    }
    if(key=='d'||key=='D')
    {
     direction=3;
     return 0;
    }
    if(key=='a'||key=='A')
    {
     direction=2;
     return 0;
    }
    if(key=='h'||key=='H')
    {
        PrintHelp();
    }
    return 1;
}

void PrintInfo()
{
    cout<<"Player position:"<<player_position<<endl;
    cout<<"Direction:"<<direction<<endl;
    cout<<"Key input:"<<(int)key_input<<endl;
}
void PrintHelp()
{
    cout<<"You are O and you must reach X to win"<<endl;
    cout<<"Control:"<<endl;
    cout<<"W - move up"<<endl;
    cout<<"S - move down"<<endl;
    cout<<"A - move left"<<endl;
    cout<<"D - move right"<<endl;
}
