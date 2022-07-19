//
//  pause.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/14.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

void pauseprogram(void){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
    printf("please press the enter to continue\n");
    getchar();
}
