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

class SVTC : public SV
{

private:
    int Hocphi;

public:
    SVTC()
    {
        Hocphi = 0;
    }
    void input();
    void output();
};

class SVCN : public SVTC
{
private:
    float Dtb;
    string Hocbong;

public:
    SVCN()
    {
        Dtb = 0;
        Hocbong = "";
    }
    void input();
    void output();
    bool operator>(SVCN cn);
};

void swap(SVCN &f1, SVCN &f2);
main()
{
    SVCN *o[3];
    for (int i = 0; i < 3; i++)
    {
        o[i] = new SVCN;
        o[i]->input();
    }

    for (int i = 0; i <3; i++)
    {
       for(int j=0; j<2 -i;j++){
        if(!(*o[j]>*o[j+1])){
            swap(o[j],o[j+1]);
        }
       }
    }

    for (int i = 0; i < 3; i++)
    {
        o[i]->output();
    }
}

void swap(SVCN &f1, SVCN &f2)
{
    SVCN temp;
    temp = f1;
    f1 = f2;
    f2 = temp;
}

bool SVCN::operator>(SVCN cn)
{
    return Dtb > cn.Dtb;
}

void SVCN::input()
{
    SVTC::input();
    cout << endl
         << "Nhap diem trung binh: ";
    cin >> Dtb;
    cout << " - Nhap hoc bong: ";
    cin.ignore();
    getline(cin, Hocbong);
}
void SVCN::output()
{
    SVTC::output();
    cout << endl
         << "Diem trung binh: " << Dtb;
    cout << "Hoc bong: " << Hocbong;
}

void SVTC::input()
{

    SV::input();
    cout << endl
         << "Nhap hoc phi:  ";
    cin >> Hocphi;
}
void SVTC::output()
{
    SV::output();
    cout << endl
         << "Hoc phi:  " << Hocphi;
}

void SV::input()
{
    cout << endl
         << "Nhap ten: ";
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