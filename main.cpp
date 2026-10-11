#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <ctime>
#include <stdexcept>
#include <memory>
#include <limits>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <type_traits>
#include <cctype>
using namespace std;

// Create a Class Customer to  fetch all about Customer Details
class Customer
{
    static long long nextCustomerId;

    long long customer_id;
    string customer_name;
    string customer_address;
    string customer_phone_no;

public: // access Classifier
    // custructor to initialize the Customer object
    Customer(string name, string address, string phone)
        : customer_id(nextCustomerId++), customer_name(name),
          customer_address(address), customer_phone_no(phone) {}

    // Constructor used when restoring a customer from persistent storage.
    Customer(long long id, string name, string address, string phone)
        : customer_id(id), customer_name(name),
          customer_address(address), customer_phone_no(phone)
    {
        if (id >= nextCustomerId)
            nextCustomerId = id + 1;
    }

    // Creating a method to Display Details of Customer
    void Display_Details() const
    {

        cout << "------------Customer Details---------------" << endl;

        cout << "Customer ID        : " << customer_id << endl;
        cout << "Customer Name      : " << customer_name << endl;
        cout << "Customer Address   : " << customer_address << endl;
        cout << "Customer Phone No. : " << customer_phone_no << endl;
    }

    // Getters
    long long getCustomerId() const
    {
        return customer_id;
    }
    string getName() const
    {
        return customer_name;
    }

    string getAddress() const
    {
        return customer_address;
    }

    string getPhoneNo() const
    {
        return customer_phone_no;
    }

    // Setters
    void setName(const string &name)
    {
        customer_name = name;
    }

    void setAddress(const string &address)
    {
        customer_address = address;
    }
    void setPhone_no(const string &phone_no)
    {
        customer_phone_no = phone_no;
    }
};

// Initialize static varibaleoutside the class
long long Customer::nextCustomerId = 1001;

// Created a Account class to fetch information about any customer account
class Account
{
private:
    long long acc_num; // account number
    double balance;
    Customer *owner;

protected:
    // Custructor  to get attributes values
    Account(long long num, double initial_balance, Customer *cust) : acc_num(num), balance(initial_balance), owner(cust)
    {

        if (!isfinite(initial_balance) || initial_balance < 0)
        {
            throw invalid_argument("Initial balance must be a finite, non-negative amount.");
        }

        if (cust == nullptr)
        {
            throw invalid_argument("Customer cannot be null");
        }
    }
    bool updatebalance(double newbalance)
    {
        if (newbalance < 0)
        {
            return false;
        }
        balance = newbalance;
        return true;
    }

public:
    // destructor
    virtual ~Account() = default;

    virtual bool withdraw(double amount) = 0;

    // getter
    double getAccountBalance() const
    {
        return balance;
    }
    long long getAccountNumber() const
    {
        return acc_num;
    }
    long long getCustomerId() const
    {
        return owner->getCustomerId();
    }

    void check_Balance() const
    {
        cout << "---------Account details---------" << endl;
        cout << "Account Number : " << acc_num << endl;
        cout << "Account name   : " << owner->getName() << endl;
        cout << "Account balance: " << balance << endl;
    }

    // Creating a method with deposit_amount parameter
    bool deposit(double deposit_amount)
    {
        if (!isfinite(deposit_amount) || deposit_amount <= 0)
        {
            cout << "Enter a valid finite, positive amount.\n";
            return false;
        }
        if (!isfinite(balance + deposit_amount))
        {
            cout << "Deposit rejected: resulting balance would be too large.\n";
            return false;
        }

        balance += deposit_amount;

        cout << "Deposit successful!\n";
        cout << "New Balance: " << balance << endl;

        return true;
    }

    void display_Account_Details() const
    {
        check_Balance();
        cout << "Customer ID: " << owner->getCustomerId() << endl;
    }
};

// Account class inherited
class SavingsAccount : public Account
{

public:
    // Inherit  Account custructor
    SavingsAccount(long long num, double initial_balance, Customer *cust) : Account(num, initial_balance, cust) {}

    void calculateInterest()
    {
        double int_balance = getAccountBalance();

        if (int_balance <= 0)
        {
            cout << "You have no balance.\n";
            return;
        }
        double interest = int_balance * 2.5 / 100;

        if (!updatebalance(int_balance + interest))
        {
            cout << "balce update failed!\n";
            return;
        }

        cout << "Interest Added : " << interest << endl;
        cout << "Updated balance: " << getAccountBalance() << endl;
    }

