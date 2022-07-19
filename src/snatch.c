//
//  snatch.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/16.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

void snatch(playerp p, playerp head, cards* card, int numofcard, int* nump, int demo){
    if (demo==0){
        printf("please choose the players you want to snatch\n");
        printf("your attack range is %d\n", attackrange(p, numofcard, card));
        playerp q=head->next; int i=1; int d;
        while (q!=NULL){
            printf("%d. %s(with the distance %d)\n", i, q->player.name, distance(p, q, nump, card, numofcard));
            q=q->next; i++;
        }
        printf("input 0 to cancel snatch\n");
        scanf("%d", &d);
        if (d!=0){
            q=head;
            for (int k=1; k<=d; k++) q=q->next;
            while(distance(p, q, nump, card, numofcard)>attackrange(p, numofcard, card)){
                printf("sorry, his distance is beyond your attack range, please input again\n");
                printf("please choose the players you want to snatch\n");
                scanf("%d", &d);
                if (d==0) break;
                for (int k=1; k<=d; k++) q=q->next;
            }
            if (d!=0){
                for (int k=0; k<numofcard; k++){
                    if (card[k].player[0]==p->player.order && strcmp(card[k].name, "snatch")==0){
                        card[k].player[0]=-1;
                        break;
                    }
                }
                for (int k=0; k<numofcard; k++){
                    int gg=0;
                    if (card[k].player[2]==q->player.order){
                        printf("the card you snatch from %s is %s\n", q->player.name, card[k].name);
                        card[k].player[2]=0;
                        card[k].player[0]=p->player.order;
                        printf("the card now belongs to you\n");
                        pauseprogram();
                        gg++;
                        break;
                    }
                    if (gg==0){
                        printf("he has no equipment card!\n");
                        pauseprogram();
                    }
                }
            }
        }
    }
    else {
        printf("please choose the players you want to snatch\n");
        printf("your attack range is %d\n", attackrange(p, numofcard, card));
        playerp q=head->next; int i=1; int d;
        while (q!=NULL){
            printf("%d. %s(with the distance %d)\n", i, q->player.name, distance(p, q, nump, card, numofcard));
            q=q->next; i++;
        }
        printf("input 0 to cancel snatch\n");
        d=rand()%i;
        printf("%d", d);
        pauseprogram();
        if (d!=0){
            q=head;
            for (int k=1; k<=d; k++) q=q->next;
            while(distance(p, q, nump, card, numofcard)>attackrange(p, numofcard, card)){
                printf("sorry, his distance is beyond your attack range, please input again\n");
                printf("please choose the players you want to snatch\n");
                d=rand()%i;
                printf("%d", d);
                pauseprogram();
                if (d==0) break;
                for (int k=1; k<=d; k++) q=q->next;
            }
            if (d!=0){
                for (int k=0; k<numofcard; k++){
                    if (card[k].player[0]==p->player.order && strcmp(card[k].name, "snatch")==0){
                        card[k].player[0]=-1;
                        break;
                    }
                }
                int gg=0;
                for (int k=0; k<numofcard; k++){
                    if (card[k].player[2]==q->player.order){
                        printf("the card you snatch from %s is %s\n", q->player.name, card[k].name);
                        card[k].player[2]=0;
                        card[k].player[0]=p->player.order;
                        printf("the card now belongs to you\n");
                        pauseprogram();
                        gg++;
                        break;
                    }
                }
                if (gg==0){
                    printf("he has no equipment card!\n");
                    pauseprogram();
                }
            }
        }
    }
}
