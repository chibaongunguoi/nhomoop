#ifndef BaiBao_H
#define BaiBao_H
#include <iostream>
#include <string>
#include "CTKH.h"
#include <iomanip>

using namespace std;

class BaiBao : public CongTrinhKhoaHoc
{
private:
    string name;
    int count;

public:
    BaiBao(string name = "", int count = 0)
        : CongTrinhKhoaHoc(), name(name), count(count)
    {
    }
    void display() override
    {
        CongTrinhKhoaHoc::display();
        cout << "Tên công trình: " << name << endl;
        cout << "Số tác giả: " << count << endl;
    }
    friend istream &operator>>(istream &is, BaiBao &nv)
    {
        string name;
        int count;
        is >> (CongTrinhKhoaHoc &)nv;
        cout << "Nhập tên bài báo: ";
        cin.ignore();
        getline(is, name);
        cout
            << "Nhập số tác giả của bài báo: ";
        cin >> count;
        nv.name = name;
        nv.count = count;
        return is;
    }
};
#endif
