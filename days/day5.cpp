#include <fstream>
#include <map>
#include <vector>
#include <iostream>

#include "days.h"

static void Part1(auto& cargo, int amount, int from, int to) {
    for (int i = 0; i < amount; ++i) {
        cargo[to].emplace_back(cargo[from].back());
        cargo[from].pop_back();
    }
}

static void Part2(auto& cargo, int amount, int from, int to) {
    std::vector<char> temp;
    for (int i = 0; i < amount; ++i) {
        temp.emplace_back(cargo[from].back());
        cargo[from].pop_back();
    }
    std::reverse(temp.begin(), temp.end());
    cargo[to].insert(cargo[to].end(), temp.begin(), temp.end());
}

void Days::Run5() {
    std::ifstream file("day5.txt");

    char cargoCrates[9][10] = {{'D', 'M', 'S', 'Z', 'R', 'F', 'W', 'N'},
                               {'W', 'P', 'Q', 'G', 'S'},
                               {'W', 'R', 'V', 'Q', 'F', 'N', 'J', 'C'},
                               {'F', 'Z', 'P', 'C', 'G', 'D', 'L'},
                               {'T', 'P', 'S'},
                               {'H', 'D', 'F', 'W', 'R', 'L'},
                               {'Z', 'N', 'D', 'C'},
                               {'W', 'N', 'R', 'F', 'V', 'S', 'J', 'Q'},
                               {'R', 'M', 'S', 'G', 'Z', 'W', 'V'}};

    std::map<int, std::vector<char>> cargo;

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (cargoCrates[i][j] != '\0') {
                cargo[i].emplace_back(cargoCrates[i][j]);
            }
        }
    }

    int amount, from, to;
    std::string _;

    while (file >> _ >> amount >> _ >> from >> _ >> to) {
        from--;
        to--;

        // Part1(cargo, amount, from, to);
        Part2(cargo, amount, from, to);
    }

    for (const auto& item: cargo) {
        std::cout << item.second.back();
    }

    file.close();
}