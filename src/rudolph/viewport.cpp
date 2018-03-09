#include "viewport.h"

using namespace rudolph;

ViewPort::ViewPort(geometry::Point top_left, geometry::Point bottom_right):
    _top_left{top_left},
    _bottom_right{bottom_right}
{}