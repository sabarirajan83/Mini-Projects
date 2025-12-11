#include <iostream>
#include <string>
using namespace std;

struct Zone {
    string con;
    int dhr;
    int dmin;
} z[11] = { 
    {"Australia", 10, 0}, 
    {"Dubai", 4, 0},
    {"England", 0, 0}, 
    {"Germany", 1, 0},
    {"India", 5, 30}, 
    {"Iran", 3, 30},
    {"Japan", 9, 0},
    {"Malaysia", 8, 0}, 
    {"Russia", 3, 0},       
    {"South Africa", 2, 0},
    {"USA", -5, 0} 
};

struct Time {
    int hr;
    int min;
    bool pm;
};

int toUTCmin(Time t, int dhr, int dmin) {
    int total = (t.hr % 12) * 60 + t.min;
    if (t.pm) total += 12 * 60;
    total -= (dhr * 60 + dmin);
    while (total < 0) total += 24 * 60;
    while (total >= 24 * 60) total -= 24 * 60;
    return total;
}

Time toLocal(int utcMin, int dhr, int dmin) {
    utcMin += (dhr * 60 + dmin);
    while (utcMin < 0) utcMin += 24 * 60;
    while (utcMin >= 24 * 60) utcMin -= 24 * 60;

    Time t;
    int hr24 = utcMin / 60;
    t.min = utcMin % 60;
    t.pm = (hr24 >= 12);
    int hr12 = hr24 % 12;
    t.hr = (hr12 == 0) ? 12 : hr12;
    return t;
}

void calculate() {
    int c[2];
    cout << "\nEnter Number to choose the country(Input Time):\n";
    for (int i = 0; i < 11; i++) {
        cout << i + 1 << "." << z[i].con << "\n";
    }
    cout << "Choice: ";
    cin >> c[0];
    if (c[0] < 1 || c[0] > 11) {
        cout << "Invalid choice\n";
        return;
    }

    int hr, min;
    char colon;
    string ampm;

    cout << "Enter time (HH:MM AM/PM): ";
    cin >> hr >> colon >> min >> ampm;
    if (ampm != "AM" && ampm != "PM" && ampm != "am" && ampm != "pm") {
        cout << "Invalid AM/PM\n";
        return;
    }

    bool pm = (ampm == "PM" || ampm == "pm");
    Time input = {hr, min, pm};

    cout << "\nEnter Number to choose the country(Output Time):\n";
    for (int i = 0; i < 11; i++) {
        cout << i + 1 << "." << z[i].con << "\n";
    }
    cout << "Choice: ";
    cin >> c[1];
    if (c[1] < 1 || c[1] > 11) {
        cout << "Invalid choice\n";
        return;
    }

    int utcMin = toUTCmin(input, z[c[0] - 1].dhr, z[c[0] - 1].dmin);
    Time output = toLocal(utcMin, z[c[1] - 1].dhr, z[c[1] - 1].dmin);

    cout << "Time in " << z[c[1] - 1].con << ": ";
    cout << (output.hr < 10 ? "0" : "") << output.hr << ":"
         << (output.min < 10 ? "0" : "") << output.min << " "
         << (output.pm ? "PM" : "AM") << "\n";
}

int main() {
    cout << "Know the time in different Countries\n";

    char ch = 'y';
    do {
        calculate();
        cout << "Enter 'y' to continue / 'n' to quit: ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    cout << "Exited Successfully\n";
    return 0;
}
