#ifndef QLNV_H
#define QLNV_H

#include "linkedlist.h"
#include "nhanvien.h"
#include <iostream>
#include <string>
#include <stdexcept>

class QLNV
{
private:
    string name;
    LinkedList<NhanVien> employees;

public:
    QLNV(const string &name) : name(name) {}

    // Thêm nhân viên
    void addEmployee(NhanVien *nv)
    {
        employees.append(nv);
    }

    // Xuất danh sách nhân viên
    void displayEmployees() const
    {
        cout << "Danh sách nhân viên " << ":\n";
        employees.display();
    }

    // Lấy số lượng nhân viên
    int getEmployeeCount() const
    {
        return employees.getSize();
    }

    // Truy cập nhân viên theo chỉ số
    NhanVien *operator[](int index)
    {
        if (index < 0 || index >= employees.getSize())
        {
            throw out_of_range("Danh sách không có chỉ số này");
        }
        return employees[index];
    }

    // Toán tử gán cho QLNV
    QLNV &operator=(const QLNV &other)
    {
        if (this == &other)
            return *this;
        name = other.name;
        employees = other.employees;
        return *this;
    }

    // Xử lý tính lương cho tất cả nhân viên
    void calculateSalaries()
    {
        for (int i = 0; i < employees.getSize(); i++)
        {
            employees[i]->Salary();
        }
    }

    void deleteEmployeeByIndex(int index)
    {
        if (index < 0 || index >= employees.getSize())
        {
            cout << "Không tìm thấy nhân viên có chỉ số trên\n";
            return;
        }
        delete employees[index];
        employees.removeAt(index);
        cout << "Nhân viên có chỉ số " << index << " đã bị xóa thành công.\n";
    }
};

#endif
