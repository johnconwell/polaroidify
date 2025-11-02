#ifndef __POLAROIDIFY_H
#define __POLAROIDIFY_H

#include "image.h"

class Polaroidify
{
public:
    static inline constexpr double IMAGE_HEIGHT = 3.1;
    static inline constexpr double IMAGE_WIDTH = 3.1;
    static inline constexpr double BORDER_HEIGHT = 4.2;
    static inline constexpr double BORDER_WIDTH = 3.5;
    static inline constexpr double IMAGE_OFFSET_Y = 0.2;
    static inline constexpr double IMAGE_OFFSET_X = 0.2;
    static inline const Color COLOR_WHITE = Color(Color::HEX_MAX);

    Image image;

    Polaroidify();

    void add_border(Color border_color = COLOR_WHITE);

    std::size_t load(const char* file_name);
    std::size_t save(const char* file_name);
};

#endif
