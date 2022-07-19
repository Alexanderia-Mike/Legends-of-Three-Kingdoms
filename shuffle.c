//
//  shufflearray.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/4.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

void shuffle(cards *card, int numofcard){
    cards card1[100]; int shuff[100]={0};
    srand((unsigned)time(NULL));
    for (int k=1; k<=numofcard; k++){
        int d=rand()%numofcard;// 0~numofcard-1.
        if (shuff[d]==0){
            shuff[d]+=k;// shuff is an array contains integers from 1~numofcard. it starts from 0.
            /*strcpy(card1[d].name,card[shuff[d]-1].name);// the card starts from 0, so shuff minus 1.
            strcpy(card1[d].color,card[shuff[d]-1].color);// and card1 also starts from 0.
            strcpy(card1[d].number,card[shuff[d]-1].number);
            card1[d].function=card[shuff[d]-1].function;
            card1[d].player=card[shuff[d]-1].player;
            card1[d].fatezone=card[shuff[d]-1].fatezone;*/
            card1[d]=card[shuff[d]-1];
        }
        else  k--;
    }
    for (int k=0; k<numofcard; k++){
        card[k]=card1[k];
    }
    //free(card1); free(shuff); 
}
