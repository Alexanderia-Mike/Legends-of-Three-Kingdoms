//
//  deal the cards.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/5.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

void dealcards(cards *card, int n, int numofcard, playerp p){// playerth=i, then the according player is player[i-1], because the player structure array starts from 0.
    int i=0, k=0;
    while(i<n){
        if (card[k].player[0]==0 && card[k].player[1]==0 && card[k].player[2]==0){
            card[k].player[0]=p->player.order;
            i++; k++;
        }
        else k++;
        if (k==numofcard){
            k=0;
            shufflediscard(card, numofcard);
        }
    }
}
