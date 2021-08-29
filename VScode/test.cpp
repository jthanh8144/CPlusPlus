#include <stdio.h>

void Nhap(float a[5][7]){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 7; j++){
            printf("A[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
}

void Xuat(float a[5][7]){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 7; j++){
            printf("A[%d][%d] = %f\t", i, j, a[i][j]);
        }
        printf("\t");
    }
}

void NhapX(float &x){
    printf("x = ");
    scanf("%f", &x);
}

void func(float x, float a[5][7]){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 7; j++){
            if (a[i][j] > (2*x + 1)) printf("%f \n", a[i][j]);
        }
    }
}

int main(){
    float A[5][7], x;
    Nhap(A);
    Xuat(A);
    NhapX(x);
    func(x, A);
}