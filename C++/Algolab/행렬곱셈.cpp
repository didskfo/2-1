#include "iostream"

using namespace std;

int main() {
    int q;
    cin >> q;
    int r, s, t;
    while (q--) {
        cin >> r >> s >> t;
        int arr_1[r][s];
        int arr_2[s][t];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < s; j++) {
                cin >> arr_1[i][j];
            }
        }
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < t; j++) {
                cin >> arr_2[i][j];
            }
        }
        int res[r*t];
        int idx = 0;
        int sum;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < t; j++) {
                sum = 0;
                for (int k = 0; k < s; k++) {
                    sum += arr_1[i][k]*arr_2[k][j];
                }
                res[idx] = sum;
                idx++;
            }
        }
        idx = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < t; j++) {
                cout << res[idx] << " ";
                idx++;
            }
            cout << "\n";
        }
    }
    return 0;
}