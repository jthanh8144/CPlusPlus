//#include "point.h"
#include "point3D.h"
#include <iostream>
#include <string>
#include <exception>

using namespace std;

double Chia(double a, double b){
    if (b == 0){
        throw 15;
        //throw string("Loi");
        //throw 11.1;
        //throw point(1, 2);
        //throw point3D(1, 2, 3);
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
        /*catch(string e){
            cout << e << endl;
        }
        catch(int e){
            cout << e << endl;
        }
        catch(point& e){ //point3D(1, 2, 3) -> e = point(1, 2) -> phai dung tham chieu o point& e
            cout << e << endl;
            throw;
        }
        catch(point3D e){
            cout << e << endl;
        }
        catch(...){
            cout << "Alo" << endl;
        };*/
        catch(invalid_argument &e){
            cout << e.what() << endl;
        }
    }while (y == 0);
    return 0;
}