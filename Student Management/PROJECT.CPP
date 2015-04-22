
#include<iostream>    	//user=1  all=0
#include<cstdlib>		//course=2
#include<fstream>		//student=3
#include<iomanip>		//employee=4
#include<string.h>
#include<cctype>
#include<conio.h>
using namespace std; 

int search(int flag=0);
void view_assign_course(int id);
void assign_course(int id);
bool check_course(int asgn[],int count,int cid);
void fee_payment(int id);
bool compare(char *big,char*a);
bool auth();
void head();
void create_space();
void backup();
void over();

class payment
{
	public:
		int count;
		int assigned_id[10];
		int paid[10];
		
		payment()
		{
			int i;
			count=0;
			for(i=0;i<10;i++)
			{
				assigned_id[i]=0;
				paid[i]=0;
			}
		}
		
		void put_payment()
		{
			cout.setf(ios::right,ios::adjustfield);
			cout<<setw(2)<<count;
			cout.setf(ios::left,ios::adjustfield);
		}
};

class student
{
	public:
		char college[50];
		char branch[30];
	
		void get_student()
		{
			cout<<"\n\tCollege\t\t:\t";
			cin.getline(college,50);
			cout<<"\tBranch\t\t:\t";
			cin.getline(branch,30);
		}
		void put_student()
		{
			cout<<setw(15)<<college<<setw(10)<<branch;
		}
		void put_student_con()
		{
			cout<<"\n\tCollege\t\t:\t";
			cout<<college<<endl;
			cout<<"\tBranch\t\t:\t";
			cout<<branch<<endl;
		}
};

class employee
{
	public:
		int course_assigned;
		char education[30];
		char desc[100];	
	
		void get_employee()
		{
			cout<<"\n\tQualification\t:\t";
			cin.ignore();
			cin.getline(education,30);
			cout<<"\tDescription\t:\t";
			cin.getline(desc,100);
		}
		void put_employee()
		{
			cout<<setw(15)<<education<<setw(15)<<desc;
		}
		void put_employee_con()
		{
			cout<<"\n\tQualification\t:\t";
			cout<<education<<endl;
			cout<<"\tDescription\t:\t";
			cout<<desc<<endl;
		}
};

class course
{
	public:
		char course_name[30];
		char branch[30];
		char subject[20];
		char sem[10];
		long fee;
	
		void get_course()
		{
			cout<<"\n\tCourse Name\t:\t";
			cin.ignore();
			cin.getline(course_name,30);
			cout<<"\tBranch\t\t:\t";
			cin.getline(branch,30);
			cout<<"\tSemester\t:\t";
			cin>>sem;
			cout<<"\tSubject\t\t:\t";
			cin.ignore();
			cin.getline(subject,20);
			cout<<"\tFee\t\t:\t";
			cin>>fee;
		}
		void put_course()
		{
			cout<<setw(20)<<course_name<<setw(20)<<branch<<setw(5)<<sem<<setw(15)<<subject<<setw(8)<<fee;
		}
		void put_course_con()
		{
			cout<<"\n\tCourse Name\t:\t";
			cout<<course_name<<endl;
			cout<<"\tBranch\t\t:\t";
			cout<<branch<<endl;
			cout<<"\tSemester\t:\t";
			cout<<sem<<endl;
			cout<<"\tSubject\t\t:\t";
			cout<<subject<<endl;
			cout<<"\tFee\t\t:\t";
			cout<<fee<<endl;
		}
};

class user
{
	public:
		char user_name[20];
		char password[20];
	
		void get_user()
		{
			cout<<"\n\tUser Name\t:\t";
			cin>>user_name;
			cout<<"\tPassword\t:\t";
			cin>>password;
		}
		void put_user()
		{
			cout<<setw(15)<<user_name;
		}
		void put_user_con()
		{
			cout<<"\n\tUser Name\t:\t";
			cout<<user_name<<endl;
			cout<<"\tPassword\t:\t";
			cout<<password<<endl;
		}
};


class person
{
	public:
		char fname[20];
		char mname[20];
		char lname[20];
		char phone[15];
		char address[100];
	
		void get_person()
		{
			cout<<"\n\tFirst Name\t:\t";
			cin>>fname;
			cout<<"\tMiddle Name\t:\t";
			cin>>mname;
			cout<<"\tLast Name\t:\t";
			cin>>lname;
			cout<<"\tPhone\t\t:\t";
			cin>>phone;
			cout<<"\tAddress\t\t:\t";
			cin.ignore();
			cin.getline(address,100);
		}
		
		void put_person()
		{
			cout<<setw(15)<<fname<<setw(15)<<lname<<setw(12)<<phone;
		}
		
		void put_person_con()
		{
			cout<<"\n\tFirst Name\t:\t";
			cout<<fname<<endl;
			cout<<"\tMiddle Name\t:\t";
			cout<<mname<<endl;
			cout<<"\tLast Name\t:\t";
			cout<<lname<<endl;
			cout<<"\tPhone\t\t:\t";
			cout<<phone<<endl;
			cout<<"\tAddress\t\t:\t";
			cout<<address<<endl;
		}
};

class man
{
	public:
		int id;
		bool user_flag,student_flag,employee_flag,course_flag;
		user u;
		person p;
		course c;
		student s;
		employee e;
		payment py;
		man()
		{
			user_flag=false;
			student_flag=false;
			employee_flag=false;
			course_flag=false;
		}
		void put()
		{
			cout<<setw(4)<<id;
			if(user_flag==true)
			{
				p.put_person();
				u.put_user();
			}
			else if(course_flag==true)
			{
				c.put_course();
			}
			else if(student_flag==true)
			{
				p.put_person();
				s.put_student();
				py.put_payment();
			}
			else if(employee_flag==true)
			{
				p.put_person();
				e.put_employee();
			}
			cout<<"\n";
		}
};