    bool withdraw(double amount) override
    {
        if (!isfinite(amount) || amount <= 0)
        {
            cout << "Invalid withdrawal amount.\n";
            return false;
        }

        double currentBalance = getAccountBalance();

        if (amount > currentBalance)
        {
            cout << "Insufficient balance!\n";
            return false;
        }

        if (!updatebalance(currentBalance - amount))
        {
            cout << "Balance update failed!\n";
            return false;
        }

        cout << "Withdrawal successful!\n";
        cout << "Remaining Balance: "
             << getAccountBalance() << endl;

        return true;
    }
};

// Account class Inherited
class CurrentAccount : public Account
{

public:
    // Inherit  Account custructor
    CurrentAccount(long long num, double initial_balance, Customer *cust)
        : Account(num, initial_balance, cust) {}

    // Override withdraw
    bool withdraw(double amount) override
    {
        if (!isfinite(amount) || amount <= 0)
        {
            cout << "Invalid withdrawal amount.\n";
            return false;
        }

        double currentBalance = getAccountBalance();

        if (amount > currentBalance)
        {
            cout << "Insufficient balance!\n";
            return false;
        }

        if (!updatebalance(currentBalance - amount))
        {
            cout << "Balance update failed!\n";
            return false;
        }

        cout << "Withdrawal successful!\n";
        cout << "Remaining Balance: " << getAccountBalance() << endl;

        return true;
    }
};

class Transaction
{
private:
    int transactionId;
    string transaction_Type;
    double amount;
    double balanceAfterTransaction;
    string date;
    long long acc_num;

public:
    // Constructor
    Transaction(int id, string type, double amt, double balance, string transactionDate, long long accountNumber) : transactionId(id), transaction_Type(type), amount(amt), balanceAfterTransaction(balance), date(transactionDate), acc_num(accountNumber) {}

    // getters
    int getTransactionId() const
    {
        return transactionId;
    }
    long long getAccountNumber() const
    {
        return acc_num;
    }
    double getAmount() const
    {
        return amount;
    }
    string getTransactionType() const
    {
        return transaction_Type;
    }
    double getbalancebefore() const
    {
        return balanceAfterTransaction;
    }
    string getDate() const
    {
        return date;
    }

    // Display transaction history entry
    void display_Transaction() const
    {
        cout << "-----------Transaction Details--------------" << endl;
        cout << "Transaction ID   : " << getTransactionId() << endl;
        cout << "Account Number   : " << getAccountNumber() << endl;
        cout << "Transaction Type : " << getTransactionType() << endl;
        cout << "Amount           : Rs. " << fixed << setprecision(2) << getAmount() << endl;
        cout << "Balance After    : Rs. " << fixed << setprecision(2) << getbalancebefore() << endl;
        cout << "Date             : " << getDate() << endl;
    }

    // Print a receipt immediately after a successful transaction.
    void displayReceipt() const
    {
        cout << "\n==================================================\n";
        cout << "             BANK TRANSACTION RECEIPT             \n";
        cout << "==================================================\n";
        cout << left << setw(20) << "Receipt / Txn ID" << ": " << getTransactionId() << '\n';
        cout << left << setw(20) << "Account Number" << ": " << getAccountNumber() << '\n';
        cout << left << setw(20) << "Transaction Type" << ": " << getTransactionType() << '\n';
        cout << left << setw(20) << "Amount" << ": Rs. " << fixed << setprecision(2) << getAmount() << '\n';
        cout << left << setw(20) << "Balance After" << ": Rs. " << fixed << setprecision(2) << getbalancebefore() << '\n';
        cout << left << setw(20) << "Date" << ": " << getDate() << '\n';
        cout << "==================================================\n";
        cout << "        Please keep this receipt for records.      \n";
        cout << "==================================================\n\n";
    }
};

class Bank
{
private:
    vector<Account *> accounts;
    map<long long, Account *> accountMap;
    vector<Transaction> transactions;
    int nextTransactionId = 1;
    vector<Customer *> customers;
    // Account numbers stay reserved even after an account is closed.
    set<long long> usedAccountNumbers;

