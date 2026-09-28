
#include <iostream>
using namespace std;

string timeConversion(string s) {
    int hour = stoi(s.substr(0, 2));

    if (s.substr(8, 2) == "AM") {
        if (hour == 12)
            s.replace(0, 2, "00");
    }
    else {
        if (hour != 12)
            hour += 12;

        s.replace(0, 2, to_string(hour));
    }

    s.erase(8, 2);
    return s;
}

int main() {
    string s;
    cin >> s;

    cout << timeConversion(s);

    return 0;
}
