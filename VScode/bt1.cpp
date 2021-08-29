// #include <iostream>
// using namespace std;

// int count = 0;

// void out(int a[], int n){
//     for (int i = 1; i <= n; i++) cout << a[i] << " ";
//     cout << endl;
// }

// void Try(int a[], int n, int k, int i){
//     int &t = k;
//     for (int j = 0; j <= k; j++){
//         a[i] = j;
//         if (t > 0) t = t - a[i];
//         else continue;
//         if (i == n){
//             if (t == 0) {
//                 out(a, n); 
//                 ::count++;
//             }
//         }
//         else Try(a, n, k, i+1);
//         t = t + a[i];
//     }
// }

// int main(){
//     int n, k;
//     cout << "n < k" << endl;
//     cout << "n = ";
//     cin >> n;
//     cout << "k = ";
//     cin >> k;
//     int *a = new int [n + 1];
//     Try(a, n, k, 1);
//     cout<< ::count;
//     cout << k;
//     return 0;
// }



#include <iostream>
using namespace std;

void out(int a[], int n){
    for (int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void Try(int a[], int n, int k, int i){
    for (int j = 0; j <= k; j++){
        a[i] = j;
        k -= j;
        if (i == n){
            if (k == 0) out(a, n);
        }
        else{
            Try(a, n, k, i+1);
        }
        k+=j;
    }
}

int main(){
    int n, k;
    cout << "n = ";
    cin >> n;
    cout << "k = ";
    cin >> k;
    int *a = new int[n+1];
    Try(a, n, k, 1);
    return 0;
}