#include "iostream"

using namespace std;

int main() {
    int t;
    cin >> t;
    int k;
    for (int q = 0; q < t; q++) {
        cin >> k;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (j == k/2 && i != k/2) {
                    cout << "I";
                }
                else if (i == k/2) {
                    if (j == k/2) {
                        cout << "O";
                    } else {
                        cout << "+";
                    }
                } else {
                    if (i + j == k-1) {
                        cout << "*";
                    } else {
                        cout << ".";
                    }
                }
            }
            cout << endl;
        }
    }
    return 0;
}