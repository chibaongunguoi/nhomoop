#include "quanly.h"
#include "nhanvien.h"
#include "nvhd.h"
#include "nvbc.h"
#include <iostream>
#include <limits>

using namespace std;

void showMenu()
{
    cout << "\nMenu:\n";
    cout << "1. Thêm nhân viên\n";
    cout << "2. Hiển thị số lượng và danh sách nhân viên  \n";
    cout << "3. Truy cập thông tin nhân viên bằng chỉ số\n";
    cout << "4. Loại bỏ 1 nhân viên bằng chỉ số\n";
    cout << "5. Thoát chương trình\n";
    cout << "Nhập lựa chọn : ";
}

int main()
{
    QLNV qlnv("Nguyễn Thành Bảo Việt");
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
            string id, name;
            int day, month, year;
            bool isWorking, sex;
            double salary, coefficient;
            int daysWorked, yearsWorked;
            cout << "Nhập ID của nhân viên (gồm 8 kí tự) : ";
            cin >> id;
            cout << "Nhập tên của nhân viên : ";
            cin.ignore();
            getline(cin, name);
            cout << "Nhập giới tính (0 - Nam, 1 - Nữ): ";
            cin >> sex;
            if (sex != 0 && sex != 1)
            {
                cout << "Dữ liệu không hợp lệ vui lòng nhập lại.\n";
                continue;
            }
            cout << "Nhập ngày bắt đầu làm việc: \n";
            cout << "Ngày: ";
            cin >> day;
            cout << "Tháng: ";
            cin >> month;
            cout << "Năm: ";
            cin >> year;
            try
            {
                Date startDate(day, month, year);
                cout << "Nhập loại nhân viên (0 - Nhân viên hợp đồng, 1 - nhân viên biên chế): ";
                cin >> isWorking;
                if (!isWorking)
                {
                    cout << "Nhập lương trong 1 ngày: ";
                    cin >> salary;
                    cout << "Nhập số ngày đã làm việc: ";
                    cin >> daysWorked;
                    NVHD *nv = new NVHD(id, name, startDate, sex, salary, daysWorked);
                    qlnv.addEmployee(nv);
                }
                else
                {
                    cout << "Nhập hệ số lương: ";
                    cin >> coefficient;
                    cout << "Nhập thâm niên làm việc: ";
                    cin >> yearsWorked;
                    NVBC *nv = new NVBC(id, name, startDate, sex, coefficient, yearsWorked);
                    qlnv.addEmployee(nv);
                    qlnv.calculateSalaries();
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
            cout << "Số lượng nhân viên hiện tại là: " << qlnv.getEmployeeCount() << endl;
            qlnv.displayEmployees();
            break;
        }
        case 3:
        {
            int index;
            cout << "Nhập chỉ số: ";
            cin >> index;
            try
            {
                NhanVien *em = qlnv[index];
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
                qlnv.deleteEmployeeByIndex(index);
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
