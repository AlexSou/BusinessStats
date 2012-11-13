/* 
 * File:   RegSegmentationCommand.h
 * Author: A. Soulier
 *
 * Created on December 2009
 */

#ifndef _REGSEGMENTATIONCOMMAND_H
#define	_REGSEGMENTATIONCOMMAND_H

#include <sstream>

#include "Workspace.h"
#include "SliceSegmentationCommand.h"

class RegSegmentationCommand : public SliceSegmentationCommand {
public:
  RegSegmentationCommand(ImageStore *imageStore);
  virtual ~RegSegmentationCommand();

  std::string ToString() const {
    std::ostringstream str;
    str << "Region Growing on Slice #" << sliceNum_;
    return str.str();
  }

  vtkStructuredPoints *Preview();

  void SetUpperLimit(short upperLimit) { upperLimit_ = upperLimit; }

  short GetUpperLimit() const { return upperLimit_; }

  void SetLowerLimit(short lowerLimit) { lowerLimit_ = lowerLimit; }

  short GetLowerLimit() const { return lowerLimit_; }

  void SetCoords(int x, int y) { coords_[0] = x; coords_[1] = y; }

  const int *GetCoords() const { return coords_; }

protected:
  vtkStructuredPoints *ApplySegmentation(vtkStructuredPoints *mask);

private:
  RegSegmentationCommand(const RegSegmentationCommand&);

  static const char *OUTPUT_VTK_FILENAME;
  static const char *SEGMENTED_VTK_FILENAME;

  int slice_;
  int coords_[2];
  short lowerLimit_, upperLimit_;

};

#endif	/* _REGSEGMENTATIONCOMMAND_H */

