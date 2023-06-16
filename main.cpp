#include <bits/stdc++.h>

#include "first_come_first_service.hpp"
#include "schedule.hpp"

using namespace std;

int main() {
    cout << "アルゴリズム" << endl
         << "0:到着時間方式" << endl
         << "1:処理時間方式" << endl
         << "2:ラウンドロビン方式" << endl;
    int num;
    cin >> num;
    switch (num) {
        case 0:
            FirstComeFirstService schedule;
            schedule.start();
            schedule.result();
            break;
    }
}
