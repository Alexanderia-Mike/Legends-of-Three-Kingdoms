//
//  askforhelp.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/15.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

int askhelp(playerp head, playerp p, cards* card, int numofcard, int* reveal, int* nump, int demo){
    if (demo==0){
        playerp q=head->next; int d;
        while (q!=NULL){
            system("clear");
            printf("please give the screen to another player\n");
            pauseprogram();
            listtitle(q, reveal, nump, head);
            printf("%s is dying, do you want to save him?(1 for yes and 0 for no)\n", p->player.name);
            scanf("%d", &d);
            if (d){
                peach(p, card, numofcard);
                system("clear");
                printf("please give the screen to another player\n");
                pauseprogram();
                printf("you recieve help from %s\n", q->player.name);
                return 1;
            }
        }
        system("clear");
        printf("please give the screen to another player\n");
        pauseprogram();
        printf("very unfortunate, no one could help you, so you die\n");
        return 0;
    }
    else{
        playerp q=head->next; int d;
        while (q!=NULL){
            system("clear");
            printf("please give the screen to another player\n");
            pauseprogram();
            listtitle(q, reveal, nump, head);
            printf("%s is dying, do you want to save him?(1 for yes and 0 for no)\n", p->player.name);
            d=rand()%2;
            printf("%d", d);
            pauseprogram();
            if (d){
                peach(p, card, numofcard);
                system("clear");
                printf("please give the screen to another player\n");
                pauseprogram();
                printf("you recieve help from %s\n", q->player.name);
                return 1;
            }
        }
        system("clear");
        printf("please give the screen to another player\n");
        pauseprogram();
        printf("very unfortunate, no one could help you, so you die\n");
        return 0;
    }
}
