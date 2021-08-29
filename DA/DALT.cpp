#include "Grap.h"

int CtoI(char c[]){
	int temp = 0;
	for (int i = 0; i < strlen(c); i++){
		temp = temp*10 + (c[i] - '0');
	}
	return temp;
}

void Menu1(int maxx, int hmaxx, int maxy, int hmaxy) {
	char key;
	char *txt1[] = {"DO AN LAP TRINH", "GVHD: Phan Thanh Tao - Phan Chi Tung", "SVTH: Vo Van Thanh - Nguyen Duy Thinh", 
		"De tai: Phan mem quan li cua hang Laptop", "Dang Nhap", "Nhan Enter de dang nhap, Esc de thoat chuong trinh"};
    cleardevice();
    setcolor(3);
    rectangle(10, 10, maxx - 20, maxy - 20);
    settextstyle(3, 0, 4);
    outtextxy(hmaxx - textwidth(txt1[0]) / 2, 20, txt1[0]);
    setcolor(2);
    settextstyle(3, 0, 2);
    outtextxy(hmaxx - textwidth(txt1[1]) / 2, 90, txt1[1]);
    outtextxy(hmaxx - textwidth(txt1[2]) / 2, 120, txt1[2]);
	setcolor(14);
	settextstyle(3, 0, 4);
	outtextxy(hmaxx - textwidth(txt1[3]) / 2, 150, txt1[3]);
    setcolor(4);
    settextstyle(3, 0, 4);
    outtextxy(hmaxx - textwidth(txt1[4]) / 2, hmaxy - textheight(txt1[4]) / 2, txt1[4]);
    setcolor(3);
    settextstyle(3, 0, 2);
    outtextxy(hmaxx - textwidth(txt1[5]) / 2, maxy - 40, txt1[5]);
	do {
        key = getch();
    } while (key != ENTER && key != ESC);
    if (key == ESC) exit(0);
}

void BoxMenu2(int maxx, int hmaxx, int maxy, int hmaxy, int chooseBox, int heightBox, int widthBox, int marginBox) {
	cleardevice();
	char txt1[] = "Tai khoan: ", txt2[] = "Mat khau: ", txt3[] = "Nhan Enter de dang nhap, ESC de quay lai";
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt3) / 2, maxy - 40, txt3);
	rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
	if (chooseBox == 1){
        outtextxy(hmaxx - widthBox / 2 - textwidth(txt1), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt1) / 2, txt1);
	}
	else{
        outtextxy(hmaxx - widthBox / 2 - textwidth(txt2), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt2) / 2, txt2);
	}
}

void Menu2(int maxx, int hmaxx, int maxy, int hmaxy, int heightBox, int widthBox, int marginBox, char* &ID, char* &Pass){
	int i = 0, j = 0, keyPress = 0;
	char tmp, *sao;
	string s;
	ID = new char[10]; ID[i] = '\0';
	Pass = new char[10]; Pass[j] = '\0';
Id:
	cleardevice();
	BoxMenu2(maxx, hmaxx, maxy, hmaxy, 1, heightBox, widthBox, marginBox);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(ID) / 2, ID);
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			i = i <= 0 ? 0 : i-1;
			ID[i] = '\0';
		} else if (tmp == ESC) Menu1(maxx, hmaxx, maxy, hmaxy);
		else {
			ID[i] = tmp;
			ID[i+1] = '\0';
			i++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu2(maxx, hmaxx, maxy, hmaxy, 1, heightBox, widthBox, marginBox);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(ID) / 2, ID);
	}while(keyPress != ENTER);
	ID[i-1] = '\0';

	cleardevice();
	BoxMenu2(maxx, hmaxx, maxy, hmaxy, 2, heightBox, widthBox, marginBox);
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			j = j <= 0 ? 0 : j-1;
			Pass[j] = '\0';
			if (!s.empty()) s.erase(s.size() - 1);
		} else if (tmp == ESC) goto Id;
		else {
			Pass[j] = tmp;
			Pass[j+1] = '\0';
			j++;
			if (tmp != ENTER) s += '*';
		}
		sao = const_cast<char*>(s.c_str());
		keyPress = tmp;
		cleardevice();
		BoxMenu2(maxx, hmaxx, maxy, hmaxy, 2, heightBox, widthBox, marginBox);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(sao) / 2, sao);
	}while(keyPress != ENTER);
	Pass[j-1] = '\0';
}

void Login(int maxx, int hmaxx, int maxy, int hmaxy, int heightBox, int widthBox, int marginBox, char* &ID, char* &Pass, char **ID1, char **Pass1, int Admin[], int n, int &lengthMenu){
	char txt1[] = "Nhan Enter de tiep tuc.", txt2[] = "Dang nhap thanh cong!", txt3[] = "Sai tai khoan hoac mat khau.", txt4[] = "Vui long thu lai!";
	char tmp;
	cleardevice();
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt1) / 2, maxy - 40, txt1);
	for (int i = 0; i < n; i++)
		if (strcmp(ID, ID1[i]) == 0 && strcmp(Pass, Pass1[i]) == 0){
			outtextxy(hmaxx - textwidth(txt2) / 2, hmaxy - textheight(txt2) / 2, txt2);
			if (Admin[i] == 1) lengthMenu = 5;
			else lengthMenu = 4;
			do{
				tmp = getch();
			}while (tmp != ENTER);
			return;
		}
	outtextxy(hmaxx - textwidth(txt3) / 2, hmaxy - textheight(txt3) / 2 - 20, txt3);
	outtextxy(hmaxx - textwidth(txt4) / 2, hmaxy - textheight(txt4) / 2 + 20, txt4);
	do{
		tmp = getch();
	}while (tmp != ENTER);
	ID = "";
	Pass = "";
	Menu2(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, ID, Pass);
	Login(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, ID, Pass, ID1, Pass1, Admin, 2, lengthMenu);
}

