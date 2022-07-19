//
//  project.h
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/10/27.
//  Copyright © 2018 娄辰飞. All rights reserved.
//
#ifdef __APPLE__
#include <GLUT/glut.h>
#elif _WIN32
#include <windows.h>
#include <GL/freeglut.h>
#else
#include <GL/freeglut.h>
#endif
#ifndef project_h
#define project_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

typedef struct _cards{
    //char* type;
    char name[30];
    //int function;
    char number[5];
    int function;// 1 represents equipment card; 2 represents fate card; 0 represents others. 
    int player[3];// for [0]: 0 represents the card is in deck; -1 represents the card is in discard pile; and a positive integer represents its owner and !!! in his hands!!!!!!!.
    // for [1]: if zero, then it is not in any fate zone. otherwise, it is in the fate zone of the player with the according number.
    // for [2]: if zero, than it is not in any equipment zone. otherwise, it is in the equipment zone of the player with the according number.
    char color[10];// the number of the cards
/*    int fatezone;// if 0, then it is not in any fate zone. otherwise, it is in the fate zone of the player with the according number.
    int equipmentzone;// if zero, than it is not in any equipment zone. otherwise, it is in the equipment zone of the player with the according number. */
} cards;

typedef struct _players{
    char name[30];// the player should have a name to specify him, such as "player 1"
    char identity[15];// general or mercenary
    //int position;// the order of players in one turn. 1 represents the first and so on.
    int health;// the health value
    int initialhealth;
    char country[5];// if identity is general.
    int order;
}players;
/*
typedef struct _cardlist{
    char name[30];
    char color[10];
    char number[5];
    int player;// 0 represents the card is in deck; -1 represents the card is in discard pile; and a positive integer represents its owner. 
    struct _cardlist *next;
} Node, *node;
*/

typedef struct _playerlist{
    /*    char name[30];
     char identity[15];
     int health;
     char country[5];*/
    players player;
    struct _playerlist *pre;
    struct _playerlist *next;
} playerlist, *playerp;


int distance(playerp p1, playerp p2, int* nump, cards* card, int numofcard);// the distance of playerth2 when observing from playerth1. 
void cardsinitial(cards* card, int *numofcard, FILE* fp);
void playersinitial(players *player, int *nump);
void shuffle(cards* card, int numofcard);
void fatezone(cards card);
//node cardinlist(cards* card, int numofcard, int* shuord);
void dealcards(cards* card, int n, int numofcard, playerp p);// n represents the number of cards that should be deat; playerth represents which player would accept the dealing.
void shufflediscard(cards* card, int numofcard);// to shuffle the cards in discard pile when all cards in deck are dealt.
cards* testifyfate(cards* card, int numofcard);
void fate(cards *card, playerp p, int numofcard, int* nump, int* playphase, int* drawphase, int* wine, int* reveal, playerp head, int demo);
void returncards(cards *cardtem, playerp p, cards* card, int numofcard);
playerp createlistofplayers(players *player, int* nump);
int attackrange(playerp p, int numofcard, cards* card);
void pauseprogram(void);
void peach(playerp p, cards* card, int numofcard);
void checksuccess(int* reveal, int* nump, playerp head);
void listtitle(playerp p, int* reveal, int* nump, playerp head);
void revealidentity(playerp p, int* reveal);
void discard(playerp p, cards* cardtem, cards* card, int numofcard, int demo);
void arrowbarrage(playerp p, cards* card, int numofcard, int *wine, int* nump, int* playphase, int* drawphase, int* reveal, playerp head, int demo);
void peachgarden(int* nump, cards* card, int numofcard, int* wine, int* playphase, int* drawphase, int* reveal, playerp head, int demo);
void winef(playerp p, int *wine, cards* card, int numofcard);
void sthfornth(cards *card, int numofcard, playerp p);
void bountiful(cards *card, int numofcard, playerp p, playerp head);
void lightning(int numofcard, cards* card, playerp p, playerp head);
void drown(int numofcard, cards* card, playerp p, playerp head);
void starv(int numofcard, cards* card, playerp p, playerp head);
void bino(int numofcard, playerp p, cards* card);
void bow(int numofcard, playerp p, cards* card);
void horse(int numofcard, playerp p, cards* card);
void cardswitharg(int argc, const char* argv[], cards* card, int* numofcard);



int changehealth(int i, playerp p, int* nump, cards* card, int numofcard, int* wine, int* playphase, int* drawphase, int* reveal, playerp head, int demo);
void strike(playerp p, playerp head, cards* card, int *wine, int numofcard, int* nump, int* playphase, int* drawphase, int* reveal, int demo);
int dodge(playerp q, playerp p, cards* card, int numofcard, int *wine, int* nump, int* playphase, int* drawphase, int* reveal, playerp head, int demo);
void playcard(int* playphase, int* drawphase, playerp p, cards* card, int* nump, int numofcard, int* wine, playerp head, int* reveal, int demo);
int askhelp(playerp head, playerp p, cards* card, int numofcard, int* reveal, int* nump, int demo);
void dismantle(playerp p, playerp head, cards* card, int numofcard, int demo);
void snatch(playerp p, playerp head, cards* card, int numofcard, int* nump, int demo);
void borrowedsword(playerp p, playerp head, int *nump, int *reveal, int *wine, int *playerphase, int *drawphase, int numofcard, cards *card, int demo);
void barbarian(playerp p, int* nump, cards* card, int numofcard, int* wine, int* playphase, int* drawphase, int* reveal, playerp head, int demo);


#endif /* project_h */
