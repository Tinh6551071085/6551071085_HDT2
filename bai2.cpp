#include <iostream>
#include <string>

using namespace std;

class Mydate
{
private:
    int ngay;
    int thang;
    int nam;

public:
    Mydate()
    {
        ngay = 0;
        thang = 0;
        nam = 0;
    }
    Mydate(int ngay, int nam, int thang)
    {
        this->ngay = ngay;
        this->thang = thang;
        this->nam = nam;
    }
    Mydate(Mydate &d)
    {
        ngay = d.ngay;
        nam = d.nam;
        thang = d.thang;
    }

    Mydate &operator=(Mydate &d);
    friend bool operator>(Mydate &d1, Mydate &d2);
    void output();
    void input();
};

class Person : public Mydate
{
private:
    string name;
    string address;
    int phone;

public:
    Person()
    {
        name = "";
        address = "";
        phone = 0;
    }
    Person &operator=(Person &d);
    void output();
    void input();
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
    Officer &operator=(Officer &d);
    void output();
    void input();
};

void swap(Officer &f1, Officer &f2);

main()
{
    Officer *o[4];
    for (int i = 0; i < 4; i++)
    {
        o[i] = new Officer;
        o[i]->input();
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3 - i; j++)
        {
            if (*o[j] > *o[j + 1])
            {
                swap(o[j],o[j + 1]);
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        o[i]->output();
    }
}

void swap(Officer &f1, Officer &f2)
{
    Officer temp;
    temp = f1;
    f1 = f2;
    f2= temp;
}


Officer &Officer::operator=(Officer &d){
    Person::operator=(d);
    this->Salary = d.Salary;
    return *this;
}

void Officer::output()
{
    Person::output();
    cout << "Luong: " << Salary;
}
void Officer::input()
{
    Person::input();
    cout << "Nhap luong: ";
    cin >> Salary;
}

Person &Person::operator=(Person &d){
    Mydate::operator=(d);
    this->name = d.name;
    this->address = d.address;
    return *this;
}

void Person::output()
{
    cout << endl;
    cout << "ten: ";
    cout << name << endl;
    cout << "dia chi: ";
    cout << address << endl;
    cout << "so dt: ";
    cout << phone;
    Mydate::output();
}
void Person::input()
{
    cout << endl;
    cout << "ten: ";
    cin.ignore();
    getline(cin, name);
    cout << "dia chi: ";
    cin.ignore();
    getline(cin, address);
    cout << "so dt: ";
    cin >> phone;
    Mydate::input();
}

Mydate &Mydate::operator=(Mydate &d)
{
    ngay = d.ngay;
    thang = d.thang;
    nam = d.nam;
    return *this;
}

void Mydate::output()
{
    cout << endl
         << "Day: "
         << ngay << "-" << thang << "-" << nam;
}

void Mydate::input()
{
    cout << endl
         << "Nhap ngay: ";
    cin >> ngay;
    cout
        << "Nhap thang: ";
    cin >> thang;
    cout
        << "Nhap nam: ";
    cin >> nam;
}

bool operator>(Mydate &d1,Mydate &d2)
{
    if (d1.nam > d2.nam)
    {

        return true;
    }
    if (d1.nam == d2.nam)
    {
        if (d1.thang > d2.thang)
        {
            return true;
        }
    }

    if (d1.nam == d2.nam)
    {
        if (d1.thang == d2.thang)
        {
            if (d1.ngay > d2.ngay)
                return true;
        }
    }

    return false;
}
