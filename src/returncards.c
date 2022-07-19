//
//  returncards.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/5.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

void returncards(cards *cardtem, playerp p, cards* card, int numofcard){
    printf("the cards in your hands:\n");
    int i=1;
    for (int k=0; k<numofcard; k++){
        if (card[k].player[0]==p->player.order){
            printf("%d. %s\n", i, card[k].name);
            cardtem[i]=card[k];
            i++;
        }
    }
    printf("\nthe cards in fate zone:\n");
    for (int k=0; k<numofcard; k++){
        if (card[k].player[1]==p->player.order){
            printf("%d. %s\n", i, card[k].name);
            cardtem[i]=card[k];
            i++;
        }
    }
    printf("\nthe cards in equipment zone:\n");
    for (int k=0; k<numofcard; k++){
        if (card[k].player[2]==p->player.order){
            printf("%d. %s\n", i, card[k].name);
            cardtem[i]=card[k];
            i++;
        }
    }
}
