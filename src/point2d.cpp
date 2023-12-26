/**
 * @file geometry/point2d.cpp
 * @author Jeonghoon Park (ses88498@gmail.com)
 * @brief Point class developments with 2-dimension
 * @version 1.0.0
 * @date 2023-12-22
 * @copyright Copyright (c) 2023 &, All Rights Reserved.
 */

// Copyright (c) 2023 Programmers, All Rights Reserved.
// Authors: Jeonghoon Park

#include "geometry/point2d.hpp"

#include <cmath>

namespace geometry {
Point2D::Point2D(double input_x, double input_y) : x_(input_x), y_(input_y) {}

auto Point2D::CalculateDistance(const Point2D& target) const -> double {
  return Point2D::CalculateDistance(*this, target);
}

auto Point2D::CalculateDistance(const Point2D& lhs, const Point2D& rhs)
    -> double {
  return std::sqrt(std::pow((lhs.x_ - rhs.x_), 2) +
                   std::pow((lhs.y_ - rhs.y_), 2));
}

auto Point2D::GetX() const -> double { return x_; }

auto Point2D::GetY() const -> double { return y_; }
}  // namespace geometry
