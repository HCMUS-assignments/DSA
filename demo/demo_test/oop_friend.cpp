#include<iostream>
#include<iomanip>
#include<string.h>
#include<stdio.h>
using namespace std;
class sv
{
    protected:
    char ma[10];
    char ten[20];
    char gt[10];
    public:
    char *getgt()
    {
        return gt;
    }
    sv()
    {
         strcpy(ma," ");
          strcpy(ten," ");
           strcpy(gt," ");
    }
    ~sv(){};
    void nhap()
    {
        cout<<"Nhap ma sinh vien:";
        fflush(stdin);
        cin.getline(ma,10);
        cout<<"Nhap ten sinh vien:";
        fflush(stdin);
        cin.getline(ten,20);
        cout<<"Nhap gioi tinh sinh vien:";
        fflush(stdin);
        cin.getline(gt,10);
    }
    void xuat()
    {
        cout<<setw(10)<<ma<<"|"<<setw(10)<<ten<<"|"<<setw(10)<<gt<<"|";
    }
    void tieude()
    {
        cout<<setw(10)<<"Ma"<<"|"<<setw(10)<<"Ten sv"<<"|"<<setw(10)<<"Gioi tinh"<<"|" <<setw(10)<<"Ma mon"<<"|"<<setw(10)<<"Ten mon"<<"|"<<setw(10)<<"Diem"<<"|"<<endl; 
    }
};
class monhoc
{
    protected:
    char mamon[10];
    char tenmon[10];
    public:
    monhoc()
    {
         strcpy(mamon," ");
          strcpy(tenmon," ");
    }
    ~monhoc(){};
    friend istream& operator>>(istream& is, monhoc &a)
    {
        cout<<"Nhap ma mon hoc:";
        is.getline(a.mamon,10);
        cout<<"Nhap ten mon hoc:";
        is.getline(a.tenmon,20);
        return is;
    }
    friend ostream& operator<<(ostream& os,monhoc a) // friend là hàm bạn: có thể truy cập vào các thành viên private của lớp,  ostream là lớp đầu ra : cout , &ostream 
    {
        os<<setw(10)<<a.mamon<<"|"<<setw(10)<<a.tenmon<<"|";
        return os;
    }
};
class diem: public sv,public monhoc
{
  protected:
  int diem1;
  public:
  diem()
  {
    this->diem1=0;
  }
  ~diem(){};
  friend istream& operator>>(istream& is,diem &a)
  {
    a.sv::nhap();
    is>>(monhoc&)a;
    cout<<"Nhap diem sinh vien:";
    is>>a.diem1;
    return is;
  }
  friend ostream& operator<<(ostream& os,diem a)
  {
    a.sv::tieude();
    a.sv::xuat();
    os<<(monhoc)a;
    os<<setw(10)<<a.diem1<<"|";
    return os;
  }
  friend diem lietke(diem a[],int &n);
  friend diem dtb(diem a[],int &n);
  friend diem timten(diem a[],int &n);
  friend diem timmh(diem a[],int &n);
  friend diem sapxep(diem a[],int &n);
};
diem lietke(diem a[],int &n)
{
    cout<<"\n\n\t\t--Danh sach liet ke cac sinh vien co gioi tinh Nam--"<<endl;
    int dem=0;
    for(int i=0;i<n;i++)
    {
        if(strcmpi(a[i].getgt(),"nam")==0)
        {
            dem++;
            cout<<a[i]<<endl;
        }
    }
}
diem dtb(diem a[],int &n)
{
    float S;
    for(int i=0;i<n;i++)
    {
        S=(a[i].diem1/3);
        cout<<"Diem trung binh cua sinh vien do la:"<<S<<endl;
    }
}
diem timten(diem a[],int &n)
{
    diem c;
    cout<<"Nhap ten sinh vien:";
    cin>>c.ten;
    cout<<"\n\n\t\t--Danh sach tim kiem ten X cua ban--"<<endl;
    for(int i=0;i<n;i++)
    {
        if(strcmp(c.ten,a[i].ten)==0){
            cout<<a[i]<<endl;
        }
    }
}
diem timmh(diem a[],int &n)
{
    diem b;
    cout<<"Nhap ten mon hoc:";
    cin>>b.tenmon;
    cout<<"\n\n\t\t--Danh sach tim kiem mon toan nho nhat--"<<endl;
    for(int i=0;i<n;i++)
    {
        if(strcmp(b.tenmon,a[i].tenmon)==0){
            cout<<a[i]<<endl;
        }
    }
}
diem sapxep(diem a[],int &n)
{
    diem tg;
    cout<<"\n\n\t\t--Danh sach sinh vien sap xep theo deim Trung binh giam dan la--"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if((a[j].diem1)/3>(a[i].diem1)/3)
            {
                tg=a[i];
                a[i]=a[j];
                a[j]=a[i];
            }
        }
    }
}
int main()
{
    diem a[50];
    int n;
    cout<<"Nhap so thi sinh:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Nhap so thi sinh:"<<i+1<<endl;
        cin>>a[i];
    }
    cout<<"\n\n\t\t--Danh sach si vien ban vua nhap la--"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
    lietke(a,n);
    dtb(a,n);
    timten(a,n);
    timmh(a,n);
    sapxep(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}