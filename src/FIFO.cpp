//
//  FIFO.cpp
//  Virtual Memory Management
//
//  Created by Haoran Jia on 4/20/15.
//  Copyright (c) 2015 Haoran Jia. All rights reserved.
//

#include "FIFO.h"

int FIFO::PageOut()
{
    int ret = l.front();
    l.pop_front();
    return ret;
}

void FIFO::PageIn(int idx)
{
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
        if (*it == idx)
            return;
    l.push_back(idx);
}