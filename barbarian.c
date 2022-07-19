//
//  barbarian.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/16.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

void barbarian(playerp p, int* nump, cards* card, int numofcard, int* wine, int* playphase, int* drawphase, int* reveal, playerp head, int demo){
    if (demo==0){
        playerp q=head->next; int i=1, health[10];
        while (q!=NULL){
            if (q!=p){
                system("clear");
                printf("please give the screen to another player\n");
                pauseprogram();
                system("clear");
                listtitle(q, reveal, reveal, head);
                cards cardtem[15];
                returncards(cardtem, q, card, numofcard);
                printf("%s used a barbarian invasion, do you want to use a strike?(1 for yes and 0 for no)\n", p->player.name);
                int d; scanf("%d", &d);
                if (d==1){
                    int f=0;
                    for (int k=0; k<numofcard; k++){
                        if (card[k].player[0]==q->player.order && strcmp(card[k].name, "strike")==0){
                            card[k].player[0]=-1;
                            f++;
                            break;
                        }
                    }
                    if (f==0){
                        printf("sorry, you have no strike card, so you recieve 1 damage on your health\n");
                        changehealth(-1, q, nump, card, numofcard, wine, playphase, drawphase, reveal, head, demo);
                        health[i]=1;
                        pauseprogram();
                    }
                    else health[i]=0;
                }
                else {
                    printf("you refuse to play strike, so you recieve 1 damage on your health\n");
                    changehealth(-1, q, nump, card, numofcard, wine, playphase, drawphase, reveal, head, demo);
                    health[i]=1;
                    pauseprogram();
                }
            }
            q=q->next;
            i++;
        }
        i--;
        system("clear");
        listtitle(p, reveal, nump, head);
        q=head->next;
        int k=1;
        while (q!=NULL){
            if (q!=p)
                printf("%s recieve %d damage\n", q->player.name, health[k]);
            q=q->next;
            k++;
        }
    }
    else {
        playerp q=head->next; int i=1, health[10];
        while (q!=NULL){
            if (q!=p){
                system("clear");
                printf("please give the screen to another player\n");
                pauseprogram();
                system("clear");
                listtitle(q, reveal, reveal, head);
                cards cardtem[15];
                returncards(cardtem, q, card, numofcard);
                printf("%s used a barbarian invasion, do you want to use a strike?(1 for yes and 0 for no)\n", p->player.name);
                int d;
                d=rand()%2;
                printf("%d", d);
                pauseprogram();
                if (d==1){
                    int f=0;
                    for (int k=0; k<numofcard; k++){
                        if (card[k].player[0]==q->player.order && strcmp(card[k].name, "strike")==0){
                            card[k].player[0]=-1;
                            f++;
                            break;
                        }
                    }
                    if (f==0){
                        printf("sorry, you have no strike card, so you recieve 1 damage on your health\n");
                        changehealth(-1, q, nump, card, numofcard, wine, playphase, drawphase, reveal, head, demo);
                        health[i]=1;
                        pauseprogram();
                    }
                    else health[i]=0;
                }
                else {
                    printf("you refuse to play strike, so you recieve 1 damage on your health\n");
                    changehealth(-1, q, nump, card, numofcard, wine, playphase, drawphase, reveal, head, demo);
                    health[i]=1;
                    pauseprogram();
                }
            }
            q=q->next;
            i++;
        }
        i--;
        system("clear");
        listtitle(p, reveal, nump, head);
        q=head->next;
        int k=1;
        while (q!=NULL){
            if (q!=p)
                printf("%s recieve %d damage\n", q->player.name, health[k]);
            q=q->next;
            k++;
        }
    }
}
