#ifndef NV_H
#define NV_H
#include <iomanip>
#include <iostream>
#include <string>
#include "date.h"
using namespace std;

class CongTrinhKhoaHoc
{
protected:
    string id;
    Date ngayxuatban;
    bool khuvuc;

public:
    CongTrinhKhoaHoc(string id = "0", Date day = {1, 1, 2024}, bool kv = 1)
    {
        this->id = id;
        this->ngayxuatban = day;
        this->khuvuc = kv;
    };
    friend istream &operator>>(istream &is, CongTrinhKhoaHoc &nv)
    {
        string id;
        Date day;
        bool kv;
        cout << "Mã công trình :" << endl;
        cin >> id;
        cout << "Ngày xuất bản : " << endl;
        cin >> day;
        cout << "Khu vực xuất bản (1 - quốc tế, 2 - trong nước): ";
        cin >> kv;
        if (kv != 0 && kv != 1)
        {
            cout << "Dữ liệu không hợp lệ .\n";
        }
        nv.id = id;
        nv.ngayxuatban = day;
        nv.khuvuc = kv;
        return is;
    }
    virtual void display()
    {
        cout << "ID: " << id << endl;
        cout << "Ngày xuất bản: " << ngayxuatban << endl;
        cout << "Khu vực xuất bản: " << (khuvuc ? "Quốc tế" : "Trong nước") << endl;
    }
    virtual void Salary() {};
};
#endif
