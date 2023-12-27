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

 protected:
 private:
};

}  // namespace geometry

#endif  // GEOMETRY__Distance_HPP_
