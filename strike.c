//
//  strike.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/12.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

void strike(playerp p, playerp head, cards* card, int *wine, int numofcard, int* nump, int* playphase, int* drawphase, int* reveal, int demo){
    if (demo==0){
        printf("please choose the players you want to attack\n");
        printf("your attack range is %d\n", attackrange(p, numofcard, card));
        playerp q=head->next; int i=1; int d;
        while (q!=NULL){
            printf("%d. %s(with the distance %d)\n", i, q->player.name, distance(p, q, nump, card, numofcard));
            q=q->next; i++;
        }
        printf("input 0 to cancel strike\n");
        scanf("%d", &d);
        if (d!=0){
            q=head;
            for (int k=1; k<=d; k++) q=q->next;
            while(distance(p, q, nump, card, numofcard)>attackrange(p, numofcard, card)){
                printf("sorry, his distance is beyond your attack range, please input again\n");
                printf("please choose the players you want to attack\n");
                scanf("%d", &d);
                if (d==0) break;
                q=head;
                for (int k=1; k<=d; k++) q=q->next;
            }
            if (d!=0){
                for (int k=0; k<numofcard; k++){
                    if (card[k].player[0]==p->player.order && strcmp(card[k].name, "strike")==0){
                        card[k].player[0]=-1;
                        break;
                    }
                }
                int j=dodge(q, p, card, numofcard, wine, nump, playphase, drawphase, reveal, head, demo);
                system("clear");
                listtitle(p, reveal, nump, head);
                switch (j) {
                    case 0:
                        printf("he used a dodge\n");
                        pauseprogram();
                        break;
                    case 1:
                        printf("he is damaged by 1 health\n");
                        pauseprogram();
                        break;
                    default:
                        printf("he is damaged by 2 health\n");
                        pauseprogram();
                        break;
                }
            }
        }
    }
    else{
        printf("please choose the players you want to attack\n");
        printf("your attack range is %d\n", attackrange(p, numofcard, card));
        playerp q=head->next; int i=1; int d;
        while (q!=NULL){
            printf("%d. %s(with the distance %d)\n", i, q->player.name, distance(p, q, nump, card, numofcard));
            q=q->next; i++;
        }
        printf("input 0 to cancel strike\n");
        d=rand()%i;
        printf("%d", d);
        pauseprogram();
        if (d!=0){
            q=head;
            for (int k=1; k<=d; k++) q=q->next;
            while(distance(p, q, nump, card, numofcard)>attackrange(p, numofcard, card)){
                printf("sorry, his distance is beyond your attack range, please input again\n");
                printf("please choose the players you want to attack\n");
                d=rand()%i;
                printf("%d", d);
                pauseprogram();
                if (d==0) break;
                q=head;
                for (int k=1; k<=d; k++) q=q->next;
            }
            if (d!=0){
                for (int k=0; k<numofcard; k++){
                    if (card[k].player[0]==p->player.order && strcmp(card[k].name, "strike")==0){
                        card[k].player[0]=-1;
                        break;
                    }
                }
                int j=dodge(q, p, card, numofcard, wine, nump, playphase, drawphase, reveal, head, demo);
                system("clear");
                listtitle(p, reveal, nump, head);
                switch (j) {
                    case 0:
                        printf("he used a dodge\n");
                        pauseprogram();
                        break;
                    case 1:
                        printf("he is damaged by 1 health\n");
                        pauseprogram();
                        break;
                    default:
                        printf("he is damaged by 2 health\n");
                        pauseprogram();
                        break;
                }
            }
        }
    }
}
