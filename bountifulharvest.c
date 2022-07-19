//
//  bountifulharvest.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/16.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

void bountiful(cards *card, int numofcard, playerp p, playerp head){
    playerp q=p;
    while (q!=NULL){
        dealcards(card, 1, numofcard, q);
        q=q->next;
    }
    q=head->next;
    while (q!=p){
        dealcards(card, 1, numofcard, q);
        q=q->next;
    }
    for (int k=0; k<numofcard; k++){
        if (card[k].player[0]==p->player.order && strcmp(card[k].name, "bountiful_harvest")==0){
            card[k].player[0]=-1;
            break;
        }
    }
}
