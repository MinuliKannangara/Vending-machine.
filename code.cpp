#include <iostream>
using namespace std;

int main(){
	int product; // variable for get the product type
	int price;// variale for the prices of products
	int c1,c2,c5,c10; //variables for number of coins
	int cL1,cL2,cL5,cL10; //variables for input insufficient coins
	int total, balance; 
	int B1=100 ,B2=100 ,B5=100 ,B10=100; //coin bins, this bins hhas preloaded 100 coins
	int overflow1,overflow2,overflow5,overflow10 ;// variable for the overflow bin
	int remain;
	int password;
	
	while(B1!=0 || B2!=0 || B5!=0 || B10!=0){
		cout<< "Welcome! \n how may I help you:" << endl;
		cout << "Product A: Enter 1 \n Product B: Enter 2 \n Product C: Enter 3 \n Product D: Enter 4 " <<endl;
		cout<< "Please enter what you want: ";
		cin>> product;
		
		while(!(product>=1 && product<=4)){
			cout <<"Invalid Product Name. \n please reenter " <<endl;
			cout << "Product A: Enter 1 \n Product B: Enter 2 \n Product C: Enter 3 \n Product D: Enter 4 " <<endl;
		    cout<< "Please enter what you want: ";
		    cin>> product;
		}
		
			switch(product){
			case 1:
				cout<< "Price is: Rs 35" <<endl;
				price=35;
				break;
			case 2:
				cout<< "Price is: Rs 43" <<endl;
				price=43;
				break;
			case 3:
				cout<< "Price is: Rs 50" <<endl;
				price=50;
				break;
			case 4:
				cout<< "Price is: Rs 56" <<endl;
				price=56;
				break;	
		}
		
		
		cout<< "Please enter coins : "<< endl;
	
		cout<< "10 coins: ";
		cin>> c10;
		cout<< "5 coins: ";
		cin>> c5;
		cout<< "2 coins: ";
		cin>> c2;
		cout<< "1 coins: ";
		cin>> c1;
		
		//calculate the total amount of money entered by the customer
		total= (1*c1)+(2*c2)+(5*c5)+(10*c10);
		cout <<"total amount of money entered = RS. "<< total <<endl;
		
		int lack; 
		while(total<price){
			lack=price-total;
			cout<< "Rs."<< lack <<"is insufficiant. Please enter remaining balance."<< endl;
			
			cout<< "10 coins: ";
			cin>> cL10;
			cout<< "5 coins: ";
			cin>> cL5;
			cout<< "2 coins: ";
			cin>> cL2;
			cout<< "1 coins: ";
			cin>> cL1;
			
			total=total+(1*cL1)+(2*cL2)+(5*cL5)+(10*cL10);	
		}
		// Add the coins to the coin bins
		for(int i=0; i<c1;i++){
			
			if(B1<200){
				B1=B1+1;
			}
			else{
				overflow1=overflow1+1;
			}
		}
		for(int i=0; i<c2;i++){
			
			if(B2<200){
				B2=B2+1;
			}
			else{
				overflow2=overflow2+1;
			}
		}
		for(int i=0; i<c5;i++){
			
			if(B5<200){
				B5=B5+1;
			}
			else{
				overflow5=overflow5+1;
			}
		}
		for(int i=0; i<c10;i++){
			
			if(B10<200){
				B10=B10+1;
			}
			else{
				overflow10=overflow10+1;
			}
		}
		
		cout<<"________________________________________________________________________________" <<endl;
		
		
		//calculate balance
		if(product==1){
			balance= total-35;
			cout<<"Your balance is: Rs "<< balance << endl;
		}
		else if(product==2){
			balance= total-43;
			cout<<"Your balance is: Rs "<< balance << endl;
		}
		else if(product==3){
			balance= total-50;
			cout<<"Your balance is: Rs "<< balance << endl;	
		}
		else {
			balance= total-56;
			cout<<"Your balance is: Rs "<< balance << endl;	
		}
		
		//giving the balance
		//number of 10 coins
		if(B10<0){
			remain==balance;
		}
		else{
			c10= balance/10;
			cout<<"number of 10 coins:" << c10 << endl;
			B10=B10-c10;  //update the bin b10
			remain=balance%10;
		}
		
		
		
		// number of 5 coins
		if(B5<0 && B10>0){
			remain=balance%10;
		}
		else if(B5<0 && B10<0){
			remain==balance;
		}
		else{
			c5=remain/5;
			cout<<"number of 5 coins:" << c5 << endl;
			B5=B5-c5; //update the bin
			remain=balance%5;
		}
		
		
		
		// number of 2 coins
		if(B2==0 && B5==0 && B10>0){
			remain=balance%10;
		}
		else if(B2<0 && B5>0 && B10<0){
			remain=balance%5;
		}
		else if(B2==0 && B5==0 && B10==0){
			remain=balance;
		}
		else{
			c2=remain/2;
			cout<<"number of 2 coins:" << c2 << endl;
			B2=B2-c2; //update the bin
			remain=balance%2;
		}
		
		
		// number of 1 coins
		c1=remain;
		
		//check wheather the machine can pay the balance when all the other coin bins are empty
		if (B1<remain){      
			cout<<"Sorry for the inconvinience. Machine is going out of change. please collect your money back.  Rs."<<total <<endl;
		}
		else{
			cout<<"number of 1 coins:" << c1 << endl;
		    B1=B1-c1; //update the bin
		}
		
		password==0;
		cout<< "Enter password to terminate(for autorized people only) \n If you are a customer, enter 0 as the password."<< endl;
		cout<<"Password: " <<endl;
		cin>> password;
		
		if(password==1234){
			break;				//terminate the loop by owner.
		}
		cout << endl<< endl;
		
	}
	cout<< endl<< endl;
	
	if(password==1234){
		cout<<"Number of 1 coins in the bin: "<<B1<< endl;
		cout<<"Number of 2 coins in the bin: "<<B2<< endl;
		cout<<"Number of 5 coins in the bin: "<<B5<< endl;
		cout<<"Number of 10 coins in the bin: "<<B10<< endl;
		
	}
	
	
	return 0;
		
		
		
		
}

