
defaultFrontalFaceClassifier <- function()
{
  front = system.file("trained_data", "haarcascade_frontalface_alt2.xml",
                      package = "rcv")
  cc = new(cvCascadeClassifier, front)
  return(cc)
}


