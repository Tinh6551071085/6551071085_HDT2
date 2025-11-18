#include <iostream>
#include <string>

using namespace std;

class MyAttr
{
private:
    int soHieu;

public:
    MyAttr()
    {
        soHieu = 0;
    }
    MyAttr(int soHieu)
    {
        this->soHieu = soHieu;
    }
    MyAttr(MyAttr &m)
    {
        soHieu = m.soHieu;
    }
    MyAttr &operator=(MyAttr &m);
    void output();
    void input();
};

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
    friend bool operator>(Mydate &d1,Mydate &d2);
    void output();
    void input();
};

class Myfile : public MyAttr,  public Mydate
{
private:
    string filename;
    int filesize;

public:
    Myfile()
    {
        filename = "";
        filesize = 0;
    }
    Myfile(string filename, int filesize)
    {
        this->filename = filename;
        this->filesize = filesize;
    }
    Myfile(Myfile &f)
    {
        filename = f.filename;
        filesize = f.filesize;
    }

    Myfile &operator=(Myfile &f);
    void output();
    void input();
};

void swap(Myfile &f1, Myfile &f2);

int main()
{
    Myfile *f[4];

    for (int i = 0; i < 4; i++)
    {
        f[i] = new Myfile;
        f[i]->input();
    }

    for(int i=0; i<3;i++){
        for(int j=0; j<4 -1 -i;j++){
            if(*f[j]>*f[j+1]){
                swap(f[j],f[j+1]);
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        cout<<endl<<"===============================";
        f[i]->output();
    }
}

void swap(Myfile &f1, Myfile &f2)
{
    Myfile temp;
    temp = f1;
    f1 = f2;
    f2= temp;
}

MyAttr &MyAttr::operator=(MyAttr &m)
{
    soHieu = m.soHieu;
    return *this;
}
Mydate &Mydate::operator=(Mydate &d)
{
    ngay = d.ngay;
    thang = d.thang;
    nam = d.nam;
    return *this;
}
Myfile &Myfile::operator=(Myfile &f)
{
    MyAttr::operator=(f);
    Mydate::operator=(f);
    filename = f.filename;
    filesize = f.filesize;
    return *this;
}

void Myfile::input()
{
    cout << endl
         << "Nhap ten file: ";
         cin.ignore();
    getline(cin, filename);
    cout << "Nhap kich thuoc tep: ";
    cin >> filesize;
    MyAttr::input();
    Mydate::input();
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

void MyAttr::input()
{
    cout << endl
         << "Nhap thuoc tinh: ";
    cin >> soHieu;
}

void Myfile::output()
{
    cout << endl
         <<"ten: "<< filename << "-" << "kich thuoc: "<<filesize;
    MyAttr::output();
    Mydate::output();
}

void Mydate::output()
{
    cout << endl<<"Day: "
         << ngay << "-" << thang << "-" << nam;
}

// true thi this lon hon
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

void MyAttr::output()
{
    cout << endl
         << "So hieu: " << soHieu;
}