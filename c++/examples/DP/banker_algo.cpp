#include <iostream>
using namespace std;

const int P = 5; // Number of Processes
const int R = 3; // Number of Resources

// Function to check if system is in a safe state
bool isSafe(int available[], int max[][R], int allocation[][R], int need[][R]) {
    bool finish[P] = {false}; // Tracks completed processes
    int safeSeq[P]; // Stores safe sequence
    int work[R]; // Work represents available resources

    for (int i = 0; i < R; i++)
        work[i] = available[i]; // Initialize work with available resources

    int count = 0;
    while (count < P) {
        bool found = false;
        for (int p = 0; p < P; p++) {
            if (!finish[p]) {
                bool canExecute = true;
                for (int r = 0; r < R; r++) {
                    if (need[p][r] > work[r]) {
                        canExecute = false;
                        break;
                    }
                }
                if (canExecute) {
                    for (int r = 0; r < R; r++)
                        work[r] += allocation[p][r];

                    safeSeq[count++] = p;
                    finish[p] = true;
                    found = true;
                }
            }
        }
        if (!found) return false; // No process could execute, deadlock detected
    }

    cout << "System is in a safe state.\nSafe Sequence: ";
    for (int i = 0; i < P; i++) cout << safeSeq[i] << " ";
    cout << endl;
    return true;
}

int main() {
    int available[R] = {3, 3, 2}; // Available resources
    int max[P][R] = {
        {7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}
    };
    int allocation[P][R] = {
        {0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}
    };
    int need[P][R];

    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - allocation[i][j];

    isSafe(available, max, allocation, need);
    return 0;
}
