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
        if (count < 0)
            throw invalid_argument("Dữ liệu về số lượng tác giả không hợp lệ");
        nv.name = name;
        nv.count = count;
        return is;
    }
    void setname(string name)
    {
        this->name = name;
    }
    void setcount(int count)
    {
        if (count < 0)
        {
            cout << "Dữ liệu về số lượng tác giả không hợp lệ" << endl;
            return;
        }
        this->count = count;
    }
    void set()
    {
        cout << "Nhập trường bạn muốn sửa (0-Mã công trình, 1-Ngày xuất bản, 2-Khu vực,3-Tên công trình ,4-Số tác giả) " << endl;
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
            string name;
            cin.ignore();
            getline(cin, name);
            setname(name);
        }
        else if (i == 4)
        {
            int c;
            cin >> c;
            setcount(c);
        }
    }
};
#endif
