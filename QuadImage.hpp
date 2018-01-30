#include <iosfwd>
#include <vector>

#include <Magick++.h>

using std::string;
using std::vector;

using Magick::Image;
using Magick::Geometry;

class QuadImage
{
  public:
    enum class Quad
    {
      // Top Left
      first = 0,

      // Top Right
      second = 1,

      // Bottom Left
      third = 2,

      // Bottom Right
      forth = 3
    };

    // Create a quad image with explicit width and height fractions.
    QuadImage(const string&, double, double, double, double);

    // Get the specified quad.
    Image getQuad(Quad);

    // Display the image.
    void display();

    // Dislpay a thumbnail of the image.
    void displayThumbnail(Quad);

  private:
    Image m_image;
    double m_widthFractionLeft;
    double m_widthFractionRight;
    double m_heightFractionTop;
    double m_heightFractionBottom;
};
