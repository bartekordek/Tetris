#pragma once

#include "CUL/Math/Vector3D.hpp"

#include <vector>
#include <array>

using cunt = const unsigned int;

using Vector3dd = CUL::Math::Vector3Dd;
using Vector3du = CUL::Math::Vector3Du;
using Vector3di = CUL::Math::Vector3Di;

using MatrixPos = Vector3du;
using CoordinatestList = std::vector<MatrixPos>;
using SlabsPositions = std::array<Vector3di, 4>;