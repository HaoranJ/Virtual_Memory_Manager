//
//  Clock.h
//  Virtual Memory Management
//
//  Created by Haoran Jia on 4/20/15.
//  Copyright (c) 2015 Haoran Jia. All rights reserved.
//

#ifndef __Virtual_Memory_Management__Clock__
#define __Virtual_Memory_Management__Clock__

#include <stdio.h>
#include "MMU.h"

class Clock : public MMU
{
public:
    int ptr;
    
    int PageOut();
    
    void PageIn(int idx);
};


#endif /* defined(__Virtual_Memory_Management__Clock__) */
