#include <iostream>
using namespace std;

int can(int s[], int i, int j) {
    int sum = 0;
    for (int k = i; k <= j; k++) {
        sum += s[k];
    }
    return sum;
}

int ABC(int s[], int i, int j) {
    if (i >= j)
        return 0;
    int tmp = (j-i+1)/3;
    int a = can(s, i, i + tmp -1);
    int b = can(s, i+tmp, i + 2*tmp -1);
    int c = can(s, i + 2*tmp, j);

    if (a == b) {
        cout << "a == b, --> c" << endl;
        return 1 + ABC(s, i + 2*tmp, j);
    } else if (a < b) {
        cout << "a < b, --> a" << endl;
        return 1 + ABC(s, i, i + tmp -1);
    } else {
        cout << "a > b, --> b" << endl;
        return 1 + ABC(s,  i+tmp, i + 2*tmp -1);
    }
}

int main() {
    int s[] = {0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 3, 3, 3};
    cout << "KQ: " << ABC(s, 1, 21) << endl;
    return 0;
}