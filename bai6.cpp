#include <iostream>
#include <string>

using namespace std;

class Printer
{
private:
    string Name;
    int Soluong;

public:
    Printer()
    {
        Name = "";
        Soluong = 0;
    }
    void inputName();
    void output();
    int nhapkho(int q);
    int xuatkho(int q);
};

class Laser : public  virtual Printer
{
private:
    int Dpi;

public:
    void input();
    void output();
};

class ColorPrinter : public virtual Printer
{
private:
    string Color;

public:
    void input();
    void output();
};

class ColorLaser : public ColorPrinter, public Laser
{
public:
    void input();
    void nhapXuatKho();
    void output();
};

main()
{
    ColorLaser *p[3];
    for (int i = 0; i < 3; i++)
    {
        p[i] = new ColorLaser;
        p[i]->input();
        p[i]->nhapXuatKho();
    }

    for (int i = 0; i < 3; i++)
    {
        p[i]->output();
    }
}
void ColorLaser::nhapXuatKho()
{
    int choose;
    cout << endl
         << "==> Lua chon nhap hay xuat kho: \n 1. Nhap \n 2. Xuat\n";
    cout << "i: ";
    cin >> choose;
    if (choose == 1)
    {
        cout << "Nhap so luong them vao kho: ";
        int q;
        cin >> q;
        Printer::nhapkho(q);
    }
    if (choose == 2)
    {
        cout << "Nhap so luong xuat kho: ";
        int q;
        cin >> q;
        Printer::xuatkho(q);
    }
}

void ColorLaser::input()
{
    Printer::inputName();
    Laser::input();
    ColorPrinter::input();
}
void ColorLaser::output()
{
    Printer::output();
    Laser::output();
    ColorPrinter::output();
}

void ColorPrinter::input()
{

    cout << " --- Nhap thuoc tinh mau: ";
    cin.ignore();
    getline(cin, Color);
}
void ColorPrinter::output()
{

    cout << " --- Thuoc tinh mau: " << Color;
}

void Laser::input()
{

    cout << " --- Nhap DPI: ";
    cin >> Dpi;
}
void Laser::output()
{

    cout << " --- DPI: " << Dpi;
}

void Printer::output()
{
    cout << endl
         << "Ten: " << Name << "--" << "So luong: " << Soluong;
}

void Printer::inputName()
{
    cout << endl
         << "Nhap ten: ";
    cin.ignore();
    getline(cin, Name);
}

int Printer::nhapkho(int q)
{
    Soluong += q;
    return Soluong;
}
int Printer::xuatkho(int q)
{
    Soluong -= q;
    return Soluong;
}