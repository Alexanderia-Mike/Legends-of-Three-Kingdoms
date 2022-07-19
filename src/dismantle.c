//
//  dismantle.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/16.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

void dismantle(playerp p, playerp head, cards* card, int numofcard, int demo){
    if (demo==0){
        playerp q=head->next; int i=1, d;
        printf("please choose the player you want to dismantle:\n");
        while (q!=NULL){
            printf("%d. %s\n", i, q->player.name);
            q=q->next;
            i++;
        }
        scanf("%d", &d);
        q=head;
        for (int k=1; k<=d; k++)
            q=q->next;
        for (int k=0; k<numofcard; k++){
            if (card[k].player[2]==q->player.order){
                card[k].player[2]=0;
                card[k].player[0]=-1;
                printf("the card you dismantle from %s is %s\n", q->player.name, card[k].name);
                pauseprogram();
                break;
            }
        }
        for (int k=0; k<numofcard; k++){
            if (card[k].player[0]==p->player.order && strcmp(card[k].name, "dismantle")==0){
                card[k].player[0]=-1;
                break;
            }
        }
    }
    else{
        playerp q=head->next; int i=1, d;
        printf("please choose the player you want to dismantle:\n");
        while (q!=NULL){
            printf("%d. %s\n", i, q->player.name);
            q=q->next;
            i++;
        }
        d=rand()%(i-1)+1;
        printf("%d", d);
        pauseprogram();
        q=head;
        for (int k=1; k<=d; k++)
            q=q->next;
        for (int k=0; k<numofcard; k++){
            if (card[k].player[2]==q->player.order){
                card[k].player[2]=0;
                card[k].player[0]=-1;
                printf("the card you dismantle from %s is %s\n", q->player.name, card[k].name);
                pauseprogram();
                break;
            }
        }
        for (int k=0; k<numofcard; k++){
            if (card[k].player[0]==p->player.order && strcmp(card[k].name, "dismantle")==0){
                card[k].player[0]=-1;
                break;
            }
        }
    }
}
