//
//  Clock_Virtual.h
//  Virtual Memory Management
//
//  Created by Haoran Jia on 4/20/15.
//  Copyright (c) 2015 Haoran Jia. All rights reserved.
//

#ifndef __Virtual_Memory_Management__Clock_Virtual__
#define __Virtual_Memory_Management__Clock_Virtual__

#include <stdio.h>
#include "MMU.h"

class Clock_Virtual : public MMU
{
public:
    int ptr;
    
    int PageOut();
    
    void PageIn(int idx);
};

#endif /* defined(__Virtual_Memory_Management__Clock_Virtual__) */
