#include <iostream>
using namespace std;

struct Date
{
    private:
        int day;
        int month;
        int year;
    public: 
        Date(int d = 1, int m = 1, int y = 1) {
            this->day = d;
            this->month = m;
            this->year = y;
        }
        ~Date() {

        }
        static bool check_leap_year(int year) {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) return true;
            return false;
        }
        friend ostream& operator<<(ostream&, const Date&);
        friend istream& operator>>(istream&, Date&);
        void getDay() {
            int JMD = (day + ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5) +
                       (365 * (year + 4800 - ((14 - month) / 12))) +
                       ((year + 4800 - ((14 - month) / 12)) / 4) -
                       ((year + 4800 - ((14 - month) / 12)) / 100) +
                       ((year + 4800 - ((14 - month) / 12)) / 400) - 32045) % 7;
            cout << "Ngay " << this->day << " thang " << this->month << " nam " << this->year;
            switch (JMD) {
                case 0:
                    cout << " la thu hai" << endl;
                    break;
                case 1:
                    cout << " la thu ba" << endl;
                    break;
                case 2:
                    cout << " la thu tu" << endl;
                    break;
                case 3:
                    cout << " la thu nam" << endl;
                    break;
                case 4:
                    cout << " la thu sau" << endl;
                    break;
                case 5:
                    cout << " la thu bay" << endl;
                    break;
                case 6:
                    cout << " la chu nhat" << endl;
                    break;
            }
        }
        int count_day_of_month(int month, int year) {
            switch (month) {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    return 31;
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    return 30;
                    break;
                case 2:
                    if (check_leap_year(year) == true) return 29;
                    else return 28;
                    break;
            }
            return 0;
        }
        Date& operator++() {
            this->day++;
            if (this->day > count_day_of_month(this->month, this->year))
            {
                this->day = 1;
                this->month++;
                if (this->month > 12)
                {
                    this->month = 1;
                    this->year++;
                }
            }
        }
        const Date operator++(int) {
            Date before = (*this);
            this->day++;
            if (this->day > count_day_of_month(this->month, this->year))
            {
                this->day = 1;
                this->month++;
                if (this->month > 12)
                {
                    this->month = 1;
                    this->year++;
                }
            }
            return before;
        }
        Date& operator--() {
            this->day--;
            if (this->day == 0) {
                this->month--;
                if (this->month == 0) {
                    this->month = 12;
                    this->year--;
                }
                this->day = count_day_of_month(this->month, this->year);
            }
            return (*this);
        }
        const Date operator--(int) {
            Date before = (*this);
            this->day--;
            if (this->day == 0) {
                this->month--;
                if (this->month == 0) {
                    this->month = 12;
                    this->year--;
                }
                this->day = count_day_of_month(this->month, this->year);
            }
            return before;
        }
        friend bool operator==(const Date&, const Date&);
        friend bool operator!=(const Date&, const Date&);
        friend bool operator>(const Date&, const Date&);
        friend bool operator<(const Date&, const Date&);
};

ostream& operator<<(ostream& o, const Date& d) {
    o << "Ngay " << d.day << " thang " << d.month << " nam " << d.year << endl;
    return o;
}



bool check_date(int day, int month, int year) {
    if (month == 2) {
        if (Date::check_leap_year(year) == true) {
            if (day != 29) return false;
            else return true;
        } else if (day != 28) return false;
        else return true;
    }
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (day > 0 && day < 32) return true;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (day > 0 && day < 31) return true;
            break;
    }
    return false;
}

bool check_month(int month) {
    if (month > 0 && month < 13) return true;
    return false;
}

bool check_year(int year) {
    if (year > 999 && year < 10000) return true;
    return false;
}

istream& operator>>(istream& i, Date& d) {
    do {
        cout << "Nhap ngay: "; i >> d.day;
        cout << "Nhap thang: "; i >> d.month;
        cout << "Nhap nam: "; i >> d.year;
    } while (check_year(d.year) == false || check_month(d.month) == false || check_date(d.day, d.month, d.year) == false);
    return i;
}

bool operator==(const Date& d1, const Date& d2) {
    if (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year) return true;
    else return false;
}

bool operator!=(const Date& d1, const Date& d2) {
    if (d1.day != d2.day || d1.month != d2.month || d1.year != d2.year) return true;
    else return false;
}

bool operator>(const Date& d1, const Date& d2) {
    if (d1.year > d2.year) return true;
    else if (d1.year < d2.year) return false;
    else {
        if (d1.month > d2.month) return true;
        else if (d1.month < d2.month) return false;
        else {
            if (d1.day > d2.day) return true;
            else if (d1.day < d2.day) return false;
        }
    }
}


bool operator<(const Date& d1, const Date& d2) {
    if (d1.year < d2.year) return true;
    else if (d1.year > d2.year) return false;
    else {
        if (d1.month < d2.month) return true;
        else if (d1.month > d2.month) return false;
        else {
            if (d1.day < d2.day) return true;
            else if (d1.day > d2.day) return false;
        }
    }
}

int main() {
    Date d;
    cin >> d;
    cout << d;
    d.getDay();
    d--;
    cout << d;
    Date d1(11, 9, 2021);
    Date d2(12, 9, 2021);
    cout << (d1 == d2) << " " << (d1 != d2) << " " << (d1 > d2) << " " << (d1 < d2) << endl;
    return 0;
}
