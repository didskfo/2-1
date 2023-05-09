//#include "iostream"
//#include "string"
//#include "algorithm"
//
//using namespace std;
//
//int main() {
//    int t;
//    cin >> t;
//    string num;
//    string mok;
//    int last;
//    int n;
//    bool check;
//    while (t--) {
//        cin >> num;
//        check = false;
//        mok = "";
//        while (num.length() > 1) {
//            last = num[num.length()-1] - '0';
//            num = num.substr(0, num.length()-1);
//            n = stoi(num) - last;
//            num = to_string(n);
//            mok += to_string(last);
//            cout << num << endl;
//        }
//        if (stoi(num) == 0) {
//            check = true;
//        }
//        if (check) {
//            reverse(mok.begin(), mok.end());
//            cout << mok << "\n";
//        } else {
//            cout << 0 << "\n";
//        }
//    }
//    return 0;
//}

#include "iostream"
#include "algorithm"

using namespace std;

int main() {
    int t;
    cin >> t;
    string num;
    while (t--) {
        cin >> num;
        string mok = "";
        int idx = 0;
        int arr[num.length()];
        for (int i = 0; i < num.length(); i++) {
            arr[i] = num[i] - '0';
        }
        for (int i = num.length()-1; i > 0; i--) {
            if (i != 1) {
                if (arr[i-1] - arr[i] < 0) {
                    arr[i-2]--;
                    arr[i-1] = arr[i-1] - arr[i] + 10;
                    mok += to_string(arr[i]);
                } else {
                    arr[i-1] -= arr[i];
                    mok += to_string(arr[i]);
                }
            } else if (i == 1) {
                arr[i-1] -= arr[i];
                mok += to_string(arr[i]);
            }
        }
        if (arr[0] == 0) {
            reverse(mok.begin(), mok.end());
            for (int i = 0; i < mok.length(); i++) {
                if (mok[i] <= 48) continue;
                else {
                    idx = i;
                    break;
                }
            }
            mok = mok.substr(idx);
            cout << mok << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    return 0;
}
