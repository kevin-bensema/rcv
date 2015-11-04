#ifndef Wrappers_h
#define Wrappers_h

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

cv::Mat wrappedImRead(std::string filename);
void wrappedImWrite(std::string filename, cv::Mat mat);

#endif

