//
//  borrowedsword.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/16.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

void borrowedsword(playerp p, playerp head, int *nump, int *reveal, int *wine, int *playerphase, int *drawphase, int numofcard, cards *card, int demo){
    if (demo==0){
        printf("please choose the player you want to give out strike\n");
        playerp q=head->next, q1=head, q2=head; int i=1, d;
        while (q!=NULL){
            printf("%d. %s\n", i, q->player.name);
            q=q->next; i++;
        }
        scanf("%d", &d);
        for (int k=1; k<=d; k++)
            q1=q1->next;
        while (q1==p){
            printf("you just chose yourself! please choose again!\n");
            scanf("%d", &d);
            q1=head;
            for (int k=1; k<=d; k++)
                q1=q1->next;
        }
        printf("please choose the player you want to be struck\n");
        q=head->next; i=1;
        while (q!=NULL){
            printf("%d. %s\n", i, q->player.name);
            q=q->next; i++;
        }
        scanf("%d", &d);
        for (int k=1; k<=d; k++)
            q2=q2->next;
        while (q2==p || q2==q1){
            if (q2==p)
                printf("you just chose yourself!\n");
            else
                printf("you just chose the striker!\n");
            printf("please choose again!\n");
            scanf("%d", &d);
            q2=head;
            for (int k=1; k<=d; k++)
                q2=q2->next;
        }
        system("clear");
        printf("please give the screen to %s\n", q1->player.name);
        pauseprogram();
        listtitle(q1, reveal, nump, head);
        printf("your have just recieve a borrwed sword from %s, do you accept to use strike to %s?(1 for yes and 0 for no)\n", p->player.name, q2->player.name);
        int f;
        scanf("%d", &f);
        if (f==0){
            printf("you have rejested to use strike\n");
            int g=0; cards cardtem[5];
            for (int k=0; k<numofcard; k++){
                if (card[k].player[2]==q1->player.order){
                    printf("your %s now belongs to %s\n", card[k].name, p->player.name);
                    card[k].player[2]=0;
                    card[k].player[0]=p->player.order;
                    cardtem[g]=card[k];
                    g++;
                }
            }
            if (g==0){
                printf("you lose nothing because you have no equipment card :)\n");
                pauseprogram();
                system("clear");
                printf("please give the screen to %s\n", p->player.name);
                pauseprogram();
                printf("%s refused to strike, but he has no equipment  card now\n", q1->player.name);
            }
            else {
                pauseprogram();
                system("clear");
                printf("please give the screen to %s\n", p->player.name);
                pauseprogram();
                printf("he refused to strike, so:\n");
                for (int k=0; k<g; k++){
                    printf("you recive %s from %s\n", cardtem[k].name, q1->player.name);
                }
            }
        }
        else{
            for (int k=0; k<numofcard; k++){
                if (card[k].player[0]==q1->player.order && strcmp(card[k].name, "strike")==0){
                    card[k].player[0]=-1;
                    break;
                }
            }
            int j=dodge(q2, q1, card, numofcard, wine, nump, playerphase, drawphase, reveal, head, demo);
            system("clear");
            listtitle(q1, reveal, nump, head);
            switch (j) {
                case 0:
                    printf("he used a dodge\n");
                    pauseprogram();
                    system("clear");
                    printf("please give the screen to %s\n", p->player.name);
                    pauseprogram();
                    printf("%s used a strike to %s, but %s used a dodge to avoid damage\n", q1->player.name, q2->player.name,q2->player.name);
                    break;
                case 1:
                    printf("he is damaged by 1 health\n");
                    pauseprogram();
                    system("clear");
                    printf("please give the screen to %s\n", p->player.name);
                    pauseprogram();
                    printf("%s used a strike to %s, and %s doesn't use a dodge, so %s recieved a 1 damage\n", q1->player.name, q2->player.name,q2->player.name, q2->player.name);
                    break;
                default:
                    printf("he is damaged by 2 health\n");
                    pauseprogram();
                    system("clear");
                    printf("please give the screen to %s\n", p->player.name);
                    pauseprogram();
                    printf("%s used a strike to %s, and %s doesn't use a dodge, so %s recieved a 2 damage\n", q1->player.name, q2->player.name,q2->player.name, q2->player.name);
                    break;
            }
        }
    }
    else {
        printf("please choose the player you want to give out strike\n");
        playerp q=head->next, q1=head, q2=head; int i=1, d;
        while (q!=NULL){
            printf("%d. %s\n", i, q->player.name);
            q=q->next; i++;
        }
        d=rand()%(i-1)+1;
        printf("%d", d);
        pauseprogram();
        for (int k=1; k<=d; k++)
            q1=q1->next;
        while (q1==p){
            printf("you just chose yourself! please choose again!\n");
            d=rand()%(i-1)+1;
            printf("%d", d);
            pauseprogram();
            q1=head;
            for (int k=1; k<=d; k++)
                q1=q1->next;
        }
        printf("please choose the player you want to be struck\n");
        q=head->next; i=1;
        while (q!=NULL){
            printf("%d. %s\n", i, q->player.name);
            q=q->next; i++;
        }
        d=rand()%(i-1)+1;
        printf("%d", d);
        pauseprogram();
        for (int k=1; k<=d; k++)
            q2=q2->next;
        while (q2==p || q2==q1){
            if (q2==p)
                printf("you just chose yourself!\n");
            else
                printf("you just chose the striker!\n");
            printf("please choose again!\n");
            d=rand()%(i-1)+1;
            printf("%d", d);
            pauseprogram();
            q2=head;
            for (int k=1; k<=d; k++)
                q2=q2->next;
        }
        system("clear");
        printf("please give the screen to %s\n", q1->player.name);
        pauseprogram();
        listtitle(q1, reveal, nump, head);
        printf("your have just recieve a borrwed sword from %s, do you accept to use strike to %s?(1 for yes and 0 for no)\n", p->player.name, q2->player.name);
        int f;
        f=rand()%2;
        printf("%d", f);
        pauseprogram();
        if (f==0){
            printf("you have rejested to use strike\n");
            int g=0; cards cardtem[5];
            for (int k=0; k<numofcard; k++){
                if (card[k].player[2]==q1->player.order){
                    printf("your %s now belongs to %s\n", card[k].name, p->player.name);
                    card[k].player[2]=0;
                    card[k].player[0]=p->player.order;
                    cardtem[g]=card[k];
                    g++;
                }
            }
            if (g==0){
                printf("you lose nothing because you have no equipment card :)\n");
                pauseprogram();
                system("clear");
                printf("please give the screen to %s\n", p->player.name);
                pauseprogram();
                printf("%s refused to strike, but he has no equipment  card now\n", q1->player.name);
            }
            else {
                pauseprogram();
                system("clear");
                printf("please give the screen to %s\n", p->player.name);
                pauseprogram();
                printf("he refused to strike, so:\n");
                for (int k=0; k<g; k++){
                    printf("you recive %s from %s\n", cardtem[k].name, q1->player.name);
                }
            }
        }
        else{
            for (int k=0; k<numofcard; k++){
                if (card[k].player[0]==q1->player.order && strcmp(card[k].name, "strike")==0){
                    card[k].player[0]=-1;
                    break;
                }
            }
            int j=dodge(q2, q1, card, numofcard, wine, nump, playerphase, drawphase, reveal, head, demo);
            system("clear");
            listtitle(q1, reveal, nump, head);
            switch (j) {
                case 0:
                    printf("he used a dodge\n");
                    pauseprogram();
                    system("clear");
                    printf("please give the screen to %s\n", p->player.name);
                    pauseprogram();
                    printf("%s used a strike to %s, but %s used a dodge to avoid damage\n", q1->player.name, q2->player.name,q2->player.name);
                    break;
                case 1:
                    printf("he is damaged by 1 health\n");
                    pauseprogram();
                    system("clear");
                    printf("please give the screen to %s\n", p->player.name);
                    pauseprogram();
                    printf("%s used a strike to %s, and %s doesn't use a dodge, so %s recieved a 1 damage\n", q1->player.name, q2->player.name,q2->player.name, q2->player.name);
                    break;
                default:
                    printf("he is damaged by 2 health\n");
                    pauseprogram();
                    system("clear");
                    printf("please give the screen to %s\n", p->player.name);
                    pauseprogram();
                    printf("%s used a strike to %s, and %s doesn't use a dodge, so %s recieved a 2 damage\n", q1->player.name, q2->player.name,q2->player.name, q2->player.name);
                    break;
            }
        }
    }
}
