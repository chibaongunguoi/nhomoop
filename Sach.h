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
    void settype(string t)
    {
        this->type = t;
    }
    void set()
    {
        cout << "Nhập trường bạn muốn sửa (0-Mã công trình, 1-Ngày xuất bản, 2-Khu vực,3-Loại sách) " << endl;
        int i;
        if (i >= 0 && i <= 4)
            cout << "Bạn muốn sửa thông tin của trường này thành :";
        else
        {
            return;
        }
        if (i == 0)
        {
            string id;
            cin >> id;
            setid(id);
        }
        else if (i == 1)
        {
            Date day;
            cin >> day;
            setngayxuatban(day);
        }
        else if (i == 2)
        {
            bool kv;
            cin >> kv;
            setkhuvuc(kv);
        }
        else if (i == 3)
        {
            string type;
            cin.ignore();
            getline(cin, type);
            settype(type);
        }
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