void ShowMenu3(int maxx, int hmaxx, int maxy, int hmaxy, int choice, int lenMenu){
	char *Menu3List[] = {"Xuat kho", "Nhap kho", "In hoa don", "Thong tin khach hang", "Thong tin nhan vien"};
	char txt[] = "Dung phim mui ten de di chuyen len xuong, Enter de tiep tuc, ESC de quay lai";

	cleardevice();
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt) / 2, maxy - 40, txt);
	int tmp = maxy / 3;
	for (int i = 0; i < lenMenu; i++){
		i == choice ? setcolor(4) : setcolor(2);
		tmp += textheight(Menu3List[i]) + 10;
		outtextxy(hmaxx - textwidth(Menu3List[i]) / 2, tmp, Menu3List[i]);
	}
}

void Menu3(int maxx, int hmaxx, int maxy, int hmaxy, int heightBox, int widthBox, int marginBox, int lengthMenu3List){
	char keyPress;
	int choice = 0;
	ShowMenu3(maxx, hmaxx, maxy, hmaxy, choice, lengthMenu3List);
	do{
		keyPress = getch();
		if (keyPress == UP_ARROW)
			choice = (choice - 1) < 0 ? lengthMenu3List - 1 : choice - 1;
		else if (keyPress == DOWN_ARROW)
			choice = (choice + 1) % lengthMenu3List;
		else if (keyPress == ESC)
			Menu1(maxx, hmaxx, maxy, hmaxy);
		ShowMenu3(maxx, hmaxx, maxy, hmaxy, choice, lengthMenu3List);
	} while (keyPress != ENTER);
	switch (choice){
		case 0: {
			Menu3_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, lengthMenu3List);
			return;
		}
		case 1: {
			Menu3_2(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, lengthMenu3List);
			return;
		}
		case 2: {
			Menu3_3(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, lengthMenu3List);
			return;
		}
		case 3: {
			Menu3_4(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, lengthMenu3List);
			return;
		}
		case 4: {
			Menu3_5(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, lengthMenu3List);
			return;
		}
	}
}

void BoxMenu3_1(int maxx, int hmaxx, int maxy, int hmaxy, int heightBox, int widthBox, int marginBox, int choice){
	cleardevice();
	char *txt[] = {"Nhan Enter de tiep tuc, ESC de quay lai", "Ma hoa don: ", "Ma khach hang: ", "Ma san pham: ", "So luong: ", "Thoi gian xuat: ", "Nhan vien xuat: ", "Xuat kho"};
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt[0]) / 2, maxy - 40, txt[0]);
	outtextxy(hmaxx - textwidth(txt[7]) / 2, 20, txt[7]);
	rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
	switch (choice){
		case 1: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[1]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[1]) / 2, txt[1]); 
			break;
		}
		case 2: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[2]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[2]) / 2, txt[2]); 
			break;
		}
		case 3: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[3]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[3]) / 2, txt[3]); 
			break;
		}
		case 4: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[4]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[4]) / 2, txt[4]); 
			break;
		}
		case 5: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[5]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[5]) / 2, txt[5]); 
			break;
		}
		case 6: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[6]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[6]) / 2, txt[6]); 
			break;
		}
		case 7: {
			setcolor(0);
			rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
			setcolor(3);
			int tmp = maxy / 3;
			for (int i = 0; i < 6; i++){
				outtextxy(50, tmp, txt[i+1]);
				tmp += textheight(txt[i+1]) + 10;
			}
			break;
		}
	}
}

void Menu3_1(int maxx, int hmaxx, int maxy, int hmaxy, int heightBox, int widthBox, int marginBox, int lengthMenu3List){
	cleardevice();
	int temp = maxy / 3, keyPress = 0, index[] = {0, 0, 0, 0, 0, 0, 0};
	char tmp;
	char *MHD, *MKH, *MSP, *sl, *TGX, *NVX;
	MHD = new char[10]; MHD[index[0]] = '\0';
	MKH = new char[10]; MKH[index[2]] = '\0';
	MSP = new char[5]; MSP[index[3]] = '\0';
	sl = new char[3]; sl[index[4]] = '\0';
	TGX = new char[8]; TGX[index[5]] = '\0';
	NVX = new char[10]; NVX[index[6]] = '\0';
	int SL = 0;
ThongTinKH:
	Menu4_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, lengthMenu3List);
MaHD:
	cleardevice();
	BoxMenu3_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 1);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MHD) / 2, MHD);
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			index[0] = index[0] <= 0 ? 0 : index[0]-1;
			MHD[index[0]] = '\0';
		}else if (tmp == ESC){
			goto ThongTinKH;
			break;
		}
		else {
			MHD[index[0]] = tmp;
			MHD[index[0] + 1] = '\0';
			index[0]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 1);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MHD) / 2, MHD);
	} while (keyPress != ENTER);
	MHD[index[0] - 1] = '\0';
