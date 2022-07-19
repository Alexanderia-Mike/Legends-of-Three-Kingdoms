//
//  dodge.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/12.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

int dodge(playerp q, playerp p, cards* card, int numofcard, int *wine, int* nump, int* playphase, int* drawphase, int* reveal, playerp head, int demo){
    if (demo==0){
        system("clear");
        printf("please give the screen to the next player\n");
        pauseprogram();
        listtitle(q, reveal, reveal, head);
        cards cardtem[15];
        returncards(cardtem, q, card, numofcard);
        int d=0;
        for (int k=0; k<15; k++){
            if (strcmp(cardtem[k].name, "dodge")==0) d++;
        }
        printf("you recieve a strike from %s.\n", p->player.name);
        if (d==0){
            if (wine[q->player.order]==0){
                printf("but you have no dodge, so you are damaged by 1 health\n");
                changehealth(-1, q, nump, card, numofcard, wine, playphase, drawphase, reveal, head, demo);
                pauseprogram();
                return 1;
            }
            else{
                printf("but you have no dodge. what's more, you have just used wine, so you're damaged by 2 health\n");
                wine[q->player.order]=0;
                changehealth(-2, q, nump, card, numofcard, wine, playphase, drawphase, reveal, head, demo);
                pauseprogram();
                return 2;
            }
        }
        else{
            printf("do you want to use a dodge?(input 1 for yes, 0 for no)\n");
            int f;
            scanf("%d", &f);
            if (f==1){
                for (int k=0; k<numofcard; k++){
                    if (card[k].player[0]==q->player.order && strcmp(card[k].name, "dodge")==0){
                        card[k].player[0]=-1;
                        break;
                    }
                }
                return 0;
            }
            else{
                if (wine[q->player.order]==1){
                    printf("you reject to dodge and you're drunk, so you are damaged by 2 health\n");
                    changehealth(-2, q, nump, card, numofcard, wine, playphase, drawphase, reveal, head, demo);
                    pauseprogram();
                    return 2;
                }
                else{
                    printf("you reject to dodge, so you are damaged by 1 health\n");
                    changehealth(-1, q, nump, card, numofcard, wine, playphase, drawphase, reveal, head, demo);
                    pauseprogram();
                    return 1;
                }
            }
        }
    }
    else{
        system("clear");
        printf("please give the screen to the next player\n");
        pauseprogram();
        listtitle(q, reveal, reveal, head);
        cards cardtem[15];
        returncards(cardtem, q, card, numofcard);
        int d=0;
        for (int k=0; k<15; k++){
            if (strcmp(cardtem[k].name, "dodge")==0) d++;
        }
        printf("you recieve a strike from %s.\n", p->player.name);
        if (d==0){
            if (wine[q->player.order]==0){
                printf("but you have no dodge, so you are damaged by 1 health\n");
                changehealth(-1, q, nump, card, numofcard, wine, playphase, drawphase, reveal, head, demo);
                pauseprogram();
                return 1;
            }
            else{
                printf("but you have no dodge. what's more, you have just used wine, so you're damaged by 2 health\n");
                wine[q->player.order]=0;
                changehealth(-2, q, nump, card, numofcard, wine, playphase, drawphase, reveal, head, demo);
                pauseprogram();
                return 2;
            }
        }
        else{
            printf("do you want to use a dodge?(input 1 for yes, 0 for no)\n");
            int f;
            f=rand()%2;
            printf("%d", f);
            pauseprogram();
            if (f==1){
                for (int k=0; k<numofcard; k++){
                    if (card[k].player[0]==q->player.order && strcmp(card[k].name, "dodge")==0){
                        card[k].player[0]=-1;
                        break;
                    }
                }
                return 0;
            }
            else{
                if (wine[q->player.order]==1){
                    printf("you reject to dodge and you're drunk, so you are damaged by 2 health\n");
                    changehealth(-2, q, nump, card, numofcard, wine, playphase, drawphase, reveal, head, demo);
                    pauseprogram();
                    return 2;
                }
                else{
                    printf("you reject to dodge, so you are damaged by 1 health\n");
                    changehealth(-1, q, nump, card, numofcard, wine, playphase, drawphase, reveal, head, demo);
                    pauseprogram();
                    return 1;
                }
            }
        }
    }
}
