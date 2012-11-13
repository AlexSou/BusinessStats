/*
 * File:   RegSegmentation3D.h
 * Author: A Soulier
 *
 * Created on December 2009
 */

#ifndef _REGSEGMENTATION3D_H
#define	_REGSEGMENTATION3D_H

#include "BasicFilters/itkConnectedThresholdImageFilter.h"
#include "Common/itkImage.h"
#include "IO/itkImageFileReader.h"
#include "IO/itkImageFileWriter.h"
#include "BasicFilters/itkMinimumMaximumImageCalculator.h"
#include "BasicFilters/itkCastImageFilter.h"

/** Performs region growing segmentation using ITK. */
class RegSegmentation3D {
public:

  RegSegmentation3D();

  virtual ~RegSegmentation3D();

  typedef signed short PixelInT;
  typedef unsigned char PixelOutT;
  //unsigned char

  void ReadImage(const char * file);
  void SetCoords(int x, int y, int z);
  void SetLower(PixelInT lowerPix);
  void SetUpper(PixelInT upperPix);
  void DelCoords();
  void WriteImage(const char * file);
  void SetReplaceVal(int replaceVal);

private:

  RegSegmentation3D(const RegSegmentation3D&);

  bool imageSet_;
  bool coordSet_;
  bool upperSet_;
  bool lowerSet_;

  enum { DimensionIn = 3 };
  enum { DimensionOut = 3 };
  enum { DimensionProc = 3 };


  typedef float PixelProcT;

  typedef itk::Image<PixelInT, DimensionIn> ImageInT;
  typedef itk::Image<PixelOutT, DimensionOut> ImageOutT;
  typedef itk::Image<PixelProcT, DimensionProc> ImageProcT;

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

#endif	/* _REGSEGMENTATION3D_H */