MaKH:
	cleardevice();
	BoxMenu3_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 2);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MKH) / 2, MKH);
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			index[2] = index[2] <= 0 ? 0 : index[2]-1;
			MKH[index[2]] = '\0';
		}else if (tmp == ESC){
			goto MaHD;
			break;
		}
		else {
			MKH[index[2]] = tmp;
			MKH[index[2] + 1] = '\0';
			index[2]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 2);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MKH) / 2, MKH);
	} while (keyPress != ENTER);
	MKH[index[2] - 1] = '\0';
MaSP:
	cleardevice();
	BoxMenu3_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 3);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MSP) / 2, MSP);
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			index[3] = index[3] <= 0 ? 0 : index[3]-1;
			MSP[index[3]] = '\0';
		}else if (tmp == ESC){
			goto MaKH;
			break;
		}
		else {
			MSP[index[3]] = tmp;
			MSP[index[3] + 1] = '\0';
			index[3]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 3);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MSP) / 2, MSP);
	} while (keyPress != ENTER);
	MSP[index[3] - 1] = '\0';
SoLuong:
	cleardevice();
	BoxMenu3_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 4);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(sl) / 2, sl);
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			index[4] = index[4] <= 0 ? 0 : index[4]-1;
			sl[index[4]] = '\0';
		}else if (tmp == ESC){
			goto MaSP;
			break;
		}
		else {
			sl[index[4]] = tmp;
			sl[index[4] + 1] = '\0';
			index[4]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 4);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(sl) / 2, sl);
	} while (keyPress != ENTER);
	sl[index[4] - 1] = '\0';
	SL = CtoI(sl);
TGXuat:
	cleardevice();
	BoxMenu3_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 5);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(TGX) / 2, TGX);
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			index[5] = index[5] <= 0 ? 0 : index[5]-1;
			TGX[index[5]] = '\0';
		}else if (tmp == ESC){
			goto SoLuong;
			break;
		}
		else {
			TGX[index[5]] = tmp;
			TGX[index[5] + 1] = '\0';
			index[5]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 5);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(TGX) / 2, TGX);
	} while (keyPress != ENTER);
	TGX[index[5] - 1] = '\0';
	
	cleardevice();
	BoxMenu3_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 6);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(NVX) / 2, NVX);
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			index[6] = index[6] <= 0 ? 0 : index[6]-1;
			NVX[index[6]] = '\0';
		}else if (tmp == ESC){
			goto TGXuat;
			break;
		}
		else {
			NVX[index[6]] = tmp;
			NVX[index[6] + 1] = '\0';
			index[6]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 6);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(NVX) / 2, NVX);
	} while (keyPress != ENTER);
	NVX[index[6] - 1] = '\0';
	
	cleardevice();
	BoxMenu3_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 7);
	outtextxy(maxx / 3, temp, MHD);
	temp += textheight(MHD) + 10;
	outtextxy(maxx / 3, temp, MKH);
	temp += textheight(MKH) + 10;
	outtextxy(maxx / 3, temp, MSP);
	temp += textheight(MSP) + 10;
	outtextxy(maxx / 3, temp, sl);
	temp += textheight(sl) + 10;
	outtextxy(maxx / 3, temp, TGX);
	temp += textheight(TGX) + 10;
	outtextxy(maxx / 3, temp, NVX);
	getch();
	Menu3(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, lengthMenu3List);
	return;
}

void BoxMenu3_2(int maxx, int hmaxx, int maxy, int hmaxy, int heightBox, int widthBox, int marginBox, int choice){
	cleardevice();
	char *txt[] = {"Nhan Enter de tiep tuc, ESC de quay lai", "Ma san pham: ", "So luong: ", "Don gia: ", "Noi nhap: ", "Thoi gian nhap: ", "Nhan vien nhap: ", "Nhap kho"};
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt[0]) / 2, maxy - 40, txt[0]);
	outtextxy(hmaxx - textwidth(txt[7]) / 2, 20, txt[7]);
	rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
	switch (choice){
		case 1: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[1]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[1]) / 2, txt[1]); 
			break;
		}
		case 2: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[2]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[2]) / 2, txt[2]); 
			break;
		}
		case 3: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[3]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[3]) / 2, txt[3]); 
			break;
		}
		case 4: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[4]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[4]) / 2, txt[4]); 
			break;
		}
		case 5: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[5]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[5]) / 2, txt[5]); 
			break;
		}
		case 6: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[6]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[6]) / 2, txt[6]); 
			break;
		}
		case 7: {
			setcolor(0);
			rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
			setcolor(3);
			int tmp = maxy / 3;
			for (int i = 0; i < 6; i++){
				outtextxy(50, tmp, txt[i+1]);
				tmp += textheight(txt[i+1]) + 10;
			}
			break;
		}
	}
}

