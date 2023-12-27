// Copyright (c) 2023 Programmers, All Rights Reserved.
// Authors: Jeonghoon Park

#include "geometry/distance.hpp"

#include "gtest/gtest.h"
namespace {
constexpr uint32_t kTestCount = 1000U;
}  // namespace
namespace geometry {

TEST(GeometryDistance, Constructor) {
  Distance distance1;
  Distance distance2(distance1);
  Distance distance3(std::move(Distance()));
}

TEST(GeometryDistance, ConstructorWithInputValue) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    Distance distance1(static_cast<double>(std::rand()));
    Distance distance2(static_cast<double>(std::rand()),
                       Distance::Type::kKilometer);
    Distance distance3(static_cast<double>(std::rand()),
                       Distance::Type::kMeter);
    Distance distance4(static_cast<double>(std::rand()),
                       Distance::Type::kCentimeter);
    Distance distance5(static_cast<double>(std::rand()),
                       Distance::Type::kMillimeter);
    Distance distance6(static_cast<double>(std::rand()),
                       Distance::Type::kMicrometer);
    Distance distance7(static_cast<double>(std::rand()),
                       Distance::Type::kNanometer);
  }
}

TEST(GeometryDistance, AssignmentOperator) {
  Distance distance1;
  auto distance2 = distance1;
  auto distance3 = std::move(Distance());
}

TEST(GeometryDistance, GetValue) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance1(KInputValue, Distance::Type::kKilometer);
  EXPECT_DOUBLE_EQ(KInputValue, distance1.GetValue(Distance::Type::kKilometer));

  Distance distance2(KInputValue, Distance::Type::kMeter);
  EXPECT_DOUBLE_EQ(KInputValue, distance2.GetValue(Distance::Type::kMeter));

  Distance distance3(KInputValue, Distance::Type::kCentimeter);
  EXPECT_DOUBLE_EQ(KInputValue,
                   distance3.GetValue(Distance::Type::kCentimeter));

  Distance distance4(KInputValue, Distance::Type::kMillimeter);
  EXPECT_DOUBLE_EQ(KInputValue,
                   distance4.GetValue(Distance::Type::kMillimeter));

  Distance distance5(KInputValue, Distance::Type::kMicrometer);
  EXPECT_DOUBLE_EQ(KInputValue,
                   distance5.GetValue(Distance::Type::kMicrometer));

  Distance distance6(KInputValue, Distance::Type::kNanometer);
  EXPECT_DOUBLE_EQ(KInputValue, distance6.GetValue(Distance::Type::kNanometer));
}

TEST(GeometryDistance, SetValue) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance1;
  distance1.SetValue(KInputValue, Distance::Type::kKilometer);
  EXPECT_DOUBLE_EQ(KInputValue, distance1.GetValue(Distance::Type::kKilometer));

  Distance distance2;
  distance2.SetValue(KInputValue, Distance::Type::kMeter);
  EXPECT_DOUBLE_EQ(KInputValue, distance2.GetValue(Distance::Type::kMeter));

  Distance distance3;
  distance3.SetValue(KInputValue, Distance::Type::kCentimeter);
  EXPECT_DOUBLE_EQ(KInputValue,
                   distance3.GetValue(Distance::Type::kCentimeter));

  Distance distance4;
  distance4.SetValue(KInputValue, Distance::Type::kMillimeter);
  EXPECT_DOUBLE_EQ(KInputValue,
                   distance4.GetValue(Distance::Type::kMillimeter));

  Distance distance5;
  distance5.SetValue(KInputValue, Distance::Type::kMicrometer);
  EXPECT_DOUBLE_EQ(KInputValue,
                   distance5.GetValue(Distance::Type::kMicrometer));

  Distance distance6;
  distance6.SetValue(KInputValue, Distance::Type::kNanometer);
  EXPECT_DOUBLE_EQ(KInputValue, distance6.GetValue(Distance::Type::kNanometer));
}

TEST(GeometryDistance, OperatorEqual) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(KInputValue, Distance::Type::kKilometer);
  Distance distance(KInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_by_nano(KInputValue * 1.0e+12, Distance::Type::kNanometer);

  EXPECT_TRUE(distance_by_kilo == distance);
  EXPECT_TRUE(distance_by_kilo == distance_by_nano);
  EXPECT_TRUE(distance == distance_by_nano);
}

TEST(GeometryDistance, OperatorNotEqual) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(KInputValue, Distance::Type::kKilometer);
  Distance distance(KInputValue, Distance::Type::kMeter);
  Distance distance_by_nano(KInputValue, Distance::Type::kNanometer);

  EXPECT_TRUE(distance_by_kilo != distance);
  EXPECT_TRUE(distance_by_kilo != distance_by_nano);
  EXPECT_TRUE(distance != distance_by_nano);
}

TEST(GeometryDistance, OperatorLessThan) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(KInputValue, Distance::Type::kKilometer);
  Distance distance(KInputValue, Distance::Type::kMeter);
  Distance distance_by_nano(KInputValue, Distance::Type::kNanometer);

  EXPECT_TRUE(distance < distance_by_kilo);
  EXPECT_TRUE(distance_by_nano < distance_by_kilo);
  EXPECT_TRUE(distance_by_nano < distance);
}

}  // namespace geometry
