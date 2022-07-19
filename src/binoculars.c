//
//  binoculars.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/16.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

void bino(int numofcard, playerp p, cards* card){
    int d=0;
    for (int k=0; k<numofcard; k++){
        if (card[k].player[2]==p->player.order && strcmp(card[k].name, "binocular")==0){
            d++;
            break;
        }
    }
    if (d==0){
        for (int k=0; k<numofcard; k++){
            if (card[k].player[0]==p->player.order && strcmp(card[k].name, "binocular")==0){
                card[k].player[0]=0;
                card[k].player[2]=p->player.order;
                break;
            }
        }
    }
    else{
        printf("you have already arm this equipment card!\n");
        pauseprogram();
    }
}
