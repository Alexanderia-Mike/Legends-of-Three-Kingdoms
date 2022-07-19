//
//  cardsinitialwithargument.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/17.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

void cardswitharg(int argc, const char* argv[], cards* card, int* numofcard){
    cards* qq=card;
    *numofcard=0; int q=1; char str2[100][3]; char str1[100][10];
    int n=(argc-1)/2;
    srand((unsigned)time(NULL));
    for (int k=1; k<=n; k++){
        (*numofcard)+=atoi(argv[2*k]);
        for (int f=1; f<=atoi(argv[2*k]); f++){
            strcpy(qq->name, argv[2*k-1]);
            qq->player[0]=0; qq->player[1]=0; qq->player[2]=0;
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
            strcpy(qq->color, str1[q]); strcpy(qq->number, str2[q]);
            q++;
            qq++;
        }
    }
}
