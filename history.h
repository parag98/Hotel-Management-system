#include<bits/stdc++.h>
#include <ctime>
using namespace std;


namespace History{
	
	class history{
		// all function are public beacause they all will be used outside of the class
		public:
		   void	checkInHistory(int rNo,string type, string name,string address,unsigned long long mobile);
		   void checkOutHistory(int rNo,string type, string name,string address,unsigned long long mobile,int amount);
		   void showHistory();  
	};
	
	//insert data in history.txt every time a 
	// check in take palace 
	void history::checkInHistory(int rNo,string type, string name,string address,unsigned long long mobile){
		time_t tt;
		struct tm *ti;
		time(&tt);
		ti = localtime(&tt);
		
		fstream f;
		f.open("history.txt",ios::app);
		f<<asctime(ti)<<"\tCheck In \t"<<rNo<<"\t"<<type<<"\t"<<name<<"\t"<<address<<"\t"<<mobile<<endl;
		f.close();
	}
	
	//insert data in history.txt every time a 
	// check out take palace 
	void history::checkOutHistory(int rNo,string type, string name,string address,unsigned long long mobile,int amount){
		time_t tt;
		struct tm *ti;
		time(&tt);
		ti = localtime(&tt);
		
		fstream f;
		f.open("history.txt",ios::app);
		f<<asctime(ti)<<"\tCheck Out \t"<<rNo<<"\t"<<type<<"\t"<<name<<"\t"<<address<<"\t"<<mobile<<"\t"<<amount<<endl;
		f.close();
	}
	
	//show history for admin
	void history::showHistory(){
		fstream f("history.txt",ios::in);
		char date[100],otherDetail[2000];
		
		while(!f.eof())
		{
			f.getline(date,100);
			f.getline(otherDetail,2000);
			cout<<date<<"\t"<<otherDetail<<endl;
		}
		
		cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";
		getch();
		system("cls");
        return ;
		}
	
}

