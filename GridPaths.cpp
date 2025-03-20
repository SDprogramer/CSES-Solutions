#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int GRID_SIZE = 7;
const int PATH_LENGTH = 48;

int count = 0;
string path;
vector<vector<bool>> visited(GRID_SIZE, vector<bool>(GRID_SIZE, false));

void backtrack(int x, int y, int step) {
    if (x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE || visited[x][y]) {
        return;
    }

    // Prune if it's impossible to reach the destination in the remaining steps
    if (step == PATH_LENGTH) {
        if (x == GRID_SIZE - 1 && y == 0) {
            count++;
        }
        return;
    }

    // Early pruning: if the remaining steps are not enough to reach the destination
    int remaining_steps = PATH_LENGTH - step;
    int min_steps_needed = abs(x - (GRID_SIZE - 1)) + abs(y - 0);
    if (remaining_steps < min_steps_needed) {
        return;
    }

    visited[x][y] = true;

    char current = path[step];
    if (current == '?' || current == 'D') {
        backtrack(x + 1, y, step + 1);
    }
    if (current == '?' || current == 'U') {
        backtrack(x - 1, y, step + 1);
    }
    if (current == '?' || current == 'L') {
        backtrack(x, y - 1, step + 1);
    }
    if (current == '?' || current == 'R') {
        backtrack(x, y + 1, step + 1);
    }

    visited[x][y] = false;
}

int main() {
    cin >> path;
    backtrack(0, 0, 0);
    cout << count << endl;
    return 0;
}