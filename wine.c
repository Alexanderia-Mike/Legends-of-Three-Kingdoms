//
//  wine.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/14.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

void winef(playerp p, int *wine, cards* card, int numofcard){
    wine[p->player.order]=1;
    for(int k=0; k<numofcard; k++){
        if (card[k].player[0]==p->player.order && strcmp(card[k].name, "wine")==0){
            card[k].player[0]=-1;
            break;
        }
    }
    if (p->player.health==0)
        p->player.health++;
}
