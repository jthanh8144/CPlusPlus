// g++ test.cpp -o a

#include <iostream>
using namespace std;

int *a, n;

void Nhap() {
    cout << "Nhap n = "; cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = "; cin >> a[i];
    }
}

void Xuat(int *a, int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void Swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

bool asc(int left, int right) {
	return left > right;
}

bool desc(int left, int right) {
	return left < right;
}

void SelectionSort(int *a, int n, bool (*compare)(int, int)) {
    int m;
    for (int i = 0; i < n - 1; i++)
    {
        m = i; 
        for (int j = i + 1; j < n; j++)
            if (compare(a[j], a[m]))
                m = j; 
        if (m != i) 
            Swap(a[i], a[m]);
    }
    cout << endl << "Selection sort:";
    Xuat(a, n);
}

void BubbleSort(int *a, int n, bool (*compare)(int, int)) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (compare(a[j], a[j+1]))
                swap(a[j], a[j + 1]); 
    cout << endl << "Bubble sort:";
    Xuat(a, n);
}

void InsertionSort(int *a, int n, bool (*compare)(int, int)) {
    int pos, x;
    for (int i = 1; i < n; i++) {
        x = a[i]; 
        pos = i - 1;
        while (pos >= 0 && compare(a[pos], x)) {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = x;
    }
    cout << endl << "Insertion sort:";
    Xuat(a, n);
}

int partition(int arr[], int l, int r, bool (*compare)(int, int)){
	int x = arr[r];
	int i = l - 1;
	for(int j = l; j <= r-1; j++){
		if(!compare(arr[j], x)){
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[r]);
	return (i+1);
}

void QuickSort(int *arr, int l, int r, bool (*compare)(int, int)){
	if(l < r){
		int p = partition(arr,l,r, compare);
		QuickSort(arr, l, p-1, compare);
		QuickSort(arr, p+1, r, compare);
	}
}

void PrintQS(int *a, int l, int r) {
    QuickSort(a, 0, n - 1, asc);
    cout << endl << "Quick sort:";
    Xuat(a, n);
    QuickSort(a, 0, n - 1, desc);
    cout << endl << "Quick sort:";
    Xuat(a, n);
}

int main() {
    Nhap();
    Xuat(a, n);
    SelectionSort(a, n, asc);
    SelectionSort(a, n, desc);
    BubbleSort(a, n, asc);
    BubbleSort(a, n, desc);
    InsertionSort(a, n, asc);
    InsertionSort(a, n, desc);
    PrintQS(a, 0, n - 1);
    return 0;
}