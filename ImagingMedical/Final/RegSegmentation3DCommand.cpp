/* 
 * File:   RegSegmentation3DCommand.cpp
 * Author: coudy
 * 
 * Created on 01 January 2010, 18:43
 */

#include <vtk-5.0/vtkStructuredPointsWriter.h>

#include "RegSegmentation3DCommand.h"
#include "RegSegmentation3D.h"

const char *RegSegmentation3DCommand::OUTPUT_VTK_FILENAME = "_seg_in.vtk";
const char *RegSegmentation3DCommand::SEGMENTED_VTK_FILENAME = "_seg_out.vtk";

RegSegmentation3DCommand::RegSegmentation3DCommand(ImageStore *imageStore) :
    Segmentation3DCommand(imageStore) {
}

RegSegmentation3DCommand::~RegSegmentation3DCommand() {
}

vtkStructuredPoints *RegSegmentation3DCommand::Preview() {
  //return ApplySegmentation(imageStore_->GetImage(IMAGE_SLOT_CURRENT));
  return NULL;
}

vtkStructuredPoints *RegSegmentation3DCommand::ApplySegmentation(
    vtkStructuredPoints *image) {

  RegSegmentation3D regSeg;

  // Store original image on disk
  vtkStructuredPointsWriter *originalWriter = vtkStructuredPointsWriter::New();
  originalWriter->SetInput(image);
  originalWriter->SetFileName(OUTPUT_VTK_FILENAME);
  originalWriter->Update();
  originalWriter->Write();

  // Perform segmentation
  regSeg.ReadImage(OUTPUT_VTK_FILENAME);
  regSeg.SetCoords(coords_[0], coords_[1], coords_[2]);
  regSeg.SetLower(lowerLimit_);
  regSeg.SetUpper(upperLimit_);
  regSeg.WriteImage(SEGMENTED_VTK_FILENAME);

  // Pick up segmented image
  vtkStructuredPointsReader *itkMaskReader = vtkStructuredPointsReader::New();
  itkMaskReader->SetFileName(SEGMENTED_VTK_FILENAME);
  itkMaskReader->Update();

  return itkMaskReader->GetOutput();
}
