
OpenCVRectToRList <- function(opencv.rect)
{
  # Converts an OpenCV Wrapped C++ Rect to a named R list
  #
  # Args:
  #   opencv.rect: a C++ wrapped cv::Rect object to be converted to a named
  #                R list storing the x, y, width, and height fields.
  # 
  # Returns:
  #   A named list with four elements: the argument rectangle's x, and y
  #   coordinates for it's lower-left corner, along with the width and height
  output <- list()
  output$x = opencv.rect$x
  output$y = opencv.rect$y
  output$width = opencv.rect$width
  output$height = opencv.rect$height
  return(output)
}


