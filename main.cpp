#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std ;


class Customer{
    int customer_id ;
    string customer_name ;
    string customer_address ;
    string customer_phone_no ;
    public: // access Classifier
    
    // custructor
    Customer(int id , string name , string address , string phone ){
        customer_id = id ;
        customer_name = name ;
        customer_address = address ;
        customer_phone_no = phone;
    }


    void Display_Details(){

    }

    // friend class Account ;


};

class  Account{
    long long acc_num ;
    double  balance ;
    Customer* owner ;
    public:
    // Custructor  to get attributes values
    Account(long long num , double initial_balance , Customer *cust){
        acc_num = num ;
        balance = initial_balance ;
        owner = cust ;

    }

    
    void deposit(){}

    virtual  void withdraw()= 0 ;

    void checkBalance(){}

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
    string transaction_Type;
    long long balance ;
    string  date ;

    public:
    long long acc_num ;
    
    void   displayTransaction() {}

};

class Bank{

    public:
    vector<Account*> accounts ;
    map<long long , Account*> accountMap;

    void CreateAccount(){ }

    void findAccount(){}

    void deposit() {}

    void withdraw(){}

    void closeAccount(){}

    void list_Accounts(){}


};

int main(){
    
    cout <<"Hello World";

    return 0;
}