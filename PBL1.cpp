#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <fstream>
using namespace std;
class sinhvien
{
    string hoten, lop, khoa, mssv;
    public:  
    friend class chucnang;
    void nhapsinhvien();
    void xuatsinhvien();
    friend void themsinhvien();
    friend void xuatsinhvien();
};
class muon
{
	string xmasach, xmssv;
    int soluongmuon=0;
	int ngaymuon, ngaytra, thangmuon, thangtra, nammuon, namtra;
    friend class chucnang;
    public:
    void themuon(int x, int y);
};
class sach
{
    string masach, tensach, nxb, tacgia;
    int soluong=0;
    friend class chucnang;
    public:
    void nhapsach();
    void xuatsach();
    friend void themsach();
    
};
class chucnang
{
    int soluongsinhvien=0;
    sinhvien arrsv[50];
    int soluongsach=0;
    sach arrsach[50];
    int soluongphieu=0;
    muon arr1[50];
    muon arr2[50];
    friend class muon;
    public:
    void themsinhvien();
    void dssinhvien();
    void xoasinhvien();
    void timkiemsinhvien();
    void themsach();
    void dssach();
    void timkiemsach();
    void xoasach();
    void muonsach();
    void trasach();
    void dsthemuon();
    void chensinhvien(int x);
    void chenthemuon(int x);
    void chensach(int x);
    void sptimsach(int x);
    void sptimsv(int x);
    void menutong();
    void menu1();
    void menu2();
    void menu3();
};

void sinhvien::nhapsinhvien()
{
    cin.ignore();
    cout<<"\t\t\t\tNhap ho ten:";
    getline(cin,hoten);
    cout<<"\t\t\t\tNhap lop:";
    getline(cin,lop);
    cout<<"\t\t\t\tNhap khoa:";
    getline(cin,khoa);
    cout<<"\t\t\t\tNhap ma so sinh vien:";
    getline(cin,mssv);
    cin.ignore();
}
void sinhvien::xuatsinhvien()
{
    cout<<"\t\t\t\t-----------------------------------------------"<<endl;
    cout<<"\t\t\t\tTen sinh vien:"<<hoten<<endl;
    cout<<"\t\t\t\tLop          :"<<lop<<endl;
    cout<<"\t\t\t\tKhoa         :"<<khoa<<endl;
    cout<<"\t\t\t\tMSSV         :"<<mssv<<endl;
    cout<<"\t\t\t\t-----------------------------------------------"<<endl;
}
void chucnang::themsinhvien()
{   sinhvien s1;
	system("cls");
    cout << "\t\t\t\t________________________________Them sinh vien__________________________________\n\n";
    int soluong;
    int k=soluongsinhvien;
    cout<<"\t\t\t\tNhap so luong sinh vien can them:"<<" ";
    cin>>soluong;
    soluongsinhvien+=soluong;
    ofstream ofile;
    ofile.open("sinhvien.txt",ios::out);
    for (int i=k;i<soluongsinhvien;i++)
    {
        cout<<"\t\t\t\tThem sinh vien thu:"<<" "<<i+1<<"\n";
        arrsv[i].nhapsinhvien();
        cout<<"\t\t\t\tThem sinh vien thanh cong!"<<endl;
        system("pause");
        ofile<<s1.hoten;
        ofile<<s1.khoa;
        ofile<<s1.lop;
        ofile<<s1.mssv;
    }
    ofile.close();
}
void chucnang::dssinhvien()
{   sinhvien s1;
    ifstream ifile;
    ifile.open("sinhvien.txt",ios::in);
	system("cls");
    cout << "\t\t\t\t_______________________________Danh sach sinh vien____________________________\n\n";
    if (soluongsinhvien<=0)
    {
        cout<<"\t\t\t\tChua co sinh vien nao trong du lieu"<<endl;
        system("pause");
        return;
    }
    {
        for (int i=0;i<soluongsinhvien;i++)
        {   ifile>>s1.hoten;
            ifile>>s1.khoa;
            ifile>>s1.lop;
            ifile>>s1.mssv;
            arrsv[i].xuatsinhvien();
        }
        ifile.close();
    }

}
void chucnang::chensinhvien(int x){
	for (int i=x;i<soluongsinhvien;i++){
		arrsv[i].hoten=arrsv[i+1].hoten;
        arrsv[i].lop=arrsv[i+1].lop;
        arrsv[i].mssv=arrsv[i+1].mssv;
        }
		soluongsinhvien--;
}
	
