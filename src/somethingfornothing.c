//
//  somethingfornothing.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/16.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

void sthfornth(cards *card, int numofcard, playerp p){
    dealcards(card, 2, numofcard, p);
    for (int k=0; k<numofcard; k++){
        if (card[k].player[0]==p->player.order && strcmp(card[k].name, "something_for_nothing")==0){
            card[k].player[0]=-1;
            break;
        }
    }
}
