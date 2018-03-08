#include "window.h"

#include <iostream>
#include <utility>

namespace {

using namespace rudolph;
using namespace rudolph::geometry;

static cairo_surface_t *surface = NULL;

void in_close(GtkWidget* btn, gpointer* data) {
    reinterpret_cast<MainWindow*>(data)->close();
}

void clear_surface()
{
    cairo_t *cr;

    cr = cairo_create(surface);

    cairo_set_source_rgb(cr, 1, 1, 1);
    cairo_paint(cr);

    cairo_destroy(cr);
}

// Create a new surface to store our scribbles
gboolean on_configure_event(GtkWidget *widget,
                            GdkEventConfigure *event,
                            gpointer data)
{
    if (surface)
    {
        cairo_surface_destroy(surface);
    }

    surface = gdk_window_create_similar_surface(gtk_widget_get_window(widget),
                                                CAIRO_CONTENT_COLOR,
                                                gtk_widget_get_allocated_width(widget),
                                                gtk_widget_get_allocated_height(widget));
    // Initialize surface to white
    clear_surface();

    return TRUE;
}

/* Redraw the screen from the surface. Note that the ::draw
 * signal receives a ready-to-be-used cairo_t that is already
 * clipped to only draw the exposed areas of the widget
 */
gboolean on_draw(GtkWidget *widget, cairo_t *cr, gpointer data)
{
    cairo_set_source_surface(cr, surface, 0, 0);
    cairo_paint(cr);

    return FALSE;
}

}

MainWindow::MainWindow(Size size, GtkBuilder* builder):
    _size{std::move(size)}
{
    gtk_builder = builder;
    gtk_window = GTK_WIDGET( gtk_builder_get_object( GTK_BUILDER(gtk_builder), "main_window"));
    gtk_window_set_default_size(GTK_WINDOW(gtk_window), size.width, size.height);
    g_signal_connect(gtk_window, "destroy", G_CALLBACK(in_close), this);

    configure_gui();
}

void MainWindow::configure_gui() {
    GtkWidget* canvas = GTK_WIDGET(gtk_builder_get_object(GTK_BUILDER(gtk_builder), "canvas"));
    // Signals used to handle the background surface
    g_signal_connect(canvas, "draw", G_CALLBACK(on_draw), NULL);
    g_signal_connect(canvas, "configure-event", G_CALLBACK(on_configure_event), NULL);
}

void MainWindow::show() {
    gtk_widget_show_all(gtk_window);
}

void MainWindow::close() {
    std::cout << "Closing...\n";
    gtk_main_quit();
}
