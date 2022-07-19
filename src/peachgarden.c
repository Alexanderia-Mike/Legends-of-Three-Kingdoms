//
//  peachgarden.c
//  Legends of the Three Kingdoms
//
//  Created by 娄辰飞 on 2018/11/16.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "project.h"

void peachgarden(int* nump, cards* card, int numofcard, int* wine, int* playphase, int* drawphase, int* reveal, playerp head, int demo){
    playerp q=head->next;
    while(q!=NULL){
        changehealth(1, q, nump, card, numofcard, wine, playphase, drawphase, reveal, head, demo);
        q=q->next;
    }
}
