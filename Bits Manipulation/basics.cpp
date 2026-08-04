#include <bits/stdc++.h>
using namespace std;

/*
-----------------------------------------
        BIT MANIPULATION BASICS
-----------------------------------------

1. Power Function
2. Binary -> Decimal
3. Decimal -> Binary

Time Complexity:
Power              : O(power)
Binary -> Decimal  : O(n)
Decimal -> Binary  : O(log n)

-----------------------------------------
*/

// --------------------
// Calculate base^power
// --------------------
int power(int base, int exponent) {
    int ans = 1;

    while (exponent--) {
        ans *= base;
    }

    return ans;
}

int binaryToDecimal(string binary) {
    int decimal = 0;

    for (char bit : binary) {
        decimal = decimal * 2 + (bit - '0');
    }

    return decimal;
}

string decimalToBinary(int n) {
    if (n == 0) return "0";

    string binary = "";

    while (n > 0) {
        binary += (n % 2) + '0';
        n /= 2;
    }

    reverse(binary.begin(), binary.end());

    return binary;
}

int main() {
    cout << "===== Power Function =====\n";
    cout << "2^6 = " << power(2, 6) << "\n\n";

    cout << "===== Binary to Decimal =====\n";
    string binary = "101101";
    cout << binary << " -> " << binaryToDecimal(binary) << "\n\n";

    cout << "===== Decimal to Binary =====\n";
    int number = 45;
    cout << number << " -> " << decimalToBinary(number) << "\n";

    return 0;
}