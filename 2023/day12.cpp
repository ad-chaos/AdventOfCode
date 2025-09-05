#include "day11-input.h"
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <iostream>
#include <numeric>
#include <ratio>
#include <utility>
#include <vector>

int main() {
  std::vector<std::pair<std::array<uint64_t, 128>, std::array<uint64_t, 32>>>
      springs = INPUT;
  auto start = std::chrono::high_resolution_clock::now();
  uint64_t bs = 0;
  int64_t done = 0;
  for (const auto &[records, damages] : springs) {
    uint64_t bit_pos = 0;
    uint64_t irec = 0;
    {
      uint64_t i = 0;
      for (const auto &record : records) {
        bit_pos |= (record == 2) << i;
        irec |= (record != 0) << i++;
      }
    }

    uint64_t bits = __builtin_popcountll(bit_pos);

    uint64_t need_damaged =
        std::accumulate(damages.cbegin(), damages.cend(), 0ULL) -
        std::accumulate(records.cbegin(), records.cend(), 0ULL) + 2ULL * bits;

    uint64_t s = 0;
    for (uint64_t i = 0; i < (1 << bits); i++) {
      if (need_damaged != __builtin_popcountll(i)) {
        continue;
      }

      uint64_t bp_copy = bit_pos;
      uint64_t j = 0;
      uint64_t ffs;
      while ((ffs = __builtin_ffsll(bp_copy))) {
        irec &= ~(1LL << (ffs - 1));
        irec |= ((i >> j) & 1LL) << (ffs - 1);
        bp_copy ^= 1LL << (ffs - 1);
        j++;
      }

      bool all_eq = true;
      uint64_t irec_c = irec;
      for (auto damage = damages.rbegin(); damage != damages.rend(); ++damage) {
        if (!irec_c) {
          break;
        }

        if (!*damage) {
          continue;
        }

        irec_c <<= __builtin_clzll(irec_c);
        uint64_t ones = __builtin_clzll(~irec_c);
        all_eq &= (*damage == ones);
        irec_c <<= ones;
      }
      s += all_eq;
    }
    bs += s;
  }
  auto end = std::chrono::high_resolution_clock::now();

  std::cout << "Part 1: " << bs << "   ("
            << std::chrono::duration<double, std::milli>(end - start).count()
            << "ms)\n";
}
