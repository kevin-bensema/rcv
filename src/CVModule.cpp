
#include "Wrappers.h"

#include <Rcpp.h>
using namespace Rcpp;

// open CV includes.
#include <opencv2/opencv.hpp>

RCPP_EXPOSED_CLASS(cv::Mat)
RCPP_EXPOSED_CLASS_NODECL(cv::Rect)
RCPP_EXPOSED_CLASS(wrappedCascadeClassifier)

RCPP_MODULE(rcv)
{
  
  function("imread", &wrappedImRead);
  function("imwrite", &wrappedImWrite);
  
  class_<cv::Mat>("cvMat")
    .field_readonly("cols", &cv::Mat::cols)
    .field_readonly("rows", &cv::Mat::rows);
  
  class_<cv::Rect>("cvRect")
    .field("x", &cv::Rect::x)
    .field("y", &cv::Rect::y)
    .field("width", &cv::Rect::width)
    .field("height", &cv::Rect::height);
  
  class_<wrappedCascadeClassifier>("cvCascadeClassifier")
    .constructor()
    .constructor<std::string>()
    .method("load", &wrappedCascadeClassifier::load)
    .method("empty", &wrappedCascadeClassifier::empty)
    .method("detectMultiScale", &wrappedCascadeClassifier::detectMultiScale);
  
}


