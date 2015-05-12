//
//  PTE.h
//  Virtual Memory Management
//
//  Created by Haoran Jia on 4/9/15.
//  Copyright (c) 2015 Haoran Jia. All rights reserved.
//

#ifndef Virtual_Memory_Management_PTE_h
#define Virtual_Memory_Management_PTE_h

using namespace::std;

struct PTE
{
    unsigned int present:1; //bitfield occupies 1 bit
    unsigned int modified:1;
    unsigned int referenced:1;
    unsigned int pagedout:1;
    unsigned int index:6;
    
    PTE()
    {
        present = 0;
        modified = 0;
        referenced = 0;
        pagedout = 0;
        index = 0;
    }
};


#endif
