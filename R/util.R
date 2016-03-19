# utility functions for the object-detect OpenCV framework

# convert a cv::Rect to a named R list.
cvrect.to.rlist <- function(cvrect)
{
  output <- list()
  output$x = cvrect$x
  output$y = cvrect$y
  output$width = cvrect$width
  output$height = cvrect$height
  return(output)
}


