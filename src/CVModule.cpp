
#include "Wrappers.h"

#include <Rcpp.h>
using namespace Rcpp;

// open CV includes.
#include <opencv2/opencv.hpp>

RCPP_EXPOSED_CLASS_NODECL(cv::Mat)
RCPP_EXPOSED_CLASS_NODECL(cv::Rect)
RCPP_EXPOSED_CLASS(wrappedCascadeClassifier)

RCPP_MODULE(rcv)
{
  
  function("imread", &wrapped_imread, 
    "Given the file path, reads an image into a cv::Mat object");
  function("imwrite", &wrapped_imwrite,
    "Given an R-wrapped cv::Mat object and a filename, writes the "
    "image to file");
  function("imdecode", &wrapped_imdecode,
    "Given a Raw data vector, decode it as a color image and return.");

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
    .method("load", &wrappedCascadeClassifier::load,
      "Attempts to load the classifier stored at the given XML file path")
    .method("empty", &wrappedCascadeClassifier::empty,
      "Returns TRUE if the classifier has not yet been loaded.")
    .method("detectMultiScale",&wrappedCascadeClassifier::detectMultiScale,
      "Takes a cv::Mat representing an image, returns list of rectangles"
      " around each face that was detected");
  
}


