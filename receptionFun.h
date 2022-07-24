#include<bits/stdc++.h>
#include<conio.h>
#include<string>
#include "room.h"
#include "customer.h"
#include "history.h"
using namespace std;
using namespace rooms;
using namespace customers;
using namespace History;

namespace functions{
	
	class action{
		history h;
		//booking of room 
	    bool checkUnoccupancy(int rNO);
		void bookARoom();
		void saveData(string status,mountainViewRoom mvr , customer cust);
		void saveData2(string status,oneBedRoom ovr , customer cust);
		void saveData3(string status,threeBedRoom tvr , customer cust);
		//checkout
		bool checkOccuancy(int rNo);
		void checkout();
		//check for unoccupied rooms
		void AllUnoccupied();
		//check for occupied rooms
		void AllOccupied();
		
		
		public:
		void mainMenu();
	};
	
	    //check unoccupancy of the room 
	    //with perticular room no
	
		bool action::checkUnoccupancy(int rNo){
			fstream f;
			string status;
			f.open(to_string(rNo)+".txt",ios::in);
			f>>status;
			
			if(status == "unoccupied")	return true;
			else  return false;
	    }
	    
	
	    void action::saveData(string status,mountainViewRoom mvr , customer cust){
				int price ; char state[15],roomType[10]; 
				fstream f;
				f.open(to_string(mvr.getRoomNo())+".txt",ios::in);
				f.getline(state,15);
				f.getline(roomType,10);
				f>>price;
				f.close();
				
				f.open(to_string(mvr.getRoomNo())+".txt",ios::out);
				f<<status<<endl<<mvr.getRoomType()<<endl<<price<<endl;
				f<<cust.getName()<<endl<<cust.getAddress()<<endl<<cust.getMobile()<<endl;
				f.close();
				
				//save to history of all customer data .....
				h.checkInHistory(mvr.getRoomNo(),mvr.getRoomType(),cust.getName(),cust.getAddress(),cust.getMobile());
				
				cout<<"\n Room is booked...!!!\n";
		    	cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";
				getch();
		        mainMenu();        
		
	    }
	
	    void action::saveData2(string status,oneBedRoom ovr , customer cust){
				int price ; char state[15],roomType[10]; 
				fstream f;
				f.open(to_string(ovr.getRoomNo())+".txt",ios::in);
				f.getline(state,15);
				f.getline(roomType,10);
				f>>price;
				f.close();
				
				f.open(to_string(ovr.getRoomNo())+".txt",ios::out);
				f<<status<<endl<<ovr.getRoomType()<<endl<<price<<endl;
				f<<cust.getName()<<endl<<cust.getAddress()<<endl<<cust.getMobile()<<endl;
				f.close();
				
				//save to history of all customer data .....
				h.checkInHistory(ovr.getRoomNo(),ovr.getRoomType(),cust.getName(),cust.getAddress(),cust.getMobile());
				
				cout<<"\n Room is booked...!!!\n";
		    	cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";
				getch();
		        mainMenu(); 
		}
	
		void action::saveData3(string status,threeBedRoom tvr , customer cust){
				int price ; char state[15],roomType[10]; 
				fstream f;
				f.open(to_string(tvr.getRoomNo())+".txt",ios::in);
				f.getline(state,15);
				f.getline(roomType,10);
				f>>price;
				f.close();
				
				f.open(to_string(tvr.getRoomNo())+".txt",ios::out);
				f<<status<<endl<<tvr.getRoomType()<<endl<<price<<endl;
				f<<cust.getName()<<endl<<cust.getAddress()<<endl<<cust.getMobile()<<endl;
				f.close();
				
				//save to history of all customer data .....
				h.checkInHistory(tvr.getRoomNo(),tvr.getRoomType(),cust.getName(),cust.getAddress(),cust.getMobile());
				
				
				cout<<"\n Room is booked...!!!\n";
		    	cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";
				getch();
		        mainMenu(); 
		}
	
