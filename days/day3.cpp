#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "days.h"

auto GetCommonChars(std::string_view s1, std::string_view s2) -> std::vector<char> {
    std::vector<char> common;

    for (const auto &charS1: s1) {
        for (const auto &charS2: s2) {
            if (charS1 == charS2 && !std::count(common.begin(), common.end(), charS2)) {
                common.push_back(charS2);
            }
        }
    }

    return common;
}

auto GetCommonChars(std::string_view s1, std::string_view s2, std::string_view s3) -> std::vector<char> {
    std::vector<char> common;

    for (const auto &charS1: s1) {
        for (const auto &charS2: s2) {
            for (const auto &charS3: s3) {
                if (charS1 == charS2 && charS1 == charS3 && !std::count(common.begin(), common.end(), charS2)) {
                    common.push_back(charS2);
                }
            }
        }
    }

    return common;
}

auto CalculatePriority(char character) -> int {
    if (character >= 'a' && character <= 'z') {
        return character - 96;
    } else if (character >= 'A' && character <= 'Z') {
        return character - 38;
    }

    return 0;
}

void Part1(std::ifstream& file) {
    std::string rucksack;

    int totalPriority = 0;
    while (file >> rucksack) {
        int middle = rucksack.length() / 2;

        std::string_view firstPart(rucksack.c_str(), middle);
        std::string_view lastPart(rucksack.c_str() + middle, middle);

        auto common = GetCommonChars(firstPart, lastPart);

        for (const auto &character: common) {
            totalPriority += CalculatePriority(character);
        }
    }

    std::cout << "Part 1: " << totalPriority << std::endl;
}

void Part2(std::ifstream& file) {
    std::string rucksack, rucksack2, rucksack3;

    int totalPriority = 0;
    while (file >> rucksack >> rucksack2 >> rucksack3) {
        auto common = GetCommonChars(rucksack, rucksack2, rucksack3);

        for (const auto &character: common) {
            totalPriority += CalculatePriority(character);
        }
    }

    std::cout << "Part 2: " << totalPriority << std::endl;
}

void Days::Run3() {
    std::ifstream file("day3.txt");

    Part1(file);
    file.clear();
    file.seekg(0, std::ios_base::beg);
    Part2(file);
}