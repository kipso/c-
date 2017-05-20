#include <bits/stdc++.h>
using namespace std;
static int seats[]={30,30,30,30};
const char trains[][20]={"satapdhi","pandian","kanyakumari","vaigai"};
const int cost=120;
class booking
{
public:
	string name;
	string train_name;
	int seat,x;
	vector<string> seat_name;
	vector<int> seat_age;
	vector<char> seat_sex;
	void get_name()
	{
		cout<<"Enter your name: ";
		cin>>name;
	}
	void get_train()
	{
		cout<<"Enter the train name: ";
		cin>>train_name;
	}
	void get_seats()
	{
		cout<<"Enter the number of seats: ";
		cin>>seat;
	}
	void get_ticket_details()
	{		
		for(int i=0;i<seat;i++)
		{
			string s;
			int a;
			char y;
			cout<<"Enter the name of the customer"<<i+1<<": ";
			cin>>s;
			seat_name.push_back(s);
			cout<<"Enter the age of the customer"<<i+1<<": ";
			cin>>a;
			seat_age.push_back(a);
			cout<<"Enter the sex of the customer"<<i+1<<"M or F: ";
			cin>>y;
			seat_sex.push_back(y);
		}
	}
};
class Availability:public booking
{
public:
	
	void train_check()
	{
		int flag=0;
		for(int i=0;i<4;i++)
		if((train_name)==trains[i])
		{		
			x=i;
			flag=1;
		}
		if(flag)
			cout<<"Number of Available seats "<<seats[x]<<endl;		
	}
	
	void book_tickets()
	{
		get_ticket_details();
		seats[x]=seats[x]-seat;
	}
	void seat_check()
	{
		if(seats[x]>=seat)
		{
			book_tickets();
			cout<<"seats array"<<seats[x]<<endl;
		}
		else if(seats[x]==0)
			cout<<"No seats available."<<endl;
		else
		{
			cout<<"Only "<<seats[x]<<" seats available"<<endl;
		}
	}	
}a;
class cancel : public booking 
{
public:
	int seat_no;
	void get_seat_no()
	{
	cout<<"Enter The Seat No To Be Cancelled :";
	cin>>seat_no;
	cancellation(seat_no);
	}
	void cancellation(int seat_no)
	{
		for(int i=1;i<=seat;i++)
			if(i==seat_no)
			{
				seat_name.erase(seat_name.begin()+i-1);
				seat_age.erase(seat_age.begin()+i-1);
				seat_sex.erase(seat_sex.begin()+i-1);
				seats[x]=seats[x]+1;
				seat=seat-1;
				cout<<"seats in canc is"<<seat<<endl;
			}
	}

};
class display:public booking
{
public:
	void print()
	{
		cout<<"\nCustomer name: "<<name<<endl;
		cout<<"Train name: "<<train_name<<endl;
		cout<<"Number of seats: "<<seat<<endl;
		cout<<"Ticket details: "<<endl;
		for(int i=0;i<seat;i++)
		{
			cout<<"Name of the customer: "<<*(seat_name.begin()+i)<<endl;
			cout<<"Age of the customer: "<<*(seat_age.begin()+i)<<endl;		
			cout<<"Sex: "<<*(seat_sex.begin()+i)<<endl;
		}
		cout<<"Total cost is: "<<cost*seat<<endl;
	}
};
int main()
{
	booking *b=new booking[30];
	while(1)
	{
		b->get_name();
		b->get_train();
		((Availability *)b)->train_check();
		b->get_seats();
		((Availability *)b)-> seat_check();
		cout<<"seat name is "<<b->seat<<endl;
		((display *)b)->print();
		int i;
		cout<<"\n1.continue Booking\n2.cancellation\n3.exit"<<endl;
		cin>>i;
		switch(i)
		{
			case 1:
				b++;
				break;
			case 2:
				((cancel *)b)->get_seat_no();
				((display *)b)->print();
				break;
			case 3:
				exit(1);
		}
	}
	return 0;
}