    string getCurrentDate()
    {
        time_t now = time(nullptr);
        tm *localTime = localtime(&now);

        char buffer[11];

        strftime(buffer, sizeof(buffer), "%Y-%m-%d", localTime);

        return string(buffer);
    }

public:
    // Create Account
    bool Create_Account(Account *account)
    {
        if (account == nullptr)
        {
            cout << "Invalid Account!" << endl;
            return false;
        }

        long long acc_num = account->getAccountNumber();

        if (acc_num <= 0)
        {
            cout << "Invalid account number!" << endl;
            return false;
        }

        if (usedAccountNumbers.find(acc_num) != usedAccountNumbers.end())
        {
            cout << "Account number has already been used and cannot be reused!" << endl;
            return false;
        }

        Customer *customer = find_Customer(account->getCustomerId());

        if (customer == nullptr)
        {
            cout << "Account creation failed: Customer is not registered!" << endl;
            return false;
        }

        accounts.push_back(account);
        accountMap[acc_num] = account;
        usedAccountNumbers.insert(acc_num);

        cout << "Account created successfully!" << endl;
        return true;
    }

    // Find Account
    Account *find_Account(long long acc_num)
    {
        auto it = accountMap.find(acc_num);

        if (it == accountMap.end())
        {
            cout << "Account not found!" << endl;
            return nullptr;
        }
        return it->second;
    }

    // Find an account only when the supplied customer ID matches its owner.
    Account *findOwnedAccount(long long acc_num, long long customerId)
    {
        Account *account = find_Account(acc_num);
        if (account == nullptr)
            return nullptr;

        if (account->getCustomerId() != customerId)
        {
            cout << "Access denied: Customer ID does not match this account.\n";
            return nullptr;
        }
        return account;
    }

    // Deposit: verify account ownership before changing the balance.
    void deposit(long long acc_num, long long customerId, double amount)
    {
        Account *account = findOwnedAccount(acc_num, customerId);
        if (account == nullptr)
            return;

        // perfect deposit
        bool success = account->deposit(amount);

        // Record only successful deposits
        if (success)
        {
            Transaction trans{nextTransactionId++, "Deposit", amount,
                              account->getAccountBalance(), getCurrentDate(), acc_num};

            transactions.push_back(trans);

            cout << "Transaction recorded successfully!" << endl;
            transactions.back().displayReceipt();
        }
    }

    // Withdraw: verify account ownership before changing the balance.
    void withdraw(long long acc_num, long long customerId, double amount)
    {
        Account *account = findOwnedAccount(acc_num, customerId);
        if (account == nullptr)
            return;

        // Perform withdrawal
        bool success = account->withdraw(amount);

        // Record only successful withdrawals
        if (success)
        {
            Transaction trans{nextTransactionId++, "Withdrawal", amount,
                              account->getAccountBalance(), getCurrentDate(), acc_num};

            transactions.push_back(trans);
            cout << "Transaction recorded successfully!\n";
            transactions.back().displayReceipt();
        }
    }

    // Close Account
    void close_Account(long long acc_num, long long customerId)
    {
        auto it = accountMap.find(acc_num);

        if (it == accountMap.end())
        {
            cout << "Account not found!" << endl;
            return;
        }

        Account *account = it->second;
        if (account->getCustomerId() != customerId)
        {
            cout << "Access denied: Customer ID does not match this account.\n";
            return;
        }

        // Step 2: Check account balance
        if (account->getAccountBalance() != 0)
        {
            cout << "Account cannot be closed!" << endl;
            cout << "Please withdraw the remaining balance first." << endl;
            cout << "Current Balance: " << account->getAccountBalance() << endl;
            return;
        }

        // Step 3: Remove account from vector
        for (auto vec_it = accounts.begin();
             vec_it != accounts.end(); ++vec_it)
        {

            if (*vec_it == account)
            {
                accounts.erase(vec_it);
                break;
            }
        }

        // Step 4: Remove account from map
        accountMap.erase(it);

        cout << "Account closed successfully!" << endl;
        cout << "Account Number: " << acc_num << endl;
    }

    // List Accounts
    void list_Accounts()
    {
        if (accounts.empty())
        {
            cout << "No accounts available!" << endl;
            return;
        }
        for (Account *account : accounts)
        {
            account->display_Account_Details();
            cout << endl;
        }
    }
    //
    void showTransactionHistry(long long accountNumber, long long customerId)
    {
        // Ownership is checked against the active account before showing history.
        if (findOwnedAccount(accountNumber, customerId) == nullptr)
            return;

        bool found = false;

        for (const Transaction &trans : transactions)
        {
            if (trans.getAccountNumber() == accountNumber)
            {
                trans.display_Transaction();
                cout << endl;
                found = true;
            }
        }

        if (!found)
        {
            cout << "No transaction history found for Account Number: " << accountNumber << endl;
        }
    }

