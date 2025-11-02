#include "polaroidify.h"
#include <iostream>

Polaroidify::Polaroidify()
{
    image = Image();
    return;
}

void Polaroidify::add_border(Color border_color)
{
    const std::size_t image_height = image.get_height();
    const std::size_t image_width = image.get_width();

    const double PIXELS_PER_INCH_Y = static_cast<double>(image_height) / IMAGE_HEIGHT;
    const double PIXELS_PER_INCH_X = static_cast<double>(image_width) / IMAGE_WIDTH;

    const std::size_t border_height = static_cast<std::size_t>(PIXELS_PER_INCH_Y * BORDER_HEIGHT);
    const std::size_t border_width = static_cast<std::size_t>(PIXELS_PER_INCH_X * BORDER_WIDTH);

    const std::size_t image_offset_y = static_cast<std::size_t>(PIXELS_PER_INCH_Y * IMAGE_OFFSET_Y);
    const std::size_t image_offset_x = static_cast<std::size_t>(PIXELS_PER_INCH_X * IMAGE_OFFSET_X);

    Image new_image = Image(border_width, border_height);

    // fill in the top border
    for(std::size_t y = 0; y < image_offset_y; y++)
    {
        for(std::size_t x = 0; x < border_width; x++)
        {
            new_image.set_pixel(border_color, x, y);
        }
    }

    // fill in left border, image, and right border
    for(std::size_t y = image_offset_y; y < image_height + image_offset_y; y++)
    {
        // fill in left border
        for(std::size_t x = 0; x < image_offset_x; x++)
        {
            new_image.set_pixel(border_color, x, y);
        }

        // fill in image
        for(std::size_t x = image_offset_x; x < image_width + image_offset_x; x++)
        {
            Color image_color = image.get_pixel(x - image_offset_x, y - image_offset_y);
            new_image.set_pixel(image_color, x, y);
        }

        // fill in right border
        for(std::size_t x = image_width + image_offset_x; x < border_width; x++)
        {
            new_image.set_pixel(border_color, x, y);
        }
    }

    // fill in bottom border
    for(std::size_t y = image_height + image_offset_y; y < border_height; y++)
    {
        for(std::size_t x = 0; x < border_width; x++)
        {
            new_image.set_pixel(border_color, x, y);
        }
    }

    image = new_image;

    return;
}

std::size_t Polaroidify::load(const char* file_name)
{
    return image.load(file_name);
}

std::size_t Polaroidify::save(const char* file_name)
{
    return image.save(file_name);
}
