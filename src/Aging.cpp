//
//  Aging.cpp
//  Virtual Memory Management
//
//  Created by Haoran Jia on 4/20/15.
//  Copyright (c) 2015 Haoran Jia. All rights reserved.
//

#include "Aging.h"

int Aging::PageOut()
{
    for (int pi = 0; pi < numFrames; ++pi)
    {
        age[pi] = (age[pi] >> 1) & (((long long)1 << 32) - (long long)1);
        if (pageTable[frameTable[pi]].referenced)
            age[pi] |= (long long)1 << 31;
        pageTable[frameTable[pi]].referenced = 0;
    }
    
    int oldest = 0;
    for (int i = 0; i < numFrames; ++i)
        if (age[oldest] > age[i])
            oldest = i;
    age[oldest] = 0;
    return frameTable[oldest];
}

void Aging::PageIn(int idx)
{
}