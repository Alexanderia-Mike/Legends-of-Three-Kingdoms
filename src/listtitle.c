//
//  listtitle.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/14.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

void listtitle(playerp p, int* reveal, int* nump, playerp head){
    printf("player: %s\n", p->player.name);
    printf("identity: %s\n", p->player.identity);
    if (reveal[p->player.order]==1)
        printf("country: %s (revealed)\n", p->player.country);
    else
        printf("country: %s (unrevealed)\n", p->player.country);
    printf("health: %d\n", p->player.health);
    printf("identity revealed players are:\n");
    playerp q=head;
    for (int k=1; k<=*nump; k++){
        if (reveal[k]==1){
            for (int i=1; i<=k; i++) q=q->next;
            printf("%s, %s, %s\n", q->player.name, q->player.identity, q->player.country);
            q=head;
        }
    }
    printf("\n\n");
}
