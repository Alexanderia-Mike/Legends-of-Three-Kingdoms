//
//  fate.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/5.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

void fate(cards *card, playerp q, int numofcard, int* nump, int* playphase, int* drawphase, int* wine, int* reveal, playerp head, int demo)
    {
    for (int k=0; k<numofcard; k++){
        if (card[k].player[1]==q->player.order){
            if (strcmp(card[k].name, "lightning")==0){
                cards* p=testifyfate(card, numofcard);
                printf("the card you draw is:\n%s %s %s\n", p->name, p->color, p->number);
                pauseprogram();
                if (strcmp(p->color, "spade")==0 && p->number[0]>='2' && p->number[0]<='9'){
                    printf("you have recieve three damage\n");
                    pauseprogram();
                    int fatee=changehealth(-3, q, nump, card, numofcard, wine, playphase, drawphase, reveal, head, demo);// pose damage.
                    if (!fatee)
                       card[k].player[1]=0;// throw it to the discard pile.
                }
                else {
                    card[k].player[1]=(q->player.order)%*nump+1;
                    printf("you are not affected\n");
                    pauseprogram();
                }
            }
            else if (strcmp(card[k].name, "drown_in_happiness")==0){
                cards* p=testifyfate(card, numofcard);
                printf("the card you draw is:\n%s %s %s", p->name, p->color, p->number);
                pauseprogram();
                if (strcmp(p->color, "heart")) {
                    playphase[q->player.order]=0;
                    printf("you lose the play phase this turn\n");
                    pauseprogram();
                }
                else{
                    printf("you are not affected\n");
                    pauseprogram();
                }
                card[k].player[1]=0;
            }
            else if (strcmp(card[k].name, "starvation")==0){
                cards* p=testifyfate(card, numofcard);
                printf("the card you draw is:\n%s %s %s", p->name, p->color, p->number);
                pauseprogram();
                if (strcmp(p->color, "club")) {
                    drawphase[q->player.order]=0;
                    printf("you lose the draw phase this turn\n");
                    pauseprogram();
                }
                else{
                    printf("you are not affected\n");
                    pauseprogram();
                }
                card[k].player[1]=0;
            }
        }
    }
}
