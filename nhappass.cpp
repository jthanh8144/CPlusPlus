#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

const int LEFT_ARROW = 75;
const int UP_ARROW = 72;
const int RIGHT_ARROW = 77;
const int DOWN_ARROW = 80;
const int ENTER = 13;
const int ESC = 27;
const int BACKSPACE = 8;
const int TAB = 9;

int main(){
	char* ID;
	string id;
	for (char c; (c = getch()); )
    {
        if (c == ENTER || c == '\r') { //phím enter
            cout << "\n";
            break;
        } else if (c == BACKSPACE) { //phím backspace
            if (!id.empty()) {
            	id.erase(id.size()-1);
            	cout << "\b \b";
			}
        } else if (c == -32) { //phím mui tên
            _getch(); //b? qua kí t? ti?p theo (hu?ng mui tên)
        } else if (isprint(c)) {
            cout << '*';
            id += c;
        }
    }
	ID = const_cast<char*>(id.c_str());
	cout << ID << endl;
	return 0;
}