int get_new_id()
{
	int id=0,last,obj;
	man m;
	ifstream file;
	file.open("D:\\Student_Management\\\lpt1\\DB",ios::binary);
	if(file)
	{
		file.seekg(0,ios::end);
		last=file.tellg();
		last-=sizeof(m);
		file.seekg(last);
		file.read((char *)&m,sizeof(m));
		id=m.id;
		id++;
	}
	else
	{
		id=1;
	}
	file.close();
	return id;
}

void delete_id(int id)
{
	man m;
	ifstream ifile;
	ofstream ofile;
	ifile.open("D:\\Student_Management\\\lpt1\\DB",ios::binary);
	ofile.open("D:\\Student_Management\\\lpt1\\TEMP",ios::binary);
	
	while(ifile.read((char*)&m,sizeof(m)))
	{
		if(m.id!=id)
		{
			ofile.write((char*)&m,sizeof(m));
		}
	}
	
	ifile.close();
	ofile.close();
	remove("D:\\Student_Management\\\lpt1\\DB");
	rename("D:\\Student_Management\\\lpt1\\TEMP","D:\\Student_Management\\\lpt1\\DB");
}

void con()
{
	ifstream file;
	man m;
	int obj;
	file.open("D:\\Student_Management\\\lpt1\\DB",ios::ate|ios::binary);
	obj=get_new_id()-2;
	file.seekg(obj*sizeof(m),ios::beg);
	file.read((char*)&m,sizeof(m));
	file.close();
	if(m.student_flag==true)
	{
		cout<<"\n\nStudent Info Received :\n";
		m.p.put_person_con();
		m.s.put_student_con();
		char choice='1';
		while(choice!='y'&&choice!='Y'&&choice!='n'&&choice!='N')
		{
			cout<<"\nSave Entry ? (y/n) : ";
			cin>>choice;
			if(choice=='n'||choice=='N')
			{
				delete_id(m.id);
				cout<<"\nEntry Discarded.";
			}
			else if(choice=='y'||choice=='Y')
			{
				cout<<"\nStudent Added Successfully.\n\nUnique ID Provided :"<<m.id;
			}
			
		}
	}
	else if(m.user_flag==true)
	{
		cout<<"\n\nUser Info Received :\n";
		m.p.put_person_con();
		m.u.put_user_con();
		char choice='1';
		while(choice!='y'&&choice!='Y'&&choice!='n'&&choice!='N')
		{
			cout<<"\nSave Entry ? (y/n) : ";
			cin>>choice;
			if(choice=='n'||choice=='N')
			{
				delete_id(m.id);
				cout<<"\nEntry Discarded.";
			}
			else if(choice=='y'||choice=='Y')
			{
				cout<<"\nUser Added Successfully.\n\nUnique ID Provided :"<<m.id;
			}
			
		}
	}
	else if(m.employee_flag==true)
	{
		cout<<"\n\nEmployee Info Received :\n";
		m.p.put_person_con();
		m.e.put_employee_con();
		char choice='1';
		while(choice!='y'&&choice!='Y'&&choice!='n'&&choice!='N')
		{
			cout<<"\nSave Entry ? (y/n) : ";
			cin>>choice;
			if(choice=='n'||choice=='N')
			{
				delete_id(m.id);
				cout<<"\nEntry Discarded.";
			}
			else if(choice=='y'||choice=='Y')
			{
				cout<<"\nEmployee Added Successfully.\n\nUnique ID Provided :"<<m.id;
			}
			
		}
	}
	else if(m.course_flag==true)
	{
		cout<<"\n\nCourse Info Received :\n";
		m.c.put_course_con();
		char choice='1';
		while(choice!='y'&&choice!='Y'&&choice!='n'&&choice!='N')
		{
			cout<<"\nSave Entry ? (y/n) : ";
			cin>>choice;
			if(choice=='n'||choice=='N')
			{
				delete_id(m.id);
				cout<<"\nEntry Discarded.";
			}
			else if(choice=='y'||choice=='Y')
			{
				cout<<"\nCourse Added Successfully.\n\nUnique ID Provided :"<<m.id;
			}
			
		}
	}
}

void add(int a)
{
	man m;
	switch(a)
	{
		case 1:
			cout<<"\n\nEnter User Info : \n";
			m.user_flag=true;
			m.u.get_user();
			m.p.get_person();
			break;
		case 2:
			cout<<"\n\nEnter Course Info : \n";
			m.course_flag=true;
			m.c.get_course();
			break;
		case 3:
			cout<<"\n\nEnter Student Info : \n";
			m.student_flag=true;
			m.p.get_person();
			m.s.get_student();	
			break;
		case 4:
			cout<<"\n\nEnter Employee Info : \n";
			m.employee_flag=true;
			m.p.get_person();
			m.e.get_employee();
			break;
	}
	ofstream file;
	m.id=get_new_id();
	file.open("D:\\Student_Management\\\lpt1\\DB",ios::app|ios::binary);
	file.write((char*)&m,sizeof(m));
	file.close();
	con();
}
bool access_id(int id,int a)
{
	man m;
	ifstream file;
	file.open("D:\\Student_Management\\\lpt1\\DB",ios::binary);
	bool flag=false;
	
	while(file.read((char *)&m,sizeof(m)))
	{
		if(m.id==id)
		{
			switch(a)
			{
				case 1:
					if(m.user_flag==true)
					{
						flag=true;
						cout<<"\nUser Info : \n";
						m.u.put_user_con();
						m.p.put_person_con();
					}
					break;
				case 3:
					if(m.student_flag==true)
					{
						flag=true;
						cout<<"\nStudent Info : \n";
						m.p.put_person_con();
						m.s.put_student_con();
					}
					break;
				case 4:
					if(m.employee_flag==true)
					{
						flag=true;
						cout<<"\nEmployee Info : \n";
						m.p.put_person_con();
						m.e.put_employee_con();
					}
					break;
				case 2:
					if(m.course_flag==true)
					{
						flag=true;
						cout<<"\nCourse Info : \n";
						m.c.put_course_con();
					}
			}
		}
	}
	return flag;
}

