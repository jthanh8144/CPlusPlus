#include <iostream>
using namespace std;

struct SV
{
    private:
        string Ten;
        int DiemToan;
        int DiemVan;
    public:
        SV(string t = "", int dt = 0, int dv = 0)
            :Ten(t), DiemToan(dt), DiemVan(dv) {

        }
        ~SV() {}
        friend ostream& operator<<(ostream&, const SV&);
        friend istream& operator>>(istream&, SV&);
        double calDTB() {
            return (double)(this->DiemToan + this->DiemVan) / 2;
        }
        void XepLoai() {
            double dtb = this->calDTB();
            if (dtb >= 8.0) {
                cout << "Xep loai gioi";
            } else if (dtb >= 7.0) {
                cout << "Xep loai kha";
            } else if (dtb >= 5.0) {
                cout << "Xep loai trung binh";
            } else cout << "Xep loai yeu";
        }
        friend bool operator>(const SV&, const SV&);
        friend bool operator<(const SV&, const SV&);
        friend void swap(SV&, SV&);
};

ostream& operator<<(ostream& o, const SV& s) {
    o << "Ten: " << s.Ten << ", Diem toan: " << s.DiemToan << ", Diem van: " << s.DiemVan;
    return o;
}

istream& operator>>(istream& i, SV& s) {
    cout << "Nhap ten: "; i >> s.Ten;
    do {
        cout << "Nhap diem toan: "; i >> s.DiemToan;
    } while (s.DiemToan < 0 || s.DiemToan > 10);
    do {
        cout << "Nhap diem van: "; i >> s.DiemVan;
    } while (s.DiemVan < 0 || s.DiemVan > 10);
    cout << endl;
    return i;
}

bool operator>(const SV& s1, const SV& s2) {
    double d1 = (double)(s1.DiemToan + s1.DiemVan) / 2;
    double d2 = (double)(s2.DiemToan + s2.DiemVan) / 2;
    return d1 > d2 ? true : false;
}

bool operator<(const SV& s1, const SV& s2) {
    double d1 = (double)(s1.DiemToan + s1.DiemVan) / 2;
    double d2 = (double)(s2.DiemToan + s2.DiemVan) / 2;
    return d1 < d2 ? true : false;
}

void Nhap(SV* &data, int &n) {
    cout << "Nhap so luong sinh vien n = "; cin >> n;
    data = new SV[n];
    SV s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        data[i] = s;
    }
}

void Xuat(SV* data, int n) {
    cout << "Danh sach sinh vien: " << endl;
    for (int i = 0; i < n; i++) {
        cout << data[i] << ", diem trung binh: " << data[i].calDTB() << ", ";
        data[i].XepLoai();
        cout << endl;
    }
    cout << endl;
}

void swap(SV &s1, SV &s2) {
    SV t;
    t.Ten = s1.Ten;
    t.DiemToan = s1.DiemToan;
    t.DiemVan = s1.DiemVan;
    s1.Ten = s2.Ten;
    s1.DiemToan = s2.DiemToan;
    s1.DiemVan = s2.DiemVan;
    s2.Ten = t.Ten;
    s2.DiemToan = t.DiemToan;
    s2.DiemVan = t.DiemVan;
}

void SapXep(SV* &data, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (data[i].calDTB() < data[j].calDTB()) {
                swap(data[i], data[j]);
            }
        }
    }
    Xuat(data, n);
}

int main() {
    SV* data;
    int n;
    Nhap(data, n);
    Xuat(data, n);
    SapXep(data, n);
    return 0;
}
