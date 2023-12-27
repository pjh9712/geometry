/**
 * @file geometry/distance.hpp
 * @author Jeonghoon Park (ses88498@gmail.com)
 * @brief Distance class declaration for abstract distance
 * @version 1.0.0
 * @date 2023-12-27
 * @copyright Copyright (c) 2023 Programmers, All Rights Reserved.
 */

// Copyright (c) 2023 Programmers, All Rights Reserved.
// Authors: Jeonghoon Park

#ifndef GEOMETRY__Distance_HPP_
#define GEOMETRY__Distance_HPP_

#include <cstdint>

namespace geometry {
/**
 * @brief The class for abstract distance
 */
class Distance {
 public:
  /**
   * @brief The enum class for distance type.
   */
  enum class Type {
    kKilometer = 0,   ///< Kilometer
    kMeter = 1,       ///< Meter
    kCentimeter = 2,  ///< Centimeter
    kMillimeter = 3,  ///< Millimeter
    kMicrometer = 4,  ///< Micrometer
    kNanometer = 5    ///< Nanometer
  };

  /**
   * @brief Construct a new Distance object.
   */
  Distance() = default;

  explicit Distance(double input_value, Type input_type = Type::kMeter);

  /**
   * @brief The copy constructor.
   * @param other The other distance object.
   */
  Distance(const Distance& other) = default;
  /**
   * @brief The move constructor.
   * @param other The other distance object.
   */
  Distance(Distance&& other) noexcept = default;

  /**
   * @brief Destroy the Distance object.
   */
  virtual ~Distance() = default;

  /**
   * @brief The copy assignment operator.
   * @param other The other distance object.
   * @return The reference of distance object.
   */
  auto operator=(const Distance& other) -> Distance& = default;

  /**
   * @brief The move assignment operator.
   * @param other The other distance object.
   * @return The reference of distance object.
   */
  auto operator=(Distance&& other) -> Distance& = default;

  /**
   * @brief Get the Distance value for distance type.
   * @param input_type The distance type.
   * @return double The distance value.
   */
  [[nodiscard]] auto GetValue(const Type& input_type) const -> double;

 protected:
 private:
  int64_t nanometer_{0};  ///< Nanometer
};

}  // namespace geometry

#endif  // GEOMETRY__Distance_HPP_
