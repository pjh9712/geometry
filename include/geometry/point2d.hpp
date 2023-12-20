/**
 * @file geometry/point2d.hpp
 * @author Jeonghoon Park (ses88498@gmail.com)
 * @brief Point class declaration with 2-dimension
 * @version 1.0.0
 * @date 2023-12-20
 * @copyright Copyright (c) 2023 Programmers, All Rights Reserved.
 */

// Copyright (c) 2023 Programmers, All Rights Reserved.
// Authors: Jeonghoon Park

#ifndef GEOMETRY__POINT_2D_HPP_
#define GEOMETRY__POINT_2D_HPP_

namespace geometry {
/**
 * @brief Point class with 2-dimension
 */
class Point2D {
public:
  /**
   * @brief Construct a new Point2D object
   */
  Point2D() = default;
  /**
   * @brief Construct a new Point2D object with x, y value
   * @param x Double type x coordinate value
   * @param y Double type y coordinate value
   */
  Point2D(double x, double y);

  /**
   * @brief Copy construct a new Point2D object with other Point2D object
   * @param other Point2D object
   */
  Point2D(const Point2D &other) = default;
  /**
   * @brief Move construct a new Point2D object with other Point2D object
   * @param other Point2D object
   */
  Point2D(Point2D &&other) noexcept = default;

  /**
   * @brief Destroy the Point2D object
   */
  virtual ~Point2D() = default;

protected:
private:
  double x_{0.0}; ///< x coordinate
  double y_{0.0}; ///< y coordinate
};
} // namespace geometry
#endif // GEOMETRY__POINT_2D_HPP_
