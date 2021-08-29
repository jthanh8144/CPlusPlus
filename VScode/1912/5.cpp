#include "QLSV.h"

int main(){
    QLSV db;
    SV s1(1, 18, 1.1);
    SV s2(2, 19, 2.2);
    SV s3(3, 20, 3.3);
    db.Add(s1);
    //cout << db;
    db.Add(s2);
    cout << db;
    db.Insert(s3, 6);
    cout << db;
    //cout << db.IndexOf(s2) << endl;
    // db.Update(5);
    // cout << db;
    return 0;
}