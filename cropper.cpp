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

  QuadImage testImage(TestImagePath, 0.5, 0.5, 0.5, 0.5);
  testImage.displayThumbnail(QuadImage::Quad::first);
  return 0;
}

