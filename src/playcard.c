//
//  playcard.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/14.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

void playcard(int* playphase, int* drawphase, playerp p, cards* card, int* nump, int numofcard, int* wine, playerp head, int* reveal, int demo){
    if (demo==0){
        printf("\n");
        fate(card, p, numofcard, nump, playphase, drawphase, wine, reveal, head, demo);
        checksuccess(reveal, nump, head);
        if (drawphase[p->player.order]!=0) dealcards(card, 2, numofcard, p);
        if (playphase[p->player.order]!=0){
            int d=-1; cards cardtem[15];
            while(d!=0 && p->player.health>0){
                listtitle(p, reveal, nump, head);
                printf("-1. reveal your identity\n");
                printf("-2. discard\n");
                printf("0. end this turn\n");
                returncards(cardtem, p, card, numofcard);
                printf("please choose the card you want to use (intput the number before it)\n");
                scanf("%d", &d);
                if (d!=0){
                    if (d==-1) revealidentity(p, reveal);
                    else if (d==-2) discard(p, cardtem, card, numofcard, demo);
                    else if (strcmp(cardtem[d].name, "strike")==0)
                        strike(p, head, card, wine, numofcard, nump, playphase, drawphase, reveal, demo);
                    else if (strcmp(cardtem[d].name, "peach")==0)
                        peach(p, card, numofcard);
                    else if (strcmp(cardtem[d].name, "wine")==0)
                        winef(p, wine, card, numofcard);
                    else if (strcmp(cardtem[d].name, "dismantle")==0)
                        dismantle(p, head, card, numofcard, demo);
                    else if (strcmp(cardtem[d].name, "snatch")==0)
                        snatch(p, head, card, numofcard, nump, demo);
                    else if (strcmp(cardtem[d].name, "borrowed_sword")==0)
                        borrowedsword(p, head, nump, reveal, wine, playphase, drawphase, numofcard, card, demo);
                    else if (strcmp(cardtem[d].name, "barbarian_invasion")==0)
                        barbarian(p, nump, card, numofcard, wine, playphase, drawphase, reveal, head, demo);
                    else if (strcmp(cardtem[d].name, "peach_garden")==0)
                        peachgarden(nump, card, numofcard, wine, playphase, drawphase, reveal, head, demo);
                    else if (strcmp(cardtem[d].name, "something_for_nothing")==0)
                        sthfornth(card, numofcard, p);
                    else if (strcmp(cardtem[d].name, "bountiful_harvest")==0)
                        bountiful(card, numofcard, p, head);
                    else if (strcmp(cardtem[d].name, "lightning")==0)
                        lightning(numofcard, card, p, head);
                    else if (strcmp(cardtem[d].name, "drown_in_happiness")==0)
                        drown(numofcard, card, p, head);
                    else if (strcmp(cardtem[d].name, "starvation")==0)
                        starv(numofcard, card, p, head);
                    else if (strcmp(cardtem[d].name, "binocular")==0)
                        bino(numofcard, p, card);
                    else if (strcmp(cardtem[d].name, "bow")==0)
                        bow(numofcard, p, card);
                    else if (strcmp(cardtem[d].name, "horse")==0)
                        horse(numofcard, p, card);
                    else if (strcmp(cardtem[d].name, "arrow_barrage")==0)
                        arrowbarrage(p, card, numofcard, wine, nump, playphase, drawphase, reveal, head, demo);
                    else{
                        printf("the card is unvalid\n");
                        pauseprogram();
                    }
                }
                else{
                    int paishu=0;
                    for (int k=0; k<numofcard; k++){
                        if (card[k].player[0]==p->player.order)
                            paishu++;
                    }
                    if (paishu<=p->player.health){
                        system("clear");
                        printf("you end this term, so please give the computer to the next player\n");
                        pauseprogram();
                        system("clear");
                    }
                    else{
                        printf("you cannot end this term, because you have too many cards. please discard until the number of cards in your hands are no more than your health\n");
                        pauseprogram();
                        d=-1;
                    }
                }
                checksuccess(reveal, nump, head);
                printf("\n\n");
            }
        }
    }
    else {
        printf("\n");
        fate(card, p, numofcard, nump, playphase, drawphase, wine, reveal, head, demo);
        checksuccess(reveal, nump, head);
        if (drawphase[p->player.order]!=0) dealcards(card, 2, numofcard, p);
        if (playphase[p->player.order]!=0){
            int d=-1; cards cardtem[15];
            while(d!=0 && p->player.health>0){
                listtitle(p, reveal, nump, head);
                printf("-1. reveal your identity\n");
                printf("-2. discard\n");
                printf("0. end this turn\n");
                returncards(cardtem, p, card, numofcard);
                printf("please choose the card you want to use (intput the number before it)\n");
                d=rand()%6-2;
                printf("%d", d);
                pauseprogram();
                if (d!=0){
                    if (d==-1) revealidentity(p, reveal);
                    else if (d==-2) discard(p, cardtem, card, numofcard, demo);
                    else if (strcmp(cardtem[d].name, "strike")==0)
                        strike(p, head, card, wine, numofcard, nump, playphase, drawphase, reveal, demo);
                    else if (strcmp(cardtem[d].name, "peach")==0)
                        peach(p, card, numofcard);
                    else if (strcmp(cardtem[d].name, "wine")==0)
                        winef(p, wine, card, numofcard);
                    else if (strcmp(cardtem[d].name, "dismantle")==0)
                        dismantle(p, head, card, numofcard, demo);
                    else if (strcmp(cardtem[d].name, "snatch")==0)
                        snatch(p, head, card, numofcard, nump, demo);
                    else if (strcmp(cardtem[d].name, "borrowed_sword")==0)
                        borrowedsword(p, head, nump, reveal, wine, playphase, drawphase, numofcard, card, demo);
                    else if (strcmp(cardtem[d].name, "barbarian_invasion")==0)
                        barbarian(p, nump, card, numofcard, wine, playphase, drawphase, reveal, head, demo);
                    else if (strcmp(cardtem[d].name, "peach_garden")==0)
                        peachgarden(nump, card, numofcard, wine, playphase, drawphase, reveal, head, demo);
                    else if (strcmp(cardtem[d].name, "something_for_nothing")==0)
                        sthfornth(card, numofcard, p);
                    else if (strcmp(cardtem[d].name, "bountiful_harvest")==0)
                        bountiful(card, numofcard, p, head);
                    else if (strcmp(cardtem[d].name, "lightning")==0)
                        lightning(numofcard, card, p, head);
                    else if (strcmp(cardtem[d].name, "drown_in_happiness")==0)
                        drown(numofcard, card, p, head);
                    else if (strcmp(cardtem[d].name, "starvation")==0)
                        starv(numofcard, card, p, head);
                    else if (strcmp(cardtem[d].name, "binocular")==0)
                        bino(numofcard, p, card);
                    else if (strcmp(cardtem[d].name, "bow")==0)
                        bow(numofcard, p, card);
                    else if (strcmp(cardtem[d].name, "horse")==0)
                        horse(numofcard, p, card);
                    else if (strcmp(cardtem[d].name, "arrow_barrage")==0)
                        arrowbarrage(p, card, numofcard, wine, nump, playphase, drawphase, reveal, head, demo);
                    else{
                        printf("the card is unvalid\n");
                        pauseprogram();
                    }
                }
                else{
                    int paishu=0;
                    for (int k=0; k<numofcard; k++){
                        if (card[k].player[0]==p->player.order)
                            paishu++;
                    }
                    if (paishu<=p->player.health){
                        system("clear");
                        printf("you end this term, so please give the computer to the next player\n");
                        pauseprogram();
                        system("clear");
                    }
                    else{
                        printf("you cannot end this term, because you have too many cards. please discard until the number of cards in your hands are no more than your health\n");
                        pauseprogram();
                        d=-1;
                    }
                }
                checksuccess(reveal, nump, head);
                printf("\n\n");
            }
        }
    }
}
