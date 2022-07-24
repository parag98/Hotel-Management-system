#include<bits/stdc++.h>
#include<conio.h>
#include <string>
#include "history.h"

using namespace std;
using namespace History;

namespace adminFun{
	
	class action{
		 
	    history h;   // object of history class in history.h header file
	    bool checkUnoccupancy(int rNO);
		void changeRoomStatus();
		void changeRoomPrice();
		
		//check for unoccupied rooms
		void AllUnoccupied();
		//check for occupied rooms
		void AllOccupied();
		//check for all not for service rooms
		void AllNotForServiceRooms();
				
		public:
		void mainMenu();
	};
	
	// function for check unoccupancy of a room
	bool action::checkUnoccupancy(int rNo){
			fstream f;
			string status;
			f.open(to_string(rNo)+".txt",ios::in);
			f>>status;
			
			if(status != "occupied")	return true;
			else  return false;
	    }
	
	
//	  for change room 
//	  status of any unoccupied room,
//    if the room is not prepared or
//	  book for vip
//	  or any other reason

    void action::changeRoomStatus(){
    	  system("cls");
		 // room and stayer person details
		 int roomno;
		 fstream f;
		 label2: 	 		
		 cout << "Enter room no from 101 to 110 or 201 to 205 or 301 to 305 whose status you whant to change : ";
	   	 cin>>roomno;
	   	        if(checkUnoccupancy(roomno)){
	   	        	char status[15];
	   	        	char state[15],roomType[10];
	   	        	int price;
			 		cout <<"what is status want to write (* less then 15 character) : ";
			 		cin.ignore();
			 		cin>>status;
			 		f.open(to_string(roomno)+".txt",ios::in);
			 		f>>state; f>>roomType; f>>price;
			 		f.close();
			 		
			 		f.open(to_string(roomno)+".txt",ios::out);
					f<<status<<endl<<roomType<<endl<<price<<endl;
					f<<"noone"<<endl<<"nowhere"<<endl<<9876543210<<endl;
					f.close();
					
					cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";
					getch();
					system("cls");
					mainMenu();			 		
				}
				else {
				 	cout << "this room is currently booked please select any other room no\n ";
				 	cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";
				 	getch();
				 	system("cls");
				 	goto label2;
				}
	}
	
//	for change the price 
//	of the room of any unoccupied room 

    void action::changeRoomPrice(){
    	  system("cls");
		 // room and stayer person details
		 int roomno;
		 fstream f;
		 label3: 	 		
		 cout << "Enter room no from 101 to 110 or 201 to 205 or 301 to 305 : ";
	   	 cin>>roomno;
	   	        if(checkUnoccupancy(roomno)){
	   	        	char state[15],roomType[10];
	   	        	int price;
			 		cout <<"what is New price : ";
			 		cin>>price;
			 		f.open(to_string(roomno)+".txt",ios::in);
			 		f>>state; f>>roomType;
			 		f.close();
			 		
			 		f.open(to_string(roomno)+".txt",ios::out);
					f<<state<<endl<<roomType<<endl<<price<<endl;
					f<<"noone"<<endl<<"nowhere"<<endl<<9876543210<<endl;
					f.close();	
					
					
					cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";
					getch();
					system("cls");
					mainMenu();		 		
				}
				else {
				 	cout << "this room is currently booked please select any other room no\n ";
				 	cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";
				 	getch();
				 	system("cls");
				 	goto label3;
				}
	
	}
	
	  // function to get all unoccupied rooms
		 
	void action::AllUnoccupied(){
		  cout<<"\n\n\t\t\t\tAll unoccupied rooms are as follows\n\n\n";
		  int i=101;
		  while(i<306){
		  	 string status,type,rType;
			 int price;
		  	 fstream f;
		  	 f.open(to_string(i)+".txt",ios::in);
		  	 f>>status; f>>type; f>>price;
		  	 if(type=="MVR") rType="Mountain View Room";
		  	 else if(type == "OBR") rType="One Bed Room";
		  	 else rType = "Three Bed Room";
		  	 if(status=="unoccupied"){
		  	 	cout<<"\t\t"+rType +"\t\t"<<i<<"\t\t"<<price<<"\n\n";
		     }
		  	
		  	
		  	if(i==110) i=201;
			else if(i==205) i=301;
			else i++;
		  }
		  
		    cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";
			getch();
			system("cls"); 
			mainMenu();
	}	 
	
	
	//function to get all occupied room
	
