#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

#include "days.h"

auto CalculatePriority(char character) -> int {
    if (character >= 'a' && character <= 'z') {
        return character - 96;
    } else if (character >= 'A' && character <= 'Z') {
        return character - 38;
    }

    return 0;
}

auto GetPriority(std::string_view s1, std::string_view s2) -> int {
    std::unordered_map<char, bool> s1Chars;

    for (const auto& charS1 : s1) {
        s1Chars[charS1] = true;
    }

    int totalPriority = 0;
    for (const auto& charS2 : s2) {
        if (s1Chars[charS2]) {
            totalPriority += CalculatePriority(charS2);
            s1Chars[charS2] = false;
        }
    }

    return totalPriority;
}

auto GetPriority(std::string_view s1, std::string_view s2, std::string_view s3) -> int {
    std::unordered_map<char, bool> s1Chars;

    for (const auto& charS1 : s1) {
        s1Chars[charS1] = true;
    }

    int totalPriority = 0;
    for (const auto& charS2 : s2) {
        for (const auto &charS3: s3) {
            if (charS2 == charS3 && s1Chars[charS2]) {
                totalPriority += CalculatePriority(charS2);
                s1Chars[charS2] = false;
            }
        }
    }

    return totalPriority;
}

void Part1(std::ifstream& file) {
    std::string rucksack;

    int totalPriority = 0;
    while (file >> rucksack) {
        int middle = rucksack.length() / 2;

        std::string_view firstPart(rucksack.c_str(), middle);
        std::string_view lastPart(rucksack.c_str() + middle, middle);

        totalPriority += GetPriority(firstPart, lastPart);
    }

    std::cout << "Part 1: " << totalPriority << std::endl;
}

void Part2(std::ifstream& file) {
    std::string rucksack, rucksack2, rucksack3;

    int totalPriority = 0;
    while (file >> rucksack >> rucksack2 >> rucksack3) {
        totalPriority += GetPriority(rucksack, rucksack2, rucksack3);
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