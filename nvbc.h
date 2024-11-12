#ifndef NVBC_H
#define NVBC_H
#include <iostream>
#include <string>
#include "nhanvien.h"
#include <iomanip>

using namespace std;

class NVBC : public NhanVien
{
private:
    double coeffSalary;
    double experience;

public:
    NVBC(string id, string name, Date dayStartOfWork, bool sex, double coeffSalary, double experience)
        : NhanVien(id, name, dayStartOfWork, sex)
    {
        if (coeffSalary < 2.34 || coeffSalary > 10 || experience < 0)
        {
            throw invalid_argument("Dữ liệu đầu vào không hợp lệ");
        }
        this->coeffSalary = coeffSalary;
        this->experience = experience;
    }

    void display() override
    {
        NhanVien::display();
        cout << "Coeff salary: " << coeffSalary << endl;
        cout << "Experience: " << experience << endl;
    }

    void Salary() override
    {
        double bonus = (experience < 5) ? 0 : experience / 100;
        this->salary = (coeffSalary * 1390000) * (1 + bonus);
    }
};
#endif
