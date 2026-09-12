#include <iostream>

using namespace std;

// Problem 1 - Recursive Ackermann function
long long ackermannRecursive(int m, long long n) {
    if (m == 0) {
        return n + 1;
    }

    if (n == 0) {
        return ackermannRecursive(m - 1, 1);
    }

    return ackermannRecursive(
        m - 1,
        ackermannRecursive(m, n - 1)
    );
}

// Problem 1 - Non-recursive Ackermann function
long long ackermannNonRecursive(int m, long long n) {
    const int MAX_STACK = 1000000;

    int* stack = new int[MAX_STACK];
    int top = 0;

    stack[top++] = m;

    while (top > 0) {
        m = stack[--top];

        if (m == 0) {
            n = n + 1;
        }
        else if (n == 0) {
            n = 1;
            stack[top++] = m - 1;
        }
        else {
            stack[top++] = m - 1;
            stack[top++] = m;
            n = n - 1;
        }
    }

    delete[] stack;

    return n;
}

int main() {
    int m;
    long long n;

    cout << "Enter m: ";
    cin >> m;

    cout << "Enter n: ";
    cin >> n;

    if (m < 0 || n < 0) {
        cout << "m and n must be non-negative." << '\n';
        return 0;
    }

    cout << "Recursive result: "
         << ackermannRecursive(m, n)
         << '\n';

    cout << "Non-recursive result: "
         << ackermannNonRecursive(m, n)
         << '\n';

    return 0;
}
