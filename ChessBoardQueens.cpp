#include <iostream>
#include <vector>

using namespace std;

int count = 0;

bool isSafe(int row, int col, vector<string>& board, vector<int>& rows, vector<int>& diag1, vector<int>& diag2) {
    // Check if the current cell is free and not under attack
    if (board[row][col] == '*' || rows[col] || diag1[row + col] || diag2[row - col + 7]) {
        return false;
    }
    return true;
}

void solve(int row, vector<string>& board, vector<int>& rows, vector<int>& diag1, vector<int>& diag2) {
    if (row == 8) {
        // All queens are placed successfully
        count++;
        return;
    }

    for (int col = 0; col < 8; col++) {
        if (isSafe(row, col, board, rows, diag1, diag2)) {
            // Place the queen
            board[row][col] = 'Q';
            rows[col] = 1;
            diag1[row + col] = 1;
            diag2[row - col + 7] = 1;

            // Recur to place the rest of the queens
            solve(row + 1, board, rows, diag1, diag2);

            // Backtrack
            board[row][col] = '.';
            rows[col] = 0;
            diag1[row + col] = 0;
            diag2[row - col + 7] = 0;
        }
    }
}

int main() {
    vector<string> board(8);
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }

    vector<int> rows(8, 0); // To track occupied columns
    vector<int> diag1(15, 0); // To track occupied diagonals (row + col)
    vector<int> diag2(15, 0); // To track occupied diagonals (row - col + 7)

    solve(0, board, rows, diag1, diag2);

    cout << count << endl;

    return 0;
}