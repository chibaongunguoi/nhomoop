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
    cout << "2. Hiển thị số lượng và danh sách nhân viên  \n";
    cout << "3. Truy cập thông tin nhân viên bằng chỉ số\n";
    cout << "4. Loại bỏ 1 nhân viên bằng chỉ số\n";
    cout << "5. Thoát chương trình\n";
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
                cout << "Nhập loại nhân viên (0 - Nhân viên hợp đồng, 1 - nhân viên biên chế): ";
                cin >> isWorking;
                if (!isWorking)
                {
                    NVHD *nv = new NVHD("00000001", "abc", day, 0, 11, 11);
                    cin >> *nv;
                    LLKHCaNhan.addEmployee(nv);
                }
                else
                {

                    NVBC *nv = new NVBC("00000001", "abc", day, 0, 5, 5);
                    cin >> *nv;
                    LLKHCaNhan.addEmployee(nv);
                }
                LLKHCaNhan.calculateSalaries();
            }
            catch (const std::invalid_argument &e)
            {
                cout << "Lỗi: " << e.what() << endl;
            }
            break;
        }
        case 2:
        {
            cout << "Số lượng nhân viên hiện tại là: " << LLKHCaNhan.getEmployeeCount() << endl;
            LLKHCaNhan.displayEmployees();
            break;
        }
        case 3:
        {
            int index;
            cout << "Nhập chỉ số: ";
            cin >> index;
            try
            {
                NhanVien *em = LLKHCaNhan[index];
                cout << "Thông tin nhân viên có chỉ số " << index << ":\n";
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
            cout << "Nhập chỉ số của nhân viên bạn muốn xóa: ";
            cin >> index;
            try
            {
                LLKHCaNhan.deleteEmployeeByIndex(index);
                cout << "nhân viên có chỉ số " << index << " đã bị xóa \n";
            }
            catch (const std::out_of_range &e)
            {
                cout << "Lỗi: " << e.what() << endl;
            }
            break;
        }
        case 5:
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
