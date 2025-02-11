#include <iostream>
#include <random>
#include <string>

using namespace std;

// Function prototypes
string getPlayerChoice();
string getComputerChoice();
string determineWinner(string player, string computer);
void updateScores(string winner, int &playerScore, int &computerScore);
void displayFinalWinner(int playerScore, int computerScore);

int main() {
    int playerScore = 0, computerScore = 0;
    string playerChoice, computerChoice, winner;

    cout << "Welcome to Rock, Paper, Scissors!" << endl;

    while (true) {
        playerChoice = getPlayerChoice();

        if (playerChoice == "quit") {
            break;  // Exit game loop
        }

        computerChoice = getComputerChoice();
        cout << "Computer chose: " << computerChoice << endl;

        winner = determineWinner(playerChoice, computerChoice);
        updateScores(winner, playerScore, computerScore);

        cout << "Current Score - You: " << playerScore << " | Computer: " << computerScore << endl;
    }

    displayFinalWinner(playerScore, computerScore);
    return 0;
}

// Function to get player's choice with input validation
string getPlayerChoice() {
    string choice;
    while (true) {
        cout << "Enter rock, paper, scissors, or quit: ";
        cin >> choice;

        // Convert input to lowercase for consistency
        for (char &c : choice) {
            c = tolower(c);
        }

        if (choice == "rock" || choice == "paper" || choice == "scissors" || choice == "quit") {
            return choice;
        } else {
            cout << "Invalid input! Please enter rock, paper, scissors, or quit." << endl;
        }
    }
}

// Function to get a random computer choice
string getComputerChoice() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 3);

    int randomNum = dist(gen);
    if (randomNum == 1) return "rock";
    if (randomNum == 2) return "paper";
    return "scissors";
}

// Function to determine the winner
string determineWinner(string player, string computer) {
    if (player == computer) {
        cout << "It's a draw!" << endl;
        return "draw";
    }

    if ((player == "rock" && computer == "scissors") ||
        (player == "scissors" && computer == "paper") ||
        (player == "paper" && computer == "rock")) {
        cout << "You win this round!" << endl;
        return "player";
    } else {
        cout << "Computer wins this round!" << endl;
        return "computer";
    }
}

// Function to update the score
void updateScores(string winner, int &playerScore, int &computerScore) {
    if (winner == "player") {
        playerScore++;
    } else if (winner == "computer") {
        computerScore++;
    }
}

// Function to display the final winner
void displayFinalWinner(int playerScore, int computerScore) {
    cout << "\nFinal Score - You: " << playerScore << " | Computer: " << computerScore << endl;

    if (playerScore > computerScore) {
        cout << "Congratulations! You won the tournament!" << endl;
    } else if (computerScore > playerScore) {
        cout << "Computer wins the tournament! Better luck next time!" << endl;
    } else {
        cout << "The tournament ended in a draw!" << endl;
    }
}
