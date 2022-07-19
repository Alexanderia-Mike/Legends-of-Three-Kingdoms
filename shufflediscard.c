//
//  shufflediscard.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/5.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

void shufflediscard(cards *card, int numofcard){
    cards card1[100]; int j=0;
    for (int k=0; k<numofcard; k++){
        if (card[k].player[0]==-1){
            /*strcpy(card1[j].name, card[k].name);
            strcpy(card1[j].color, card[k].color);
            strcpy(card1[j].number, card[k].number);
            card1[j].function=card[k].function;
            card1[j].fatezone=card[k].fatezone;
            card1[j].player=0;*/
            card1[j]=card[k];
            j++;
        }
    }
    shuffle(card1, j);
    j=0;
    for(int k=0; k<numofcard; k++){
        if (card[k].player[0]==-1){
            /*strcpy(card[k].name, card1[j].name);
            strcpy(card[k].color, card1[j].color);
            strcpy(card[k].number, card1[j].number);
            card[k].function=card1[j].function;
            card[k].player=card1[j].player;
            card[k].fatezone=card1[j].fatezone;*/
            card[k]=card1[j];
            j++;
        }
    }
    //free(card1);
}
