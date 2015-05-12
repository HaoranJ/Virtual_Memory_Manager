//
//  SecondChance.cpp
//  Virtual Memory Management
//
//  Created by Haoran Jia on 4/20/15.
//  Copyright (c) 2015 Haoran Jia. All rights reserved.
//

#include "SecondChance.h"

int SecondChance::PageOut()
{
    while (pageTable[l.front()].referenced)
    {
        pageTable[l.front()].referenced = 0;
        l.push_back(l.front());
        l.pop_front();
    }
    int ret = l.front();
    l.pop_front();
    return ret;
}

void SecondChance::PageIn(int idx)
{
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
        if (*it == idx)
            return;
    l.push_back(idx);
}