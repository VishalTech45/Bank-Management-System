# 🏦 Bank Management System in C++

A menu-driven **Bank Management System** developed in C++ using Object-Oriented Programming (OOP) concepts. The application supports customer registration, account creation, deposits, withdrawals, account details, and transaction history.

The project uses **file handling** to store data locally in `bank_data.txt`, allowing saved records to be loaded when the application runs again.

## 📌 Features

* **Customer Management**

  * Create new customers.
  * Display registered customers.
  * Validate phone numbers.
  * Prevent duplicate phone numbers.

* **Account Management**

  * Create savings accounts.
  * Create current accounts.
  * View account details and balances.
  * Display all active accounts.
  * Close accounts when their balance is zero.
  * Prevent reuse of previously used account numbers.

* **Banking Operations**

  * Deposit money.
  * Withdraw money.
  * Validate transaction amounts.
  * Check account ownership during supported operations.

* **Transaction Management**

  * Maintain transaction records.
  * View transaction history for an account.
  * Display transaction receipts.

* **File Handling**

  * Save customer and account information.
  * Store transaction records.
  * Load saved data when the program starts.

## 🛠️ Technologies Used

| Technology                      | Purpose                         |
| ------------------------------- | ------------------------------- |
| C++                             | Core programming language       |
| Object-Oriented Programming     | Application design              |
| File Handling                   | Local data persistence          |
| Standard Template Library (STL) | Data structures and collections |
| Command-Line Interface          | User interaction                |

## 🧠 OOP Concepts Demonstrated

### 1. Encapsulation

Classes manage their data through member functions and controlled access.

### 2. Inheritance

`SavingsAccount` and `CurrentAccount` inherit common account functionality from the abstract `Account` class.

### 3. Abstraction

The `Account` class defines a common interface and declares `withdraw()` as a pure virtual function.

### 4. Polymorphism

Different account types implement the `withdraw()` function according to their account-specific behavior.

### 5. Classes and Objects

The project uses classes such as `Customer`, `Account`, `SavingsAccount`, `CurrentAccount`, `Transaction`, and `Bank`.

### 6. Static Data Members

A static counter is used for customer ID generation.

## 🏗️ Project Structure

```text
Bank-Management-System/
├── main.cpp
├── bank_data.txt
└── README.md
```

**Note:** Replace `main.cpp` with your actual C++ source filename. The `bank_data.txt` file is used at runtime for local data storage and does not need to be committed unless you want to include sample data.

## ⚙️ Installation and Execution

### Prerequisites

* A C++ compiler such as GCC/G++.
* A terminal or IDE, such as Visual Studio Code.

### Step 1: Clone the Repository

```bash
git clone https://github.com/VishalTech45/Bank-Management-System.git
cd Bank-Management-System
```

### Step 2: Compile the Program

Replace `main.cpp` with your actual source filename.

```bash
g++ -std=c++17 main.cpp -o bank
```

### Step 3: Run the Program

**Windows — PowerShell or Command Prompt**

```powershell
.\bank.exe
```

**Linux / macOS**

```bash
./bank
```

## 📋 Application Menu

| Option | Operation                       |
| -----: | ------------------------------- |
|      1 | Create Customer                 |
|      2 | Create Savings Account          |
|      3 | Create Current Account          |
|      4 | Deposit Money                   |
|      5 | Withdraw Money                  |
|      6 | Check Account Balance / Details |
|      7 | Display All Accounts            |
|      8 | View Transaction History        |
|      9 | Close Account                   |
|     10 | Display All Customers           |
|      0 | Exit                            |

Select an option and follow the on-screen instructions.

## 💾 Data Storage

The application stores data locally in `bank_data.txt`.

The file preserves information such as:

* Customer records
* Active account records
* Previously used account numbers
* Transaction records

The program loads saved data when it starts and saves data through its file-persistence functionality.

**Important:** Keep the data file in the location expected by the application. Back it up if you want to preserve your records.

This is a local file-based application. It does not currently use PostgreSQL or another database.

## ✅ Validation and Error Handling

The current implementation includes checks for:

* Phone numbers containing exactly 10 digits.
* Duplicate customer phone numbers.
* Invalid or non-positive transaction amounts.
* Account ownership during supported operations.
* Account closure only when the balance is zero.
* Reuse of previously assigned account numbers.

## ⚠️ Current Limitations

* Data is stored in a local text file rather than a database.
* Monetary values use `double`, which can introduce floating-point precision issues.
* The application uses a console-based interface.
* Login/PIN authentication is not currently implemented.
* Online banking, fund transfers, and overdraft facilities are not implemented.
* The interest calculation is basic and does not represent a complete real-world banking policy.

## 🚀 Future Improvements

Potential enhancements for future versions include:

* Integrating PostgreSQL for structured data storage.
* Using integer paise for more reliable monetary calculations.
* Adding secure authentication and role-based access.
* Implementing fund transfers between accounts.
* Improving transaction consistency and error handling.
* Adding account statements and financial reports.
* Developing a graphical user interface or REST API.
* Adding automated unit tests.

*These are proposed enhancements, not features currently implemented.*

## 🎯 Learning Objectives

This project demonstrates practical applications of:

* C++ classes and objects
* Inheritance and polymorphism
* Abstract classes and virtual functions
* Encapsulation and abstraction
* Pointers and object management
* Input validation
* File handling and data persistence
* Menu-driven program design

## 👨‍💻 Author

**Vishal Kumar**

## 📄 License

No specific open-source license is included unless a `LICENSE` file is added to the repository.

---

**Disclaimer:** This is an educational banking simulation and is not intended for real banking or financial transactions.
