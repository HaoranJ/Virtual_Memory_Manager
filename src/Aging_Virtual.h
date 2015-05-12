//
//  Aging_Virtual.h
//  Virtual Memory Management
//
//  Created by Haoran Jia on 4/20/15.
//  Copyright (c) 2015 Haoran Jia. All rights reserved.
//

#ifndef __Virtual_Memory_Management__Aging_Virtual__
#define __Virtual_Memory_Management__Aging_Virtual__

#include <stdio.h>
#include "MMU.h"

class Aging_Virtual : public MMU
{
public:
    long long age[64];
    
    int PageOut();
    
    void PageIn(int idx);};
#endif /* defined(__Virtual_Memory_Management__Aging_Virtual__) */