void chucnang::xoasinhvien()
{  
	system("cls");
    cout << "\t\t\t\t________________________________Xoa sinh vien__________________________________\n\n";
    if (soluongsinhvien<=0)
    {
        cout<<"\t\t\t\tChua co sinh vien nao trong du lieu"<<endl;
        system("pause");
        return;
    }
    {
        string tim;
        cout<<"\t\t\t\tNhap ten sinh vien hoac MSSV sinh vien can xoa:\n";
        cout<<"\t\t\t\t";
        getline(cin,tim);
        for (int i=0;i<soluongsinhvien;i++)
        {
            if (tim==arrsv[i].hoten||tim==arrsv[i].mssv)
            {
                int xoa;
                cout<<"\t\t\t\tThong tin cua sinh vien ban muon xoa:\n";
                arrsv[i].xuatsinhvien();
                cout<<"\t\t\t\tBan co chac muon xoa du lieu sinh vien nay khong?"<<endl;
                cout<<"\t\t\t\t\t1.Co\t\t2.Khong"<<endl;
                cin>>xoa;
                if (xoa==1)
                    {
                        chucnang::chensinhvien(i);
		                cout<<"\t\t\t\tDu lieu sinh vien da duoc xoa!"<<endl;
		                system("pause");
                        return;
                    }
                    else if (xoa==2)
                    {
                        cout<<"\t\t\t\tDu lieu sinh vien khong bi xoa!"<<endl;
                        system("pause");
                        return;
                    }
            }
        }
        cout<<"\t\t\t\tKhong ton tai sinh vien nay!"<<endl;
    }
}
void chucnang::timkiemsinhvien()
{
	system("cls");
    cout << "\t\t\t\t________________________________Tim kiem sinh vien__________________________________\n\n";
    if (soluongsinhvien<=0)
    {
        cout<<"\t\t\t\tChua co sinh vien nao trong du lieu"<<endl;
        system("pause");
        cout<<"\t\t\t\tNhan phim bat ki de tiep tuc!"<<endl;
        return;
    }
    string tim;
    cout<<"\t\t\t\tNhap ten sinh vien hoac MSSV sinh vien ban tim kiem:"<<endl;
    cout<<"\t\t\t\t";
    getline(cin,tim);
    for (int i=0;i<soluongsinhvien;i++)
    {
        if (tim==arrsv[i].hoten||tim==arrsv[i].mssv)
        {

            cout<<"\t\t\t\tThong tin cua sinh vien ban tim kiem:"<<endl;
            arrsv[i].xuatsinhvien();
            system("pause");
            return;

        }
    }
}
void sach::nhapsach()
{
    cout<<"\t\t\t\tNhap ten sach:";
    getline(cin,tensach);
    cout<<"\t\t\t\tNhap ma sach:";
    getline(cin,masach);
    cout<<"\t\t\t\tNhap tac gia:";
    getline(cin,tacgia);
    cout<<"\t\t\t\tNhap nha xuat ban:";
    getline(cin,nxb);
	cin.ignore();
}
void sach::xuatsach()
{
    cout<<"\t\t\t\t-----------------------------------------------"<<endl;
    cout<<"\t\t\t\tTen sach    :"<<tensach<<endl;
    cout<<"\t\t\t\tMa sach     :"<<masach<<endl;
    cout<<"\t\t\t\tTac gia     :"<<tacgia<<endl;
    cout<<"\t\t\t\tNha xuat ban:"<<nxb<<endl;
    cout<<"\t\t\t\t-----------------------------------------------"<<endl;
}
void chucnang::themsach()
{   sach s1;
	system("cls");
    cout << "\t\t\t\t______________________________Them sach_____________________________\n\n";
    int soluong;
    int k=soluongsach;
    cout<<"\t\t\t\tNhap so luong sach can them:"<<" ";
    cin>>soluong;
    soluongsach+=soluong;
	cin.ignore();
    ofstream ofile;
    ofile.open("sach.txt",ios::in);

    for (int i=k;i<soluongsach;i++)
    {
        cout<<"\t\t\t\tThem cuon sach thu:"<<""<<i+1<<endl;
        arrsach[i].nhapsach();
        cout<<"\t\t\t\tThem sach thanh cong!"<<endl;
        system("pause");
        ofile<<s1.tensach;
        ofile<<s1.masach;
        ofile<<s1.tacgia;
    }
    ofile.close();
}   
void chucnang::dssach()
{
	system("cls");
	cout << "\t\t\t\t__________________________Danh sach sach__________________________\n\n";
    if (soluongsach<=0)
    {
        cout<<"\t\t\t\tKhong co sach trong du lieu"<<endl;
        system("pause");
        return;
    }
    for (int i=0;i<soluongsach;i++)
    {
        arrsach[i].xuatsach();
    }
}
void chucnang::chensach(int x)
{
	for (int i=0;i<soluongsach;i++)
	{
		arrsach[i].tensach=arrsach[i+1].tensach;
		arrsach[i].masach=arrsach[i+1].masach;
	}
	soluongsach--;
}
void chucnang::xoasach()
{   
	system("cls");
    cout << "\t\t\t\t________________________________Xoa Sach__________________________________\n\n";
    if (soluongsach<=0)
    {
        cout<<"\t\t\t\tKhong co sach trong du lieu!"<<endl;
        system("pause");
        return;
    }
    string tim;
    cout<<"\t\t\t\tNhap ten sach hoac ma sach:";
    getline(cin,tim);
    for (int i=0;i<soluongsach;i++)
    {
        if (tim==arrsach[i].tensach||tim==arrsach[i].masach)
        {
            cout<<"\t\t\t\tThong tin cua sach ban muon xoa:"<<endl;
            arrsach[i].xuatsach();
            cout<<"\t\t\t\tBan co chac muon xoa du lieu sach nay khong?"<<endl;
            cout<<"\t\t\t\t1.Co\t\t\t2.Khong"<<endl;
            int xoa;
            cin>>xoa;
            if (xoa==1)
                {
                    chucnang::chensach(i);
		            cout<<"\t\t\t\tDu lieu ssach da duoc xoa!"<<endl;
		            system("pause");
                    return;
                }
            if (xoa==2)
                {
                    cout<<"\t\t\t\tDu lieu sach khong bi xoa!"<<endl;
                    system("pause");
                    return;
                }
        }
    }
    cout<<"\t\t\t\tKhong ton tai sach trong du lieu!"<<endl;
}
void chucnang::timkiemsach()
{
	system("cls");
    cout << "\t\t\t\t\n________________________________Tim kiem sach__________________________________\n\n";
	if (soluongsach<=0)
    {
        cout<<"\t\t\t\tKhong co sach trong du lieu!"<<endl;
        system("pause");
        return;
    }
    string tim;
    cout<<"\t\t\t\tNhap ten sach hoac ma sach:";
    getline(cin,tim);
    for (int i=0;i<soluongsach;i++){
        if (tim==arrsach[i].tensach||tim==arrsach[i].masach)
        {
            cout<<"\t\t\t\tThong tin sach tim kiem"<<endl;
            arrsach[i].xuatsach();
            system("pause");
            return;
        }
    }
     cout<<"\t\t\t\tKhong ton tai sach trong du lieu!"<<endl;
}
void muon::themuon(int x,int y)
{
	sach s;
	chucnang CN;
	muon m;
	cout << "\t\t\t\tNhap so luong sach muon: ";
	cin >> soluongmuon;
	cout << "\t\t\t\tThoi gian muon:\n";
	cout << "\t\t\t\tNgay: ";
	cin >> ngaymuon;
	cout << "\t\t\t\tThang: ";
	cin >> thangmuon;
	cout << "\t\t\t\tNam: ";
	cin >> nammuon;
	cout << "\t\t\t\tThoi gian tra:\n ";
	cout << "\t\t\t\tNgay: ";
	cin >> ngaytra;
	cout << "\t\t\t\tThang: ";
	cin >> thangtra;
	cout << "\t\t\t\tNam: ";
	cin >> namtra;
	system("cls");
	cout << "\t\t\t\tSo luong muon: " << soluongmuon << endl;
	cout << "\t\t\t\tThoi gian muon: " << ngaymuon << "/" << thangmuon<< "/" << nammuon<<endl;
	cout << "\t\t\t\tThoi gian tra: " << ngaytra << "/" << thangtra << "/" << namtra << endl;;
}
void chucnang::muonsach()
{
	system("cls");
    cout << "\t\t\t\t_________________________________Muon sach______________________________\n";
	bool check1=false;
    bool check2=false;
		string timkiemsach;
        do{
        
		cout << "\t\t\t\tNhap ma sach muon muon: ";
		getline(cin,timkiemsach);
		for (int i = 0; i < soluongsach; i++)
		{
			if (arrsach[i].masach == (string)timkiemsach)
			{
                check1=true;
				arr1[soluongphieu].xmasach = arrsach[i].masach;
				string timkiemsv;
				do{
                
				cout << "\t\t\t\tNhap MSSV muon muon: ";
				getline(cin,timkiemsv);
				for (int j = 0; j < soluongsinhvien; j++)
				{
					if (arrsv[j].mssv == timkiemsv)
					{
                        check2=true;
                        arr2[soluongphieu].xmssv=arrsv[j].mssv;
						arr1[soluongphieu].themuon(i,j);
						cout << "\t\t\t\tTen sinh vien: " << arrsv[j].hoten << endl;
						cout << "\t\t\t\tMSSV         : " << arrsv[j].mssv << endl;
						cout << "\t\t\t\tTen sach     : " << arrsach[i].tensach << endl;
						cout << "\t\t\t\tMa sach      : " << arrsach[i].masach << endl;
						muon m;
						system("pause");
						soluongphieu++;
                        ofstream ofile;
                        ofile.open("Phieumuon.txt",ios::out);
						
                        ofile << "Ten sinh vien: " << arrsv[i].hoten << endl;
						ofile << "Ma Sach      : " << arrsv[i].mssv << endl;
						ofile << "Ten sach     : " << arrsach[i].tensach << endl;
						ofile << "Ma Sach      : " << arrsach[i].masach << endl;
                        ofile.close();
						return;
					}
				}
				if(check2==false){system("cls");
				cout << "\t\t\t\tKhong ton tai sinh vien trong du lieu!";
				system("pause");}
                }while(check2==true);
			}
		}
		system("cls");
		cout << "\t\t\t\tKhong ton tai sach trong du lieu!";
		system("pause");
}while(check1==false);
}
void chucnang::chenthemuon(int x)
{
	arr1[x].xmasach = arr1[x + 1].xmasach;
    arr2[x].xmssv = arr2[x + 1].xmssv;
	soluongphieu--;
}
void chucnang::trasach()
{
	system("cls");
	muon m;
    cout << "\t\t\t\t_________________________________Tra sach______________________________\n";
	if (soluongphieu <= 0)
	{
		cout << "\t\t\t\tKhong co phieu muon nao trong du lieu!\n";
		system("pause");
		return;
	}
		string timkiemsach;
		cout << "\t\t\t\tNhap ma sach muon tra: ";
		getline(cin,timkiemsach);
		for (int i = 0; i < soluongphieu; i++)
		{
			if (arr1[i].xmasach == timkiemsach)
                cout<<"\t\t\t\tThong tin sach duoc tra:\n";
		        cout<< "\t\t\t\tTen sach:"<<"";sptimsach(i);cout<<endl;
                cout <<"\t\t\t\tTen sinh vien muon:"<<"";sptimsv(i);cout<<endl;
                int tra;
                cout<<"\t\t\t\tBan co xac nhan sach duoc tra khong?"<<endl;
                cout<<"\t\t\t\t\t1.Co\t\t2.Khong"<<endl;
                cin>>tra;
                if (tra==1)
                    {
                        chucnang::chenthemuon(i);
		                soluongphieu--;
                        cout<<"\t\t\t\tXac nhan thanh cong!"<<endl;
		                system("pause");
                        return;
                    }
                else if (tra==2)
                    {
                        cout<<"\t\t\t\tXac nhan khong thanh cong"<<endl;
                        system("pause");
                        return;
                    }	
		}
		cout << "\t\t\t\tKhong ton tai sach trong he thong!";
}

