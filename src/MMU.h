//
//  MMU.h
//  Virtual Memory Management
//
//  Created by Haoran Jia on 4/9/15.
//  Copyright (c) 2015 Haoran Jia. All rights reserved.
//

#ifndef __Virtual_Memory_Management__MMU__
#define __Virtual_Memory_Management__MMU__

#include <vector>
#include <fstream>
#include <list>
#include <sstream>

#include "PTE.h"

using namespace::std;

class MMU
{
public:
    int ofs;
    int numFrames;
    int numUsedFrames;
    int replaces;
    
    int inst_count;
    int unmaps;
    int maps;
    int ins;
    int outs;
    int zeros;
    
    int randTotalNum;
    
    long long totalcost;
    
    vector<int> randVals;
    
    PTE* pageTable;
    int* frameTable;
    
    MMU();
    
    int MyRandom(int burst);
    
    void InitRef();
    
    void SetNumFrames(int _numFrames);
    
    void InitRandValues(string randFileName);
    
    void Run(string inputFileName, string randFileName, bool OFlag, bool pFlag, bool fFlag);
    
    void PrintP(bool PFlag);
    
    void PrintF(bool FFlag);
    
    void PrintS(bool SFlag);
    
    void Print(bool PFlag, bool FFlag, bool SFlag);
    
    virtual int PageOut() = 0;
    
    virtual void PageIn(int idx) = 0;
};


#endif /* defined(__Virtual_Memory_Management__MMU__) */
