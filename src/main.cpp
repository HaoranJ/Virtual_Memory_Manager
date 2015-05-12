//
//  main.cpp
//  Virtual Memory Management
//
//  Created by Haoran Jia on 4/9/15.
//  Copyright (c) 2015 Haoran Jia. All rights reserved.
//
#include <iostream>
#include <unistd.h>
#include <string>
#include <cstdlib>

#include "MMU.h"
#include "NRU.h"
#include "LRU.h"
#include "Random.h"
#include "FIFO.h"
#include "SecondChance.h"
#include "Clock.h"
#include "Aging.h"
#include "Clock_Virtual.h"
#include "Aging_Virtual.h"

using namespace::std;

int main(int argc, char * argv[])
{
    int c;
    string aValue = "l";
    string oValue = "";
    string fValue = "32";
    
    while ((c = getopt (argc, argv, "a:o:f:")) != -1)
        if (c == 'a')
            aValue = optarg;
        else
            if (c == 'o')
                oValue = optarg;
            else
                if (c == 'f')
                    fValue = optarg;
    
    string inputFileName = argv[optind];
    string randFileName = argv[optind + 1];
    
    bool OFlag = false;
    bool PFlag = false;
    bool FFlag = false;
    bool SFlag = false;
    bool pFlag = false;
    bool fFlag = false;
    
    for (int i = 0; i < oValue.length(); ++i)
    {
        if (oValue[i] == 'O')
            OFlag = true;
        if (oValue[i] == 'P')
            PFlag = true;
        if (oValue[i] == 'F')
            FFlag = true;
        if (oValue[i] == 'S')
            SFlag = true;
        if (oValue[i] == 'p')
            pFlag = true;
        if (oValue[i] == 'f')
            fFlag = true;
    }
    
    MMU* mmu;
    
    if(aValue == "N") { mmu = new NRU(); }
    if(aValue == "l") { mmu = new LRU(); }
    if(aValue == "r") { mmu = new Random(); }
    if(aValue == "f") { mmu = new FIFO(); }
    if(aValue == "s") { mmu = new SecondChance(); }
    if(aValue == "c") { mmu = new Clock(); }
    if(aValue == "a") { mmu = new Aging(); }
    if(aValue == "X") { mmu = new Clock_Virtual(); }
    if(aValue == "Y") { mmu = new Aging_Virtual(); }
    
    mmu->SetNumFrames(atoi(fValue.c_str()));
    mmu->Run(inputFileName, randFileName, OFlag, pFlag, fFlag);
    mmu->Print(PFlag, FFlag, SFlag);
    
    return 0;
}
