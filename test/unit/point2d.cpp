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

TEST(GeometryPoint2D, AssignmentOperator) {
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

TEST(GeometryPoint2D, StaticCalculateDistance) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto KSourceX = static_cast<double>(std::rand());
    const auto KSourceY = static_cast<double>(std::rand());
    const auto KTargetX = static_cast<double>(std::rand());
    const auto KTargetY = static_cast<double>(std::rand());

    Point2D source(KSourceX, KSourceY);
    Point2D target(KTargetX, KTargetY);

    EXPECT_FLOAT_EQ(std::sqrt((KSourceX - KTargetX) * (KSourceX - KTargetX) +
                              (KSourceY - KTargetY) * (KSourceY - KTargetY)),
                    Point2D::CalculateDistance(source, target));
  }
}

TEST(GeometryPoint2D, GetX) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto KSourceX = static_cast<double>(std::rand());

    Point2D source(KSourceX, 0.0);

    EXPECT_FLOAT_EQ(KSourceX, source.GetX());
  }
}

TEST(GeometryPoint2D, GetY) {
  constexpr uint32_t kTestCount = 10000U;
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto KSourceY = static_cast<double>(std::rand());

    Point2D source(0.0, KSourceY);

    EXPECT_FLOAT_EQ(KSourceY, source.GetY());
  }
}

TEST(GeometryPoint2D, SetX) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto KSourceX = static_cast<double>(std::rand());

    Point2D source;

    source.SetX(KSourceX);

    EXPECT_FLOAT_EQ(KSourceX, source.GetX());
  }
}

TEST(GeometryPoint2D, SetY) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto KSourceY = static_cast<double>(std::rand());

    Point2D source;

    source.SetY(KSourceY);

    EXPECT_FLOAT_EQ(KSourceY, source.GetY());
  }
}

TEST(GeometryPoint2D, AdditionOperator) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto KSourceX1 = static_cast<double>(std::rand());
    const auto KSourceY1 = static_cast<double>(std::rand());
    const auto KSourceX2 = static_cast<double>(std::rand());
    const auto KSourceY2 = static_cast<double>(std::rand());

    Point2D point1(KSourceX1, KSourceY1);
    Point2D point2(KSourceX2, KSourceY2);

    Point2D result = point1 + point2;

    EXPECT_FLOAT_EQ(result.GetX(), KSourceX1 + KSourceX2);
    EXPECT_FLOAT_EQ(result.GetY(), KSourceY1 + KSourceY2);
  }
}

TEST(GeometryPoint2D, SubtractionOperator) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto KSourceX1 = static_cast<double>(std::rand());
    const auto KSourceY1 = static_cast<double>(std::rand());
    const auto KSourceX2 = static_cast<double>(std::rand());
    const auto KSourceY2 = static_cast<double>(std::rand());

    Point2D point1(KSourceX1, KSourceY1);
    Point2D point2(KSourceX2, KSourceY2);

    Point2D result = point1 - point2;

    EXPECT_FLOAT_EQ(result.GetX(), KSourceX1 - KSourceX2);
    EXPECT_FLOAT_EQ(result.GetY(), KSourceY1 - KSourceY2);
  }
}

TEST(GeometryPoint2D, CompoundOperators) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto KSourceX1 = static_cast<double>(std::rand());
    const auto KSourceY1 = static_cast<double>(std::rand());
    const auto KSourceX2 = static_cast<double>(std::rand());
    const auto KSourceY2 = static_cast<double>(std::rand());

    Point2D point1(KSourceX1, KSourceY1);
    Point2D point2(KSourceX2, KSourceY2);

    Point2D result_add = point1;
    result_add += point2;

    Point2D result_subtract = point1;
    result_subtract -= point2;

    EXPECT_FLOAT_EQ(result_add.GetX(), KSourceX1 + KSourceX2);
    EXPECT_FLOAT_EQ(result_add.GetY(), KSourceY1 + KSourceY2);

    EXPECT_FLOAT_EQ(result_subtract.GetX(), KSourceX1 - KSourceX2);
    EXPECT_FLOAT_EQ(result_subtract.GetY(), KSourceY1 - KSourceY2);
  }
}

TEST(GeometryPoint2D, MultiplicationOperator) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto KSourceX = static_cast<double>(std::rand());
    const auto KSourceY = static_cast<double>(std::rand());
    const auto KScalar = static_cast<double>(std::rand());

    Point2D point(KSourceX, KSourceY);

    Point2D result = point * KScalar;

    EXPECT_FLOAT_EQ(result.GetX(), KSourceX * KScalar);
    EXPECT_FLOAT_EQ(result.GetY(), KSourceY * KScalar);
  }
}

TEST(GeometryPoint2D, DivisionOperator) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto KSourceX = static_cast<double>(std::rand());
    const auto KSourceY = static_cast<double>(std::rand());
    const auto KScalar = static_cast<double>(std::rand());
    // const auto KScalar = 0.0;

    Point2D point(KSourceX, KSourceY);

    Point2D result = point / KScalar;

    if (KScalar != 0.0) {
      EXPECT_FLOAT_EQ(result.GetX(), KSourceX / KScalar);
      EXPECT_FLOAT_EQ(result.GetY(), KSourceY / KScalar);
    } else {
      EXPECT_TRUE(std::isnan(result.GetX()));
      EXPECT_TRUE(std::isnan(result.GetY()));
    }
  }
}

TEST(GeometryPoint2D, EqualityOperator) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto KSourceX = static_cast<double>(std::rand());
    const auto KSourceY = static_cast<double>(std::rand());

    Point2D point1(KSourceX, KSourceY);
    const Point2D& point2(point1);

    EXPECT_TRUE(point1 == point2);

    Point2D point3(KSourceX + 1.0, KSourceY);
    EXPECT_FALSE(point1 == point3);
  }
}

TEST(GeometryPoint2D, InequalityOperator) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto KSourceX = static_cast<double>(std::rand());
    const auto KSourceY = static_cast<double>(std::rand());

    Point2D point1(KSourceX, KSourceY);
    const Point2D& point2(point1);

    EXPECT_FALSE(point1 != point2);

    Point2D point3(KSourceX + 1.0, KSourceY);
    EXPECT_TRUE(point1 != point3);
  }
}
}  // namespace geometry
