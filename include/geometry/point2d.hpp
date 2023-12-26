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
  Point2D(double input_x, double input_y);

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

  /**
   * @brief Copy assignment operator
   * @param other Point2D object
   * @return Point2D& Reference of Point2D object
   */
  auto operator=(const Point2D &other) -> Point2D & = default;
  /**
   * @brief Move assignment operator
   * @param other Point2D object
   * @return Point2D& Reference of Point2D object
   */
  auto operator=(Point2D &&other) -> Point2D & = default;

  /**
   * @brief Calculate distance between this point and target point
   * @param target Other Point2D object to calculate distance
   * @return double Euclidean distance between this point and target point
   */
  [[nodiscard]] auto CalculateDistance(const Point2D &target) const -> double;

  /**
   * @brief Calculate distance between lhs point and rhs point
   * @param lhs Left hand side Point2D object
   * @param rhs Right hand side Point2D object
   * @return double Euclidean distance between lhs point and rhs point
   */
  [[nodiscard]] static auto CalculateDistance(const Point2D &lhs,
                                              const Point2D &rhs) -> double;

  /**
   * @brief Set x coordinate value
   * @param x Double type input x coordinate value
   */
  void SetX(double input_x);
  /**
   * @brief Set y coordinate value
   * @param y Double type input y coordinate value
   */
  void SetY(double input_y);

  /**
   * @brief Get x coordinate value of this point
   * @return double x coordinate value of this point
   */
  [[nodiscard]] auto GetX() const -> double;
  /**
   * @brief Get y coordinate value of this point
   * @return double y coordinate value of this point
   */
  [[nodiscard]] auto GetY() const -> double;

  /**
   * @brief Overloaded addition operator
   * @param other The Point2D to be added
   * @return Point2D The result of the addition operation
   */
  auto operator+(const Point2D &other) const -> Point2D;

  /**
   * @brief Overloaded subtraction operator
   * @param other The Point2D to be subtracted
   * @return Point2D The result of the subtraction operation
   */
  auto operator-(const Point2D &other) const -> Point2D;

  /**
   * @brief Overloaded compound addition operator
   * @param other The Point2D to be added
   * @return Point2D& Reference to the modified current Point2D object
   */
  auto operator+=(const Point2D &other) -> Point2D &;

  /**
   * @brief Overloaded compound subtraction operator
   * @param other The Point2D to be subtracted
   * @return Point2D& Reference to the modified current Point2D object
   */
  auto operator-=(const Point2D &other) -> Point2D &;

  /**
   * @brief Overloaded multiplication operator
   * @param scalar The scalar value
   * @return Point2D The result of the multiplication operation
   */
  auto operator*(double scalar) const -> Point2D;

  /**
   * @brief Overloaded division operator
   * @param scalar The scalar value
   * @return Point2D The result of the division operation
   */
  auto operator/(double scalar) const -> Point2D;

  /**
   * @brief Overloaded equality operator
   * @param other The Point2D to be compared with
   * @return bool True if the coordinates are equal, otherwise false
   */
  auto operator==(const Point2D &other) const -> bool;

  /**
   * @brief Overloaded inequality operator
   * @param other The Point2D to be compared with
   * @return bool True if the coordinates are not equal, otherwise false
   */
  auto operator!=(const Point2D &other) const -> bool;

protected:
private:
  double x_{0.0}; ///< x coordinate
  double y_{0.0}; ///< y coordinate
};
} // namespace geometry
#endif // GEOMETRY__POINT_2D_HPP_
