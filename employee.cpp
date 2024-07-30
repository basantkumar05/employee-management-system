#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
#include <windows.h>
class emp_management_system
{
private:
    struct emp
    {
        string name, id, address;
        int contact, salary;
    };
    emp e[100];
    int total = 0;

public:
    void empdata()
    {
        int choice;
        cout << "How many employees data do you want to enter??" << endl;
        cin >> choice;
        for (int i = total; i < total + choice; i++)
        {
            cout << "Enter data of employe" << i + 1 << endl
                 << endl;
            cout << "Enter employee name : ";
            cin.ignore();
            getline(cin,e[i].name);
            cout << "Enter id : ";
            cin >> e[i].id;
            cout << "Enter address: ";
            cin >> e[i].address;
            cout << "Enter contact: ";
            cin >> e[i].contact;
            cout << "Enter salary: ";
            cin >> e[i].salary;
        }
        total = total + choice;
    }

    void show()
    {
        if (total != 0)
        {
            for (int i = 0; i < total; i++)
            {
                cout << "Data of employee " << i + 1 << endl;
                cout << "Name: " << e[i].name << endl;
                cout << "ID: " << e[i].id << endl;
                cout << "Address: " << e[i].address << endl;
                cout << "Contact: " << e[i].contact << endl;
                cout << "Salary: " << e[i].salary << endl;
            }
        }
        else
        {
            cout << "Your record is empty" << endl;
        }
    }

    void search()
    {
        if (total != 0)
        {
            string id;
            cout << "Enter id of employee which you want to search" << endl;
            cin >> id;
            for (int i = 0; i < total; i++)
            {
                if (id == e[i].id)
                {
                    cout << "Data of employee " << i + 1 << endl;
                    cout << "Name: " << e[i].name << endl;
                    cout << "ID: " << e[i].id << endl;
                    cout << "Address: " << e[i].address << endl;
                    cout << "Contact: " << e[i].contact << endl;
                    cout << "Salary: " << e[i].salary << endl;
                    break;
                }
                if (i == total - 1)
                {
                    cout << "no such record found..." << endl;
                }
            }
        }
        else
        {
            cout << "your record is empty" << endl;
        }
    }

    void update()
    {
        if (total != 0)
        {
            string id;
            cout << "Enter id of employee which you want to update." << endl;
            cin >> id;
            for (int i = 0; i < total; i++)
            {
                if (id == e[i].id)
                {
                    cout << "Previous Data" << endl;
                    cout << "Data of employee " << i + 1 << endl;
                    cout << "Name: " << e[i].name << endl;
                    cout << "ID: " << e[i].id << endl;
                    cout << "Address: " << e[i].address << endl;
                    cout << "Contact: " << e[i].contact << endl;
                    cout << "Salary: " << e[i].salary << endl;
                    cout << " Enter New Data" << endl;

                    cout << "Enter employee name : ";
                    cin >> e[i].name;
                    cout << "Enter id : ";
                    cin >> e[i].id;
                    cout << "Enter address: ";
                    cin >> e[i].address;
                    cout << "Enter contact: ";
                    cin >> e[i].contact;
                    cout << "Enter salary: ";
                    cin >> e[i].salary;
                    break;
                }
                if (i == total - 1)
                {
                    cout << "no such record found..." << endl;
                }
            }
        }
        else
        {
            cout << "your record is empty..." << endl;
        }
    }

    void del()
    {
        if (total != 0)
        {
            char user;
            cout << "press 1 to delete full record" << endl;
            cout << "press 2 to delete specific record" << endl;
            user = getch();
            if (user == '1')
            {
                total = 0;
                cout << "all record is deleted....!!!" << endl;
            }
            else if (user == '2')
            {
                string id;
                cout << "Enter id of employee which you want to delete." << endl;
                cin >> id;
                for (int i = 0; i < total; i++)
                {
                    if (id == e[i].id)
                    {
                        for (int j = i; j < total; j++)
                        {
                            e[j].name = e[j + 1].name;
                            e[j].id = e[j + 1].id;
                            e[j].address = e[j + 1].address;
                            e[j].contact = e[j + 1].contact;
                            e[j].salary = e[j + 1].salary;
                            total--;
                            cout << "your required code is deleted.." << endl;
                            break;
                        }
                        if (i == total - 1)
                        {
                            cout << "no such record found..." << endl;
                        }
                    }
                }
            }
        }
        else
        {
            cout << "your record is empty" << endl;
        }
    }

    void login()
    {
        cout << "\n\n\tEmployee Management System";
        cout << "\n\n\tSign Up/Create account";
        string username, password;
        cout << "\n\tCreate username : ";
        cin >> username;
        cout << "\n\tCreate Password : ";
        cin >> password;
        cout << "\n\n\tYour id is creating, please wait";
        for (int i = 0; i < 4; i++)
        {
            cout << ".";
            Sleep(1000);
        }
        cout << "\n\t\tYour id created successfully" << endl;
        Sleep(2000);
        system("CLS");
    start:
        system("CLS");
        cout << "\n\n\tEmployee Management System";
        cout << "\n\n\tLogin" << endl;
        string usern, pass;
        cout << "\n\tUsername : ";
        cin >> usern;
        cout << "\n\tPassword : ";
        cin >> pass;
        if (usern == username && pass == password)
        {
            system("CLS");
            char user;
            while (1)
            {
                cout << "\n\nPress 1 to enter data" << endl;
                cout << "Press 2 to show data" << endl;
                cout << "Press 3 to search data" << endl;
                cout << "Press 4 to update data" << endl;
                cout << "Press 5 to delete data" << endl;
                cout << "Press 6 to logout data" << endl;
                cout << "Press 7 to exit" << endl;
                user = getch();
                system("CLS");
                switch (user)
                {
                case '1':
                    empdata();
                    break;

                case '2':
                    show();
                    break;

                case '3':
                    search();
                    break;

                case '4':
                    update();
                    break;

                case '5':
                    del();
                    break;

                case '6':
                    goto start;
                    break;

                default:
                    cout << "\aExit successfully...." << endl;
                    break;
                }
            }
        }
        else if (usern != username)
        {
            cout << "Your username is incorrect" << endl;
            Sleep(3000);
            goto start;
        }
        else if (pass != password)
        {
            cout << "Your username is incorrect" << endl;
            Sleep(3000);
            goto start;
        }
        else
        {
            cout << "\t\tInvalid username and password";
            Sleep(3000);
            goto start;
        }
    }
};
int main(){
    emp_management_system obj;
    obj.login();
    return 0;
}