//
//  checksuccess.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/14.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

void checksuccess(int* reveal, int* nump, playerp head){
    for (int k=1; k<=*nump; k++){
        if (reveal[k]==0) return;
    }
    int G=0, M=0;
    playerp q=head;
    while (q!=NULL){
        if (strcmp(q->player.identity, "general")==0)
            G++;
        if (strcmp(q->player.identity, "mercenaty")==0)
            M++;
        q=q->next;
    }
    q=head;
    if (G!=0 && M!=0) return;
    else if (G==0){
        printf("mercenaries win!\n");
        while (q!=NULL){
            playerp x=q->next;
            free(q);
            q=x;
        }
        exit(0);
    }
    else {
        int S=0, Wu=0, Wei=0, Q=0;
        while (q!=NULL){
            if (strcmp(q->player.country, "Shu")==0)
                S++;
            if (strcmp(q->player.country, "Wu")==0)
                Wu++;
            if (strcmp(q->player.country, "Wei")==0)
                Wei++;
            if (strcmp(q->player.country, "Qun")==0)
                Q++;
            q=q->next;
        }
        if (S!=0 && Wu==0 && Wei==0 && Q==0){
            printf("generals from country Shu win!\n");
            while (q!=NULL){
                playerp x=q->next;
                free(q);
                q=x;
            }
            exit(0);
        }
        else if (S==0 && Wu!=0 && Wei==0 && Q==0){
            printf("generals from country Wu win!\n");
            while (q!=NULL){
                playerp x=q->next;
                free(q);
                q=x;
            }
            exit(0);
        }
        else if (S==0 && Wu==0 && Wei!=0 && Q==0){
            printf("generals from country Wei win!\n");
            while (q!=NULL){
                playerp x=q->next;
                free(q);
                q=x;
            }
            exit(0);
        }
        else if (S==0 && Wu==0 && Wei==0 && Q!=0){
            printf("generals from country Qun win!\n");
            while (q!=NULL){
                playerp x=q->next;
                free(q);
                q=x;
            }
            exit(0);
        }
    }
}
