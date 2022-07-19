//
//  discard.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/15.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

void discard(playerp p, cards* cardtem, cards* card, int numofcard, int demo){
    if (demo==0){
        printf("please choose the card you want to throw to the discard pile:\n");
        returncards(cardtem, p, card, numofcard);
        int d;
        scanf("%d", &d);
        printf("the card you just threw away is %s\n", cardtem[d].name);
        for (int k=0; k<numofcard; k++){
            if (card[k].player[0]==p->player.order && strcmp(card[k].name, cardtem[d].name)==0){
                card[k].player[0]=-1;
                break;
            }
        }
    }
    else{
        printf("please choose the card you want to throw to the discard pile:\n");
        returncards(cardtem, p, card, numofcard);
        int d;
        d=rand()%4+1;
        printf("the card you just threw away is %s\n", cardtem[d].name);
        for (int k=0; k<numofcard; k++){
            if (card[k].player[0]==p->player.order && strcmp(card[k].name, cardtem[d].name)==0){
                card[k].player[0]=-1;
                break;
            }
        }
    }
}
