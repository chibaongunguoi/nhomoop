#ifndef LLKHCaNhan_H
#define LLKHCaNhan_H

#include "linkedlist.h"
#include "CTKH.h"
#include <iostream>
#include <string>
#include <stdexcept>

class LLKHCaNhan
{
private:
    string name;
    LinkedList<CongTrinhKhoaHoc> list;

public:
    LLKHCaNhan(const string &name) : name(name) {};

    void add(CongTrinhKhoaHoc *nv)
    {
        list.append(nv);
    }

    // Xuất danh sách nhân viên
    void display() const
    {
        cout << "Danh sách công trình khoa học " << ":\n";
        list.display();
    }

    // Lấy số lượng nhân viên
    int getCount() const
    {
        return list.getSize();
    }

    // Truy cập nhân viên theo chỉ số
    CongTrinhKhoaHoc *operator[](int index)
    {
        if (index < 0 || index >= list.getSize())
        {
            throw out_of_range("Danh sách không có chỉ số này");
        }
        return list[index];
    }

    // Toán tử gán cho LLKHCaNhan
    LLKHCaNhan &operator=(const LLKHCaNhan &other)
    {
        if (this == &other)
            return *this;
        name = other.name;
        list = other.list;
        return *this;
    }

    void deleteByIndex(int index)
    {
        if (index < 0 || index >= list.getSize())
        {
            cout << "Không tìm thấy công trình khoa học có chỉ số trên\n";
            return;
        }
        delete list[index];
        list.removeAt(index);
        cout << "Công trình khoa học có chỉ số " << index << " đã bị xóa thành công.\n";
    }
};

#endif
