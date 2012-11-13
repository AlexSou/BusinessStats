/* 
 * File:   RegSegmentationCommand.cpp
 * Author: coudy
 * 
 * Created on 01 December 2009, 01:22
 */

#include <vtk-5.0/vtkStructuredPointsWriter.h>

#include "RegSegmentationCommand.h"
#include "RegSegmentation.h"

const char *RegSegmentationCommand::OUTPUT_VTK_FILENAME = "_seg_in.vtk";
const char *RegSegmentationCommand::SEGMENTED_VTK_FILENAME = "_seg_out.vtk";

RegSegmentationCommand::RegSegmentationCommand(ImageStore *imageStore)
    : SliceSegmentationCommand(imageStore) {
}

RegSegmentationCommand::~RegSegmentationCommand() {
}

vtkStructuredPoints *RegSegmentationCommand::Preview() {
  return ApplySegmentation(imageStore_->GetImage(IMAGE_SLOT_CURRENT));
}

vtkStructuredPoints *RegSegmentationCommand::ApplySegmentation(
    vtkStructuredPoints* slice) {

  RegSegmentation regSeg;

  // Store original image on disk
  vtkStructuredPointsWriter *sliceWriter = vtkStructuredPointsWriter::New();
  sliceWriter->SetInput(slice);
  sliceWriter->SetFileName(OUTPUT_VTK_FILENAME);
  sliceWriter->Update();
  sliceWriter->Write();

  // Perform segmentation
  regSeg.ReadImage(OUTPUT_VTK_FILENAME);
  regSeg.SetCoords(coords_[0], coords_[1]);
  regSeg.SetLower(lowerLimit_);
  regSeg.SetUpper(upperLimit_);
  regSeg.WriteImage(SEGMENTED_VTK_FILENAME);

  // Pick up segmented image
  vtkStructuredPointsReader *itkMaskReader = vtkStructuredPointsReader::New();
  itkMaskReader->SetFileName(SEGMENTED_VTK_FILENAME);
  itkMaskReader->Update();

  return itkMaskReader->GetOutput();

}
