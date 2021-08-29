#include "Number.h"
#include <iostream>
using namespace std;

int main(){
    Number n1(3.4);
    int x = int(n1);
    double y = double(n1);
    cout << x << endl << y << endl;
    return 0;
}