	void action::AllOccupied(){
		cout<<"\n\n\t\t\t\tAll unoccupied rooms are as follows\n\n\n";
		  int i=101;
		  while(i<306){
		  	 string status,type,rType;
		  	 char name[50], address[800];
		  	 unsigned long long mobile;
			 int price;
		  	 fstream f;
		  	 f.open(to_string(i)+".txt",ios::in);
		  	 f>>status; f>>type; f>>price;
		  	 f.ignore();
		  	 f.getline(name,50); f.getline(address,800);
		  	 f>>mobile;
		  	 if(type=="MVR") rType="Mountain View Room";
		  	 else if(type == "OBR") rType="One Bed Room";
		  	 else rType = "Three Bed Room";
		  	 if(status=="occupied"){
		  	 	cout<<"\t\tRoomType : "+rType +"\t\tRoomNo : "<<i<<"\t\tRent : "<<price<<endl;
		  	 	cout<<"\t\tName : "<<name<<"\t\t\taddress : "<<address<<"\t\t mobile : "<<mobile<<"\n\n\n";
		     }
		  	
		  	
		  	if(i==110) i=201;
			else if(i==205) i=301;
			else i++;
		  }
		  
		    cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";
			getch();
			system("cls"); 
			mainMenu();
	}
		 
    // function to show all rooms which are not
    //available for booking due to any reason
		 
    void action::AllNotForServiceRooms(){
    	cout<<"\n\n\t\t\t\tAll NOt For Service rooms are as follows\n\n\n";
		  int i=101;
		  while(i<306){
		  	 string status,type,rType;
			 int price;
		  	 fstream f;
		  	 f.open(to_string(i)+".txt",ios::in);
		  	 f>>status; f>>type; f>>price;
		  	 if(type=="MVR") rType="Mountain View Room";
		  	 else if(type == "OBR") rType="One Bed Room";
		  	 else rType = "Three Bed Room";
		  	 if(status !="unoccupied" && status !="occupied"){
		  	 	cout<<"\t\t"+rType +"\t\t"<<i<<"\t\t"<<price<<"\n\n";
		     }
		  	
		  	
		  	if(i==110) i=201;
			else if(i==205) i=301;
			else i++;
		  }
		  
		    cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";
			getch();
			system("cls"); 
			mainMenu();
	}
		 //mainmenu  for admin
		 //the options in switch
		 //case 
		 
void action::mainMenu()
	{
	
		int choice;
		label1:
		while(choice!=5)
		{
	
			  system("cls");
			cout<<"\n\t\t\t\t*************************";
			cout<<"\n\t\t\t\t SIMPLE HOTEL MANAGEMENT ";
			cout<<"\n\t\t\t\t      * MAIN MENU *";
			cout<<"\n\t\t\t\t*************************";
			cout<<"\n\n\n\t\t\t1.Change Room Status of a unoccupid room";
			cout<<"\n\t\t\t2.Change Room Price of a unoccupid room ";
			cout<<"\n\t\t\t3.All Unoccupied Rooms";
			cout<<"\n\t\t\t4.All Occupied Room Details";
			cout<<"\n\t\t\t5.All Rooms which are not available for service";
			cout<<"\n\t\t\t6.Show the history";
			cout<<"\n\t\t\t7.Exit";
			cout<<"\n\n\t\t\tEnter Your Choice: ";
			cin>>choice;
	
			switch(choice)
			{
			
			case 1:	changeRoomStatus();
					break;
			
			case 2: changeRoomPrice();
					break;
			
			case 3: AllUnoccupied();
			break;
			
			case 4:	AllOccupied();
					break;
			
			case 5: AllNotForServiceRooms();
			        break;
				  
			case 6: h.showHistory();
			        break;
			        
			case 7: return ;
			
			default:
				{
				cout<<"\n\n\t\t\tWrong choice.....!!!";
				cout<<"\n\t\t\tPress any key to   continue....!!";
				getch();
				goto label1;
				}
			
			}
	
	    }
	
	}
	
	
	
	//end of namespace
}
