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
    aa.readImage("/vol/project/2009/362/g0936216/itkVTK/itkSeg/HeadCTSlice.vtk");
    printf("2");
    aa.setCoords(60,60);
    printf("3");
    aa.setLower(800);
    printf("4");
    aa.setUpper(4000);
    printf("5 ");
    aa.writeImage("/vol/project/2009/362/g0936216/itkVTK/itkSeg/HeadCTSliceOut.vtk");
    printf("Done.\n");
    return (EXIT_SUCCESS);
}