    bool Create_Customer(Customer *cust)
    {
        if (cust == nullptr)
        {
            cout << "Invalid Customer !" << endl;
            return false;
        }
        // Check duplicate customer ID
        for (Customer *customer : customers)
        {

            if (customer->getCustomerId() == cust->getCustomerId())
            {
                cout << "Customer already exists!" << endl;
                return false;
            }

            if (customer->getPhoneNo() == cust->getPhoneNo())
            {
                cout << "Customer Phone number already exists!" << endl;
                return false;
            }
        }

        // Register customer
        customers.push_back(cust);

        cout << "Customer created successfully!" << endl;
        cout << "Customer ID : " << cust->getCustomerId() << endl;
        cout << "Customer Name: " << cust->getName() << endl;
        return true;
    }

    Customer *find_Customer(long long customerId)
    {
        for (Customer *customer : customers)
        {
            if (customer->getCustomerId() == customerId)
            {
                return customer;
            }
        }

        cout << "Customer not found!" << endl;
        return nullptr;
    }

    void list_Customers()
    {
        if (customers.empty())
        {
            cout << "No customer available!\n";
            return;
        }
        for (Customer *customer : customers)
        {
            customer->Display_Details();
            cout << endl;
        }
    }
    // Save customers, active accounts, reserved account numbers, and transactions.
    bool saveData(const string &filename = "bank_data.txt") const
    {
        ofstream out(filename);
        if (!out)
        {
            cerr << "Error: Could not open " << filename << " for saving.\n";
            return false;
        }

        out << setprecision(17);
        out << "CUSTOMERS " << customers.size() << '\n';
        for (const Customer *customer : customers)
        {
            out << customer->getCustomerId() << ' '
                << quoted(customer->getName()) << ' '
                << quoted(customer->getAddress()) << ' '
                << quoted(customer->getPhoneNo()) << '\n';
        }

        out << "ACCOUNTS " << accounts.size() << '\n';
        for (const Account *account : accounts)
        {
            const char *type = dynamic_cast<const SavingsAccount *>(account)
                                   ? "SAVINGS" : "CURRENT";
            out << type << ' ' << account->getAccountNumber() << ' '
                << account->getAccountBalance() << ' '
                << account->getCustomerId() << '\n';
        }

        out << "USED_ACCOUNTS " << usedAccountNumbers.size() << '\n';
        for (long long number : usedAccountNumbers)
            out << number << '\n';

        out << "TRANSACTIONS " << transactions.size() << '\n';
        for (const Transaction &transaction : transactions)
        {
            out << transaction.getTransactionId() << ' '
                << quoted(transaction.getTransactionType()) << ' '
                << transaction.getAmount() << ' '
                << transaction.getbalancebefore() << ' '
                << quoted(transaction.getDate()) << ' '
                << transaction.getAccountNumber() << '\n';
        }

        if (!out)
        {
            cerr << "Error: Failed while writing to " << filename << ".\n";
            return false;
        }
        return true;
    }

