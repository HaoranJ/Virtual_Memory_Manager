//
//  Random.cpp
//  Virtual Memory Management
//
//  Created by Haoran Jia on 4/20/15.
//  Copyright (c) 2015 Haoran Jia. All rights reserved.
//

#include "Random.h"

int Random::PageOut()
{
    return frameTable[MyRandom(numFrames)];
}

void Random::PageIn(int idx)
{
}