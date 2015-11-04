#include "Wrappers.h"

cv::Mat wrappedImRead(std::string filename)
{
  return cv::imread(filename);
}

void 
wrappedImWrite(std::string filename, cv::Mat mat)
{
  cv::imwrite(filename, mat);
}

///////////////////////////////////////
//// CascadeClassifier wrapper    /////
///////////////////////////////////////
wrappedCascadeClassifier::wrappedCascadeClassifier()
  : scaleFactor(1.1f) {}

wrappedCascadeClassifier::wrappedCascadeClassifier(std::string name)
  : internal(name), scaleFactor(1.1f) {}

bool
wrappedCascadeClassifier::load(std::string classifier)
{
  return internal.load(classifier);
}

bool
wrappedCascadeClassifier::empty()
{
  return internal.empty();
}

std::vector<cv::Rect> 
wrappedCascadeClassifier::detectMultiScale(cv::Mat image)
{
  std::vector<cv::Rect> objects;
  internal.detectMultiScale(image, objects, scaleFactor);
  return objects;
}


