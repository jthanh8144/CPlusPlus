#include <iostream>
using namespace std;

#define max 50
#define oo 100000

int n, a, z; //so dinh cua do thi, diem dau, diem cuoi
int way[max], L[max], w[max][max], mark[max];

void init(){
    cout << "So dinh n = "; cin >> n;
    cout << "Nhap dinh dau: "; cin >> a;
    cout << "Nhap dinh cuoi: "; cin >> z;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            cout << "w[" << i << "][" << j << "] = ";
            cin >> w[i][j];
            if (w[i][j] == 0) w[i][j] = oo;
        }
}

void dijkstra(){
    int v, minP;
    //Khoi tao
    for (int u = 1; u <= n; u++){
        L[u] = w[a][u];
        way[u] = a;
        mark[u] = 0;
    }
    way[a] = 0;
    L[a] = 0;
    mark[a] = 1;
    //Lap
    while (!mark[z]){
        minP = oo;
        //Tim u sao cho L[u] min
        for (int u = 1; u <= n; u++)
            if ((!mark[u]) && (minP > L[u])){
                v = u;
                minP = L[u];
            }
        mark[v] = 1; //u la dinh danh dau tam thoi nho nhat
        if (!mark[z]) //danh dau lai cac dinh
            for (int u = 1; u <= n; u++){
                if ((!mark[u]) && (L[v] + w[v][u] < L[u])){
                    L[u] = L[v] + w[v][u];
                    way[u] = v;
                }
            }
    }
}

void result(){
    cout << "Duong di ngan nhat tu dinh " << a << " den dinh " << z << " la: " << endl;
    cout << z << " <- ";
    int i = way[z];
    while (i != a){
        cout << i << " <- ";
        i = way[i];
    }
    cout << a << endl;
    cout << "Do dai duong di la: " << L[z];
}

int main(){
    init();
    dijkstra();
    result();
    return 0;
}