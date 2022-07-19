//
//  starvation.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/16.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

void starv(int numofcard, cards* card, playerp p, playerp head){
    for (int k=0; k<numofcard; k++){
        if (card[k].player[0]==p->player.order && strcmp(card[k].name, "starvation")==0){
            card[k].player[0]=0;
            if (p->next!=NULL)
                card[k].player[1]=p->next->player.order;
            else
                card[k].player[1]=head->next->player.order;
            break;
        }
    }
}
