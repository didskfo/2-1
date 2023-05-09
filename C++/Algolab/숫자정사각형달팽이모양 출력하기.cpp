#include "iostream"

using namespace std;

int main() {
    int t;
    int n, a, b;
    cin >> t;
    for (int q = 0; q < t; q++) {
        cin >> n >> a >> b;
        int num[n*n];
        int tmp = n;
        int n_cnt = 0;
        int arr[n][n];
        int x = -1;
        int y = 0;
        int landr = 1;
        for (int i = 0; i < n; i++) {           // 행렬 완성
            for (int j = 0; j < n; j++) {
                arr[i][j] = i*n + j+1;
            }
        }
        while (n_cnt < n*n) {
            for (int i = 0; i < tmp; i++) {
                x += landr;
                num[n_cnt++] = arr[y][x];
            }
            tmp--;
            if (tmp < 1) {
                break;
            }
            for (int i = 0; i < tmp; i++) {
                y += landr;
                num[n_cnt++] = arr[y][x];
            }
            landr = -landr;
        }
        for (int i = a-1; i < b; i++) {
            cout << num[i] << " ";
        }
        cout << endl;
    }
    return 0;
}