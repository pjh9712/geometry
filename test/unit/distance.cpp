// Copyright (c) 2023 Programmers, All Rights Reserved.
// Authors: Jeonghoon Park

#include "geometry/distance.hpp"

#include "gtest/gtest.h"

namespace geometry {

TEST(GeometryDistance, Constructor) {
  Distance distance1;
  Distance distance2(distance1);
  Distance distance3(std::move(Distance()));
}

TEST(GeometryDistance, AssignmentOperator) {
  Distance distance1;
  auto distance2 = distance1;
  auto distance3 = std::move(Distance());
}

}  // namespace geometry
