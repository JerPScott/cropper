#include <Magick++.h>

#include "QuadImage.hpp"

QuadImage::QuadImage(const string& imagePath,
                     double widthFractionLeft,
                     double widthFractionRight,
                     double heightFractionTop,
                     double heightFractionBottom)
  : m_image(imagePath),
    m_widthFractionLeft(widthFractionLeft),
    m_widthFractionRight(widthFractionRight),
    m_heightFractionTop(heightFractionTop),
    m_heightFractionBottom(heightFractionBottom)
{ }

void QuadImage::display()
{
  m_image.display();
}

Magick::Image QuadImage::getQuad(Quad quad)
{
  size_t x, y, width, height;
  size_t width_l = m_image.columns() * m_widthFractionRight;
  size_t width_r = m_image.columns() * m_widthFractionRight;
  size_t height_t = m_image.rows() * m_heightFractionTop;
  size_t height_b = m_image.rows() * m_heightFractionBottom;

  // Select correct image region
  switch(quad)
  {
    case QuadImage::Quad::first:
      width = width_l;
      height = height_t;
      x = y = 0;
      break;
    case QuadImage::Quad::second:
      width = width_r;
      height = height_t;
      x = m_image.columns() - width;
      y = 0;
      break;
    case QuadImage::Quad::third:
      width = width_l;
      height = height_b;
      x = 0;
      y = m_image.rows() - height;
      break;
    case QuadImage::Quad::forth:
      width = width_r;
      height = height_b;
      x = m_image.columns() - width;
      y = m_image.rows() - height;
      break;
  }

  Magick::Image crop_image(m_image);
  crop_image.crop(Magick::Geometry(width, height, x, y));

  return crop_image;
}
