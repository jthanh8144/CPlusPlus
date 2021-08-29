#include <iostream>
#include <string>

using namespace std;

double Chia(double a, double b){
    if (b == 0){
        //throw 15;
        //throw string("Loi");
        throw 11.1;
    }
    else{
        return a/b;
    }
}

int main(){
    double x, y;
    cout << "x = ";
    cin >> x;
    do{
        cout << "y = ";
        cin >> y;
        try{
            double z = Chia(x, y);
        }
        catch(string e){
            cout << e << endl;
        }
        catch(int e){
            cout << e << endl;
        }
        catch(...){
            cout << "Alo" << endl;
        };
    }while (y == 0);
    return 0;
}
//xem tiep thi qua ben KeThua -> NgoaiLe1.cpp