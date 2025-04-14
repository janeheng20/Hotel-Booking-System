#include<iostream>
#include<iomanip>
#include <stdlib.h>
using namespace std;

class room
{
	int num;
	string roomtype[3],type[3]; 
	bool availability[10];	

	public:
	room()
	{
		int i;
		type[0]="delux";
		type[1]="normal";
		type[2]="presidential";
		for(i=0;i<10;i++)
		{
			availability[i]=true;
			availability[i]=true;
			availability[i]=true;
		}
	};
	void getnum(int rnum)
	{
		num=rnum;
	}
	void favailability()
	{
		availability[num-1]=false;
	}	
	void tavailability()
	{
		availability[num-1]=true;
	}
	
	friend void display_availabity(int z, room obj[]);
};

class customer
{	
	protected:
	int id,day;
	string phonenum,name;
	
	public:
	customer()
	{
		id=0;
		day=0;
		phonenum="000-000000";
		name="none";
	}
		
	void booking(room obj[], int rnum, int i)
	{
		cout<<"Please enter your id"<<setw(16)<<": ";
		cin>>id;
		cin.ignore();
		cout<<"Please enter your name"<<setw(14)<<": ";
		getline(cin,name);
		cout<<"Please enter your phone number"<<setw(6)<<": ";
		cin>>phonenum;
		cout<<"Please enter day you want to stay : ";
		cin>>day;
		obj[i].getnum(rnum);
		obj[i].favailability();
	}
	
	void checkin()
	{
		int id_check;
		cout<<"Please enter your ID for check-in : "; 
		cin >>id_check;
				
		if(id==id_check)
		{
			cout<<"\nCheck in successfully!"<<endl;
		}
		else
		{
			cout<<"\nCheck-in fail. Please enter your ID or room number correctly."<<endl;
		}
	}	
	
	void checkout(room obj[],int rnum, int i)
	{
		int id_check;
		
		cout<<"Please enter your ID for check-out : "; 
		cin>>id_check;
		
		if(id==id_check)
		{
			cout<<"Check out successfully!"<<endl;
			obj[i].getnum(rnum);
			obj[i].tavailability();
		}				
		else
		{
			cout<<"Check-out fail. Please enter your ID or room number correctly."<<endl;
		}
	}
};

class delux: public customer
{
	float price;
	string type;
	
	public:
	delux()
	{
		type="delux";
		price=35.50;
	}
	
	float rprice()
	{
		return price;
	}
	string rtype()
	{
		return type;
	}
	string rname()
	{
		return name;
	}
	string rphonenum()
	{
		return phonenum;
	}
	int rid()
	{
		return id;
	}
	int rday()
	{
		return day;
	}
};

class normal: public customer
{
	float price;
	string type;
	
	public:
	normal()
	{
		type="normal";
		price=20.50;
	}
	
	float rprice()
	{
		return price;
	}
	string rtype()
	{
		return type;
	}
	string rname()
	{
		return name;
	}
	string rphonenum()
	{
		return phonenum;
	}
	int rid()
	{
		return id;
	}
	int rday()
	{
		return day;
	}
};

class presidential: public customer
{
	float price;
	string type;
	
	public:
	presidential()
	{
		type="presidential";
		price=55.50;
	}

	float rprice()
	{
		return price;
	}
	string rtype()
	{
		return type;
	}
	string rname()
	{
		return name;
	}
	string rphonenum()
	{
		return phonenum;
	}
	int rid()
	{
		return id;
	}
	int rday()
	{
		return day;
	}
};

class bill
{
	float price1,totalp;
	int id1,day1,num;
	string phonenum1,name1,type1;
	
	public:
	bill(int rnum, int i, delux droom[10], normal nroom[10], presidential proom[10])
	{
		num=rnum;
		if(i==0)
		{
			id1=droom[num].rid();
			day1=droom[num].rday();
			price1=droom[num].rprice();
			phonenum1=droom[num].rphonenum();
			name1=droom[num].rname();
			type1=droom[num].rtype();
		}
		else if(i==1)
		{
			id1=nroom[num].rid();
			day1=nroom[num].rday();
			price1=nroom[num].rprice();
			phonenum1=nroom[num].rphonenum();
			name1=nroom[num].rname();
			type1=nroom[num].rtype();
		}
		else if(i==2)
		{
			id1=proom[num].rid();
			day1=proom[num].rday();
			price1=proom[num].rprice();
			phonenum1=proom[num].rphonenum();
			name1=proom[num].rname();
			type1=proom[num].rtype();
		}
	}
	~bill()
	{
		cout<<"\n\nThanks for choose FIVE NINJA HOTEL~~~~~~~~\n";
	}
	
