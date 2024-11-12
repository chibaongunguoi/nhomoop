#ifndef NV_H
#define NV_H
#include <iomanip>
#include <iostream>
#include <string>
#include "date.h"
using namespace std;

class NhanVien
{
protected:
    string id;
    string name;
    Date dayStartOfWork;
    bool sex;
    double salary;

public:
    NhanVien(string id, string name, Date dayStartOfWork, bool sex)
    {
        if (id.length() != 8 || name == "")
        {
            throw invalid_argument("Dữ liệu đầu vào không hợp lệ ");
        }
        this->id = id;
        this->name = name;
        this->dayStartOfWork = dayStartOfWork;
        this->sex = sex;
        this->salary = 0;
    }

    virtual void display()
    {
        cout << "ID: " << id << endl;
        cout << "Tên: " << name << endl;
        cout << "Ngày bắt đầu làm việc: " << dayStartOfWork << endl;
        cout << "Giới tính: " << (sex ? "Nữ" : "Nam") << endl;
        cout << "Lương: " << fixed << setprecision(2) << salary << endl;
    }
    virtual void Salary() = 0;
};
#endif
