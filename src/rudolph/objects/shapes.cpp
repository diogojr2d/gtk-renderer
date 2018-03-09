#include "shapes.h"

using namespace rudolph;
using namespace objects;

Point::Point(int x, int y):
    _x{x},
    _y{y}
{

}

void Point::draw(render::RenderTarget &) const {
    
}