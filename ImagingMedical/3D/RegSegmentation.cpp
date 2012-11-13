/* 
 * File:   RegSegmentation.cpp
 * Author: A Soulier
 * 
 * Created on November 2009
 */

#include "RegSegmentation.h"




RegSegmentation::RegSegmentation() {
        imageSet_ = false;
        coordSet_ = false;
        upperSet_ = false;
        lowerSet_ = false;
        imgReader_ = ImgReaderT::New();
        imgWriter_ = ImgWriterT::New();
        imgCastFilterIn_ = CastFilterInType::New();
        imgCastFilterOut_ = CastFilterOutType::New();
        imgCTIF_ = CTIFT::New();

}



 void RegSegmentation::readImage(const char * file) {

     //printf("%s", file);
     imgReader_->SetFileName(file);
     imgReader_->Update();

     //typedef itk::MinimumMaximumImageCalculator<ImageProcT> imgCalc;
     //imgCalc::Pointer calc = imgCalc::New();

     imgCastFilterIn_->SetInput(imgReader_->GetOutput());

     imgCastFilterIn_->Update();

     imgCTIF_->SetInput(imgCastFilterIn_->GetOutput());

     imgCTIF_->Update();
     //calc->SetImage(imgCTIF_->GetOutput());
     //calc->ComputeMaximum();
     //const float max = calc->GetMaximum();
     //PixelOutT outRepPixel = static_cast<PixelOutT>(max * 1.1);

     //imgCTIF_->SetReplaceValue(outRepPixel);

     
    imageSet_ = true;
 }

 void RegSegmentation::setCoords(int x, int y, int z ) {

     IndexTypeSeed seed;
     seed[0] = static_cast<IndexTypeSeed::IndexValueType>(x);
     seed[1] = static_cast<IndexTypeSeed::IndexValueType>(y);
     seed[2] = static_cast<IndexTypeSeed::IndexValueType>(z);

     imgCTIF_->SetSeed(seed);

    coordSet_ = true;
 }

 void RegSegmentation::setLower(PixelInT lowerPix) {
     imgCTIF_->SetLower(static_cast<PixelInT> (lowerPix) );

     lowerSet_ = true;
 }

 void RegSegmentation::setUpper(PixelInT upperPix) {
    imgCTIF_->SetUpper(static_cast<PixelInT> (upperPix) );

     upperSet_ = true;
 }


 void RegSegmentation::delCoords() {
     imgCTIF_->ClearSeeds();
     coordSet_ = false;
 }

void RegSegmentation::writeImage(const char * file) {

    if(imageSet_ && coordSet_ && upperSet_ && lowerSet_) {
        
        //imgCTIF_->SetReplaceValue(255);
        imgCTIF_->Update();

        imgCastFilterOut_->SetInput(imgCTIF_->GetOutput());
        imgCastFilterOut_->Update();

        imgWriter_->SetInput(imgCastFilterOut_->GetOutput());
        imgWriter_->SetFileName(file);

        try
        {
            imgWriter_->Update();
        }
        catch( itk::ExceptionObject & excep )
        {
            std::cerr << "Exception when writing  segmented image." << std::endl;
            std::cerr << excep << std::endl;
            exit(EXIT_FAILURE);
        }
        


    }

 }


RegSegmentation::RegSegmentation(const RegSegmentation& orig) {
}

RegSegmentation::~RegSegmentation() {
}

