#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>

using namespace std;

typedef struct fraction
{
    int numerator;
    int denominator;
} Fraction;

Fraction sum(int n1, int n2, int d1, int d2) {
    Fraction fraction;
    fraction.numerator = n1 * d2 + n2 * d1;
    fraction.denominator = d1 * d2;
    return fraction;
}

Fraction sub(int n1, int n2, int d1, int d2) {
    Fraction fraction;
    fraction.numerator = n1 * d2 - n2 * d1;
    fraction.denominator = d1 * d2;
    return fraction;
}

Fraction mult(int n1, int n2, int d1, int d2) {
    Fraction fraction;
    fraction.numerator = n1 * n2;
    fraction.denominator = d1 * d2;
    return fraction;
}

Fraction div(int n1, int n2, int d1, int d2) {
    Fraction fraction;
    fraction.numerator = 0;
    fraction.denominator = 0;
    if (!n2) {
        return fraction;
    }
    fraction.numerator = n1 * d2;
    fraction.denominator = d1 * n2;
    return fraction;
}

int mdc(int x, int y) {
    if (!x && !y) return 1;
    while (y) {
        int mod = abs(x) % abs(y);
        x = y;
        y = mod;
    }
    return x;
}

string algo(const string& input) {
    int n1, n2, d1, d2;
    char operation, slash1, slash2;

    stringstream ss(input);
    ss >> n1 >> slash1 >> d1 >> operation >> n2 >> slash2 >> d2;

    Fraction fraction;
    Fraction fraction_simplified;

    switch (operation) {
        case '+':
            fraction = sum(n1, n2, d1, d2);
            break;
        case '-':
            fraction = sub(n1, n2, d1, d2);
            break;
        case '/':
            fraction = div(n1, n2, d1, d2);
            break;
        case '*':
            fraction = mult(n1, n2, d1, d2);
            break;
        default:
            return "Invalid operator";
    }

    fraction_simplified.numerator = fraction.numerator;
    fraction_simplified.denominator = fraction.denominator;
    int fraction_mdc = 1;

    do {
        fraction_simplified.numerator = fraction_simplified.numerator / fraction_mdc;
        fraction_simplified.denominator = fraction_simplified.denominator / fraction_mdc;
        fraction_mdc = mdc(fraction_simplified.numerator, fraction_simplified.denominator);
    } while (fraction_mdc != 1);

    return to_string(fraction.numerator) + "/" + to_string(fraction.denominator)
         + " = "
         + to_string(fraction_simplified.numerator) + "/" + to_string(fraction_simplified.denominator);
}

int main() {
    int q;
    cin >> q;
    cin.ignore();
    vector<string> arr(q);
    for (int i = 0; i < q; i++) {
        getline(cin, arr[i]);
    }
    for (const string& s : arr) {
        cout << algo(s) << endl;
    }
    return 0;
}