void Menu3_2(int maxx, int hmaxx, int maxy, int hmaxy, int heightBox, int widthBox, int marginBox, int lengthMenu3List){
	cleardevice();
	int temp = maxy / 3, keyPress = 0, index[] = {0, 0, 0, 0, 0, 0};
	char tmp;
	char *MSP, *sl, *dg, *NN, *TGN, *NVN;
	int SL, DG;
	MSP = new char[10]; MSP[index[0]] = '\0';
	sl = new char[3]; sl[index[1]] = '\0';
	dg = new char[3]; dg[index[2]] = '\0';
	NN = new char[15]; NN[index[3]] = '\0';
	TGN = new char[8]; TGN[index[4]] = '\0';
	NVN = new char[10]; NVN[index[5]] = '\0';
MaSP:
	cleardevice();
	BoxMenu3_2(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 1);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MSP) / 2, MSP);
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			index[0] = index[0] <= 0 ? 0 : index[0]-1;
			MSP[index[0]] = '\0';
		}else if (tmp == ESC){
			Menu3(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, lengthMenu3List);
			break;
		}
		else {
			MSP[index[0]] = tmp;
			MSP[index[0] + 1] = '\0';
			index[0]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_2(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 1);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MSP) / 2, MSP);
	} while (keyPress != ENTER);
	MSP[index[0] - 1] = '\0';
SoLuong:
	cleardevice();
	BoxMenu3_2(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 2);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(sl) / 2, sl);
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			index[1] = index[1] <= 0 ? 0 : index[1]-1;
			sl[index[1]] = '\0';
		}else if (tmp == ESC){
			goto MaSP;
			break;
		}
		else {
			sl[index[1]] = tmp;
			sl[index[1] + 1] = '\0';
			index[1]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_2(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 2);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(sl) / 2, sl);
	} while (keyPress != ENTER);
	sl[index[1] - 1] = '\0';
	SL = CtoI(sl);
DonGia:
	cleardevice();
	BoxMenu3_2(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 3);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(dg) / 2, dg);
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			index[2] = index[2] <= 0 ? 0 : index[2]-1;
			dg[index[2]] = '\0';
		}else if (tmp == ESC){
			goto SoLuong;
			break;
		}
		else {
			dg[index[2]] = tmp;
			dg[index[2] + 1] = '\0';
			index[2]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_2(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 3);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(dg) / 2, dg);
	} while (keyPress != ENTER);
	dg[index[2] - 1] = '\0';
	DG = CtoI(dg);
NoiNhap:
	cleardevice();
	BoxMenu3_2(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 4);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(NN) / 2, NN);
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			index[3] = index[3] <= 0 ? 0 : index[3]-1;
			NN[index[3]] = '\0';
		}else if (tmp == ESC){
			goto DonGia;
			break;
		}
		else {
			NN[index[3]] = tmp;
			NN[index[3] + 1] = '\0';
			index[3]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_2(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 4);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(NN) / 2, NN);
	} while (keyPress != ENTER);
	NN[index[3] - 1] = '\0';
TGNhap:
	cleardevice();
	BoxMenu3_2(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 5);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(TGN) / 2, TGN);
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			index[4] = index[4] <= 0 ? 0 : index[4]-1;
			TGN[index[4]] = '\0';
		}else if (tmp == ESC){
			goto NoiNhap;
			break;
		}
		else {
			TGN[index[4]] = tmp;
			TGN[index[4] + 1] = '\0';
			index[4]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_2(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 5);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(TGN) / 2, TGN);
	} while (keyPress != ENTER);
	TGN[index[4] - 1] = '\0';

	cleardevice();
	BoxMenu3_2(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 6);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(NVN) / 2, NVN);
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			index[5] = index[5] <= 0 ? 0 : index[5]-1;
			NVN[index[5]] = '\0';
		}else if (tmp == ESC){
			goto TGNhap;
			break;
		}
		else {
			NVN[index[5]] = tmp;
			NVN[index[5] + 1] = '\0';
			index[5]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_2(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 6);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(NVN) / 2, NVN);
	} while (keyPress != ENTER);
	NVN[index[5] - 1] = '\0';
	
	cleardevice();
	BoxMenu3_2(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 7);
	outtextxy(maxx / 3, temp, MSP);
	temp += textheight(MSP) + 10;
	outtextxy(maxx / 3, temp, sl);
	temp += textheight(sl) + 10;
	outtextxy(maxx / 3, temp, dg);
	temp += textheight(dg) + 10;
	outtextxy(maxx / 3, temp, NN);
	temp += textheight(NN) + 10;
	outtextxy(maxx / 3, temp, TGN);
	temp += textheight(TGN) + 10;
	outtextxy(maxx / 3, temp, NVN);
	getch();
	Menu3(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, lengthMenu3List);
	return;
}

void BoxMenu3_3(int maxx, int hmaxx, int maxy, int hmaxy, int heightBox, int widthBox, int marginBox, int choice){
	cleardevice();
	char *txt[] = {"Nhan Enter de tiep tuc, ESC de quay lai", "Tu ngay: ", "Den ngay: ", "In hoa don: "};
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt[0]) / 2, maxy - 40, txt[0]);
	outtextxy(hmaxx - textwidth(txt[3]) / 2, 20, txt[3]);
	rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
	switch (choice){
		case 1: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[1]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[1]) / 2, txt[1]); 
			break;
		}
		case 2: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[2]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[2]) / 2, txt[2]); 
			break;
		}
	}
}

