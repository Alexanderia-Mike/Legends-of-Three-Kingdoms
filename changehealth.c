//
//  changehealth.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/5.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"


int changehealth(int i, playerp p, int* nump, cards* card, int numofcard, int* wine, int* playphase, int* drawphase, int* reveal, playerp head, int demo){
    if (demo==0){
        p->player.health+=i;
        if (p->player.health>p->player.initialhealth){
            p->player.health=p->player.initialhealth;
            return 0;
        }
        else if (p->player.health<=0){
            p->player.health=0;
            printf("you are dying, do you want to ask for help?(1 for yes and 0 for no)\n");
            int d, f;
            scanf("%d", &d);
            if (d)
                f=askhelp(head, p, card, numofcard, reveal, nump, demo);
            else {
                f=0;
                printf("you rejected to ask for help, so you died\n");
            }
            if (!f){
                (*nump)--;
                int d=p->player.order;
                p->pre->next=p->next;
                if (p->next!=NULL)
                    p->next->pre=p->pre;
                playerp q=p->next;
                free(p);
                for (int k=0; k<numofcard; k++){
                    for (int t=0; t<3; t++){
                        if (card[k].player[t]>d)
                            card[k].player[t]--;
                        if (card[k].player[t]==d)
                            card[k].player[t]=-1;
                    }
                }
                for (int k=d; k<=*nump; k++){
                    wine[d]=wine[d+1];
                    playphase[d]=playphase[d+1];
                    drawphase[d]=drawphase[d+1];
                    reveal[d]=reveal[d+1];
                }
                while (q!=NULL){
                    q->player.order--;
                    q=q->next;
                }
                //pauseprogram();
                return 1;
            }
            else return 0;
        }
        else return 0;
    }
    else{
        p->player.health+=i;
        if (p->player.health>p->player.initialhealth){
            p->player.health=p->player.initialhealth;
            return 0;
        }
        else if (p->player.health<=0){
            p->player.health=0;
            printf("you are dying, do you want to ask for help?(1 for yes and 0 for no)\n");
            int d, f;
            d=rand()%2;
            printf("%d", d);
            pauseprogram();
            if (d)
                f=askhelp(head, p, card, numofcard, reveal, nump, demo);
            else {
                f=0;
                printf("you rejected to ask for help, so you died\n");
            }
            if (!f){
                (*nump)--;
                int d=p->player.order;
                p->pre->next=p->next;
                if (p->next!=NULL)
                    p->next->pre=p->pre;
                playerp q=p->next;
                free(p);
                for (int k=0; k<numofcard; k++){
                    for (int t=0; t<3; t++){
                        if (card[k].player[t]>d)
                            card[k].player[t]--;
                        if (card[k].player[t]==d)
                            card[k].player[t]=-1;
                    }
                }
                for (int k=d; k<=*nump; k++){
                    wine[d]=wine[d+1];
                    playphase[d]=playphase[d+1];
                    drawphase[d]=drawphase[d+1];
                    reveal[d]=reveal[d+1];
                }
                while (q!=NULL){
                    q->player.order--;
                    q=q->next;
                }
                //pauseprogram();
                return 1;
            }
            else return 0;
        }
        else return 0;
    }
}

