// vim: se sts=2 sw=2:
#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

class Line {
  std::string data;

public:
  friend std::istream &operator>>(std::istream &is, Line &l) {
    std::getline(is, l.data);
    return is;
  }
  operator std::string() const { return data; }
};

class Play {
public:
  inline static std::array<int16_t, 128> counter = {};
  char hand[5];
  int16_t bid;
  uint32_t integer;

  Play(std::string h, int16_t b) : bid(b) { h.copy(hand, h.length()); }

  void update_counter() const {
    counter[hand[0]]++;
    counter[hand[1]]++;
    counter[hand[2]]++;
    counter[hand[3]]++;
    counter[hand[4]]++;
  }

  int32_t calculate_highness(int16_t keys) const {
    switch (keys) {
    case 1:
      return 6;
    case 2:
      if (std::find(counter.begin(), counter.end(), 4) != counter.end())
        return 5;
      return 4;
    case 3:
      if (std::find(counter.begin(), counter.end(), 3) != counter.end())
        return 3;
      return 2;
    case 4:
      return 1;
      break;
    case 5:
      return 0;
    }
    __builtin_unreachable();
  }

  int32_t as_int(const int16_t *ordering, bool part2 = false) const {
    counter.fill(0);
    update_counter();
    auto counter_keys = 128 - std::count(counter.begin(), counter.end(), 0);

    if (part2) {
      auto jcounts = counter['J'];
      if (jcounts and counter_keys != 1) {
        counter['J'] = 0;
        *std::max_element(counter.begin(), counter.end()) += jcounts;
        counter_keys--;
      }
    }

    return calculate_highness(counter_keys) << 20 | ordering[hand[4]] |
           ordering[hand[3]] << 4 | ordering[hand[2]] << 8 |
           ordering[hand[1]] << 12 | ordering[hand[0]] << 16;
  }
};

Play to_play(std::string play) {
  auto space = play.find(' ');
  return {play.substr(0, space),
          static_cast<int16_t>(stoi(play.substr(space + 1)))};
}

int main() {
  const int16_t card_ordering_p1[128] = {
      ['A'] = 12, ['K'] = 11, ['Q'] = 10, ['J'] = 9, ['T'] = 8,
      ['9'] = 7,  ['8'] = 6,  ['7'] = 5,  ['6'] = 4, ['5'] = 3,
      ['4'] = 2,  ['3'] = 1,  ['2'] = 0};
  const int16_t card_ordering_p2[128] = {
      ['A'] = 12, ['K'] = 11, ['Q'] = 10, ['T'] = 9, ['9'] = 8,
      ['8'] = 7,  ['7'] = 6,  ['6'] = 5,  ['5'] = 4, ['4'] = 3,
      ['3'] = 2,  ['2'] = 1,  ['J'] = 0};

  std::vector<Play> plays;

  auto start = std::chrono::high_resolution_clock::now();

  std::ifstream input("day7.txt");
  std::transform(std::istream_iterator<Line>(input),
                 std::istream_iterator<Line>(), std::back_inserter(plays),
                 to_play);

  auto end = std::chrono::high_resolution_clock::now();

  std::cout << "Parsed in: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                     start)
                   .count()
            << " ms" << std::endl;

  start = std::chrono::high_resolution_clock::now();
  for (auto &play : plays) {
    play.integer = play.as_int(card_ordering_p1);
  }

  std::sort(plays.begin(), plays.end(), [](const auto &p1, const auto &p2) {
    return p1.integer < p2.integer;
  });

  auto i = 1;
  auto part1 = std::accumulate(
      plays.cbegin(), plays.cend(), 0,
      [&](auto acc, const auto &p) { return acc + (i++) * p.bid; });
  end = std::chrono::high_resolution_clock::now();

  std::cout << "Part 1: " << part1 << "    ("
            << std::chrono::duration<double, std::milli>(end - start).count()
            << " ms)" << std::endl;

  start = std::chrono::high_resolution_clock::now();
  for (auto &play : plays) {
    play.integer = play.as_int(card_ordering_p2, true);
  }

  std::sort(plays.begin(), plays.end(), [&](const auto &p1, const auto &p2) {
    return p1.integer < p2.integer;
  });

  i = 1;
  auto part2 = std::accumulate(
      plays.cbegin(), plays.cend(), 0,
      [&](auto acc, const auto &p) { return acc + (i++) * p.bid; });
  end = std::chrono::high_resolution_clock::now();

  std::cout << "Part 2: " << part2 << "    ("
            << std::chrono::duration<double, std::milli>(end - start).count()
            << " ms)" << std::endl;
}
