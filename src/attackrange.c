//
//  attackrange.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/12.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

int attackrange(playerp p, int numofcard, cards* card){
    int d=1;
    for (int k=0; k<numofcard; k++){
        if (card[k].player[2]==p->player.order){
            if (strcmp(card[k].name, "bow")==0) d+=2;
        }
    }
    return d;
}
