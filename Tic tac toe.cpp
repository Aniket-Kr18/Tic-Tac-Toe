#include <iostream>
#include <vector>
#include <string>

void displayBoard(const std::vector<char>& board) {
    std::cout << std::endl;
    std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << std::endl;
    std::cout << std::endl;
}

bool checkWin(const std::vector<char>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i * 3] == player && board[i * 3 + 1] == player && board[i * 3 + 2] == player) return true;
        if (board[i] == player && board[i + 3] == player && board[i + 6] == player) return true;
    }
    if (board[0] == player && board[4] == player && board[8] == player) return true;
    if (board[2] == player && board[4] == player && board[6] == player) return true;
    return false;
}

bool checkDraw(const std::vector<char>& board) {
    for (char cell : board) {
        if (cell == ' ') return false;
    }
    return true;
}

int main() {
    char playAgain;
    do {
        std::vector<char> board(9, ' ');
        char currentPlayer = 'X';
        bool gameEnd = false;
        int moves = 0;

        std::cout << "Welcome to Tic Tac Toe!" << std::endl;
        std::cout << "Player 1: X, Player 2: O" << std::endl;

        while (!gameEnd) {
            displayBoard(board);
            int move;
            bool validMove = false;

            while (!validMove) {
                std::cout << "Player " << currentPlayer << ", enter your move (1-9): ";
                std::cin >> move;
                move--;

                if (move >= 0 && move < 9 && board[move] == ' ') {
                    board[move] = currentPlayer;
                    validMove = true;
                } else {
                    std::cout << "Invalid move. Please try again." << std::endl;
                }
            }

            moves++;

            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                std::cout << "Player " << currentPlayer << " wins! Congratulations!" << std::endl;
                gameEnd = true;
            } else if (checkDraw(board)) {
                displayBoard(board);
                std::cout << "It's a draw!" << std::endl;
                gameEnd = true;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "Thanks for playing!" << std::endl;
    return 0;
}