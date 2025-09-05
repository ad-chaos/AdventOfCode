#include "day6-input.h"
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <unordered_set>
#include <utility>
#include <vector>

using Grid = std::vector<std::vector<uint8_t>>;
using Coord = std::pair<int8_t, int8_t>;

#define PACKI4(dx, dy, x, y)                                                   \
  (uint32_t)(((uint8_t)dx) << 24 | ((uint8_t)dy) << 16 | ((uint8_t)x) << 8 |   \
             ((uint8_t)y))

class Walker {
public:
  Grid grid;
  int8_t sx, sy, x, y, dx, dy;
  std::unordered_set<uint32_t> seen = {};

  Walker(Grid &&grid) : grid(grid), dx(-1), dy(0) {
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid.size(); j++) {
        if (grid[i][j] == '^') {
          sx = i;
          sy = j;

          x = i;
          y = j;
        }
      }
    }
  }

  void step() {
    if (grid[x][y] != '#') {
      seen.insert(PACKI4(dx, dy, x, y));
      grid[x][y] = 'X';
      x += dx;
      y += dy;
    } else {
      x -= dx;
      y -= dy;

      dx = -dx;
      std::swap(dx, dy);
    }
  }

  bool within_bounds() {
    return 0 <= x and 0 <= y and x < grid.size() and y < grid[0].size();
  }

  bool simulate() {
    while (within_bounds()) {
      step();
      if (seen.contains(PACKI4(dx, dy, x, y))) {
        return true;
      }
    }
    return false;
  }

  void reset() {
    seen.clear();
    x = sx;
    y = sy;
    dx = -1;
    dy = 0;
  }
};

std::pair<int, std::unordered_set<uint32_t>> part1(Walker &wk) {
  wk.reset();
  wk.simulate();
  int cover = 0;
  for (const auto &row : wk.grid) {
    cover += std::count(row.cbegin(), row.cend(), 'X');
  }
  return {cover, wk.seen};
}

int part2(Walker &wk, std::unordered_set<uint16_t> &candidates) {
  wk.reset();
  int loops = 0;
  for (const auto h : candidates) {
    int8_t i = h >> 8;
    int8_t j = h;
    wk.grid[i][j] = '#';
    if (wk.simulate()) {
      loops++;
    }
    wk.reset();
    wk.grid[i][j] = '.';
  }
  return loops;
}

int main() {
  auto wk = Walker(INPUT);
  auto [ans, visited] = part1(wk);
  std::unordered_set<uint16_t> tocheck;
  std::transform(visited.cbegin(), visited.cend(),
                 std::inserter(tocheck, tocheck.end()), std::identity{});
  std::cout << "Part 1: " << ans << std::endl;
  std::cout << "Part 2: " << part2(wk, tocheck) << std::endl;
}
