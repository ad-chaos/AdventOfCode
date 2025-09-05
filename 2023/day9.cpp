// vim: se sts=2 sw=2:
#include <chrono>
#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>
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

int main() {
  std::ifstream input("day9.txt");
  std::vector<std::vector<int>> sequences;

  auto start = std::chrono::high_resolution_clock::now();
  std::transform(std::istream_iterator<Line>(input),
                 std::istream_iterator<Line>(), std::back_inserter(sequences),
                 [](std::string seq) {
                   std::istringstream sseq{seq};
                   return std::vector<int>{std::istream_iterator<int>(sseq),
                                           std::istream_iterator<int>()};
                 });
  auto end = std::chrono::high_resolution_clock::now();
  std::cout << "Parsed in: "
            << std::chrono::duration<double, std::milli>(end - start).count()
            << " ms\n";

  int part1 = 0;
  int part2 = 0;

  start = std::chrono::high_resolution_clock::now();
  std::vector<int> diffed;
  for (auto &sequence : sequences) {
    diffed.reserve(sequence.size());
    std::copy(sequence.cbegin(), sequence.cend(), std::back_inserter(diffed));
    int before = diffed.front();
    int after = diffed.back();
    int sgn = -1;

    int off = 0;
    while (std::any_of(diffed.begin() + off++, diffed.end(), std::identity{})) {
      std::adjacent_difference(diffed.begin(), diffed.end(), diffed.begin());
      after += diffed.back();
      before += sgn * diffed[off];
      sgn = -sgn;
    }
    part1 += after;
    part2 += before;

    diffed.clear();
  }
  end = std::chrono::high_resolution_clock::now();

  std::cout << "Day9: "
            << std::chrono::duration<double, std::milli>(end - start).count()
            << " ms (parallelly computed both)\n";
  std::cout << "Part 1: " << part1 << std::endl;
  std::cout << "Part 2: " << part2 << std::endl;
}
