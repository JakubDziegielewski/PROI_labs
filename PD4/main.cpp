#include "src/drawing.hpp"
#include "src/invalid_color_exception.hpp"
#include "src/bad_coordinates_exception.hpp"

int main()
{

    Drawing drawing(200, 200);
    try
    {
        drawing.add_line(0, 0, 100, 100, "black");
        drawing.add_line(100, 0, 100, 100, "black");
        drawing.add_circle(50, 100, 100, "red", "blue");
        drawing.add_rectangle(50, 60, 130, 130, "blue", "red");
        drawing.add_writing("PROI 23Z", 22, "middle", 70, 170, "None", "red");
        drawing.add_circle(30, 170, 170, "black", "white");
    }
    catch (InvalidColorException &e)
    {
        std::cerr << "InvalidColorException" << std::endl
                  << e.what() << std::endl;
    }
    catch (BadCoordinatesException &e)
    {
        std::cerr << "BadCoordinatesException\n"
                  << "Coordinates: x: " << e.get_x() << "; y: " << e.get_y() << std::endl;
    }
    drawing.save_to_svg_file("test.svg");

    return 0;
}