#include <array>
#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>
#include <string>
#include <unordered_map>
#include <vector>

struct BotInst {
    std::array<int, 2> ids;
    std::array<int, 2> maptypes;
};

struct Line: std::string {
    friend std::istream& operator>>(std::istream& is, Line& line)
    {
        return std::getline(is, line);
    }
};

int main(int argc, char* argv[])
{
    std::array<std::unordered_map<unsigned, std::vector<unsigned>>, 2> maps;
    auto&                                 botMap    = maps[0];
    auto&                                 outputMap = maps[1];
    std::unordered_map<unsigned, BotInst> botInstMap;
    struct BotIdPair {
        int                   id;
        std::vector<unsigned> bot;
    };
    std::vector<BotIdPair> workList;
    for(auto& line: std::vector<std::string>(
            std::istream_iterator<Line>(std::ifstream(argv[1])), {})) {
        std::smatch m;
        if(std::regex_match(line, m,
                            std::regex(R"(value (\d+) goes to bot (\d+))"))) {
            [&](auto id) {
                [&](auto id, auto& b) {
                    b.push_back(std::stoi(m[1]));
                    if(b.size() == 2) {
                        workList.push_back({id, b});
                    }
                }(id, botMap[id]);
            }(std::stoi(m[2]));
        } else if(
            std::regex_match(
                line, m,
                std::regex(
                    R"(bot (\d+) gives low to (bot|output) (\d+) and high to (bot|output) (\d+))"))) {
            botInstMap[std::stoi(m[1])] = {
                {std::stoi(m[3]), std::stoi(m[5])},
                {m[2] == "bot" ? 0 : 1, m[4] == "bot" ? 0 : 1}};
        }
    }

    while(!workList.empty()) {
        auto  bidp = workList.back();
        auto& b    = bidp.bot;
        workList.pop_back();

        if(b.size() != 2) {
            continue;
        }

        std::sort(b.begin(), b.end());
        if(b[1] == 61 && b[0] == 17) {
            std::cout << bidp.id << "\n";
        }

        BotInst& bi = botInstMap[bidp.id];
        for(auto i = 0; i < 2; i++) {
            auto& rec = maps[bi.maptypes[i]][bi.ids[i]];
            rec.push_back(b[i]);
            if(bi.maptypes[i] == 0 && b.size() == 2) {
                workList.push_back({bi.ids[i], rec});
            }
        }
        b.clear();
    }
    std::cout << (outputMap[0][0] * outputMap[1][0] * outputMap[2][0]) << "\n";
    return 0;
}
