/* 
 * File:   RegSegmentation.h
 * Author: A Soulier
 *
 * Created on November 2009
 */

#ifndef _REGSEGMENTATION_H
#define	_REGSEGMENTATION_H

#include "itkConnectedThresholdImageFilter.h"
#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkMinimumMaximumImageCalculator.h"
#include "itkCastImageFilter.h"

class RegSegmentation {
public:
    

    RegSegmentation();
  
    virtual ~RegSegmentation();

      typedef signed short PixelInT;
      typedef unsigned char PixelOutT;
//unsigned char


    void readImage(const char * file);
    void setCoords(int x, int y, int z);
    void setLower(PixelInT lowerPix);
    void setUpper(PixelInT upperPix);
    void delCoords();
    void writeImage(const char * file);


private:
      
      RegSegmentation(const RegSegmentation& orig);
      

      bool imageSet_;
      bool coordSet_;
      bool upperSet_;
      bool lowerSet_;

      enum {DimensionIn = 3};
      enum {DimensionOut = 3};
      enum {DimensionProc = 3};

      
      typedef float PixelProcT;

      typedef itk::Image<PixelInT,DimensionIn> ImageInT;
      typedef itk::Image<PixelOutT,DimensionOut> ImageOutT;
      typedef itk::Image<PixelProcT,DimensionProc> ImageProcT;
      
      typedef itk::ImageFileReader<ImageInT> ImgReaderT;
      typedef itk::ImageFileWriter<ImageOutT> ImgWriterT;

      typedef itk::ConnectedThresholdImageFilter<ImageProcT, ImageProcT> CTIFT;
      typedef itk::CastImageFilter<ImageInT, ImageProcT> CastFilterInType;
      typedef itk::CastImageFilter<ImageProcT, ImageOutT> CastFilterOutType;

      typedef CTIFT::IndexType IndexTypeSeed;
      
      CTIFT::Pointer imgCTIF_;
      ImgReaderT::Pointer imgReader_;
      ImgWriterT::Pointer imgWriter_;
      CastFilterInType::Pointer imgCastFilterIn_;
        CastFilterOutType::Pointer imgCastFilterOut_;
      

};

#endif	/* _REGSEGMENTATION_H */

