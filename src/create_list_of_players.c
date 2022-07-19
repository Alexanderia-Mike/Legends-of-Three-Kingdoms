//
//  create list of players.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/11.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

playerp createlistofplayers(players *player, int* nump){
    playerp head, p, p1;
    head=(playerp)malloc(sizeof(playerlist));
    if (head==NULL) {printf("error!"); exit(1);}
    else {head->pre=NULL; head->next=NULL;}
    for (int i=0; i<*nump; i++){
        p=(playerp)malloc(sizeof(playerlist));
        p->player=player[i];
        if (head->next==NULL){
            head->next=p; p->pre=head; p1=p;
        }
        else {
            p->pre=p1; p1->next=p; p1=p;
        }
        p1->next=NULL;
    }
    return head;
}

