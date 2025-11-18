#include <iostream>
#include <string>

using namespace std;

typedef struct
{
    int lop;
    int khoi;
} Lop;

class SV
{
private:
    Lop lop;
    string Hoten;

public:
    SV()
    {
        lop.khoi = 0;
        lop.lop = 0;
        Hoten = "";
    }
    void input();
    void output();
};

class SVSP : public SV
{
private:
    float Dtb;
    string Hocbong;

public:
    SVSP()
    {
        Dtb = 0;
        Hocbong = "";
    }
    void input();
    void output();
};

class SVCN : public SVSP
{
private:
    int Hocphi;

public:
    SVCN()
    {
        Hocphi = 0;
    }
    void input();
    void output();
};
main()
{
     SVCN *o[3];
    for (int i = 0; i < 3; i++)
    {
        o[i] = new SVCN;
        o[i]->input();
    }

    for(int i=0;i<3;i++){
         o[i]->output();
    }
}

void SVCN::input()
{
    SVSP::input();
    cout << endl
         << "Nhap hoc phi:  ";
    cin >> Hocphi;
}
void SVCN::output()
{
    SVSP::output();
    cout << endl
         << "Hoc phi:  "<<Hocphi;
}

void SVSP::input()
{
    SV::input();
    cout << endl
         << "Nhap diem trung binh: ";
    cin >> Dtb;
    cout << " - Nhap hoc bong: ";
    cin.ignore();
    getline(cin, Hocbong);
}
void SVSP::output()
{
    SV::output();
    cout << endl
         << "Diem trung binh: " << Dtb;
    cout << "Hoc bong: " << Hocbong;
}

void SV::input()
{
    cout << endl
         << "Nhap ten: ";
    cin.ignore();
    getline(cin, Hoten);
    cout << "Khoi: ";
    cin >> lop.khoi;
    cout << "Lop: ";
    cin >> lop.lop;
}
void SV::output()
{
    cout << endl
         << "Ten: " << Hoten;
    cout << " - Khoi: " << lop.khoi;
    cout << " - Lop: " << lop.lop;
}