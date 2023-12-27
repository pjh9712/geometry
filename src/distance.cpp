/**
 * @file geometry/distance.cpp
 * @author Jeonghoon Park (ses88498@gmail.com)
 * @brief Distance class implementation for abstract distance
 * @version 1.0.0
 * @date 2023-12-27
 * @copyright Copyright (c) 2023 &, All Rights Reserved.
 */

// Copyright (c) 2023 Programmers, All Rights Reserved.
// Authors: Jeonghoon Park

#include "geometry/distance.hpp"

#include <cstdint>
#include <tuple>

namespace {
auto ScaleDistanceToNanometer(double input_value,
                              geometry::Distance::Type input_type) -> int64_t {
  int64_t result{static_cast<int64_t>(input_value)};
  if (input_type == geometry::Distance::Type::kKilometer) {
    result = static_cast<int64_t>(input_value * 1.0e+12);
  } else if (input_type == geometry::Distance::Type::kMeter) {
    result = static_cast<int64_t>(input_value * 1.0e+9);
  } else if (input_type == geometry::Distance::Type::kCentimeter) {
    result = static_cast<int64_t>(input_value * 1.0e+7);
  } else if (input_type == geometry::Distance::Type::kMillimeter) {
    result = static_cast<int64_t>(input_value * 1.0e+6);
  } else if (input_type == geometry::Distance::Type::kMicrometer) {
    result = static_cast<int64_t>(input_value * 1.0e+3);
  }
  return result;
}
}  // namespace

namespace geometry {

Distance::Distance(double input_value, Type input_type)
    : nanometer_(ScaleDistanceToNanometer(input_value, input_type)) {}

auto Distance::GetValue(const Type &input_type) const -> double {
  auto result{static_cast<double>(nanometer_)};
  if (input_type == geometry::Distance::Type::kKilometer) {
    result = result / 1.0e+12;
  } else if (input_type == geometry::Distance::Type::kMeter) {
    result = result / 1.0e+9;
  } else if (input_type == geometry::Distance::Type::kCentimeter) {
    result = result / 1.0e+7;
  } else if (input_type == geometry::Distance::Type::kMillimeter) {
    result = result / 1.0e+6;
  } else if (input_type == geometry::Distance::Type::kMicrometer) {
    result = result / 1.0e+3;
  }
  return result;
}
}  // namespace geometry
