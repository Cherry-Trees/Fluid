#pragma once
#include "globals.hpp"
#include "Cell.h"

// Compute the divergence of a Cell using five-point stencil method
float divergence(Cell** U, const int x, const int y)
{
    return (a * DELTA / float(PIXEL_DELTA * PIXEL_DELTA)) * 
            (U[y-1][x].q + U[y+1][x].q + U[y][x-1].q + U[y][x+1].q - 4 * U[y][x].q);
}