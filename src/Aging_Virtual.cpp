//
//  Aging_Virtual.cpp
//  Virtual Memory Management
//
//  Created by Haoran Jia on 4/20/15.
//  Copyright (c) 2015 Haoran Jia. All rights reserved.
//

#include "Aging_Virtual.h"

int Aging_Virtual::PageOut()
{
    for (int pi = 0; pi < 64; ++pi)
    {
        age[pi] = (age[pi] >> 1) & (((long long)1 << 32) - (long long)1);
        if (pageTable[pi].referenced)
            age[pi] |= (long long)1 << 31;
        pageTable[pi].referenced = 0;
    }
    
    int oldest = -1;
    for (int i = 0; i < 64; ++i)
    {
        PTE* p = pageTable + i;
        if (p->present)
            if (oldest == -1 || age[i] < age[oldest])
                oldest = i;
    }
    age[oldest] = 0;
    return oldest;
}

void Aging_Virtual::PageIn(int idx)
{
}