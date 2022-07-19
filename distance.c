//
//  structure for cards.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/10/27.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

int distance(playerp p1, playerp p2, int* nump, cards* card, int numofcard){
    int n1=p1->player.order;
    int n2=p2->player.order;
    int d1=(n1-n2+*nump)%*nump;
    int d2=(n2-n1+*nump)%*nump;
    int d;
    if (d1>d2) d=d2;
    else d=d1;
    for (int k=0; k<numofcard; k++){
        if (card[k].player[2]==n1){
            if (strcmp(card[k].name, "binocular")==0) d=d-1;
        }
        if (card[k].player[2]==n2){
            if (strcmp(card[k].name, "horse")==0) d=d+1;
        }
    }
    return d;
}