void edit(int id,int flag)
{
	man m,n;
	if(!access_id(id,flag))
	{
		cout<<"\nNo Record Found for this ID.";
		return;
	}

	switch(flag)
	{
		case 1:
			cout<<"User : \n";
			m.user_flag=true;
			m.u.get_user();
			m.p.get_person();
			break;
		case 2:
			cout<<"course : \n";
			m.course_flag=true;
			m.c.get_course();
			break;
		case 3:
			cout<<"\n\nEnter Student Info : \n";
			m.student_flag=true;
			m.p.get_person();
			m.s.get_student();	
			break;
		case 4:
			cout<<"employee : \n";
			m.employee_flag=true;
			m.e.get_employee();
			m.p.get_person();
			break;
	}
	m.id=id;
	ofstream ofile;
	ifstream ifile;
	ifile.open("D:\\Student_Management\\\lpt1\\DB",ios::binary);
	ofile.open("D:\\Student_Management\\\lpt1\\TEMP",ios::trunc|ios::binary);
	while(ifile.read((char*)&n,sizeof(n)))
	{
		if(n.id!=id)
		{
			ofile.write((char*)&n,sizeof(n));
		}
		else
		{
			ofile.write((char*)&m,sizeof(m));
		}
	}
	ifile.close();
	ofile.close();
	remove("D:\\Student_Management\\\lpt1\\DB");
	rename("D:\\Student_Management\\\lpt1\\TEMP","D:\\Student_Management\\\lpt1\\DB");
	cout<<"\n\nEdited Successfully";
}

void show_all_user(int a=0)
{
	man m;
	ifstream file;
	file.open("D:\\Student_Management\\\lpt1\\DB",ios::binary);
	while(file.read((char *)&m,sizeof(m)))
	{
		switch(a)
		{
			case 1:
				if(m.user_flag==true)
				m.put();
				break;
			case 2:
				if(m.course_flag==true)
				m.put();
				break;
			case 3:
				if(m.student_flag==true)
				m.put();
				break;
			case 4:
				if(m.employee_flag==true)
				m.put();
				break;
			default:
				m.put();
		}
	}
	file.close();
}

void line(char a,int start,int end)
{
	int i;
	for(i=0;i<=end;i++)
	{
		if(i<start)
		{
			cout<<" ";
		}
		else
		{
		cout.put(a);
		}
	}
	cout<<endl;
}

void get_employee_list()
{
	line('_',0,79);
	cout.setf(ios::left,ios::adjustfield);
	cout<<setw(4)<<"Id"<<setw(15)<<"First Name"<<setw(15)<<"Last Name"<<setw(12)<<"Phone"<<setw(15)<<"Qualification"<<setw(15)<<"Description"<<endl;
	line('-',0,79);
	show_all_user(4);
}

void get_student_list()
{
	line('_',0,79);
	cout.setf(ios::left,ios::adjustfield);
	cout<<setw(4)<<"Id"<<setw(15)<<"First Name"<<setw(15)<<"Last Name"<<setw(12)<<"Phone"<<setw(15)<<"College"<<setw(10)<<"Branch"<<setw(2)<<"C.A"<<endl;
	line('-',0,79);
	show_all_user(3);
}

void get_user_list()
{
	line('_',0,79);
	cout.setf(ios::left,ios::adjustfield);
	cout<<setw(4)<<"Id"<<setw(15)<<"First Name"<<setw(15)<<"Last Name"<<setw(12)<<"Phone"<<setw(15)<<"Username"<<endl;
	line('-',0,79);
	show_all_user(1);
}

void get_course_list()
{
	line('_',0,79);
	cout.setf(ios::left,ios::adjustfield);
	cout<<setw(4)<<"Id"<<setw(20)<<"Course Name"<<setw(20)<<"Branch"<<setw(5)<<"Sem"<<setw(15)<<"Subject"<<setw(5)<<"Fee"<<endl;
	line('-',0,79);
	show_all_user(2);
}