void Menu3_3(int maxx, int hmaxx, int maxy, int hmaxy, int heightBox, int widthBox, int marginBox, int lengthMenu3List){
	int i = 0, j = 0, keyPress = 0;
	char tmp;
	char *TN, *DN;
	TN = new char[8]; TN[i] = '\0';
	DN = new char[8]; DN[j] = '\0';
TuNgay:
	cleardevice();
	BoxMenu3_3(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 1);
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			i = i <= 0 ? 0 : i-1;
			TN[i] = '\0';
		} else if (tmp == ESC){
			Menu3(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, lengthMenu3List);
			break;
		}
		else {
			TN[i] = tmp;
			TN[i+1] = '\0';
			i++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_3(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 1);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(TN) / 2, TN);
	}while(keyPress != ENTER);
	TN[i-1] = '\0';

	cleardevice();
	BoxMenu3_3(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 2);
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			j = j <= 0 ? 0 : j-1;
			DN[j] = '\0';
		} else if (tmp == ESC){
			goto TuNgay;
			break;
		}
		else {
			DN[j] = tmp;
			DN[j+1] = '\0';
			j++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_3(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 2);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(DN) / 2, DN);
	}while(keyPress != ENTER);
	DN[j-1] = '\0';
	//Xu li in hoa don
	getch();
	Menu3(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, lengthMenu3List);
}

void ShowMenu3_4(int maxx, int hmaxx, int maxy, int hmaxy, int choice){
	char *Menu3List[] = {"Them khach hang", "Tim khach hang"};
	char txt[] = "Dung phim mui ten de di chuyen len xuong, Enter de tiep tuc, ESC de quay lai";

	cleardevice();
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt) / 2, maxy - 40, txt);
	int tmp = maxy / 3;
	settextstyle(3, 0, 3);
	for (int i = 0; i < 2; i++){
		i == choice ? setcolor(4) : setcolor(2);
		tmp += textheight(Menu3List[i]) + 10;
		outtextxy(hmaxx - textwidth(Menu3List[i]) / 2, tmp, Menu3List[i]);
	}
}

void Menu3_4(int maxx, int hmaxx, int maxy, int hmaxy, int heightBox, int widthBox, int marginBox, int lengthMenu3List){
	char keyPress;
	int choice = 0, lengthMenu3_4List = 2;
	ShowMenu3_4(maxx, hmaxx, maxy, hmaxy, choice);
	do{
		keyPress = getch();
		if (keyPress == UP_ARROW)
			choice = (choice - 1) < 0 ? lengthMenu3_4List - 1 : choice - 1;
		else if (keyPress == DOWN_ARROW)
			choice = (choice + 1) % lengthMenu3_4List;
		else if (keyPress == ESC)
			Menu3(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, lengthMenu3List);
		ShowMenu3_4(maxx, hmaxx, maxy, hmaxy, choice);
	} while (keyPress != ENTER);
	switch (choice){
		case 0: {
			Menu4_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, lengthMenu3List);
			return;
		}
		case 1: {
			Menu4_2(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, lengthMenu3List);
			return;
		}
		default: return;
	}
}

void BoxMenu4_1(int maxx, int hmaxx, int maxy, int hmaxy, int heightBox, int widthBox, int marginBox, int choice){
	cleardevice();
	char *txt[] = {"Nhan Enter de tiep tuc, ESC de quay lai", "Ma khach hang: ", "Ten khach hang: ", "SDT: ", "Dia chi: ", "Thong tin khach hang: "};
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt[0]) / 2, maxy - 40, txt[0]);
	outtextxy(hmaxx - textwidth(txt[5]) / 2, 20, txt[5]);
	rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
	switch (choice){
		case 1: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[1]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[1]) / 2, txt[1]); 
			break;
		}
		case 2: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[2]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[2]) / 2, txt[2]); 
			break;
		}
		case 3: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[3]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[3]) / 2, txt[3]); 
			break;
		}
		case 4: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[4]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[4]) / 2, txt[4]); 
			break;
		}
		case 5: {
			setcolor(0);
			rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
			setcolor(3);
			int tmp = maxy / 3;
			for (int i = 0; i < 4; i++){
				outtextxy(50, tmp, txt[i+1]);
				tmp += textheight(txt[i+1]) + 10;
			}
			break;
		}
	}
}

void Menu4_1(int maxx, int hmaxx, int maxy, int hmaxy, int heightBox, int widthBox, int marginBox, int lengthMenu3List){
	int temp = maxy / 3, keyPress = 0, index[] = {0, 0, 0, 0, 0};
	char tmp;
	char *MKH, *TKH, *SDT, *DC;
	MKH = new char[10]; MKH[index[1]] = '\0';
	TKH = new char[45]; TKH[index[2]] = '\0';
	SDT = new char[15]; SDT[index[3]] = '\0';
	DC = new char[50]; DC[index[4]] = '\0';
MaKH:
	cleardevice();
	BoxMenu4_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 1);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MKH) / 2, MKH);
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			index[1] = index[1] <= 0 ? 0 : index[1]-1;
			MKH[index[1]] = '\0';
		}else if (tmp == ESC){
			Menu3(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, lengthMenu3List);
			break;
		}
		else {
			MKH[index[1]] = tmp;
			MKH[index[1] + 1] = '\0';
			index[1]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu4_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 1);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MKH) / 2, MKH);
	} while (keyPress != ENTER);
	MKH[index[1] - 1] = '\0';
TenKH:
	cleardevice();
	BoxMenu4_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 2);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(TKH) / 2, TKH);
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			index[2] = index[2] <= 0 ? 0 : index[2]-1;
			TKH[index[2]] = '\0';
		}else if (tmp == ESC){
			goto MaKH;
			break;
		}
		else {
			TKH[index[2]] = tmp;
			TKH[index[2] + 1] = '\0';
			index[2]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu4_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 2);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(TKH) / 2, TKH);
	} while (keyPress != ENTER);
	TKH[index[2] - 1] = '\0';
