#include <algorithm>
#include <array>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

#include "day15.hpp"

typedef struct {
  std::string label;
  int focal_length;
} lens;

int32_t hash(int32_t start, int32_t end) {
  int32_t hash = 0;
  for (int i = start; i < end; i++) {
    hash += INPUT[i];
    hash *= 17;
    hash &= 0xff;
  }
  return hash;
};

void insert_into(std::array<std::vector<lens>, 256> &boxes, int32_t start,
                 int32_t end) {
  int32_t hash = 0;
  int i = start;
  for (; i < end; i++) {
    if (INPUT[i] == '=' || INPUT[i] == '-') {
      break;
    }
    hash += INPUT[i];
    hash *= 17;
    hash &= 0xff;
  }

  auto label = INPUT.substr(start, i - start);
  auto &box = boxes[hash];
  auto lens = std::find_if(box.begin(), box.end(),
                           [&](auto lens) { return lens.label == label; });
  switch (INPUT[i]) {
  case '=': {
    auto focal_length = std::stoi(INPUT.substr(i + 1, end - i - 1));
    if (lens == box.end()) {
      box.push_back({label, focal_length});
    } else {
      (*lens).focal_length = focal_length;
    }
    break;
  }
  case '-':
    if (lens != box.end()) {
      box.erase(lens);
    }
    break;
  }
};

int main() {
  int32_t hash_sum = 0;

  int32_t start = 0;
  int32_t end = 0;
  int32_t size = INPUT.size();

  auto start_t = std::chrono::high_resolution_clock::now();
  while ((end = INPUT.find(',', start)) != INPUT.npos) {
    hash_sum += hash(start, end);
    start = end + 1;
  }
  hash_sum += hash(start, size);
  auto end_t = std::chrono::high_resolution_clock::now();

  std::cout
      << "Part 1: " << hash_sum << "    ("
      << std::chrono::duration<double, std::milli>(end_t - start_t).count()
      << "ms)\n";

  start = 0;
  std::array<std::vector<lens>, 256> boxes;
  start_t = std::chrono::high_resolution_clock::now();
  while ((end = INPUT.find(',', start)) != INPUT.npos) {
    insert_into(boxes, start, end);
    start = end + 1;
  }
  insert_into(boxes, start, size);

  int boxno = 1;
  uint64_t focusing_power = 0;
  for (const auto &box : boxes) {
    int lensno = 1;
    for (const auto &lens : box) {
      focusing_power += boxno * lensno * lens.focal_length;
      lensno++;
    }
    boxno++;
  }
  end_t = std::chrono::high_resolution_clock::now();

  std::cout
      << "Part 2: " << focusing_power << "    ("
      << std::chrono::duration<double, std::milli>(end_t - start_t).count()
      << "ms)\n";
}
