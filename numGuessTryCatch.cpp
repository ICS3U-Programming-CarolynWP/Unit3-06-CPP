// Copyright Carolyn
// Created by: Carolyn Webster Pless
// Created on: 22/10/17
// Takes the user input for a number between 0 and 9 and
// generates a random number for the user to guess.
// Uses Try Catch to make sure the input is an integer.

#include <iostream>
#include <random>
#include <string>

int main() {
    // Variables for the correct number and guess
    int randomNumber;
    int guessAsInteger;
    std::string guessAsString;

    // Generating a random number
    std::random_device rseed;

    std::mt19937 rgen(rseed());

    std::uniform_int_distribution<int> idist(0, 9);

    // The random number variable
    randomNumber = idist(rgen);

    // Title of the program
    std::cout << "Guess a number between 0 and 9 2.0\n";

    // user input for the guessed number
    std::cout << "Enter your integer between 0 and 9: ";
    std::cin >> guessAsString;
    try {
        guessAsInteger = std::stoi(guessAsString);
    } catch (std::invalid_argument) {
        std::cout << "That is not an integer.";
    }

    // IF statement to make sure the guess is between 0 and 9
    if (guessAsInteger > 9 || guessAsInteger < 0) {
        std::cout << "Your guess must be between 0 and 9.";
    } else {
        // IF statement if the guess is correct
        if (guessAsInteger == randomNumber) {
            std::cout << "You guessed the number correctly! Great job!";
        } else {
            std::cout << "Sorry, the correct number was actually "
            << randomNumber;
        }
    }
}