SoDT:
	cleardevice();
	BoxMenu4_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 3);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(SDT) / 2, SDT);
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			index[3] = index[3] <= 0 ? 0 : index[3]-1;
			SDT[index[3]] = '\0';
		}else if (tmp == ESC){
			goto TenKH;
			break;
		}
		else {
			SDT[index[3]] = tmp;
			SDT[index[3] + 1] = '\0';
			index[3]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu4_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 3);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(SDT) / 2, SDT);
	} while (keyPress != ENTER);
	SDT[index[3] - 1] = '\0';
	
	cleardevice();
	BoxMenu4_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 4);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(DC) / 2, DC);
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			index[4] = index[4] <= 0 ? 0 : index[4]-1;
			DC[index[4]] = '\0';
		}else if (tmp == ESC){
			goto SoDT;
			break;
		}
		else {
			DC[index[4]] = tmp;
			DC[index[4] + 1] = '\0';
			index[4]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu4_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 4);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(DC) / 2, DC);
	} while (keyPress != ENTER);
	DC[index[4] - 1] = '\0';
	
	cleardevice();
	BoxMenu4_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 5);
	outtextxy(maxx / 3, temp, MKH);
	temp += textheight(MKH) + 10;
	outtextxy(maxx / 3, temp, TKH);
	temp += textheight(TKH) + 10;
	outtextxy(maxx / 3, temp, SDT);
	temp += textheight(SDT) + 10;
	outtextxy(maxx / 3, temp, DC);
	getch();
}

void BoxMenu4_2(int maxx, int hmaxx, int maxy, int hmaxy, int heightBox, int widthBox, int marginBox){
	char *txt[] = {"Dung phim mui ten de di chuyen len xuong, Enter de tiep tuc, ESC de quay lai", "Nhap SDT khach hang: "};

	cleardevice();
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt[0]) / 2, maxy - 40, txt[0]);
	outtextxy(hmaxx - widthBox / 2 - textwidth(txt[1]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[1]) / 2, txt[1]);
	rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
}

void Menu4_2(int maxx, int hmaxx, int maxy, int hmaxy, int heightBox, int widthBox, int marginBox, int lengthMenu3List){
	int i = 0, keyPress = 0;
	char tmp;
	char *SDT;
	SDT = new char[15]; SDT[i] = '\0';
	
	cleardevice();
	BoxMenu4_2(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox);
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			i = i <= 0 ? 0 : i-1;
			SDT[i] = '\0';
		} else if (tmp == ESC){
			Menu3_4(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, lengthMenu3List);
			return;
		}
		else {
			SDT[i] = tmp;
			SDT[i+1] = '\0';
			i++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu4_2(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(SDT) / 2, SDT);
	}while(keyPress != ENTER);
	SDT[i-1] = '\0';
	//Xu li tim kiem thong tin khach hang
}

void ShowMenu3_5(int maxx, int hmaxx, int maxy, int hmaxy, int choice){
	char *Menu3List[] = {"Them nhan vien", "Tim nhan vien", "Xoa nhan vien"};
	char txt[] = "Dung phim mui ten de di chuyen len xuong, Enter de tiep tuc, ESC de quay lai";

	cleardevice();
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt) / 2, maxy - 40, txt);
	int tmp = maxy / 3;
	settextstyle(3, 0, 3);
	for (int i = 0; i < 3; i++){
		i == choice ? setcolor(4) : setcolor(2);
		tmp += textheight(Menu3List[i]) + 10;
		outtextxy(hmaxx - textwidth(Menu3List[i]) / 2, tmp, Menu3List[i]);
	}
}

void Menu3_5(int maxx, int hmaxx, int maxy, int hmaxy, int heightBox, int widthBox, int marginBox, int lengthMenu3List){
	char keyPress;
	int choice = 0, lengthMenu3_5List = 3;
	ShowMenu3_5(maxx, hmaxx, maxy, hmaxy, choice);
	do{
		keyPress = getch();
		if (keyPress == UP_ARROW)
			choice = (choice - 1) < 0 ? lengthMenu3_5List - 1 : choice - 1;
		else if (keyPress == DOWN_ARROW)
			choice = (choice + 1) % lengthMenu3_5List;
		else if (keyPress == ESC)
			Menu3(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, lengthMenu3List);
		ShowMenu3_5(maxx, hmaxx, maxy, hmaxy, choice);
	} while (keyPress != ENTER);
	switch (choice){
		case 0: {
			Menu5_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, lengthMenu3List);
			return;
		}
		case 1: {
			Menu5_2(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, lengthMenu3List);
			return;
		}
		case 2: {
			Menu5_3(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, lengthMenu3List);
			return;
		}
	}
}

