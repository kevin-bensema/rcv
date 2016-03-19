
GetOpenCVHaarCascadeList <- function()
{
  # Returns a list of all the built-in OpenCV Haar cascades
  # Returns:
  #   a list of strings that can be passed to DefaultOpenCVHaarCascade
  #   to load a wrapped CascadeClassifier
  return(list(
    "haarcascade_eye.xml",
    "haarcascade_eye_tree_eyeglasses.xml",
    "haarcascade_frontalcatface.xml",
    "haarcascade_frontalcatface_extended.xml",
    "haarcascade_frontalface_alt.xml",
    "haarcascade_frontalface_alt2.xml",
    "haarcascade_frontalface_alt_tree.xml",
    "haarcascade_frontalface_default.xml",
    "haarcascade_fullbody.xml",
    "haarcascade_lefteye_2splits.xml",
    "haarcascade_licence_plate_rus_16stages.xml",
    "haarcascade_lowerbody.xml",
    "haarcascade_profileface.xml",
    "haarcascade_righteye_2splits.xml",
    "haarcascade_russian_plate_number.xml",
    "haarcascade_smile.xml",
    "haarcascade_upperbody.xml"))
}

GetOpenCVHaarCascadeClassifier <- function(cascade.name) {
  # Loads a default OpenCV classifier with the given name from rcv/inst
  #
  # Args:
  #   cascade.name: the name of the cascade to load.
  # 
  # Returns:
  #   a cvCascadeClassifier object loaded from the given xml name
  full.path <- system.file("haarcascades", cascade.name, package="rcv")
  cascade.classifier <- new(cvCascadeClassifier, full.path)
  return(cascade.classifier)
}

