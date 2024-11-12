#include "quanly.h"
#include "CTKH.h"
#include "BB.h"
#include "Sach.h"
#include <iostream>
#include <limits>

using namespace std;

void showMenu()
{
    cout << "\nMenu:\n";
    cout << "1. Thêm bài báo hoặc sách\n";
    cout << "2. Hiển thị số lượng và danh sách công trình khoa học  \n";
    cout << "3. Truy cập thông tin công trình khoa học bằng chỉ số\n";
    cout << "4. Chỉnh sửa thông tin công trình khoa học bằng chỉ số\n";
    cout << "5. Loại bỏ 1 công trình khoa học bằng chỉ số\n";
    cout << "6. Thoát chương trình\n";
    cout << "Nhập lựa chọn : ";
}

int main()
{
    LLKHCaNhan LLKHCaNhan("Nguyễn Thành Bảo Việt");
    Date day(1, 1, 2024);
    bool running = true;
    int choice;
    while (running)
    {
        showMenu();
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Vui lòng nhập đúng số ứng với chức năng cần dùng" << endl;
            continue;
        }
        switch (choice)
        {
        case 1:
        {
            try
            {
                bool isWorking;
                cout << "Nhập loại công trình khoa học (0 - Bài báo, 1 - Sách): ";
                cin >> isWorking;
                if (!isWorking)
                {
                    BaiBao *nv = new BaiBao;
                    cin >> *nv;
                    LLKHCaNhan.add(nv);
                }
                else
                {

                    Sach *nv = new Sach;
                    cin >> *nv;
                    LLKHCaNhan.add(nv);
                }
            }
            catch (const std::invalid_argument &e)
            {
                cout << "Lỗi: " << e.what() << endl;
            }
            break;
        }
        case 2:
        {
            cout << "Số lượng công trình khoa học hiện tại là: " << LLKHCaNhan.getCount() << endl;
            LLKHCaNhan.display();
            break;
        }
        case 3:
        {
            int index;
            cout << "Nhập chỉ số: ";
            cin >> index;
            try
            {
                CongTrinhKhoaHoc *em = LLKHCaNhan[index];
                cout << "Thông tin công trình khoa học có chỉ số " << index << ":\n";
                em->display();
            }
            catch (const std::out_of_range &e)
            {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }
        case 4:
        {
            int index;
            cout << "Nhập chỉ số: ";
            cin >> index;
            try
            {
                CongTrinhKhoaHoc *em = LLKHCaNhan[index];
                cout << "Thông tin công trình khoa học có chỉ số " << index << ":\n";
                em->display();
                em->set();
            }
            catch (const std::out_of_range &e)
            {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }
        case 5:
        {
            int index;
            cout << "Nhập chỉ số của công trình khoa học bạn muốn xóa: ";
            cin >> index;
            try
            {
                LLKHCaNhan.deleteByIndex(index);
                cout << "công trình khoa học có chỉ số " << index << " đã bị xóa \n";
            }
            catch (const std::out_of_range &e)
            {
                cout << "Lỗi: " << e.what() << endl;
            }
            break;
        }
        case 6:
        {
            running = false;

            break;
        }
        default:
        {
            cout << "Lựa chọn không tồn tại vui lòng thử lại\n";
            break;
        }
        }
    }
    return 0;
}