    // Load data. The storage vectors own objects; Bank keeps non-owning pointers.
    bool loadData(vector<unique_ptr<Customer>> &customerStorage,
                  vector<unique_ptr<Account>> &accountStorage,
                  const string &filename = "bank_data.txt")
    {
        ifstream in(filename);
        if (!in)
        {
            cout << "No saved data found. Starting with an empty bank.\n";
            return true;
        }

        struct CustomerRecord { long long id; string name, address, phone; };
        struct AccountRecord { string type; long long number; double balance; long long customerId; };
        struct TransactionRecord { int id; string type; double amount, balance; string date; long long accountNumber; };

        string section;
        size_t count = 0;
        vector<CustomerRecord> customerRecords;
        vector<AccountRecord> accountRecords;
        vector<TransactionRecord> transactionRecords;
        set<long long> usedRecords;

        if (!(in >> section >> count) || section != "CUSTOMERS")
        {
            cerr << "Error: Invalid data file format.\n";
            return false;
        }
        for (size_t i = 0; i < count; ++i)
        {
            CustomerRecord r;
            if (!(in >> r.id >> quoted(r.name) >> quoted(r.address) >> quoted(r.phone)))
            {
                cerr << "Error: Invalid customer record in data file.\n";
                return false;
            }
            customerRecords.push_back(r);
        }

        if (!(in >> section >> count) || section != "ACCOUNTS")
        {
            cerr << "Error: Missing ACCOUNTS section in data file.\n";
            return false;
        }
        for (size_t i = 0; i < count; ++i)
        {
            AccountRecord r;
            if (!(in >> r.type >> r.number >> r.balance >> r.customerId) ||
                (r.type != "SAVINGS" && r.type != "CURRENT") ||
                r.number <= 0 || r.balance < 0)
            {
                cerr << "Error: Invalid account record in data file.\n";
                return false;
            }
            accountRecords.push_back(r);
        }

        if (!(in >> section >> count) || section != "USED_ACCOUNTS")
        {
            cerr << "Error: Missing USED_ACCOUNTS section in data file.\n";
            return false;
        }
        for (size_t i = 0; i < count; ++i)
        {
            long long number;
            if (!(in >> number) || number <= 0)
            {
                cerr << "Error: Invalid reserved account number in data file.\n";
                return false;
            }
            usedRecords.insert(number);
        }

        if (!(in >> section >> count) || section != "TRANSACTIONS")
        {
            cerr << "Error: Missing TRANSACTIONS section in data file.\n";
            return false;
        }
        int maxTransactionId = 0;
        for (size_t i = 0; i < count; ++i)
        {
            TransactionRecord r;
            if (!(in >> r.id >> quoted(r.type) >> r.amount >> r.balance
                     >> quoted(r.date) >> r.accountNumber) ||
                r.id <= 0 || r.amount <= 0 || r.balance < 0 || r.accountNumber <= 0)
            {
                cerr << "Error: Invalid transaction record in data file.\n";
                return false;
            }
            maxTransactionId = max(maxTransactionId, r.id);
            transactionRecords.push_back(r);
        }

        // Validate parsed data before restoring pointers and objects.
        set<long long> customerIds;
        set<string> phoneNumbers;
        for (const auto &r : customerRecords)
        {
            if (r.id <= 0 || !customerIds.insert(r.id).second || !phoneNumbers.insert(r.phone).second)
            {
                cerr << "Error: Duplicate or invalid customer data in file.\n";
                return false;
            }
        }
        set<long long> activeNumbers;
        for (const auto &r : accountRecords)
        {
            if (!customerIds.count(r.customerId) || !activeNumbers.insert(r.number).second || !usedRecords.count(r.number))
            {
                cerr << "Error: Invalid account owner or number in data file.\n";
                return false;
            }
        }

        for (const auto &r : customerRecords)
        {
            auto customer = make_unique<Customer>(r.id, r.name, r.address, r.phone);
            customers.push_back(customer.get());
            customerStorage.push_back(move(customer));
        }

        usedAccountNumbers = usedRecords;
        for (const auto &r : accountRecords)
        {
            Customer *owner = nullptr;
            for (Customer *customer : customers)
                if (customer->getCustomerId() == r.customerId) { owner = customer; break; }

            unique_ptr<Account> account;
            if (r.type == "SAVINGS")
                account = make_unique<SavingsAccount>(r.number, r.balance, owner);
            else
                account = make_unique<CurrentAccount>(r.number, r.balance, owner);

            Account *ptr = account.get();
            accounts.push_back(ptr);
            accountMap[r.number] = ptr;
            accountStorage.push_back(move(account));
        }

        for (const auto &r : transactionRecords)
            transactions.emplace_back(r.id, r.type, r.amount, r.balance, r.date, r.accountNumber);
        nextTransactionId = maxTransactionId + 1;

        cout << "Saved bank data loaded successfully.\n";
        return true;
    }
};

// Reads one value and clears the rest of the input line.
template <typename T>
bool readValue(const string &prompt, T &value)
{
    cout << prompt;

    if (cin >> value)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if constexpr (is_floating_point_v<T>)
        {
            if (!isfinite(value))
            {
                cout << "Invalid input! Enter a finite number.\n";
                return false;
            }
        }
        return true;
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input! Please try again.\n";
    return false;
}

bool isBlank(const string &text)
{
    return all_of(text.begin(), text.end(), [](unsigned char ch)
    {
        return isspace(ch);
    });
}

