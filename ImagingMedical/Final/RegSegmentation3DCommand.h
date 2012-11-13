/*
 * File:   RegSegmentationCommand.h
 * Author: A. Soulier
 *
 * Created on December 2009
 */

#ifndef _REGSEGMENTATION3DCOMMAND_H
#define	_REGSEGMENTATION3DCOMMAND_H

#include <sstream>

#include "Workspace.h"
#include "Segmentation3DCommand.h"

class RegSegmentation3DCommand : public Segmentation3DCommand {
public:
  RegSegmentation3DCommand(ImageStore *imageStore);
  virtual ~RegSegmentation3DCommand();

  std::string ToString() const {
    std::ostringstream str;
    str << "3D Region Growing (" << coords_[0] << "," << coords_[1] << ","
        << coords_[2] << ")";
    return str.str();
  }

  vtkStructuredPoints *Preview();

  void SetUpperLimit(short upperLimit) { upperLimit_ = upperLimit; }

  short GetUpperLimit() const { return upperLimit_; }

  void SetLowerLimit(short lowerLimit) { lowerLimit_ = lowerLimit; }

  short GetLowerLimit() const { return lowerLimit_; }

  void SetCoords(int x, int y, int z) { coords_[0] = x; coords_[1] = y; coords_[2] = z; }

  const int *GetCoords() const { return coords_; }

protected:
  vtkStructuredPoints *ApplySegmentation(vtkStructuredPoints *mask);

private:
  RegSegmentation3DCommand(const RegSegmentation3DCommand&);

  static const char *OUTPUT_VTK_FILENAME;
  static const char *SEGMENTED_VTK_FILENAME;

  int slice_;
  int coords_[3];
  short lowerLimit_, upperLimit_;

};

#endif	/* _REGSEGMENTATION3DCOMMAND_H */

