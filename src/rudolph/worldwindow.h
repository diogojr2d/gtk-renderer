#ifndef RUDOLPH_WORLD_WINDOW_H
#define RUDOLPH_WORLD_WINDOW_H

#include <gtk/gtk.h>

#include "geometry.h"

namespace rudolph {

class WorldWindow {
public:
    WorldWindow(geometry::Point, geometry::Point);

    geometry::Point bottom_left() const
    {
        return _bottom_left;
    }

    geometry::Point top_right() const
    {
        return _top_right;
    }

private:
    geometry::Point _bottom_left;
    geometry::Point _top_right;
};

}

#endif
