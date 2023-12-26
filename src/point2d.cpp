/**
 * @file geometry/point2d.cpp
 * @author Jeonghoon Park (ses88498@gmail.com)
 * @brief Point class developments with 2-dimension
 * @version 1.0.0
 * @date 2023-12-22
 * @copyright Copyright (c) 2023 Programmers, All Rights Reserved.
 */

// Copyright (c) 2023 Programmers, All Rights Reserved.
// Authors: Jeonghoon Park

#include "geometry/point2d.hpp"

#include <cmath>

namespace geometry {
Point2D::Point2D(double input_x, double input_y) : x_(input_x), y_(input_y) {}
}  // namespace geometry
