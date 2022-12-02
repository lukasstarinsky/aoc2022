#include <iostream>
#include <fstream>
#include <vector>

#include "days.h"

void Days::Run1() {
    std::ifstream file("day1.txt");
    std::string line;
    std::vector<int> elves;

    int elfTotal = 0;
    while (std::getline(file, line)) {
        if (line.empty()) {
            elves.push_back(elfTotal);
            elfTotal = 0;
            continue;
        }

        elfTotal += std::stoi(line);
    }

    std::sort(elves.begin(), elves.end(), std::ranges::greater());

    std::cout << "Part 1: " << elves.front() << std::endl;
    std::cout << "Part 2: " << elves[0] + elves[1] + elves[2] << std::endl;
}