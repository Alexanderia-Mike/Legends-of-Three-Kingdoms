//
//  players.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/4.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

void playersinitial(players *player, int *nump){
    srand((unsigned)time(NULL));
    printf("do you want the game to be initialized randomly by the system?(please answer 'yes' or 'no')");
    char yon[5];
    scanf("%s",yon);
    if (!strcmp(yon, "yes")){
        *nump=rand()%7+4;// the number of the players,players
        //printf("%d",num);
        //int o, k;
    /*    int position[15];
        for (int h=1; h<=*nump; h++){
            position[h]=0;
        }
        for (o=0; o<*nump; o++){
            k=rand()%(*nump)+1;
            if (position[k]==0){
                position[k]+=o+1;
                //printf("%d",k);
            }
            else{
                o-=1;
            }
        }// to generate an array composed of 1~num of random order.*/
        char identity[15][10];
        char name[15][10];
        for (int p=1; p<=*nump; p++){
            sprintf(name[p],"player%d",p);
            int l=rand()%2+1;// 1 for general and 2 for mercenary.
            switch (l){
                case 1:
                    sprintf(identity[p],"%s","general");
                    break;
                default:
                    sprintf(identity[p],"%s","mercenary");
                    break;
            }
            player->order=p;
            int health=rand()%3+3;
            strcpy(player->name,name[p]);
            strcpy(player->identity,identity[p]);
            //player[p].position=position[p];
            player->health=health;
            player->initialhealth=health;
            if (!strcmp(identity[p],"general")){
                int coun=rand()%4+1;
                switch (coun){
                    case 1:
                        sprintf(player->country, "%s", "Shu");
                        break;
                    case 2:
                        sprintf(player->country, "%s", "Wu");
                        break;
                    case 3:
                        sprintf(player->country, "%s", "Wei");
                        break;
                    default:
                        sprintf(player->country, "%s", "Qun");
                        break;
                }
            }
            else sprintf(player->country, "%s", "none");
            player++;
        }
        //free(yon); free(name); free(identity);
    }
    else{
        printf("please input an the number of the players");
        scanf("%d",nump); getchar();
        // int position[15];
        char name[15][10]; char identity[15][15]; char country[15][5];//int health[15];
        int th=1;
        while (th<=*nump){
            printf("please input the name of player%d",th);
            scanf("%s",name[th]); getchar();
            strcpy(player->name,name[th]);
            printf("please input the identity of player%d(general or mercenary)",th);
            scanf("%s",identity[th]); getchar();
            strcpy(player->identity,identity[th]);
            if (!strcmp(identity[th], "general")){
                printf("please input the country of player%d(Shu, Wei, Wu or Qun)",th);
                scanf("%s", country[th]); getchar();
                strcpy(player->country,country[th]);
            }
            else sprintf(player->country, "%s", "none");
/*            printf("please input the position of player%d(ei. 2 represents the second position)",th);
            scanf("%d",&player[th].position);*/
            printf("please input the health of player%d(just an integer)",th);
            scanf("%d",&player[th-1].health); getchar();
            player->initialhealth=player[th].health;
            player->order=th;
            th++;
            player++;
        }
        //free(name); free(identity); free(country); free(yon);
    }
}
