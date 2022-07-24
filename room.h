#include<bits/stdc++.h>
using namespace std;

namespace rooms{
	
	class room{
		 private:
		 	int roomNo;
		 	int price;
		 	string type;
		    

		public:
			// constructor
			room(){
				this->roomNo = 0;
				this->price = 0 ;
				this->type = "none";
			}
			
			
			void setRoomNo(int no){
				 this->roomNo = no;
			}
			void setRoomPrice(int price){
				this->price = price;
			}
			void setRoomType(string s){
				this->type = s;
			}
			int getRoomNo(){
				return roomNo;
			}
			string getRoomType(){
				return this->type;
			}
			int getRoomPrice(){
				return price;
			}
			
			
			
			//to make it abstract function make a pure virtual function;
			virtual void fun1()=0;   // now room is a abstract class and no objects can be formed
			                          // of room class.
	
			//destructor 
			~room(){
              delete &roomNo;
              delete &price ;
			}
	};
	
	// mountain view rooms class
	class mountainViewRoom:public room{
		 
		 public:
		 	mountainViewRoom(int no){
		 		room::setRoomNo(no);
		 		room::setRoomType("MVR");
			 }
			 
			 //hiding the fun1 of parent class
			 void fun1(){
			 	cout<< "hiding the fun1 of parent class";
			 }
	};
	
	// 1 bed room class
	class oneBedRoom: public room{
		 
		 public:
		 		oneBedRoom(int no){
			 		room::setRoomNo(no);
			 		room::setRoomType("OBR");
				 }
				 void fun1(){
				 	cout<< "hiding the fun1 of parent class";
				 }
	};
	
	// 3 bed room class
	class threeBedRoom: public room{

		 public:
		 		threeBedRoom(int no){
			 		room::setRoomNo(no);
			 		room::setRoomType("TBR");
				 }
				 void fun1(){
				 	cout<< "hiding the fun1 of parent class";
				 }
	};
	
	
}
