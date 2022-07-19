//
//  testifyfate.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/5.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

cards* testifyfate(cards* card, int numofcard){
    int k=0;
    while (0<1){
        if (card[k].player[0]==0 && card[k].player[1]==0 && card[k].player[2]==0){
            card[k].player[0]=-1;
            return &card[k];
        }
        else k++;
        if (k==numofcard){
            k=0;
            shuffle(card, numofcard);
        }
    }
}
