#include <iostream>
#include <fstream>

#include "days.h"

static void Part1(std::ifstream& file) {
    int a, b;
    int a1, b1;
    char _;

    int total = 0;
    while (file >> a >> _ >> b >> _ >> a1 >> _ >> b1) {
        if (a <= a1 && b >= b1 || a1 <= a && b1 >= b) {
            total++;
        }
    }

    std::cout << "Part 1: " << total << std::endl;
}

static void Part2(std::ifstream& file) {
    int a, b;
    int a1, b1;
    char _;

    int total = 0;
    while (file >> a >> _ >> b >> _ >> a1 >> _ >> b1) {
        for (int i = a; i <= b; i++) {
            if (i >= a1 && i <= b1) {
                total++;
                break;
            }
        }
    }

    std::cout << "Part 2: " << total << std::endl;
}

void Days::Run4() {
    std::ifstream file("day4.txt");

    std::cout << "Day 4\n";
    Part1(file);
    file.clear();
    file.seekg(0, std::ios_base::beg);
    Part2(file);

    file.close();
}