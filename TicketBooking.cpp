#include <bits/stdc++.h>
using namespace std;
static bool a1[20];
static bool a2[20];
static bool b1[10];
static bool b2[10];
class book
{
public:
	string name;
	int a,screen_no,rate,no_of_seats;
	vector<int> k;
	int cost;
	book()
	{
		for(int i=0;i<20;i++)
		{
			a1[i]=false;
		

			a2[i]=false;
		}
		for(int i=0;i<10;i++)
		{
			b1[i]=false;
			b2[i]=false;
		}
	}
	void get_name()
	{
		cout<<"Enter your name: ";
		cin>>name;
	}
	void get_screen()
	{
		cout<<"Enter the screen number: ";
		cin>>screen_no;
	}
	void get_rate()
	{
		cout<<"Enter the class(1 or 2): ";
		cin>>rate;
	}
	void get_tickets()
	{
		cout<<"Enter the number of tickets: ";
		cin>>no_of_seats;
	}
	void book_tickets()
	{
		for(int i=0;i<no_of_seats;i++)
		{
			int l;
			cout<<"Enter the seat number "<<i+1<<": ";
			cin>>l;
			k.push_back(l);
			if(screen_no==1)
			{
				if(a==20)
					a1[l-1]=true;
				else
					b1[l-1]=true;
			}
			else
			{
				if(a==20)
					a2[l-1]=true;
				else
					b2[l-1]=true;
			}

		}
		cost=(a==20)?no_of_seats*120:no_of_seats*10;
	}
};
class availability:public book
{
public:
	int count;
	void show_tickets()
	{
		count=0;
		a=(rate==120)?20:10;
		if(screen_no==1)
		{
			if(a==20)
				for(int i=0;i<a;i++)
				{
					if(a1[i]==false)
						{
							cout<<i+1<<" ";
							count++;
						}
					if(i%4==0)
						cout<<endl;
				}
			else
				for(int i=0;i<a;i++)
				{
					if(b1[i]==false)
						{
							cout<<i+1<<" ";
							count++;
						}
					if(i%4==0)
						cout<<endl;
				}
		}
		if(screen_no==2)
		{
			a=(rate==120)?a=20:a=10;
			if(a==20)
				for(int i=0;i<a;i++)
				{
					if(a2[i]==false)
					{
						cout<<i+1<<" ";
						count++;
					}
					if(i%4==0)
						cout<<endl;
				}
			else
				for(int i=0;i<a;i++)
				{
					if(b2[i]==false)
					{
						cout<<i+1<<" ";
						count++;
					}
					if(i%4==0)
						cout<<endl;
				}
		}
		cout<<endl;
	}
	void seat_check()
	{
		block:
		if(count>=no_of_seats)
			book_tickets();
		else
		{
			cout<<"limit exceeded"<<endl;
			get_tickets();
			goto block;
		}
	}
};
class display:public book
{
public:
	void print_summary()
	{
			cout<<"Ticket Summary:"<<endl;
			cout<<"Customer Name: "<<name<<endl;
			cout<<"Screen "<<screen_no<<endl;
			cout<<"Booked seats are: ";
			for(int i=0;i<no_of_seats;i++)
				cout<<k[i]<<" ";
			cout<<endl<<"TOTAL : "<<cost<<endl;
	}
};
int main()
{
	book *b,base;
	book *temp;
	int c=0;
	b=new book [20];
	temp=b;
	while(1)
	{
		cout<<"1.User\t2.Admin:\n";
		int j;
		cin>>j;
		switch(j)
		{
		case 1:
			b->get_name();
			cout<<"enters\n";
			b->get_screen();
			b->get_rate();
			((availability *)b)->show_tickets();
			b->get_tickets();
			((availability *)b)->seat_check();
			((display *)b)->print_summary();
			int i;
			cout<<"1.continue\t2.exit:\n";
			cin>>i;
			switch(i)
			{
				case 1:
				c++;
				b++;
				break;
				default:
					exit(1);
			}
			break;
		case 2:
			for(int i=0;i<c;i++)
			{
				((display *)temp)->print_summary();
				cout<<endl;
				temp++;
			}
			temp=temp-c;
			break;
		}
	}				
	return 0;
}