int main()
{
    // Declare storage before Bank, so Bank is destroyed before the objects
    // its non-owning pointers refer to.
    vector<unique_ptr<Customer>> customerStorage;
    vector<unique_ptr<Account>> accountStorage;
    Bank bank;

    if (!bank.loadData(customerStorage, accountStorage))
    {
        cerr << "Could not load bank data. Exiting to avoid overwriting it.\n";
        return 1;
    }

    int choice = -1;

    while (true)
    {
        cout << "\n========== BANK MANAGEMENT SYSTEM ==========\n";
        cout << "1.  Create Customer\n";
        cout << "2.  Create Savings Account\n";
        cout << "3.  Create Current Account\n";
        cout << "4.  Deposit Money\n";
        cout << "5.  Withdraw Money\n";
        cout << "6.  Check Account Balance / Details\n";
        cout << "7.  Display All Accounts\n";
        cout << "8.  View Transaction History\n";
        cout << "9.  Close Account\n";
        cout << "10. Display All Customers\n";
        cout << "0.  Exit\n";
        cout << "============================================\n";

        if (!readValue("Enter your choice: ", choice))
        {
            if (cin.eof())
                break;
            continue;
        }

        if (choice == 0)
        {
            if (bank.saveData())
                cout << "Bank data saved successfully.\n";
            cout << "Thank you for using the Bank Management System!\n";
            break;
        }

        switch (choice)
        {
        case 1:
        {
            string name, address, phone;

            cout << "Enter customer name: ";
            getline(cin, name);
            cout << "Enter customer address: ";
            getline(cin, address);
            cout << "Enter customer phone number: ";
            getline(cin, phone);

            if (isBlank(name) || isBlank(address) || isBlank(phone))
            {
                cout << "Name, address, and phone number cannot be empty.\n";
                break;
            }

            bool phoneIsDigits = all_of(phone.begin(), phone.end(), [](unsigned char ch)
            {
                return isdigit(ch);
            });
            if (phone.size() != 10 || !phoneIsDigits)
            {
                cout << "Invalid phone number! Enter exactly 10 digits.\n";
                break;
            }

            auto customer = make_unique<Customer>(name, address, phone);
            Customer *customerPtr = customer.get();
            if (bank.Create_Customer(customerPtr))
                customerStorage.push_back(move(customer));
            break;
        }

        case 2:
        case 3:
        {
            long long accountNumber, customerId;
            double initialBalance;

            if (!readValue("Enter new account number: ", accountNumber))
                break;
            if (!readValue("Enter initial balance: ", initialBalance))
                break;
            if (!readValue("Enter registered customer ID: ", customerId))
                break;

            Customer *owner = bank.find_Customer(customerId);
            if (owner == nullptr)
                break;

            try
            {
                unique_ptr<Account> account;

                if (choice == 2)
                    account = make_unique<SavingsAccount>(accountNumber, initialBalance, owner);
                else
                    account = make_unique<CurrentAccount>(accountNumber, initialBalance, owner);

                Account *accountPtr = account.get();

                if (bank.Create_Account(accountPtr))
                    accountStorage.push_back(move(account));
            }
            catch (const invalid_argument &error)
            {
                cout << "Account creation failed: " << error.what() << '\n';
            }
            break;
        }

        case 4:
        {
            long long accountNumber, customerId;
            double amount;

            if (!readValue("Enter account number: ", accountNumber))
                break;
            if (!readValue("Enter your customer ID: ", customerId))
                break;
            if (!readValue("Enter deposit amount: ", amount))
                break;

            bank.deposit(accountNumber, customerId, amount);
            break;
        }

        case 5:
        {
            long long accountNumber, customerId;
            double amount;

            if (!readValue("Enter account number: ", accountNumber))
                break;
            if (!readValue("Enter your customer ID: ", customerId))
                break;
            if (!readValue("Enter withdrawal amount: ", amount))
                break;

            bank.withdraw(accountNumber, customerId, amount);
            break;
        }

        case 6:
        {
            long long accountNumber, customerId;

            if (!readValue("Enter account number: ", accountNumber))
                break;
            if (!readValue("Enter your customer ID: ", customerId))
                break;

            Account *account = bank.findOwnedAccount(accountNumber, customerId);
            if (account != nullptr)
                account->check_Balance();
            break;
        }

        case 7:
            bank.list_Accounts();
            break;

        case 8:
        {
            long long accountNumber, customerId;

            if (!readValue("Enter account number: ", accountNumber))
                break;
            if (!readValue("Enter your customer ID: ", customerId))
                break;

            bank.showTransactionHistry(accountNumber, customerId);
            break;
        }

        case 9:
        {
            long long accountNumber, customerId;

            if (!readValue("Enter account number to close: ", accountNumber))
                break;
            if (!readValue("Enter your customer ID: ", customerId))
                break;

            bank.close_Account(accountNumber, customerId);
            break;
        }

        case 10:
            bank.list_Customers();
            break;

        default:
            cout << "Invalid menu choice. Please select 0-10.\n";
            break;
        }

        // Persist changes after every menu operation.
        bank.saveData();
    }

    return 0;
}