	void action::bookARoom(){
		 system("cls");
		 int choise;
		 // room and stayer person details
		 char status[15], roomType[10], name[50],address[800];
		 int price,roomno;
		 unsigned long long mobile;
		 
		 fstream f;
		 cout<<"\nwhich type of room you want to book\nPress 1 for MOUNTAIN VIEW ROOMS\n";
		 cout<<"Press 2 for ONE BED ROOMS \nPress 3 for THREE BED ROOMS"<<endl;
		 
		 cin>>choise;
		 
		 switch(choise){
		 	case 1:	
			    label2: 	 		
		 		cout << "Enter room no from 301 to 305 : ";
				cin>>roomno;
		 		if(roomno<301 || roomno>305){
		 			 cout<< "please enter a valid room no";
		 			 cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";
		 			 getch();
		 			 system("cls");
		 			 goto label2;
				 }
		 		  
		 		
		 	    // checking avability of that room no ;
				 if(checkUnoccupancy(roomno)){
					mountainViewRoom mvr1(roomno);   // creating object of a m.v. room 
			 		customer  cust;   //creating object of customer
			 		
			 		cout<<"\n Enter Customer Detalis";
					cout<<"\n ----------------------"<<endl;
					cin.ignore() ; // to remove input buffer 
					cout<<" Name: ";
					cin.getline(name,50);
					cout<<" Address: ";
					cin.getline(address,800);
					cout<<" Phone No: ";
					cin>>mobile;
					
					cust.SetPerson(name,address,mobile); // seting person detail in customer object 
					saveData("occupied",mvr1,cust);
				}
				else {
				 	cout << "this room is not available for booking please select any other room no\n ";
				 	cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";
				 	getch();
				 	system("cls");
				 	goto label2;
				}
				break;
				 
			case 2:
				label3: 
		 		cout << "Enter room no from 101 to 110 : ";
				cin>>roomno;
		 		if(roomno<101 || roomno>110){
		 			 cout<< "please enter a valid room no";
		 			 cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";
		 			 getch();
		 			 system("cls");
		 			 goto label3;
				 }
		 		  
		 		
		 	    // checking avability of that room no ;
				 if(checkUnoccupancy(roomno)){
					oneBedRoom ovr(roomno);   // creating object of a m.v. room 
			 		customer  cust;   //creating object of customer
			 		
			 		cout<<"\n Enter Customer Detalis";
					cout<<"\n ----------------------"<<endl;
					cin.ignore() ; // to remove input buffer 
					cout<<" Name: ";
					cin.getline(name,50);
					cout<<" Address: ";
					cin.getline(address,800);
					cout<<" Phone No: ";
					cin>>mobile;
					
					cust.SetPerson(name,address,mobile); // seting person detail in customer object 
					saveData2("occupied",ovr,cust);
				 }else {
				 	cout << "this room is not available for booking please select any other room no\n ";
				 	cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";
				 	getch();
				 	system("cls");
				 	goto label3;
				 } 	
				 break;
				 
			case 3:
			    label4:
		 		cout << "Enter room no from 201 to 205 : ";cin>>roomno;
		 		if(roomno<201 || roomno>205){
		 			 cout<< "please enter a valid room no";
		 			 cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";
		 			 getch();
		 			 system("cls");
		 			 goto label4;
				 }
		 		  
		 		
		 	    // checking avability of that room no ;
				 if(checkUnoccupancy(roomno)){
					threeBedRoom tvr(roomno);   // creating object of a m.v. room 
			 		customer  cust;   //creating object of customer
			 		
			 		cout<<"\n Enter Customer Detalis";
					cout<<"\n ----------------------"<<endl;
					cin.ignore() ; // to remove input buffer 
					cout<<" Name: ";
					cin.getline(name,50);
					cout<<" Address: ";
					cin.getline(address,800);
					cout<<" Phone No: ";
					cin>>mobile;
					
					cust.SetPerson(name,address,mobile); // seting person detail in customer object 
					saveData3("occupied",tvr,cust);
				 }else {
				 	cout << "this room is not available for booking please select any other room no\n ";
				 	cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";
				 	getch();
				 	system("cls");
				 	goto label4;
				 }
				 break;
			
			default :
			    cout<<"enter a valid input ";
			    cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";
				getch();
				system("cls");
				mainMenu();
		 }
	}

  //function for checkout 
  // first we check
  // that the room is really occupied 
  //or not, then is it is
  //occupied then we perform checkout 	
	
	
bool action::checkOccuancy(int rNo){
       	fstream f;
		string status;
		f.open(to_string(rNo)+".txt",ios::in);
		f>>status;
		
		if(status == "occupied"){
			return true;
		}  
		else{
			return false;
		} 
}

// function for checkout 

void action::checkout(){
	        	int roomno;
	        		label2: 
		 		cout << "\t\t\t\t\tEnter room no from 101 to 110 or 201 t0 205 or 301 to 305 : ";
			    cin>>roomno;
				
				if(checkOccuancy(roomno)){
						int price ; char status[15],roomType[10],name[50],address[800]; 
						int amount;
						unsigned long long mobile;
						fstream f;
						f.open(to_string(roomno)+".txt",ios::in);
						f.getline(status,15);
						f.getline(roomType,10);
						f>>price;
						f.getline(name,50); f.getline(address,800);
						f>>mobile;
						f.close();
						cout <<"Enter amount the customer pays (no of days * "<<price<<") : ";
						cin>>amount;
						f.open(to_string(roomno)+".txt",ios::out);
						f<<"unoccupied"<<endl<<roomType<<endl<<price<<endl;
						f<<"noone"<<endl<<"nowhere"<<endl<<9876543210<<endl;
						f.close();
						
						//save to history of all customer data .....
		                h.checkOutHistory(roomno,roomType,name,address,mobile,amount);
		
		
						cout<< "\t\t\t\t\tRoom no "<<roomno<<" is unoccupied now the person in this room have checkout just.";
						cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";
						getch();
						system("cls");
						mainMenu();
						
				}else{
					cout<< "this room is already empty ";
					cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";
					getch();
					system("cls");
					goto label2;
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
		 
		 
		 //mainmenu for reception
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
			cout<<"\n\n\n\t\t\t1.Book A Room";
			cout<<"\n\t\t\t2.Check Out ";
			cout<<"\n\t\t\t3.All Unoccupied Rooms";
			cout<<"\n\t\t\t4.All Occupied Room Details";
			cout<<"\n\t\t\t5.Exit";
			cout<<"\n\n\t\t\tEnter Your Choice: ";
			cin>>choice;
	
			switch(choice)
			{
			
			case 1:	bookARoom();
			break;
			
			case 2: checkout();
			break;
			
			case 3: AllUnoccupied();
			break;
			
			case 4:	AllOccupied();
			break;
			
			case 5: return ;
			
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
		
	
}



