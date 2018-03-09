#ifndef RUDOLPH_VIEWPORT_H
#define RUDOLPH_VIEWPORT_H

#include <gtk/gtk.h>

#include "geometry.h"

namespace rudolph {

class ViewPort {
public:
    ViewPort(geometry::Point, geometry::Point);

    geometry::Point top_left() const
    {
        return _top_left;
    }

    geometry::Point bottom_right() const
    {
        return _bottom_right;
    }

private:
    geometry::Point _top_left;
    geometry::Point _bottom_right;
};

}

#endif
