#include "Wrappers.h"

cv::Mat 
wrapped_imread(std::string filename)
{
  return cv::imread(filename);
}

void 
wrapped_imwrite(std::string filename, cv::Mat mat)
{
  cv::imwrite(filename, mat);
}

cv::Mat
wrapped_imdecode(Rcpp::RawVector rawData)
{
  std::vector<uchar> bytes;
  bytes.resize(rawData.size());
  std::copy(rawData.begin(), rawData.end(), bytes.begin());
  cv::Mat image = cv::imdecode(bytes, CV_LOAD_IMAGE_COLOR);
  return image;
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