bool contain(char *a,char *b)
{
	char *c;
	strlwr(a);
	strlwr(a);
	c=strstr(a,b);
	if(c==NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void show_search(int flag)
{
	ifstream file;
	man m;

	line('_',0,79);	
	switch(flag)
	{
		case 1:
			cout.setf(ios::left,ios::adjustfield);
			cout<<setw(4)<<"Id"<<setw(15)<<"First Name"<<setw(15)<<"Last Name"<<setw(15)<<"Phone"<<setw(15)<<"Username"<<endl;
			break;
		case 2:
			cout.setf(ios::left,ios::adjustfield);
			cout<<setw(4)<<"Id"<<setw(20)<<"Course Name"<<setw(20)<<"Branch"<<setw(5)<<"Sem"<<setw(15)<<"Subject"<<setw(5)<<"Fee"<<endl;
			break;
		case 3:
			cout.setf(ios::left,ios::adjustfield);
			cout<<setw(4)<<"Id"<<setw(15)<<"First Name"<<setw(15)<<"Last Name"<<setw(12)<<"Phone"<<setw(15)<<"College"<<setw(10)<<"Branch"<<setw(2)<<"C.A"<<endl;
			break;
		case 4:
			cout.setf(ios::left,ios::adjustfield);
			cout<<setw(4)<<"Id"<<setw(15)<<"First Name"<<setw(15)<<"Last Name"<<setw(15)<<"Phone"<<setw(15)<<"Qualification"<<setw(20)<<"Description"<<endl;
	}
	line('-',0,79);
	
	file.open("D:\\Student_Management\\\lpt1\\SEARCH",ios::binary);
	while(file.read((char *)&m,sizeof(m)))
	{
		switch(flag)
		{
			case 1:
				if(m.user_flag==true)
				m.put();
				break;
			case 2:
				if(m.course_flag==true)
				m.put();
				break;
			case 3:
				if(m.student_flag==true)
				m.put();
				break;
			case 4:
				if(m.employee_flag==true)
				m.put();
				break;
		}
		
	}
	file.close();
	cout<<"\n\n";
	system("pause");
}

class menu
{
	private:
		man m;
	public:
		
		void help()
		{
			system("cls");
			head();
			cout<<"\n\n\n\tFeel free to contact if-\n\n\t\t-you have difficulty with any task\n\t\t-forgotten password\n\t\t-recover database\n\t\n\n\n\tSee About for Contact Details.\n\n\n\n\n";
			system("pause");
			main_menu();
		}
		
		void about()
		{
			system("cls");
			
			cout<<"\tAbout Me : ";
			
			cout<<"\n\n        ____  _                                   _____      _       _ \n       ";cout.put(179);cout<<"  _ \\";cout.put(179);cout<<" ";cout.put(179);cout<<"                                 ";cout.put(179);cout<<"  __ \\    ";cout.put(179);cout<<" ";cout.put(179);cout<<"     ";cout.put(179);cout<<" ";cout.put(179);cout<<"\n       ";cout.put(179);cout<<" ";cout.put(179);cout<<"_) ";cout.put(179);cout<<" ";cout.put(179);cout<<"__   __ _ _ __ __ _  __ ___   __ ";cout.put(179);cout<<" ";cout.put(179);cout<<"__) ";cout.put(179);cout<<"_ _";cout.put(179);cout<<" ";cout.put(179);cout<<"_ ___";cout.put(179);cout<<" ";cout.put(179);cout<<"\n       ";cout.put(179);cout<<"  _ <";cout.put(179);cout<<" '_ \\ / _` ";cout.put(179);cout<<" '__/ _` ";cout.put(179);cout<<"/ _` \\ \\ / / ";cout.put(179);cout<<"  ___/ _` ";cout.put(179);cout<<" __/ _ \\ ";cout.put(179);cout<<"\n       ";cout.put(179);cout<<" ";cout.put(179);cout<<"_) ";cout.put(179);cout<<" ";cout.put(179);cout<<" ";cout.put(179);cout<<" ";cout.put(179);cout<<" (_";cout.put(179);cout<<" ";cout.put(179);cout<<" ";cout.put(179);cout<<" ";cout.put(179);cout<<" (_";cout.put(179);cout<<" ";cout.put(179);cout<<" (_";cout.put(179);cout<<" ";cout.put(179);cout<<"\\ V /  ";cout.put(179);cout<<" ";cout.put(179);cout<<"  ";cout.put(179);cout<<" (_";cout.put(179);cout<<" ";cout.put(179);cout<<" ";cout.put(179);cout<<"";cout.put(179);cout<<"  __/ ";cout.put(179);cout<<"\n       ";cout.put(179);cout<<"____/";cout.put(179);cout<<"_";cout.put(179);cout<<" ";cout.put(179);cout<<"_";cout.put(179);cout<<"\\__,_";cout.put(179);cout<<"_";cout.put(179);cout<<"  \\__, ";cout.put(179);cout<<"\\__,_";cout.put(179);cout<<" \\_/   ";cout.put(179);cout<<"_";cout.put(179);cout<<"   \\__,_";cout.put(179);cout<<"\\__\\___";cout.put(179);cout<<"_";cout.put(179);cout<<"\n                               __/ ";cout.put(179);cout<<"                                   \n                              ";cout.put(179);cout<<"___/                                    ";
			
			
			cout<<"\n\n\n\tBhargav K Patel\n";
			cout<<"\n\n\tEmail\t\t:\tbhargav079@gmail.com";
			cout<<"\n\n\tFacebook\t:\twww.facebook.com/olodoio";
			
			cout<<"\n\n\n\n";
			
			cout<<"\n\n";
			system("pause");
		}
		
		void main_menu()
		{
			char choice;
			
			system("cls");
			
			head();
			
			cout<<"\t\tWelcome"<<endl;
			line('=',15,23);
			
			cout<<"\n\n\t1. Student Menu";
			cout<<"\n\t2. Employee Menu";
			cout<<"\n\t3. Course Menu";
			cout<<"\n\t4. User Menu";
			cout<<"\n\n\t5. Help";
			cout<<"\n\t6. About";
			cout<<"\n\t9. Log Out";
			
			cout<<"\n\n\n\tEnter Choice : ";
			
			cin>>choice;
			
			switch(choice)
			{
				case '1':
					student_menu();
					break;
				case '2':
					employee_menu();
					break;
				case '3':
					course_menu();
					break;
				case '4':
					user_menu();
					break;
				case '6':
					about();
					main_menu();
				case '5':
					help();
				case '9':
					cout<<"\n\n\t\t";
					backup();
					cout.put(3);
					cout<<" Bye ";
					cout.put(3);
					cout<<endl;
					exit(0);
				default:
					cout<<"\n\tInvalid\n\n";
					system("pause");
					main_menu();
			}
		}
		
		void student_menu()
		{
			int id;
			char choice;
			
			system("cls");
			
			head();
			
			cout<<"\t\tStudent Menu"<<endl;
			line('=',16,27);
			
			cout<<"\n\n\t1. Search Student";
			cout<<"\n\t2. Fee Payment";
			cout<<"\n\t3. Add/Remove/Edit Student";
			cout<<"\n\t4. Assign course to Student";
			cout<<"\n\n\t8. Back";
			cout<<"\n\t9. Log Out";
			cout<<"\n\n\n\tEnter Choice : ";
			
			cin>>choice;
			
			switch(choice)
			{
				case '1':
					id=search(3);
					view_assign_course(id);
					cout<<endl<<endl;
					system("pause");
					student_menu();
				case '2':
					cout<<"\nEnter Student Id : ";
					cin>>id;
					fee_payment(id);
					cout<<"\n\n";
					system("pause");
					student_menu();
				case '4':
					cout<<"\nEnter Student Id : ";
					cin>>id;
					assign_course(id);
					cout<<"\n\n";
					system("pause");
					student_menu();
				case '3':
					modify(3);
				case '8':
					main_menu();
				case '9':
					cout<<"\n\n\t\t";
					backup();
					cout.put(3);
					cout<<" Bye ";
					cout.put(3);
					cout<<endl;
					exit(0);
				default:
					cout<<"\n\nInvalid\n\n";
					system("pause");
					student_menu();
			}
		}
		void employee_menu()
		{
			char choice;
			
			system("cls");
			
			head();
			
			cout<<"\t\tEmployee Menu"<<endl;
			line('=',16,28);
			
			cout<<"\n\n\t1. Search Employee";
			cout<<"\n\t2. Add/Remove/Edit Employee";
			cout<<"\n\n\t8. Back";
			cout<<"\n\t9. Log Out";
			cout<<"\n\n\n\tEnter Choice : ";
			
			cin>>choice;
			
			switch(choice)
			{
				case '1':
					access_id(search(4),4);
					cout<<endl<<endl;
					system("pause");
					search(4);
				case '2':
					modify(4);
					break;
				case '8':
					main_menu();
					break;
				case '9':
					cout<<"\n\n\t\t";
					backup();
					cout.put(3);
					cout<<" Bye ";
					cout.put(3);
					cout<<endl;
					exit(0);
				default:
					cout<<"\n\nInvalid\n\n";
					system("pause");
					employee_menu();
			}
		}
		void user_menu()
		{
			char choice;
			
			system("cls");
			
			head();
			
			cout<<"\t\tUser Menu"<<endl;
			line('=',16,24);
			
			cout<<"\n\n\t1. Search User";
			cout<<"\n\t2. Add/Remove/Edit User";
			cout<<"\n\t8. Back";
			cout<<"\n\t9. Log Out";
			cout<<"\n\n\n\tEnter Choice : ";
			
			cin>>choice;
			
			switch(choice)
			{
				case '1':
					access_id(search(1),1);
					cout<<endl<<endl;
					system("pause");
					search(1);
				case '2':
					if(!auth())
					{
						cout<<"\n\n\tInvalid Details\n\n";
						system("pause");
						user_menu();
					}
					else
					{
						modify(1);
					}
					break;
				case '8':
					main_menu();
					break;
				case '9':
					cout<<"\n\n\t\t";
					backup();
					cout.put(3);
					cout<<" Bye ";
					cout.put(3);
					cout<<endl;
					exit(0);
				default:
					cout<<"\n\nInvalid\n\n";
					system("pause");
					user_menu();
			}
		}
		void course_menu()
		{
			char choice;
			
			system("cls");
			
			head();
			
			cout<<"\t\tCourse Menu"<<endl;
			line('=',16,26);
			
			cout<<"\n\n\t1. Search Course";
			cout<<"\n\t2. Add/Remove/Edit Course";
			cout<<"\n\n\t8. Back";
			cout<<"\n\t9. Log Out";
			cout<<"\n\n\n\tEnter Choice : ";
			
			cin>>choice;
			
			switch(choice)
			{
				case '1':
					access_id(search(2),2);
					cout<<endl<<endl;
					system("pause");
					search(2);
				case '2':
					modify(2);
				case '8':
					main_menu();
				case '9':
					cout<<"\n\n\t\t";
					backup();
					cout.put(3);
					cout<<" Bye ";
					cout.put(3);
					cout<<endl;
					exit(0);
				default:
					cout<<"\n\nInvalid\n\n";
					system("pause");
					course_menu();
			}
		}
		void modify(int a)
		{
			char choice;
			char *b;
			switch(a)
			{
				case 1:
					b="User";break;
				case 2:
					b="Course";break;
				case 3:
					b="Student";break;
				case 4:
					b="Employee";
			}
			
			system("cls");
			
			head();
			
			cout<<"\t\t"<<b<<" Modify Menu"<<endl;
			line('=',16,34);
			
			cout<<"\n\n\t1. Add New "<<b;
			cout<<"\n\t2. Remove "<<b;
			cout<<"\n\t3. Edit "<<b;
			cout<<"\n\n\t8. Back";
			cout<<"\n\t9. Log Out";
			cout<<"\n\n\n\tEnter Choice : ";
			
			cin>>choice;
			int id;
			char cho='1';
			switch(choice)
			{
				case '1':
					add(a);
					cout<<endl<<endl;
					system("pause");
					modify(a);
				case '2':
					cout<<"\n\nEnter ID of "<<b<<" To delete : ";
					cin>>id;
					if(access_id(id,a))
					{
						while(cho!='y'&&cho!='Y'&&cho!='n'&&cho!='N')
						{
							cout<<"\nAre you Sure ? (y/n) : ";
							cin>>cho;
							if(cho=='n'||cho=='N')
							{
								cout<<"\nEntry Discarded.";
							}
							else if(cho=='y'||cho=='Y')
							{
								delete_id(id);
								cout<<"\n"<<b<<" Deleted Successfully.";
							}
						}
					}
					else
					{
						cout<<"\nNo Record Found for this ID.";
					}	
					cout<<endl<<endl;
					system("pause");
					modify(a);
				case '3':
					cout<<"\n\nEnter ID of "<<b<<" To edit : ";
					cin>>id;
					edit(id,a);
					cout<<endl<<endl;
					system("pause");
					modify(a);
				case '8':
					switch(a)
					{
						case 1:
							user_menu();
						case 2:
							course_menu();
						case 3:
							student_menu();
						case 4:
							employee_menu();
					}
				case '9':
					cout<<"\n\n\t\t";
					backup();
					cout.put(3);
					cout<<" Bye ";
					cout.put(3);
					cout<<endl;
					exit(0);
				default:
					cout<<"\n\nInvalid\n\n";
					system("pause");
					modify(a);
			}
		}
		
	
};

int search(int flag)
{
			menu n;
			man m;
			char choice;
			int id;
			char fname[20];
			char lname[20];
			char phone[20];
			char college[50];
			char branch[30];
			ifstream ifile;
			ofstream ofile;
			
			system("cls");
			
			head();
			
			cout<<"\t\tSearch"<<endl;
			line('=',16,21);
			
			cout<<"\n\n\t1. By ID";
			cout<<"\n\t2. Show All";
			cout<<"\n\t3. By First Name";
			cout<<"\n\t4. By Last Name";
			cout<<"\n\t5. By Phone";
			
			if(flag==3)
			{
				cout<<"\n\t6. By College";
				cout<<"\n\t7. By Branch";
			}
			cout<<"\n\n\t8. Back";
			cout<<"\n\t9. Log Out";
			cout<<"\n\n\n\tEnter Choice : ";
			
			cin>>choice;
			
			switch(choice)
			{
				case '1':
					system("cls");
					cout<<"\nEnter ID : ";
					cin>>id;
					return id;
					break;
				case '2':
					switch(flag)
					{
						case 1:
							get_user_list();
							break;
						case 2:
							get_course_list();
							break;
						case 3:
							get_student_list();
							break;
						case 4:
							get_employee_list();
							break;
					}
					cout<<endl<<endl;
					system("pause");
					search(flag);
					break;
				case '3':
					cout<<"\nEnter Few Characters of First Name : ";
					cin>>fname;
					
					ifile.open("D:\\Student_Management\\\lpt1\\DB",ios::binary);
					ofile.open("D:\\Student_Management\\\lpt1\\SEARCH",ios::trunc|ios::binary);
					
					while(ifile.read((char *)&m,sizeof(m)))
					{
						if(contain(m.p.fname,fname))
						{
							ofile.write((char *)&m,sizeof(m));
						}	
					}
					
					ifile.close();
					ofile.close();
					show_search(flag);
					search(flag);
					break;
				case '4':
					cout<<"\nEnter Few Characters of Last Name : ";
					cin>>lname;
					
					ifile.open("D:\\Student_Management\\\lpt1\\DB",ios::binary);
					ofile.open("D:\\Student_Management\\\lpt1\\SEARCH",ios::trunc|ios::binary);
					
					while(ifile.read((char *)&m,sizeof(m)))
					{
						if(contain(m.p.lname,lname))
						{
							ofile.write((char *)&m,sizeof(m));
						}	
					}
					
					ifile.close();
					ofile.close();
					show_search(flag);
					search(flag);
					break;
				case '5':
					cout<<"\nEnter Few Numbers of Phone : ";
					cin>>phone;
					
					ifile.open("D:\\Student_Management\\\lpt1\\DB",ios::binary);
					ofile.open("D:\\Student_Management\\\lpt1\\SEARCH",ios::trunc|ios::binary);
					
					while(ifile.read((char *)&m,sizeof(m)))
					{
						if(contain(m.p.phone,phone))
						{
							ofile.write((char *)&m,sizeof(m));
						}	
					}
					
					ifile.close();
					ofile.close();
					show_search(flag);
					search(flag);
					break;
				case '6':
					cout<<"\nEnter Few Characters College : ";
					cin>>college;
					
					ifile.open("D:\\Student_Management\\\lpt1\\DB",ios::binary);
					ofile.open("D:\\Student_Management\\\lpt1\\SEARCH",ios::trunc|ios::binary);
					
					while(ifile.read((char *)&m,sizeof(m)))
					{
						if(contain(m.s.college,college))
						{
							ofile.write((char *)&m,sizeof(m));
						}	
					}
					
					ifile.close();
					ofile.close();
					show_search(flag);
					search(flag);
					break;
				case '7':
					cout<<"\nEnter Few Characters Branch : ";
					cin>>branch;
					
					ifile.open("D:\\Student_Management\\\lpt1\\DB",ios::binary);
					ofile.open("D:\\Student_Management\\\lpt1\\SEARCH",ios::trunc|ios::binary);
					
					while(ifile.read((char *)&m,sizeof(m)))
					{
						if(contain(m.s.branch,branch))
						{
							ofile.write((char *)&m,sizeof(m));
						}	
					}
					
					ifile.close();
					ofile.close();
					show_search(flag);
					search(flag);
					break;
				case '8':
					switch(flag)
					{
						case 1:
							n.user_menu();
						case 2:
							n.course_menu();
						case 3:
							n.student_menu();
						case 4:
							n.employee_menu();
					}
					break;
				case '9':
					cout<<"\n\n\t\t";
					backup();
					cout.put(3);
					cout<<" Bye ";
					cout.put(3);
					cout<<endl;
					exit(0);
				default:
					cout<<"\n\nInvalid\n\n";
					system("pause");
					search(flag);
			}
}

void assign_course(int id)
{
	if(access_id(id,3)||access_id(id,4))
	{
		char choice='1';
		while(choice!='y'&&choice!='Y'&&choice!='n'&&choice!='N')
		{
			cout<<"\nDo you want to Assign Course to this Person ? (y/n) : ";
			cin>>choice;
			if(choice=='n'||choice=='N')
			{
				cout<<"\nEntry Discarded.";
			}
			else if(choice=='y'||choice=='Y')
			{
				int cid;
				cout<<"\nEnter ID of Course to Assign : ";
				cin>>cid;
				if(access_id(cid,2))
				{
					char cho='1';
					while(cho!='y'&&cho!='Y'&&cho!='n'&&cho!='N')
					{
						cout<<"\nDo you want to Assign this Course ? (y/n) : ";
						cin>>cho;
						if(cho=='n'||cho=='N')
						{
							cout<<"\nEntry Discarded.";
						}
						else if(cho=='y'||cho=='Y')
						{
							man m,n;
							int count;
							ifstream file;
							file.open("D:\\Student_Management\\\lpt1\\DB",ios::binary);
							file.seekg(0,ios::beg);
							while(file.read((char*)&m,sizeof(m)))
							{
								if(m.id==id)
								{
									count=m.py.count;
									if(check_course(m.py.assigned_id,count,cid))
									{
										m.py.assigned_id[count]=cid;
										(m.py.count)++;
										break;
									}
									else
									{
										cout<<"\n\nCourse Already Assigned";
										file.close();
										return;
									}
								}
							}
							file.clear();
							file.close();
							ofstream ofile;
							ifstream ifile;
							ifile.open("D:\\Student_Management\\\lpt1\\DB",ios::binary);
							ofile.open("D:\\Student_Management\\\lpt1\\TEMP",ios::trunc|ios::binary);
							ifile.seekg(0,ios::beg);
							while(ifile.read((char*)&n,sizeof(n)))
							{
								if(n.id!=id)
								{
									ofile.write((char*)&n,sizeof(n));
								}
								else
								{
									ofile.write((char*)&m,sizeof(m));
								}
							}
							ifile.close();
							ofile.close();
							remove("D:\\Student_Management\\\lpt1\\DB");
							rename("D:\\Student_Management\\\lpt1\\TEMP","D:\\Student_Management\\\lpt1\\DB");
							cout<<"\n\nCourse Assigned Successfully";
						}
			
					}
				}
				else
				{
					cout<<"\nNo Record Found for this ID.";
				}
			}
			
		}		
	}
	else
	{
		cout<<"\nNo Record Found for this ID.";
	}
}

void view_assign_course(int id)
{
	if(access_id(id,3))
	{
		man m;
		int i,count,paid[10],asgn[10];
		ifstream file;
		file.open("D:\\Student_Management\\\lpt1\\DB",ios::binary);
		file.seekg(0,ios::beg);
		while(file.read((char*)&m,sizeof(m)))
		{
			if(m.id==id)
			{
				count=m.py.count;
				for(i=0;i<count;i++)
				{
					asgn[i]=m.py.assigned_id[i];
					paid[i]=m.py.paid[i];
				}
				break;
			}
		}
		file.clear();
		file.seekg(0,ios::beg);
		line('_',0,79);
		cout.setf(ios::left,ios::adjustfield);
		cout<<setw(4)<<"Id"<<setw(20)<<"Course Name"<<setw(20)<<"Branch"<<setw(5)<<"Sem"<<setw(15)<<"Subject"<<setw(8)<<"Fee";
		cout.setf(ios::right,ios::adjustfield);
		cout<<setw(8)<<"Paid"<<endl;
		cout.setf(ios::left,ios::adjustfield);
		line('-',0,79);
		for(i=0;i<count;i++)
		{
			while(file.read((char*)&m,sizeof(m)))
			{
				if(m.id==asgn[i])
				{
					cout<<setw(4)<<m.id;
					m.c.put_course();
					cout.setf(ios::right,ios::adjustfield);
					cout<<setw(8)<<paid[i]<<endl;
					cout.setf(ios::left,ios::adjustfield);
					file.clear();
					file.seekg(0,ios::beg);
					break;
				}
			}
		}
			file.close();
			
	}
	else
	{
		cout<<"\nNo Record Found for this ID.";
	}
}

void fee_payment(int id)
{
	view_assign_course(id);
	cout<<"\n\nEnter Course id for Payment : ";
	int cid;
	cin>>cid;
	
	man m,n;
	int count,i;
	ifstream file;
	file.open("D:\\Student_Management\\\lpt1\\DB",ios::binary);
	file.seekg(0,ios::beg);
	while(file.read((char*)&m,sizeof(m)))
	{
		if(m.id==id)
		{
			count=m.py.count;
			if(!check_course(m.py.assigned_id,count,cid))
			{
				for(i=0;i<count;i++)
				{
					if(m.py.assigned_id[i]==cid)
					{
						break;
					}
				}
				break;
			}
			else
			{
				cout<<"\n\nCourse Not Found. First assign course to this student.";
				file.close();
				return;
			}
		}
	}
		
	long fee;
		
	cout<<"Enter Amount : ";
	cin>>fee;
	
	m.py.paid[i]+=fee;
					
	file.clear();
	file.close();
	ofstream ofile;
	ifstream ifile;
	ifile.open("D:\\Student_Management\\\lpt1\\DB",ios::binary);
	ofile.open("D:\\Student_Management\\\lpt1\\TEMP",ios::trunc|ios::binary);
	ifile.seekg(0,ios::beg);
	while(ifile.read((char*)&n,sizeof(n)))
	{
		if(n.id!=id)
		{
			ofile.write((char*)&n,sizeof(n));
		}
		else
		{
			ofile.write((char*)&m,sizeof(m));
		}
	}
	ifile.close();
	ofile.close();
	remove("D:\\Student_Management\\\lpt1\\DB");
	rename("D:\\Student_Management\\\lpt1\\TEMP","D:\\Student_Management\\\lpt1\\DB");
	cout<<"\n\nPayment Successful.";
}

bool check_course(int asgn[],int count,int cid)
{
	int i=0;
	bool flag=true;
	for(i=0;i<count;i++)
	{
		if(asgn[i]==cid)
		{
			flag=false;
		}
	}
	return flag;
}

bool auth()
{
	int i=0;
	char user_name[20];
	char password[20];
	system("cls");
	line('=',0,79);
	cout<<"\t\t\t\tInstitute Name\n";
	line('=',0,79);
	cout<<"\n\n\t\t\tLog In\n";
	line('=',23,30);
	cout<<"\n\n\n\t\tUsername\t:\t";
	cin>>user_name;
	cout<<"\n\t\tPassword\t:\t";
	
	password[-1]=3;
	for(i=0;password[i-1]!=13;i++)
	{
		password[i]=getch();
		cout.put('*');
	}
	password[i]='\0';
	
	man m;
	ifstream file;
	bool user=false;
	bool pass=false;
	file.open("D:\\Student_Management\\\lpt1\\DB",ios::binary);
	file.seekg(0,ios::beg);
	while(file.read((char*)&m,sizeof(m)))
	{
		if(m.user_flag==true)
		{
			if(compare(m.u.user_name,user_name))
			{
				user=true;
				if(compare(m.u.password,password))
				{
					pass=true;
				}
			}
		}
	}
	return pass&&user;
}

bool compare(char *big,char*a)
{
	int i=0;
	while(big[i]!='\0')
	{
		if(big[i]!=a[i])
		{
			return false;
		}
		i++;
	}
	return true;
}

void start()
{
	ifstream file;
	file.open("D:\\Student_Management\\\lpt1\\DB",ios::binary);
	if(!file)
	{
		create_space();
		file.close();
		system("cls");
		line('=',0,79);
		cout<<"\t\t\t\tInstitute Name\n";
		line('=',0,79);
		cout<<"\n\t\tRegister First Time\n";
		line('=',16,34);
		add(1);
		cout<<"\n\nNew User Generated please Restart\n\n";
		system("pause");
	}
	else
	{
		
		over();
		file.close();
		while(!auth())
		{
			cout<<"\n\n\tInvalid Details\n\n";
			system("pause");
		}
		menu m;
		m.main_menu();
	}
}

void create_space()
{
	system("md C:\\Student_Management\\\lpt1\\");
	system("md D:\\Student_Management\\\lpt1\\");
	system("md E:\\Student_Management\\\lpt1\\");
	system("md F:\\Student_Management\\\lpt1\\");
}

void backup()
{
	cout<<"\n\tBacking Up Database.......\n\n\n\t\t";
	man n;
	ifstream ifile;
	ofstream ofile1;
	ofstream ofile2;
	ofstream ofile3;
	ofstream ofile4;
	ifile.open("D:\\Student_Management\\\lpt1\\DB",ios::binary);
	ofile1.open("C:\\Student_Management\\\lpt1\\BACKUP",ios::trunc|ios::binary);
	ofile2.open("D:\\Student_Management\\\lpt1\\BACKUP",ios::trunc|ios::binary);
	ofile3.open("E:\\Student_Management\\\lpt1\\BACKUP",ios::trunc|ios::binary);
	ofile4.open("F:\\Student_Management\\\lpt1\\BACKUP",ios::trunc|ios::binary);
	while(ifile.read((char*)&n,sizeof(n)))
	{
		ofile1.write((char*)&n,sizeof(n));
		ofile2.write((char*)&n,sizeof(n));
		ofile3.write((char*)&n,sizeof(n));
		ofile4.write((char*)&n,sizeof(n));
	}
	ifile.close();
	ofile1.close();
	ofile2.close();
	ofile3.close();
	ofile4.close();
}

void head()
{
		line('=',0,79);
		cout<<"\t\t\t\tInstitute Name\n";
		line('=',0,79);
		cout<<"\n";
}

void over()
{
	if(get_new_id()>30)
	{
		system("cls");
		cout<<"\n\n\nYou have used more than 30 Unique Ids.\n\nTo Unlock email me.\n\n\nSee About.";
		system("pause");
		menu m;
		m.about();
		exit(0);
	}
	return;
}

int main()
{
	start();
	return 0;
}
