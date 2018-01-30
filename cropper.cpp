#include <iostream>
#include <string>

#include <Magick++.h>

#include "QuadImage.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;

using Magick::Image;

int main()
{
  const string TestImagePath = "test_images/IMG.jpg";

  QuadImage testImage(TestImagePath, 0.45, 0.43, 0.4, 0.6);
  Image croppedImage = testImage.getQuad(QuadImage::Quad::first);
  croppedImage.display();
  croppedImage = testImage.getQuad(QuadImage::Quad::second);
  croppedImage.display();
  croppedImage = testImage.getQuad(QuadImage::Quad::third);
  croppedImage.display();
  croppedImage = testImage.getQuad(QuadImage::Quad::forth);
  croppedImage.display();
  return 0;
}

