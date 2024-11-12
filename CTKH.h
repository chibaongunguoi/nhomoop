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
    void setid(string id)
    {
        this->id = id;
    }
    void setngayxuatban(Date day)
    {
        if (day.getyear() < 1900)
        {
            throw invalid_argument("Dữ liệu về thời gian không hợp lệ");
        }
        this->ngayxuatban = day;
    }
    void setkhuvuc(bool kv)
    {

        if (kv != 0 && kv != 1)
        {
            throw invalid_argument("Dữ liệu về khu vực không hợp lệ");
        }
        this->khuvuc = kv;
    }
    friend istream &operator>>(istream &is, CongTrinhKhoaHoc &nv)
    {
        string id;
        Date day;
        bool kv;
        cout << "Mã công trình :" << endl;
        cin >> id;
        cout << "Ngày xuất bản : " << endl;
        cin >> day;
        if (day.getyear() < 1900)
        {
            throw invalid_argument("Dữ liệu về thời gian không hợp lệ");
        }
        cout << "Khu vực xuất bản (1 - quốc tế, 0 - trong nước): ";
        cin >> kv;
        if (kv != 0 && kv != 1)
        {
            throw invalid_argument("Dữ liệu về khu vực không hợp lệ");
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
    virtual void set() {};
};
#endif
