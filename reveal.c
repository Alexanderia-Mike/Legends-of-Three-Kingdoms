//
//  reveal.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/15.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

void revealidentity(playerp p, int* reveal){
    reveal[p->player.order]=1;
    printf("you have revealed your identity!\n");
    pauseprogram();
}
