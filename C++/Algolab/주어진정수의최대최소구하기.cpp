//#include "iostream"
//#include "climits"
//
//using namespace std;
//
//int main() {
//    int t;
//    int n;
//    cin >> t;
//    for (int i = 0; i < t; i++) {
//        cin >> n;
//        int arr[n];
//        int min = INT_MAX;
//        int max = INT_MIN;
//        for (int j = 0; j < n; j++) {
//            cin >> arr[j];
//        }
//        for (int j = 0; j < n; j++) {
//            if (arr[j] > max) {
//                max = arr[j];
//            }
//            if (arr[j] < min) {
//                min = arr[j];
//            }
//        }
//        cout << max << " " << min << endl;
//    }
//    return 0;
//}

#include "iostream"

using namespace std;

int main() {
    int t, n;
    int min, max, cur;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        cin >> min;
        max = min;
        for (int j = 1; j < n; j++) {
            cin >> cur;
            if (cur > max) {
                max = cur;
            }
            if (cur < min) {
                min = cur;
            }
        }
        cout << max << " " << min << endl;
    }
    return 0;
}