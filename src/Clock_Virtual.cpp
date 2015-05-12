//
//  Clock_Virtual.cpp
//  Virtual Memory Management
//
//  Created by Haoran Jia on 4/20/15.
//  Copyright (c) 2015 Haoran Jia. All rights reserved.
//

#include "Clock_Virtual.h"

int Clock_Virtual::PageOut()
{
    while (true)
    {
        PTE* p = pageTable + ptr;
        if (p->present)
        {
            if (p->referenced == 0)
                break;
            p->referenced = 0;
        }
        if (++ptr == 64)
            ptr = 0;
    }
    int ret = ptr;
    if (++ptr == 64)
        ptr = 0;
    return ret;
}

void Clock_Virtual::PageIn(int idx)
{
}