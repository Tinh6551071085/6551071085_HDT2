#include <iostream>
#include <string>

using namespace std;

class MyAddress
{
private:
    string tinh;
    string huyen;

public:
    MyAddress()
    {
        tinh = "";
        huyen = "";
    }
    void input();
    void output();
};

class Person : public MyAddress
{
private:
    string Name;
    int Phone;

public:
    Person()
    {
        Name = "";
        Phone = 0;
    }
    void input();
    void output();
};

class Officer : public Person
{
private:
    int Salary;

public:
    Officer()
    {
        Salary = 0;
    }
    void input();
    void output();
    bool operator>(Officer Salary);
};

void swap(Officer &f1, Officer &f2);

main()
{
    Officer *p[4];
    for (int i = 0; i < 4; i++)
    {
       p[i]= new Officer;
       p[i]->input();
    }

    for (int i = 0; i <3; i++)
    {
       for(int j=0; j<3 -i;j++){
        if(*p[j]>*p[j+1]){
            swap(p[j],p[j+1]);
        }
       }
    }

    for (int i = 0; i < 4; i++)
    {
     cout<<endl<<"+++++++++++++++++++++++";
       p[i]->output();
    }
}

void swap(Officer &f1, Officer &f2)
{
    Officer temp;
    temp = f1;
    f1 = f2;
    f2= temp;
}


// true thi this lon hon
bool Officer::operator>(Officer p)
{
    return Salary > p.Salary;
}

void Officer::input()
{
    Person::input();
    cout << endl
         << "Nhap luong: ";
    cin >> Salary;
}
void Officer::output()
{
    Person::output();
    cout << endl
         << "Luong: " << Salary;
}

void Person::input()
{
    cout << endl
         << "Nhap ten:";
    cin.ignore();
    getline(cin, Name);
    cout << "Nhap so dt: ";
    cin >> Phone;
    MyAddress::input();
}
void Person::output()
{
    cout << endl
         << "Ten:" << Name;
    cout << "So dt: " << Phone;
    MyAddress::output();
}

void MyAddress::input()
{
    cout << endl
         << "Dia chi: ";
    cout << endl
         << "Tinh: ";
    cin.ignore();
    getline(cin, tinh);

    cout << endl
         << "Huyen: ";
    cin.ignore();
    getline(cin, huyen);
}
void MyAddress::output()
{
    cout << endl
         << "Dia chi: " << "Huyen: " << huyen << "- Tinh: " << tinh;
}