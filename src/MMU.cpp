//
//  MMU.cpp
//  Virtual Memory Management
//
//  Created by Haoran Jia on 4/9/15.
//  Copyright (c) 2015 Haoran Jia. All rights reserved.
//

#include "MMU.h"

using namespace::std;

MMU::MMU()
{
    ofs = 0;
    numUsedFrames = 0;
    replaces = 0;
    
    inst_count = 0;
    unmaps = 0;
    maps = 0;
    ins = 0;
    outs = 0;
    zeros = 0;
    
    totalcost = 0;
    
    pageTable = new PTE[64];
}

void MMU::SetNumFrames(int _numFrames)
{
    numFrames = _numFrames;
    frameTable = new int[numFrames];
}

void MMU::InitRandValues(string randFileName)
{
    ifstream readFile;
    int rand;
    
    readFile.open(randFileName.c_str());
    readFile >> randTotalNum;
    while (readFile >> rand)
        randVals.push_back(rand);
}

int MMU::MyRandom(int size)
{
    if (ofs == randTotalNum)
        ofs = 0;
    return randVals[ofs++] % size;
}

void MMU::InitRef()
{
    for (int i = 0; i < 64; ++i)
        pageTable[i].referenced = 0;
}

void MMU::Run(string inputFileName, string randFileName, bool OFlag, bool pFlag, bool fFlag)
{
    InitRandValues(randFileName);
    InitRef();
    
    ifstream readFile;
    readFile.open(inputFileName.c_str());
    string line;
    while (getline(readFile, line))
        if (line[0] != '#')
        {
            int rw, idx;
            stringstream ss;
            ss << line;
            ss >> rw >> idx;
            
            PTE* inPage = pageTable + idx;
            if (OFlag)
                printf("==> inst: %d %d\n", rw, idx);
            if (inPage->present == 0)
            {
                if (numUsedFrames < numFrames)
                    inPage->index = numUsedFrames++;
                else
                {
                    int outIdx = PageOut();
                    PTE* outPage = pageTable + outIdx;
                    inPage->index = outPage->index;
                    if (OFlag)
                    {
                        ++unmaps;
                        printf("%d: UNMAP %d %d\n", inst_count, outIdx, outPage->index);
                        if (outPage->modified == 1)
                        {
                            ++outs;
                            outPage->pagedout = 1;
                            printf("%d: OUT %d %d\n", inst_count, outIdx, outPage->index);
                        }
                    }
                    outPage->present = 0;
                    outPage->modified = 0;
                    outPage->referenced = 0;
                }
                if (OFlag)
                {
                    if (inPage->pagedout == 0)
                    {
                        ++zeros;
                        printf("%d: ZERO   %d\n", inst_count, inPage->index);
                    }
                    else
                    {
                        ++ins;
                        printf("%d: IN %d %d\n", inst_count, idx, inPage->index);
                    }
                    ++maps;
                    printf("%d: MAP %d %d\n", inst_count, idx, inPage->index);
                }
            }
            inPage->present = 1;
            inPage->modified |= rw;
            inPage->referenced = 1;
            frameTable[inPage->index] = idx;
            PageIn(idx);
            ++inst_count;
            
            PrintP(pFlag);
            PrintF(fFlag);
        }
    readFile.close();
}

void MMU::PrintP(bool PFlag)
{
    if (PFlag)
    {
        for (int i = 0; i < 64; ++i)
        {
            PTE* p = pageTable + i;
            if (!p->present)
                if (p->pagedout)
                    printf("# ");
                else
                    printf("* ");
                else
                {
                    printf("%d:", i);
                    if (p->referenced)
                        printf("R");
                    else
                        printf("-");
                    if (p->modified)
                        printf("M");
                    else
                        printf("-");
                    if (p->pagedout)
                        printf("S ");
                    else
                        printf("- ");
                }
        }
        printf("\n");
    }
}

void MMU::PrintF(bool FFlag)
{
    if (FFlag)
    {
        for (int i = 0; i < numUsedFrames; ++i)
            printf("%d ", frameTable[i]);
        for (int i = numUsedFrames; i < numFrames; ++i)
            printf("* ");
        printf("\n");
    }
}

void MMU::PrintS(bool SFlag)
{
    if (SFlag)
    {
        totalcost = (maps +unmaps) * 400 + (ins + outs) * 3000 + zeros * 150 + inst_count;
        printf("SUM %d U=%d M=%d I=%d O=%d Z=%d ===> %llu\n", inst_count, unmaps, maps, ins, outs, zeros, totalcost);
    }
}

void MMU::Print(bool PFlag, bool FFlag, bool SFlag)
{
    PrintP(PFlag);
    PrintF(FFlag);
    PrintS(SFlag);
}