	void display()
	{
		totalp=price1*day1;
		cout<<"\n================================"
			<<"\n		BILL"
			<<"\n================================"
			<<"\n\nName"<<setw(11)<<": "<<name1
			<<"\nID"<<setw(13)<<": "<<id1
			<<"\nPhone Number : "<<phonenum1
			<<"\n\nSelected Room-"
			<<"\nRoom Type"<<setw(6)<<": "<<type1
			<<"\nRoom Number"<<setw(4)<<": "<<num	
			<<"\n\nPrice"<<setw(12)<<": RM"<<fixed<<setprecision(2)<<totalp;
	}
	void forbill()
	{
		int id_check;
		cout<<"Please enter your ID for check the bill : "; 
		cin >>id_check;
				
		if(id1==id_check)
		{
			totalp=price1*day1;
			cout<<"\n================================"
				<<"\n		BILL"
				<<"\n================================"
				<<"\n\nName"<<setw(11)<<": "<<name1
				<<"\nID"<<setw(13)<<": "<<id1
				<<"\nPhone Number : "<<phonenum1
				<<"\n\nSelected Room-"
				<<"\nRoom Type"<<setw(6)<<": "<<type1
				<<"\nRoom Number"<<setw(4)<<": "<<num
				<<"\n\nPrice"<<setw(12)<<": RM"<<fixed<<setprecision(2)<<totalp;
		}
		else
		{
			cout<<"\nCheck Bill fail. Please enter your ID or room number correctly."<<endl;
		}
	}
};

void display_availabity(int z, room obj[])
{
	int i,j,k=0;
	cout<<"\nroom type :"<<obj[z].type[z]<<"\n"
		<<"(room available=1)	(room unavailable=0)\n";
	for(i=0;i<2;i++)
	{
		for(j=0;j<5;j++)
		{
			cout<<"room"<<j+k+1<<"	:"<<obj[z].availability[j+k]<<" 	";
		}
		k=5;	
		cout<<"\n";
	}
}

int main()
{
	customer person;
	room obj[3];
	delux droom[10];
	normal nroom[10];
	presidential proom[10];
	
	char type,condition;
	int rnum,i,choose;
	
	do
	{
		cout<<"Welcome to five ninja hotel\n"
		    <<"what can I help you?\n\n"
		    <<"1.booking\n"
		    <<"2.checking\n"
		    <<"3.check in\n"
		    <<"4.check out\n"
		    <<"5.Bill\n"
		    <<"choose one of these please~~~       : ";
		cin >>choose;  
		cout<<"Enter the room type you want[D/N/P] : ";
		cin >>type;
		
		if(choose==1)
		{
			if(type=='D')
			{
				i=0;
				display_availabity(i,obj);
				cout<<"Enter the room you want[1~10]"<<setw(7)<<": ";
				cin >>rnum;
				droom[rnum].booking(obj,rnum,i);
			}
			else if(type=='N')
			{
				i=1;
				display_availabity(i,obj);
				cout<<"Enter the room you want[1~10]"<<setw(7)<<": ";
				cin >>rnum;
				nroom[rnum].booking(obj,rnum,i);
			}
			else if(type=='P')
			{
				i=2;
				display_availabity(i,obj);
				cout<<"Enter the room you want[1~10]"<<setw(7)<<": ";
				cin >>rnum;
				proom[rnum].booking(obj,rnum,i);
			}
			bill *obja;
			obja= new bill(rnum,i,droom,nroom,proom);
			obja->display();
			delete obja;
		}
		else if(choose==2)
		{
			if(type=='D')
			{
				i=0;
			}
			else if(type=='N')
			{
				i=1;
			}
			else if(type=='P')
			{
				i=2;
			}
			display_availabity(i,obj);
		}
		else if(choose==3)
		{
			cout<<"Enter the room you want to check in[1~10] : ";
			cin >>rnum;
			if(type=='D')
			{
				droom[rnum].checkin();
			}
			else if(type=='N')
			{
				nroom[rnum].checkin();
			}
			else if(type=='P')
			{
				proom[rnum].checkin();
			}
		}
		else if(choose==4)
		{
			cout<<"Enter the room you want to check out[1~10] : ";
			cin >>rnum;
			if(type=='D')
			{
				i=0;
				droom[rnum].checkout(obj,rnum,i);
			}
			else if(type=='N')
			{
				i=1;
				nroom[rnum].checkout(obj,rnum,i);
			}
			else if(type=='P')
			{
				i=2;
				proom[rnum].checkout(obj,rnum,i);
			}
			bill *obja;
			obja= new bill(rnum,i,droom,nroom,proom);
			obja->display();
			delete obja;
		}
		else if(choose==5)
		{
			cout<<"Enter the room you want to check the bill[1~10]";
			cin >>rnum;
			bill *obja;
			obja= new bill(rnum,i,droom,nroom,proom);
			obja->forbill();
			delete obja;
		}
		cout<<"Did you want to continue?[Y/N]";
		cin>>condition;
		system("cls");	
	}while(condition=='Y');
}
