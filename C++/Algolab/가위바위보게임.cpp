#include "iostream"

using namespace std;

int main() {
    int t;
    cin >> t;
    int n;
    int a;
    for (int i = 0; i < t; i++) {
        cin >> n;
        int arr[3] = {0, 0, 0};
        for (int j = 0; j < n; j++) {
            cin >> a;
            arr[a-1]++;
        }
        if (arr[0] != 0 && arr[1] != 0 && arr[2] != 0) {
            cout << 0 << "\n";
        } else if ((arr[0] == 0 && arr[1] == 0) || (arr[1] == 0 && arr[2] == 0) || (arr[0] == 0 && arr[2] == 0)) {
            cout << 0 << "\n";
        } else if (arr[0] == 0) {
            cout << arr[2] << "\n";
        } else if (arr[1] == 0) {
            cout << arr[0] << "\n";
        } else {
            cout << arr[1] << "\n";
        }
    }
    return 0;
}