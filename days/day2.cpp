#include <iostream>
#include <fstream>

#include "days.h"

enum Shape {
    ROCK = 1,
    PAPER,
    SCISSORS
};

auto GetShape(char letter) -> Shape {
    switch (letter) {
        case 'A':
            return ROCK;
        case 'B':
            return PAPER;
        case 'C':
            return SCISSORS;
        default:
            return ROCK;
    }
}

auto GetPlayerShape(char letter, Shape opponentHand) -> Shape {
    if (letter == 'Y') {
        return opponentHand;
    }

    if (opponentHand == ROCK) {
        return letter == 'Z' ? PAPER : SCISSORS;
    } else if (opponentHand == PAPER) {
        return letter == 'Z' ? SCISSORS : ROCK;
    } else if (opponentHand == SCISSORS) {
        return letter == 'Z' ? ROCK : PAPER;
    }

    return ROCK;
}

void Days::Run2() {
    std::ifstream file("day2.txt");
    char opponentChar;
    char playerChar;

    int totalScore = 0;
    while (file >> opponentChar >> playerChar) {
        auto opponentHand = GetShape(opponentChar);
        auto playerHand = GetPlayerShape(playerChar, opponentHand);

        if (opponentHand == ROCK && playerHand == PAPER) {
            totalScore += 6 + (int)playerHand;
        } else if (opponentHand == PAPER && playerHand == SCISSORS) {
            totalScore += 6 + (int)playerHand;
        } else if (opponentHand == SCISSORS && playerHand == ROCK) {
            totalScore += 6 + (int)playerHand;
        } else if (opponentHand == playerHand) {
            totalScore += 3 + (int)playerHand;
        } else {
            totalScore += (int)playerHand;
        }
    }

    std::cout << "Part 2: " << totalScore << std::endl;

    file.close();
}