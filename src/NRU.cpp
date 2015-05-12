//
//  NRU.cpp
//  Virtual Memory Management
//
//  Created by Haoran Jia on 4/9/15.
//  Copyright (c) 2015 Haoran Jia. All rights reserved.
//

#include "NRU.h"

int NRU::PageOut()
{
    vector<int> arr[4];
    for (int i = 0; i < 64; ++i)
    {
        PTE* p = pageTable + i;
        if (p->present)
            arr[p->referenced * 2 + p->modified].push_back(i);
    }
    ++replaces;
    if (replaces == 10)
    {
        replaces = 0;
        InitRef();
    }
    for (int i = 0; i < 4; ++i)
        if (arr[i].size() > 0)
            return arr[i][MyRandom((int)arr[i].size())];
    return -1;
}

void NRU::PageIn(int idx)
{
}