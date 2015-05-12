//
//  LRU.cpp
//  Virtual Memory Management
//
//  Created by Haoran Jia on 4/20/15.
//  Copyright (c) 2015 Haoran Jia. All rights reserved.
//

#include "LRU.h"

int LRU::PageOut()
{
    int ret = l.back();
    l.pop_back();
    return ret;
}

void LRU::PageIn(int idx)
{
    l.remove(idx);
    l.push_front(idx);
}