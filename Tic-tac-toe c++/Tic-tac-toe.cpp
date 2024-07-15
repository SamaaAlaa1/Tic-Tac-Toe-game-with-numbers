#include <iostream>
#include <limits>
using namespace std;

bool check_winner(int arr[3][3]) {
    // Check rows and columns for winning
    for (int i = 0; i < 3; i++) {
        if ((arr[i][0] + arr[i][1] + arr[i][2] == 15 && arr[i][0] && arr[i][1] && arr[i][2]) ||
            (arr[0][i] + arr[1][i] + arr[2][i] == 15 && arr[0][i] && arr[1][i] && arr[2][i])) {
            return true;
        }
    }

    // Check diagonals for winning
    if ((arr[0][0] + arr[1][1] + arr[2][2] == 15 && arr[0][0] && arr[1][1] && arr[2][2]) ||
        (arr[0][2] + arr[1][1] + arr[2][0] == 15 && arr[0][2] && arr[1][1] && arr[2][0])) {
        return true;
    }

    return false;
}

void display_board(int game[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << game[i][j] << " | ";
        }
        cout << endl;
        if (i < 2) {
            cout << "____|____|____" << endl;
        }
    }
    cout << "-------------" << endl;
}

bool get_valid_input(int& value, int min, int max, const string& prompt) {
    cout << prompt;
    while (true) {
        if (!(cin >> value) || value < min || value > max) {
            cout << "Invalid input. Please enter a number (" << min << "/" << max << "): \n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            return true;
        }
    }
}

int main() {
    cout << "Hello Players this is Tic-Tac-Toe with numbers\n"
            "A board of 3 x 3 is displayed and player 1 takes odd numbers 1, 3, 5, 7, 9\n"
            "and player 2 takes even numbers 0, 2, 4, 6, 8. Players take turns to write their\n"
            "numbers. Odd numbers start. Use each number only once. The first person to complete a line\n"
            "that adds up to 15 is the winner. The line can have both odd and even numbers\n"
            "Enjoy:)\n ";

    bool play_again = true;

    while (play_again) {
        int player1_nums[] = {1, 3, 5, 7, 9};
        int player2_nums[] = {0, 2, 4, 6, 8};
        int game[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
        int arr[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
        int moves = 0;

        while (true) {
            display_board(game);

            int row, column, player_number;
            bool valid = false;

            // Player 1's turn
            while (!valid) {
                get_valid_input(row, 1, 3, "Player 1 Turn\nEnter number of row (1/2/3): ");
                get_valid_input(column, 1, 3, "Enter number of column (1/2/3): ");
                row -= 1;
                column -= 1;

                if (arr[row][column] != 0) {
                    cout << "Cell already filled. Please choose another position.\n";
                    continue;
                }

                get_valid_input(player_number, 1, 9, "Enter your odd number (1:9): ");
                if (player_number % 2 == 0) {
                    cout << "Invalid input: Please enter an odd number between 1 and 9\n";
                    continue;
                }

                for (int i = 0; i < 5; i++) {
                    if (player_number == player1_nums[i]) {
                        valid = true;
                        arr[row][column] = player_number;
                        game[row][column] = player_number;
                        player1_nums[i] = -1;
                        moves++;
                        break;
                    }
                }
            }

            if (check_winner(arr)) {
                display_board(game);
                cout << "Player 1 is the Winner!!\n";
                break;
            }

            if (moves == 9) {
                display_board(game);
                cout << "No Winner, it's a draw\n";
                break;
            }

            display_board(game);
            valid = false;

            // Player 2's turn
            while (!valid) {
                get_valid_input(row, 1, 3, "Player 2 Turn\nEnter number of row (1/2/3): ");
                get_valid_input(column, 1, 3, "Enter number of column (1/2/3): ");
                row -= 1;
                column -= 1;

                if (arr[row][column] != 0) {
                    cout << "Cell already filled. Please choose another position.\n";
                    continue;
                }

                get_valid_input(player_number, 0, 8, "Enter your number (0:8): ");
                if (player_number % 2 != 0) {
                    cout << "Invalid input: Please enter an even number between 0 and 8\n";
                    continue;
                }

                for (int i = 0; i < 5; i++) {
                    if (player_number == player2_nums[i]) {
                        valid = true;
                        arr[row][column] = player_number;
                        game[row][column] = player_number;
                        player2_nums[i] = -1;
                        moves++;
                        break;
                    }
                }
            }

            if (check_winner(arr)) {
                display_board(game);
                cout << "Player 2 is the Winner!!\n";
                break;
            }

            if (moves == 9) {
                display_board(game);
                cout << "No Winner, it's a draw\n";
                break;
            }
        }

        cout << "Do you want to play again or exit?\n1 => Play Again\n2 => Exit\n";
        char choice;
        while (true) {
            cin >> choice;
            if (choice == '1') {
                break;
            } else if (choice == '2') {
                play_again = false;
                break;
            } else {
                cout << "Choose a valid option (1 or 2):\n";
            }
        }
    }
    return 0;
}
