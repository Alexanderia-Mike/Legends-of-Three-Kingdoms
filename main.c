//  main.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/10/27.
//  Copyright © 2018 娄辰飞. All rights reserved.

#include "project.h"

int main(int argc, const char* argv[]) {
    printf("%d", argc);
    system("clear");
    cards card[100];// the card[] start from zero.
    int num, numofcard;// num represents the number of players. it starts from 1.
    int *nump=&num, *numofcardp=&numofcard;
    if (argc==1){
        FILE* fp=fopen("the_cards5.txt","r");
        if (fp==NULL){
            printf("fail to open!\n");
            exit(-1);
        }
        else printf("success open!\n");
        cardsinitial(card, numofcardp, fp);// to store the information about cards in a structure, using pointer. the information comes from a file called the_cards.txt.
        fclose(fp);
    }
    else{
        cardswitharg(argc, argv, card, numofcardp);
    }
    players player[10];// the player[] starts from zero.
    playersinitial(player, nump);// to store the information about players in a structure, using pointer. the stteing could be either automatical or specified by the user.

    shuffle(card, numofcard);// to update the card array.
    
    int playphase[11], drawphase[11], reveal[11]={0}, wine[11]={0};// if playphase[i]=0, then the player lose its turn, elseif =1, then the player could play. so as drawphase. the i_th player is referred to playerphase[i].
    int demo;
    printf("do you want to use demo-mode?(1 for yes and 0 for no)\n");
    scanf("%d", &demo);
    for (int k=0; k<11; k++){
        playphase[k]=1;
        drawphase[k]=1;
    }
    playerp head=createlistofplayers(player, nump);
    playerp p=head->next, q=p;
    while (q!=NULL){
        dealcards(card, 4, numofcard, q);
        q=q->next;
    }
    q=p;
    while (1>0){
        while (q!=NULL){
            playcard(playphase, drawphase, q, card, nump, numofcard, wine, head, reveal, demo);
            q=q->next;
        }
        q=p;
    }
    return 0;
}