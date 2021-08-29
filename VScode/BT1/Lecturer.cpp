#include "Lecturer.h"

Lecturer::Lecturer(string Ten, int Tuoi, string DiaChi, bool GioiTinh, string MaLeturer, string CapBac)
    : Person(Ten, Tuoi, DiaChi, GioiTinh), MaLecturer(MaLecturer), CapBac(CapBac){

}

Lecturer::Lecturer(const Lecturer& l)
    : Person(l.Ten, l.Tuoi, l.DiaChi, l.GioiTinh), MaLecturer(l.MaLecturer), CapBac(l.CapBac) {

}

Lecturer::~Lecturer(){

}

/*void Lecturer::setLec() {
    cout << "Nhap giang vien: " << endl;
    cout << "\tTen: ";
    getline(cin, this->Ten);
    cout << "\tTuoi: ";
    cin >> this->Tuoi;
    cin.ignore();
    cout << "\tDia chi: ";
    getline(cin, this->DiaChi);
    string GT;
    cout << "\tGioi tinh: ";
    getline(cin, GT);
    if (GT == "Nam" || GT == "nam") this->GioiTinh = true;
    if (GT == "Nu" || GT == "nu") this->GioiTinh = false;
    this->MaLecturer = setML(this->Ten);
    cout << "\tCap bac Lecturer: ";
    getline(cin, this->CapBac);
}*/

string Lecturer::setML(string Ten){
    int l = Ten.length();
    string ML = "102";
    ML += Ten[0];
    for (int i = 1; i < l - 1; i++){
		if (Ten[i] == ' ') ML += Ten[i+1];
	}
	for (int i = l - 1; i > 0; i--){
		if (Ten[i] == ' '){
			for (int j = i+2; j < l; j++) {
				ML += Ten[j];
			}
			break;
		}
	}
    return ML;
}

string Lecturer::getNameL() const{
    return this->Ten;
}

ostream& operator<<(ostream& o, const Lecturer& l){
    o << "Giang vien:\n\tTen: " << l.Ten << endl
        << "\tTuoi: " << l.Tuoi << endl
        << "\tDia chi: " << l.DiaChi << endl
        << "\tGioi tinh: " << ((l.GioiTinh == true) ? "Nam" : "Nu") << endl
        << "\tMa Lecturer: " << l.MaLecturer << endl
        << "\tCap bac: " << l.CapBac << endl;
    return o;
}

istream& operator>>(istream& i, Lecturer& l){
    cout << "Nhap giang vien: " << endl;
    cout << "\tTen: ";
    getline(i, l.Ten);
    cout << "\tTuoi: ";
    i >> l.Tuoi;
    i.ignore();
    cout << "\tDia chi: ";
    getline(i, l.DiaChi);
    string GT;
    cout << "\tGioi tinh: ";
    getline(i, GT);
    if (GT == "Nam" || GT == "nam") l.GioiTinh = true;
    if (GT == "Nu" || GT == "nu") l.GioiTinh = false;
    l.MaLecturer = l.setML(l.Ten);
    cout << "\tCap bac Lecturer: ";
    getline(i, l.CapBac);
    return i;
}