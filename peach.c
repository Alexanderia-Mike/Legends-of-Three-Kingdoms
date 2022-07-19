//
//  peach.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/14.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

void peach(playerp p, cards* card, int numofcard){
    if (p->player.health==p->player.initialhealth){
        printf("you cannot use this card because your health is already full\n");
        pauseprogram();
        return;
    }
    else {
        p->player.health++;
        for (int k=0; k<numofcard; k++){
            if (card[k].player[0]==p->player.order && strcmp(card[k].name, "peach")==0){
                card[k].player[0]=-1;
                break;
            }
        }
    }
}
