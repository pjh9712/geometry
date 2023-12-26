// Copyright (c) 2023 Programmers, All Rights Reserved.
// Authors: Jeonghoon Park

#include "geometry/point2d.hpp"

#include <cmath>
#include <limits>
#include <stdexcept>

#include "gtest/gtest.h"

namespace {
constexpr uint32_t kTestCount = 10000U;
}

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
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto KSourceX = static_cast<double>(std::rand());
    const auto KSourceY = static_cast<double>(std::rand());
    const auto KTargetX = static_cast<double>(std::rand());
    const auto KTargetY = static_cast<double>(std::rand());

    Point2D source(KSourceX, KSourceY);
    Point2D target(KTargetX, KTargetY);

    EXPECT_FLOAT_EQ(std::sqrt((KSourceX - KTargetX) * (KSourceX - KTargetX) +
                              (KSourceY - KTargetY) * (KSourceY - KTargetY)),
                    source.CalculateDistance(target));
  }
}

}  // namespace geometry
