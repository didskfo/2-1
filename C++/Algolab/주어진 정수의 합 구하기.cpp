#include "iostream"

using namespace std;

int main() {
    int t;
    int n;
    int num;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int sum = 0;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> num;
            sum += num;
        }
        cout << sum << endl;
    }
    return 0;
}