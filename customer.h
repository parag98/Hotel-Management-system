#include<bits/stdc++.h>
using namespace std;

namespace customers{

 class customer{
    	private:
		    string name,address;
		    unsigned long long mobile;
		
		public:
			customer(){           // constructor
				name="root";address="rootpur";
		        mobile=9012345678;
			}
			
			void SetPerson(string name,string add ,  unsigned long long phone){
				this->name = name;
				this->address = add ;
				this->mobile = phone;
			}
			
			string getName(){
				return this->name;
			}
			
			string getAddress(){
				return this->address;
			}
			
			 unsigned long long getMobile(){
				return this->mobile;
			}    
			
				     
	};
	
	
	
}