void chucnang::sptimsach(int x)
{
	for (int i = 0; i < soluongphieu; i++)
	{
		if (arr1[x].xmasach == arrsach[i].masach)
		{
			cout << arrsach[i].tensach;
		}
	}
}
void chucnang::sptimsv(int x)
{
	for (int i = 0; i < soluongphieu; i++)
	{
		if (arr2[x].xmssv == arrsv[i].mssv)
		{
			cout << arrsv[i].hoten;
		}
	}
}
void chucnang::dsthemuon()
{
	system("cls");
	if (soluongphieu <= 0)
	{
		cout << "\t\t\t\tKhong ton tai phieu muon trong he thong\n";
		system("pause");
		return;
	}
	cout << "\t\t\t\t__________________________Sach dang duoc muon_______________________________\n";
	for (int i = 0; i < soluongphieu; i++)
	{
		cout <<"\t\t\t\t..."<< i + 1 << "... "<<endl;
		cout<< "\t\t\t\tTen sach:"<<"";sptimsach(i);cout<<endl;
        cout <<"\t\t\t\tTen sinh vien muon:"<<"";sptimsv(i);
		cout << endl;
	}
	system("pause");
}
void chucnang::menutong()
{
	system("cls");
    cout << "\n\t\t\t\t===============================================\n";
	cout << "\t\t\t\t===========>";
	cout << "MENU QUAN LY THU VIEN";
	cout << "<=============\n";
	cout << "\t\t\t\t===============================================\n";
    cout << "\t\t\t\t-----------------------------------------------\n";
	cout << "\t\t\t\t1. Quan ly sinh vien\n";
	cout << "\t\t\t\t2. Quan ly sach\n";
	cout << "\t\t\t\t3. Quan ly the muon\n";
	cout << "\t\t\t\t4. Thoat\n";
    cout << "\t\t\t\t-----------------------------------------------\n";
    cout << "\t\t\t\tNhap so de chon chuc nang tuong ung!";
}
void chucnang::menu1()
{
	system("cls");
    cout << "\t\t\t\t=============>";
	cout << "QUAN LY SINH VIEN";
	cout << "<===============\n";
    cout << "\t\t\t\t-----------------------------------------------\n";
	cout << "\t\t\t\t1. Them sinh vien\n";
	cout << "\t\t\t\t2. Danh sach sinh vien\n";
	cout << "\t\t\t\t3. Xoa sinh vien\n";
	cout << "\t\t\t\t4. Tim kiem sinh vien\n";
	cout << "\t\t\t\t5. Thoat\n";
    cout << "\t\t\t\t-----------------------------------------------\n";
    cout << "\t\t\t\tNhap so de chon chuc nang tuong ung!";
}

