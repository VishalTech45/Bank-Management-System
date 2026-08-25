#include<iostream>
#include<string>
#include<vector>
#include<map>

//Create a Class Customer to  fetch all about Customer Details
class Customer{
    int customer_id ;
    std::string customer_name ;
    std::string customer_address ;
    std::string customer_phone_no ;

    public: // access Classifier
    
    // custructor to initialize the Customer object 
    Customer(int id , std::string name , std::string address , std::string phone ){
        customer_id = id ;
        customer_name = name ;
        customer_address = address ;
        customer_phone_no = phone;
    }

    // Creating a method to Display Details of Customer 
      void Display_Details(){
        std::cout <<"============================================="<< std::endl;
         std::cout <<"          Customer Details                   "<< std::endl;
         std::cout<<"=============================================="<< std::endl;
        std:: cout<<"Customer ID : "<<customer_id<< std::endl;
        std:: cout<<"Customer Name : "<<customer_name<< std::endl;
         std::cout<<"Customer Address : "<<customer_address << std::endl;
         std::cout<<"Customer Phone No. : "<<customer_phone_no ;
    }
};

// Created a Account class to fetch information about any customer account
class  Account{
    // private attributes
    long long acc_num ;  // Attributes 
    double  balance ;   
    Customer* owner ;

    public:
    // Custructor  to get attributes values
    Account(long long num , double initial_balance   , Customer *cust){
        acc_num = num ;
        balance = initial_balance ;
        owner = cust ;

    } 

    // Creating a method with deposit_amount parameter 
     void deposit(double deposit_amount){
        if(deposit_amount >= 150000){
         std::cout<<"Give me Varification Code : ";

        balance = balance + deposit_amount ;
         std::cout<<"Deposit Successfully! New Balance = "<<balance << std::endl;
        }else{
             std::cout <<"Enter a Positive Deposit Amount";
           
        }     
    }

    virtual  void withdraw()= 0 ;

     void checkBalance(){
        std::cout<<"" ;
    }

     void display_Account_Details(){}
    
};

// Account class inherited
class SavingsAccount : public Account{

    public:
    // Inherit  Account custructor
    SavingsAccount(long long num , double initial_balance , Customer* cust):Account( num , initial_balance ,cust){}
     void  calculateInterest(){}
     void withdraw(){} 

};


// Account class Inherited 
class CurrentAccount: public Account{

    public:
    // Inherit  Account custructor
    CurrentAccount(long long num , double initial_balance , Customer* cust):Account( num , initial_balance ,cust){}

       void withdraw(){}

};

class Transaction {
     int  transactionId ;
    std::string transaction_Type;
     long long balance ;
    std::string  date ;

    public:
    long long acc_num ;
    
     void   displayTransaction() {}

};

class Bank{

    public:
    std::vector<Account*> accounts ;
    std::map<long long , Account*> accountMap;

    void CreateAccount(){ }

     void findAccount(){}

     void deposit() {}

     void withdraw(){}

      void closeAccount(){}

      void list_Accounts(){}


};

// int main(){
//     std::double deposit_amount ;
//     std::cout<<"Enter Deposit Amount : ";
//     std::cin >>deposit_amount;
//     Account acc ;
//     acc.deposit(deposit_amount);

//     return 0;
// }
int main(){
   int  n ;
     std::cout<<"hello world"<<std::endl ;

    return 0;
}