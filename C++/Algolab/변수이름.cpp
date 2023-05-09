//#include "iostream"
//
//using namespace std;
//
//int main() {
//    int t;
//    cin >> t;
//    string var;
//    while (t--) {
//        cin >> var;
//        bool check = true;
//        if (var[0] - '0' >= 0 && var[0] - '0' <= 9) {
//            check = false;
//        }
//        for (int i = 0; i < var.length(); i++) {
//             if (var[i] < 48 || (var[i] > 57 && var[i] < 65) || (var[i] > 90 && var[i] < 97) || (var[i] > 122) || var[i] != 95) {
//                check = false;
//                break;
//             }
//        }
//        if (check) {
//            cout << 1 << "\n";
//        } else {
//            cout << 0 << "\n";
//        }
//    }
//    return 0;
//}

#include "iostream"
#include "cctype"

using namespace std;

int main() {
    int t;
    cin >> t;
    string var;
    while (t--) {
        cin >> var;
        bool check = true;
        if (isdigit(var[0])) {
//            cout << var[0] << endl;
//            cout << isdigit(var[0]) << endl;
//            cout << "false1 : " << var[0] << endl;
            check = false;
        }
        for (int i = 0; i < var.length(); i++) {
//            cout << var[i] << endl;
            if (!isalpha(var[i])) {
                if (var[i] != '_') {
                    if (!isdigit(var[i])) {
//                        cout << "false : " << var[i] << endl;
                        check = false;
                    }
                }
            }
        }
        if (check) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    return 0;
}