//
//  Aging.h
//  Virtual Memory Management
//
//  Created by Haoran Jia on 4/20/15.
//  Copyright (c) 2015 Haoran Jia. All rights reserved.
//

#ifndef __Virtual_Memory_Management__Aging__
#define __Virtual_Memory_Management__Aging__

#include <stdio.h>
#include "MMU.h"

class Aging : public MMU
{
public:
    long long age[64];
    
    int PageOut();
    
    void PageIn(int idx);
};
#endif /* defined(__Virtual_Memory_Management__Aging__) */
