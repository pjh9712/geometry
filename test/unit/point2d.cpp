// Copyright (c) 2023 Programmers, All Rights Reserved.
// Authors: Jeonghoon Park

#include "geometry/point2d.hpp"

#include <cmath>
#include <limits>
#include <stdexcept>

#include "gtest/gtest.h"

namespace geometry {
TEST(GeometryPoint2D, Constructor) {
  Point2D point1;
  Point2D point2(0.0, 1.0);
  Point2D point3(point2);
  Point2D point4(std::move(Point2D()));
}

TEST(GeometryPoint2D, AssigmentOperator) {
  Point2D point1;
  auto point2 = point1;
  auto point3 = std::move(Point2D());
}

TEST(GeometryPoint2D, CalculateDistance) {
  constexpr double kSourceX = 1.0;
  constexpr double kSourceY = 2.0;
  constexpr double kTargetX = 4.0;
  constexpr double kTargetY = 6.0;

  Point2D source(kSourceX, kSourceY);
  Point2D target(kTargetX, kTargetY);

  EXPECT_FLOAT_EQ(std::sqrt((kSourceX - kTargetX) * (kSourceX - kTargetX) +
                            (kSourceY - kTargetY) * (kSourceY - kTargetY)),
                  source.CalculateDistance(target));
}
}  // namespace geometry