void chucnang::menu2()
{
	system("cls");
    cout << "\t\t\t\t================>";
	cout << "QUAN LY SACH";
	cout << "<=================\n";
    cout << "\t\t\t\t-----------------------------------------------\n";
	cout << "\t\t\t\t1. Them sach\n";
	cout << "\t\t\t\t2. Danh sach sach\n";
	cout << "\t\t\t\t3. Xoa sach\n";
	cout << "\t\t\t\t4. Tim kiem sach\n";
	cout << "\t\t\t\t5. Thoat\n";
    cout << "\t\t\t\t-----------------------------------------------\n";
    cout << "\t\t\t\tNhap so de chon chuc nang tuong ung!";
}
void chucnang::menu3()
{
	system("cls"); 
    cout << "\t\t\t\t==============>";
	cout << "QUAN LY MUON TRA";
	cout << "<===============\n";
    cout << "\t\t\t\t-----------------------------------------------\n";
	cout << "\t\t\t\t1. Muon Sach\n";
	cout << "\t\t\t\t2. Tra Sach\n";
	cout << "\t\t\t\t3. Thong Ke Muon Sach\n";
	cout << "\t\t\t\t4. Thoat\n";
    cout << "\t\t\t\t-----------------------------------------------\n";
    cout << "\t\t\t\tNhap so de chon chuc nang tuong ung!";
}
int main()
{
    const string USERNAME = "admin123";
	const string PASSWORD = "0123456789";
	string username, password;
	bool xacthuc;

	do 
	{
		xacthuc=false;
		cout << "\t\t\t\tNhap tai khoan:";
		cin >> username;
		if (username.length() < 4)
		{
			cout << "\t\t\t\tTai khoan co do dai tu 4 ki tu tro len";
		}
		else  
		{
			cout << "\t\t\t\tNhap mat khau:";
			cin >> password;
			
			if (password.length() < 6)
			{
				cout << "\t\t\t\tMat khau co do dai tu 6 ki tu tro len" << endl;
			}
			else 
			{
			
				if (username == USERNAME && password == PASSWORD)
				{
					cout << "\t\t\t\tDang nhap thanh cong!" << endl;
                    system("pause");
					xacthuc = true;
				}
				else
				{
					cout << "\t\t\t\tTai khoan hoac mat khau khong chinh xac vui long nhap lai!" << endl;
				}
			}
		}
	} while (xacthuc == false);
    chucnang CN;
    while (true)
    {
        back:
        CN.menutong();
        char choose =_getch();
        switch (choose)
        {
            case '1':
            {
                back1:
                CN.menu1();
                char key1=_getch();
                switch (key1)
                {
                    case '1':
                    CN.themsinhvien();
                    break;
                    case '2':
                    CN.dssinhvien();
                    system("pause");
                    break;
                    case '3':
                    CN.xoasinhvien();
                    break;
                    case '4':
                    CN.timkiemsinhvien();
                    break;
                    case '5':
                    break;
                    default:
                    goto back1;
                    break;
                }
                break;
            }
            case '2':
            {
                back2:
                CN.menu2();
                char key2=_getch();
                switch (key2)
                {
                    case '1':
                    CN.themsach();
                    break;
                    case '2':
                    CN.dssach();
                    system("pause");
                    break;
                    case '3':
                    CN.xoasach();
                    break;
                    case '4':
                    CN.timkiemsach();
                    break;
                    case '5':
                    break;
                    default:
                    goto back2;
                    break;
                }
                break;
            }
            case '3':
		{
		back3:
			CN.menu3();
			char key3 = _getch();
			switch (key3)
			{
			case '1':
				CN.muonsach();
				break;
			case '2':
			{
				CN.trasach();
				break;
			}
			case '3':
			{
				system("cls");
				CN.dsthemuon();
				break;
			}
			case '4':
				break;
			default:
				goto back3;
				break;
			}
			break;
		}
            case '4':
            
        {
        goto out;
        break;
        }
        default:
        {
            goto back;
            break;
        }
        }
    }
    out:
    return 0;
}