void BoxMenu5_1(int maxx, int hmaxx, int maxy, int hmaxy, int heightBox, int widthBox, int marginBox, int choice){
	cleardevice();
	char *txt[] = {"Nhan Enter de tiep tuc, ESC de quay lai", "Ma nhan vien: ", "Ten nhan vien: ", "Ngay sinh: ", "Gioi tinh: ", "SDT", "Chuc vu: ", 
		"Dia chi: ", "Thong tin nhan vien: ", "Them nhan vien thanh cong!"};
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt[0]) / 2, maxy - 40, txt[0]);
	outtextxy(hmaxx - textwidth(txt[8]) / 2, 20, txt[8]);
	rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
	switch (choice){
		case 1: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[1]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[1]) / 2, txt[1]); 
			break;
		}
		case 2: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[2]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[2]) / 2, txt[2]); 
			break;
		}
		case 3: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[3]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[3]) / 2, txt[3]); 
			break;
		}
		case 4: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[4]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[4]) / 2, txt[4]); 
			break;
		}
		case 5: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[5]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[5]) / 2, txt[5]);
			break;
		}
		case 6: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[6]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[6]) / 2, txt[6]);
			break;
		}
		case 7: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[7]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[7]) / 2, txt[7]);
			break;
		}
		case 8: {
			setcolor(0);
			rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
			setcolor(3);
			int tmp = maxy / 3;
			for (int i = 0; i < 7; i++){
				outtextxy(50, tmp, txt[i+1]);
				tmp += textheight(txt[i+1]) + 10;
			}
			break;
		}
		case 9: {
			setcolor(0);
			rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
			setcolor(3);
			outtextxy(hmaxx - textwidth(txt[9]) / 2, hmaxy - textheight(txt[9]) / 2, txt[9]);
			break;
		}
	}
}

void Menu5_1(int maxx, int hmaxx, int maxy, int hmaxy, int heightBox, int widthBox, int marginBox, int lengthMenu3List){
	cleardevice();
	int temp = maxy / 3, keyPress = 0, index[] = {0, 0, 0, 0, 0, 0, 0};
	char tmp;
	char *MNV, *TNV, *NS, *GT, *SDT, *CV, *DC;
	MNV = new char[10]; MNV[index[0]] = '\0';
	TNV = new char[45]; TNV[index[1]] = '\0';
	NS = new char[8]; NS[index[2]] = '\0';
	GT = new char[5]; GT[index[3]] = '\0';
	SDT = new char[15]; SDT[index[4]] = '\0';
	CV = new char[15]; CV[index[5]] = '\0';
	DC = new char[50]; DC[index[6]] = '\0';
MaNV:
	cleardevice();
	BoxMenu5_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 1);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MNV) / 2, MNV);
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			index[0] = index[0] <= 0 ? 0 : index[0]-1;
			MNV[index[0]] = '\0';
		}else if (tmp == ESC){
			Menu3_5(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, lengthMenu3List);
			break;
		}
		else {
			MNV[index[0]] = tmp;
			MNV[index[0] + 1] = '\0';
			index[0]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu5_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 1);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MNV) / 2, MNV);
	} while (keyPress != ENTER);
	MNV[index[0] - 1] = '\0';
TenNV:
	cleardevice();
	BoxMenu5_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 2);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(TNV) / 2, TNV);
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			index[1] = index[1] <= 0 ? 0 : index[1]-1;
			TNV[index[1]] = '\0';
		}else if (tmp == ESC){
			goto MaNV;
			break;
		}
		else {
			TNV[index[1]] = tmp;
			TNV[index[1] + 1] = '\0';
			index[1]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu5_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 2);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(TNV) / 2, TNV);
	} while (keyPress != ENTER);
	TNV[index[1] - 1] = '\0';
NgaySinh:
	cleardevice();
	BoxMenu5_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 3);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(NS) / 2, NS);
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			index[2] = index[2] <= 0 ? 0 : index[2]-1;
			NS[index[2]] = '\0';
		}else if (tmp == ESC){
			goto TenNV;
			break;
		}
		else {
			NS[index[2]] = tmp;
			NS[index[2] + 1] = '\0';
			index[2]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu5_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 3);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(NS) / 2, NS);
	} while (keyPress != ENTER);
	NS[index[2] - 1] = '\0';
GioiTinh:
	cleardevice();
	BoxMenu5_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 4);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(GT) / 2, GT);
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			index[3] = index[3] <= 0 ? 0 : index[3]-1;
			GT[index[3]] = '\0';
		}else if (tmp == ESC){
			goto NgaySinh;
			break;
		}
		else {
			GT[index[3]] = tmp;
			GT[index[3] + 1] = '\0';
			index[3]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu5_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 4);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(GT) / 2, GT);
	} while (keyPress != ENTER);
	GT[index[3] - 1] = '\0';
SoDT:
	cleardevice();
	BoxMenu5_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 5);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(SDT) / 2, SDT);
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			index[4] = index[4] <= 0 ? 0 : index[4]-1;
			SDT[index[4]] = '\0';
		}else if (tmp == ESC){
			goto GioiTinh;
			break;
		}
		else {
			SDT[index[4]] = tmp;
			SDT[index[4] + 1] = '\0';
			index[4]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu5_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 5);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(SDT) / 2, SDT);
	} while (keyPress != ENTER);
	SDT[index[4] - 1] = '\0';
