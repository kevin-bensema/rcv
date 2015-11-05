#ifndef Wrappers_h
#define Wrappers_h

#include <Rcpp.h>

// open CV includes.
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect/objdetect.hpp>

#include <string>
#include <vector>

class wrappedCascadeClassifier
{
public:
  wrappedCascadeClassifier();
  wrappedCascadeClassifier(std::string filename);
  
  bool load(std::string classifier);
  bool empty();
  
  std::vector<cv::Rect> detectMultiScale(cv::Mat image);
private:
  cv::CascadeClassifier internal;
  float scaleFactor;
};

cv::Mat wrapped_imread(std::string filename);
void wrapped_imwrite(std::string filename, cv::Mat mat);
cv::Mat wrapped_imdecode(Rcpp::RawVector);

#endif

