//
//  cards.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/4.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

void cardsinitial(cards* p, int *numofcard, FILE* fp){
    char str[30][30]; *numofcard=0; int t=1, d, q=1; char str2[100][3]; char str1[100][10];
    while (!feof(fp)){
        fscanf(fp,"%s %d",str[t],&d);
        *numofcard=*numofcard+d;
        srand((unsigned)time(NULL));
        for (int r=1; r<=d; r++){
            p->player[0]=0; p->player[1]=0; p->player[2]=0;
            if (strcmp(str[t], "binocular")==0 || strcmp(str[t], "bow")==0 || strcmp(str[t], "horse")==0)
                p->function=1;
            else if (strcmp(str[t], "lightning")==0 || strcmp(str[t], "drown_in_happiness")==0 || strcmp(str[t], "starvation")==0) p->function=2;
            else p->function=0;
            int e=rand()%13+1;
            switch (e){
                case 1:
                    sprintf(str2[q],"%s","A");
                    break;
                case 2:
                    sprintf(str2[q],"%s","2");
                    break;
                case 3:
                    sprintf(str2[q],"%s","3");
                    break;
                case 4:
                    sprintf(str2[q],"%s","4");
                    break;
                case 5:
                    sprintf(str2[q],"%s","5");
                    break;
                case 6:
                    sprintf(str2[q],"%s","6");
                    break;
                case 7:
                    sprintf(str2[q],"%s","7");
                    break;
                case 8:
                    sprintf(str2[q],"%s","8");
                    break;
                case 9:
                    sprintf(str2[q],"%s","9");
                    break;
                case 10:
                    sprintf(str2[q],"%s","10");
                    break;
                case 11:
                    sprintf(str2[q],"%s","J");
                    break;
                case 12:
                    sprintf(str2[q],"%s","Q");
                    break;
                default:
                    sprintf(str2[q],"%s","K");
                    break;
            }
            int w=rand()%4+1;
            switch (w){
                case 1:
                    sprintf(str1[q],"%s","heart");
                    break;
                case 2:
                    sprintf(str1[q],"%s","diamond");
                    break;
                case 3:
                    sprintf(str1[q],"%s","spade");
                    break;
                default:
                    sprintf(str1[q],"%s","club");
                    break;
            }
            strcpy(p->name, str[t]); strcpy(p->color, str1[q]); strcpy(p->number, str2[q]);
            q++;
            p++;
        }
        t++;
    }
}
