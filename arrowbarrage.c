//
//  arrowbarrage.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/16.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

void arrowbarrage(playerp p, cards* card, int numofcard, int *wine, int* nump, int* playphase, int* drawphase, int* reveal, playerp head, int demo){
    playerp q=head->next; int i=1, health[10];
    while(q!=NULL){
        if (q!=p)
            health[i]=dodge(q, p, card, numofcard, wine, nump, playphase, drawphase, reveal, head, demo);
        i++;
        q=q->next;
    }
    i--;
    system("clear");
    listtitle(p, reveal, nump, head);
    q=head->next;
    int k=1;
    while (q!=NULL){
        if (q!=p)
            printf("%s recieve %d damage\n", q->player.name, health[k]);
        q=q->next;
        k++;
    }
}
