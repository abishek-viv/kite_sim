/* Simulator for firing orders,takes client id ,client and scrip name and fires the order for multiple persons at a time. 
	Though certain functionalities can be extended here it is not included for easy analysing.....meme is pronounced as miim.
*/
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

string scrip_name="JUSTDIAL";
double entry_price;
double exit_price;

class client_details{
		//string login_passwd;
		//string 2_fa;
		
	public:
		string client_name;
		string client_id;
		string scrip_name_temp;
		//double entry_price;
		//double exit_price;
};

class fire_order_functions: public client_details {					//child class inheriting the parent for variable access
	public:
		void pre_order_details(){										
			cout << "firing order for:" << client_name << endl;
			cout << "client ID:" << client_id<< endl;
		}

		void buy(){
			pre_order_details();										
			cout << "order placed for :"<< scrip_name_temp << endl;
			cout << "entry price: " << entry_price << endl;
			//cout << ""

		} 

		void sell(){
			cout << "placing counter order for:" << scrip_name_temp << endl;
			cout << "exit price:" << exit_price << endl; 

		}
		fire_order_functions(string,string);						//constructor for initializig the client details through mapping
		
};

fire_order_functions::fire_order_functions(string cl_name,string cl_id){

			//fire_order_functions FIRE_odr_1;
			//fire_order_functions FIRE_odr_2;

			client_name= cl_name;
			client_id= cl_id;
			scrip_name_temp=scrip_name;
			
		}

int main()
{   fire_order_functions FIRE_odr_1("CLIENT1","RA3113");             // client details being passed to the constructor
	fire_order_functions FIRE_odr_2("CLIENT2","QW9112");
	
	//client_details cld;	

	for(int i=500;i<=527;i++){										//for loop for simulating the price movement in the market					

		cout << "current price:" << i <<endl;
		sleep(1);
		if(i==512){													//making sure the buy order is placed					
			//client_map_init();
			cout << "===========" << endl;
			FIRE_odr_1.buy();	
			cout << "===========" << endl;
			FIRE_odr_2.buy();
			cout << "===========" << endl;
		}
		else if(i==523){											//making sure the sell order is placed if the tgt is met
			cout << "===========" << endl;
			FIRE_odr_1.sell();
			cout << "===========" << endl;
			FIRE_odr_2.sell();
			cout << "===========" << endl;

		}
		else{

			continue;
		}
	}

	return 0;
}