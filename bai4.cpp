#include <iostream>
#include <string>

using namespace std;
typedef struct
{
    int giay;
    int phut;
    int gio;
} ThoiGian;

class Media
{
private:
    string name;
    int price;

public:
    Media()
    {
        name = "";
        price = 0;
    }
    void input();
    void output();
};

class Book : public Media
{
private:
    int soTrang;
    string tacGia;

public:
    Book()
    {
        soTrang = 0;
        tacGia = "";
    }
    void input();
    void output();
};

class Video : public Media
{
private:
    ThoiGian thoigianchay;

public:
    void input();
    void output();
};
main()
{
    int n;
    cout << endl
         << "Nhap so sach: ";
    cin >> n;
    Book *b = new Book[n];
    cout << "Sach: ";
    for (int i = 0; i < n; i++)
    {
        (b + i)->input();
    }
    int k;
    cout << endl
         << "Nhap so bang video: ";
    cin >> k;
    Video *v = new Video[k];
    cout << "Video: ";
    for (int i = 0; i < k; i++)
    {
        (v+ i)->input();
    }
 cout << "===================Sach: ";
    for (int i = 0; i < n; i++)
    {
        (b + i)->output();
    }
cout <<endl<< "=================Video: ";
    for (int i = 0; i < k; i++)
    {
        (v+ i)->output();
    }
}

void Video::input()
{
    Media::input();
    cout << endl
         << "> Nhap thoi gian chay: ";
    cout << "Giay: ";
    cin >> thoigianchay.giay;
    cout << "Phut: ";
    cin >> thoigianchay.phut;
    cout << "Gio: ";
    cin >> thoigianchay.gio;

    if (thoigianchay.giay > 60)
    {
        thoigianchay.phut += thoigianchay.giay / 60;
        thoigianchay.giay = thoigianchay.giay % 60;
    }

    if (thoigianchay.phut > 60)
    {
        thoigianchay.gio += thoigianchay.phut / 60;
        thoigianchay.phut = thoigianchay.phut % 60;
    }
}
void Video::output()
{
    Media::output();
    cout << endl
         << "> Thoi gian chay: ";
    cout << thoigianchay.giay;
    cout << " - " << thoigianchay.phut;
    cout << " - " << thoigianchay.gio;
}

void Book::input()
{
    Media::input();
    cout << endl
         << "Nhap so trang: ";
    cin >> soTrang;
    cout << "Nhap ten tac gia: ";
    cin.ignore();
    getline(cin, tacGia);
}
void Book::output()
{
    Media::output();
    cout << endl
         << "So trang: " << soTrang;
    cout << " -- Ten tac gia: " << tacGia;
}

void Media::input()
{
    cout << endl
         << "Ten: ";
    cin.ignore();
    getline(cin, name);
    cout << "--" << "Gia: ";
    cin >> price;
}
void Media::output()
{
    cout << endl
         << "Ten: " << name << "--" << "Gia: " << price;
}