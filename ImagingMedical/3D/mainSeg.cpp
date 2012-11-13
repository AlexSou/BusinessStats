/* 
 * File:   mainSeg.cpp
 * Author: A Soulier
 *
 * Created on November 2009
 */

#include <stdlib.h>
#include "RegSegmentation.h"



/*
 * 
 */
int main(int argc, char** argv) {
printf("0");
    RegSegmentation aa;
    printf("1");
    aa.readImage("/Users/ale/Documents/RegSegTest/HeadCT.vtk");
    printf("2");
    aa.setCoords(34,74,32);
    printf("3");
    aa.setLower(1300);
    printf("4");
    aa.setUpper(4000);
    printf("5 ");
    aa.writeImage("/Users/ale/Documents/RegSegTest/HeadCTOut.vtk");
    printf("Done.\n");
    return (EXIT_SUCCESS);
}