ChucVu:
	cleardevice();
	BoxMenu5_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 6);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(CV) / 2, CV);
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			index[5] = index[5] <= 0 ? 0 : index[5]-1;
			CV[index[5]] = '\0';
		}else if (tmp == ESC){
			goto SoDT;
			break;
		}
		else {
			CV[index[5]] = tmp;
			CV[index[5] + 1] = '\0';
			index[5]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu5_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 6);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(CV) / 2, CV);
	} while (keyPress != ENTER);
	CV[index[5] - 1] = '\0';
	
	cleardevice();
	BoxMenu5_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 7);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(DC) / 2, DC);
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			index[6] = index[6] <= 0 ? 0 : index[6]-1;
			DC[index[6]] = '\0';
		}else if (tmp == ESC){
			goto ChucVu;
			break;
		}
		else {
			DC[index[6]] = tmp;
			DC[index[6] + 1] = '\0';
			index[6]++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu5_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 7);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(DC) / 2, DC);
	} while (keyPress != ENTER);
	DC[index[6] - 1] = '\0';
	
	cleardevice();
	BoxMenu5_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 8);
	outtextxy(maxx / 3, temp, MNV);
	temp += textheight(MNV) + 10;
	outtextxy(maxx / 3, temp, TNV);
	temp += textheight(TNV) + 10;
	outtextxy(maxx / 3, temp, NS);
	temp += textheight(NS) + 10;
	outtextxy(maxx / 3, temp, GT);
	temp += textheight(GT) + 10;
	outtextxy(maxx / 3, temp, SDT);
	temp += textheight(SDT) + 10;
	outtextxy(maxx / 3, temp, CV);
	temp += textheight(CV) + 10;
	outtextxy(maxx / 3, temp, DC);
	getch();
	BoxMenu5_1(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 9);
	getch();
	Menu3(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, lengthMenu3List);
	return;
}

void BoxMenu5_2(int maxx, int hmaxx, int maxy, int hmaxy, int heightBox, int widthBox, int marginBox, int choice){
	char *txt[] = {"Dung phim mui ten de di chuyen len xuong, Enter de tiep tuc, ESC de quay lai", "Nhap ma nhan vien: ", "Ma nhan vien khong ton tai!", "Xoa nhan vien thanh cong!",
		"Xoa nhan vien that bai!"};

	cleardevice();
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt[0]) / 2, maxy - 40, txt[0]);
	switch (choice){
		case 1: {
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[1]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[1]) / 2, txt[1]);
			rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
			break;
		}
		case 2: {
			outtextxy(hmaxx - textwidth(txt[2]) / 2, hmaxy - textheight(txt[2]) / 2, txt[2]);
			getch();
			break;
		}
		case 3: {
			outtextxy(hmaxx - textwidth(txt[3]) / 2, hmaxy - textheight(txt[3]) / 2, txt[3]);
			getch();
			break;
		}
		case 4: {
			outtextxy(hmaxx - textwidth(txt[4]) / 2, hmaxy - textheight(txt[4]) / 2, txt[4]);
			getch();
			break;
		}
	}
}

void ShowStaff(){
	
}

void Menu5_2(int maxx, int hmaxx, int maxy, int hmaxy, int heightBox, int widthBox, int marginBox, int lengthMenu3List){
	int i = 0, keyPress = 0;
	char tmp;
	char *MNV;
	MNV = new char[15];
	
	cleardevice();
	BoxMenu5_2(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 1);
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			i = i <= 0 ? 0 : i-1;
			MNV[i] = '\0';
		} else if (tmp == ESC){
			Menu3_5(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, lengthMenu3List);
			return;
		}
		else {
			MNV[i] = tmp;
			MNV[i+1] = '\0';
			i++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu5_2(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 1);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MNV) / 2, MNV);
	}while(keyPress != ENTER);
	MNV[i-1] = '\0';
	
	if (strcmp(MNV, "01") == 0) ShowStaff();
	else {
		BoxMenu5_2(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 2);
		Menu3_5(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, lengthMenu3List);
		return;
	}
}

void Menu5_3(int maxx, int hmaxx, int maxy, int hmaxy, int heightBox, int widthBox, int marginBox, int lengthMenu3List){
	int i = 0, keyPress = 0;
	char tmp;
	char *MNV;
	MNV = new char[15]; MNV[i] = '\0';
	
	cleardevice();
	BoxMenu5_2(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 1);
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			i = i <= 0 ? 0 : i-1;
			MNV[i] = '\0';
		} else if (tmp == ESC){
			Menu3_5(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, lengthMenu3List);
			return;
		}
		else {
			MNV[i] = tmp;
			MNV[i+1] = '\0';
			i++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu5_2(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 1);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(MNV) / 2, MNV);
	}while(keyPress != ENTER);
	MNV[i-1] = '\0';
	
	if (strcmp(MNV, "01") == 0) {
		BoxMenu5_2(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 3);
		Menu3_5(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, lengthMenu3List);
	}
	else {
		BoxMenu5_2(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, 4);
		Menu3_5(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, lengthMenu3List);
	}
}

int main(){
	char key, 
		*ID, *Pass, **ID1, **Pass1, 
		*MHD, *MKH, *TKH, *SDT, *DC;
	int heightBox = 40, widthBox = 200, marginBox = 25, lengthMenu3List;

	//initwindow(1000, 700);
	initwindow(1500, 800);
	int maxx = getmaxx();
    int hmaxx = maxx / 2;
    int maxy = getmaxy();
    int hmaxy = maxy / 2;

    Menu1(maxx, hmaxx, maxy, hmaxy);
    Menu2(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, ID, Pass);
	ID1 = new char*[2]; ID1[0] = "thanh"; ID1[1] = "thinh";
	Pass1 = new char*[2]; Pass1[0] = "123"; Pass1[1] = "456";
	int Admin[2] = {1, 0};
	Login(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, ID, Pass, ID1, Pass1, Admin, 2, lengthMenu3List);
	
	Menu3(maxx, hmaxx, maxy, hmaxy, heightBox, widthBox, marginBox, lengthMenu3List);
	
	getch();
	return 0;
}
