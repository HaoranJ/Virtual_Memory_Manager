//
//  Clock.cpp
//  Virtual Memory Management
//
//  Created by Haoran Jia on 4/20/15.
//  Copyright (c) 2015 Haoran Jia. All rights reserved.
//

#include "Clock.h"

int Clock::PageOut()
{
    while (true)
    {
        PTE* p = pageTable + frameTable[ptr];
        if (p->referenced == 0)
            break;
        p->referenced = 0;
        if (++ptr == numFrames)
            ptr = 0;
    }
    int ret = frameTable[ptr];
    if (++ptr == numFrames)
        ptr = 0;
    return ret;
}

void Clock::PageIn(int idx)
{
}