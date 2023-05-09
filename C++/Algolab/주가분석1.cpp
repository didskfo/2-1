//#include "iostream"
//
//using namespace std;
//
//int main() {
//    int n;
//    int num;
//    int cnt;
//    cin >> n;
//    for (int t = 0; t < n; t++) {
//        cin >> num;
//        cnt = 0;
//        int arr[num];
//        for (int q = 0; q < num; q++) {
//            cin >> arr[q];
//        }
//        for (int i = 1; i < num-1; i++) {
//            if (arr[i] > arr[i-1]) {
//                if (arr[i] == arr[i+1]) {
//                    while (arr[i] == arr[i+1]) {
//                        i++;
//                    }
//                    if (arr[i] > arr[i+1]) {
//                        cnt++;
//                    }
//                } else if (arr[i] > arr[i+1]) {
//                    cnt++;
//                }
//            }
//        }
//        cout << cnt << endl;
//    }
//    return 0;
//}

#include "iostream"

using namespace std;

int main() {
    int n, m;
    int num;
    int cnt;
    cin >> n;
    for (int t = 0; t < n; t++) {
        cin >> m;
        cnt = 0;
        int prev = 0, cur = 0, next;
        for (int q = 0; q < m; q++) {
            cin >> num;
            if (prev == 0) {
                prev = num;
                continue;
            }
            if (cur == 0) {
                cur = num;
                continue;
            }
            next = num;
            if (cur == next) {
                continue;
            } else if (cur > prev && cur > next) {
                cnt++;
            }
            prev = cur;
            cur = next;
        }
        cout << cnt << endl;
    }
    return 0;
}