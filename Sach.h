#ifndef Sach_H
#define Sach_H
#include <iostream>
#include <string>
#include <iomanip>
#include "CTKH.h"

using namespace std;

class Sach : public CongTrinhKhoaHoc
{
private:
    string type;

public:
    Sach(string type = "")
        : CongTrinhKhoaHoc(), type(type)
    {
    }
    void display() override
    {
        CongTrinhKhoaHoc::display();
        cout << "Loại sách : " << type << endl;
    }
    friend istream &operator>>(istream &is, Sach &nv)
    {
        string type;
        is >> (CongTrinhKhoaHoc &)nv;
        cout << "Nhập loại sách: ";
        cin.ignore();
        getline(is, type);
        nv.type = type;
        return is;
    }
};
#endif
