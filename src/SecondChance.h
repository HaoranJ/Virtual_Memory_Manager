//
//  SecondChance.h
//  Virtual Memory Management
//
//  Created by Haoran Jia on 4/20/15.
//  Copyright (c) 2015 Haoran Jia. All rights reserved.
//

#ifndef __Virtual_Memory_Management__SecondChance__
#define __Virtual_Memory_Management__SecondChance__

#include <stdio.h>
#include <list>
#include "MMU.h"

class SecondChance : public MMU
{
public:
    list<int> l;
    
    int PageOut();
    
    void PageIn(int idx);

};
#endif /* defined(__Virtual_Memory_Management__SecondChance__) */
