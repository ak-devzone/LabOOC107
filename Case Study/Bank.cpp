

#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <string>

using namespace std;

// Constants
const int MAX_NAME = 50;
const int MAX_MONEY = 7;
const int MAX_NUMBER = 12;
const int TYPE_SIZE = 4;

const string SEP = " |";
const int TOTAL_LEN =
    MAX_NAME + MAX_NUMBER + TYPE_SIZE + MAX_MONEY + SEP.size() * 4;

const string SEP_LINE = SEP + string(TOTAL_LEN - 1, '=') + '|';

// ============================================================
// Bank Class
// ============================================================

class Bank
{
private:
    unsigned long long accountNumber;
    char holderName[51];
    int deposit;
    char type;

public:
    // Constructor
    Bank();

    void SystemClear();
    void GetData();
    void WriteData();

    void DepositWithdraw(int amount, int option);
    void DisplayIndividualRecords(unsigned long long accountNumber);

    void Report() const;
    void ShowAccount() const;

    void DepositMoney(int amount);
    void WithdrawMoney(int amount);

    unsigned long long GetAccountNumber() const;
    int GetDeposit() const;
    char GetType() const;

    void ModifyData();
};

// ============================================================
// Bank Class Functions
// ============================================================

// Constructor
Bank::Bank()
{
    accountNumber = 0;
    holderName[0] = '\0';
    deposit = 0;
    type = 'S';
}

// Clear screen
void Bank::SystemClear()
{
    system("cls");
}

// Get account information
void Bank::GetData()
{
    cout << "\n\n=========== CREATE BANK ACCOUNT ===========\n\n";

    cout << "Enter Account Number: ";
    cin >> accountNumber;

    while (to_string(accountNumber).size() != 12)
    {
        cout << "Account number must contain 12 digits.\n";
        cout << "Please enter again: ";

        cin.clear();
        cin.ignore(10000, '\n');

        cin >> accountNumber;
    }

    cout << "\nEnter Account Holder Name: ";
    cin.ignore(10000, '\n');
    cin.getline(holderName, 51);

    cout << "\nWhich type of Account?\n";
    cout << "[S] Saving Account\n";
    cout << "[C] Current Account\n";
    cout << "Enter choice: ";

    cin >> type;
    type = toupper(type);

    while (type != 'S' && type != 'C')
    {
        cout << "Please enter either S or C: ";
        cin >> type;
        type = toupper(type);
    }

    if (type == 'S')
    {
        cout << "\nEnter Initial Amount for Saving Account ";
        cout << "[Minimum 500]: ";
        cin >> deposit;
    }
    else
    {
        cout << "\nEnter Initial Amount for Current Account ";
        cout << "[Minimum 1000]: ";
        cin >> deposit;
    }

    while (deposit >= 1000000)
    {
        cout << "Maximum balance is 1000000.\n";
        cout << "Please enter again: ";
        cin >> deposit;
    }

    cout << "\nAccount has been created successfully.\n";
}

// Write account data to file
void Bank::WriteData()
{
    ofstream outFile("account.dat", ios::binary | ios::app);

    if (!outFile)
    {
        cout << "Unable to open account file.\n";
        return;
    }

    GetData();

    outFile.write(reinterpret_cast<char*>(this), sizeof(*this));
    outFile.close();
}

// Modify account information
void Bank::ModifyData()
{
    cout << "\nAccount No: " << accountNumber;

    cout << "\nModify Account Holder Name: ";
    cin.ignore(10000, '\n');
    cin.getline(holderName, 51);

    cout << "\nModify Type of Account [S/C]: ";
    cin >> type;
    type = toupper(type);

    while (type != 'S' && type != 'C')
    {
        cout << "Please enter either S or C: ";
        cin >> type;
        type = toupper(type);
    }

    cout << "\nModify Total Balance Amount: ";
    cin >> deposit;

    while (deposit >= 1000000)
    {
        cout << "Maximum balance is 1000000.\n";
        cout << "Please enter again: ";
        cin >> deposit;
    }
}

// Display individual account record
void Bank::DisplayIndividualRecords(unsigned long long number)
{
    bool found = false;

    ifstream inFile("account.dat", ios::binary);

    if (!inFile)
    {
        cout << "\nAn error occurred. Please try again.\n";
        return;
    }

    cout << "\nBALANCE DETAILS\n";

    while (inFile.read(reinterpret_cast<char*>(this), sizeof(*this)))
    {
        if (GetAccountNumber() == number)
        {
            ShowAccount();
            found = true;
            break;
        }
    }

    inFile.close();

    if (!found)
    {
        cout << "\nAccount details not found.\n";
    }
}

// Display account in table format
void Bank::Report() const
{
    cout << SEP
         << setw(MAX_NUMBER) << accountNumber << SEP
         << setw(MAX_NAME) << holderName << SEP
         << setw(TYPE_SIZE) << type << SEP
         << setw(MAX_MONEY) << deposit << SEP
         << endl
         << SEP_LINE << endl;
}

// Deposit money
void Bank::DepositMoney(int amount)
{
    deposit += amount;
}

// Withdraw money
void Bank::WithdrawMoney(int amount)
{
    deposit -= amount;
}

// Display account details
void Bank::ShowAccount() const
{
    cout << "\nAccount No: " << accountNumber;
    cout << "\nAccount Holder Name: " << holderName;

    if (type == 'S')
        cout << "\nType of Account: Saving";
    else
        cout << "\nType of Account: Current";

    cout << "\nTotal Balance: " << deposit << endl;
}

// Return account number
unsigned long long Bank::GetAccountNumber() const
{
    return accountNumber;
}

// Return balance
int Bank::GetDeposit() const
{
    return deposit;
}

// Return account type
char Bank::GetType() const
{
    return type;
}

// ============================================================
// Function Prototypes
// ============================================================

void DeleteAccount(unsigned long long);
void SystemClear();

void GetAllData();
void DepositWithdraw(unsigned long long, int);
void AccountModification(unsigned long long);

// ============================================================
// Main Function
// ============================================================

int main()
{
    char choice;
    unsigned long long accountNumber;

    Bank bank;

    do
    {
        SystemClear();

        cout << "\n==============================";
        cout << "\n     BANKING RECORD SYSTEM";
        cout << "\n==============================\n";

        cout << "\n1. CREATE NEW ACCOUNT";
        cout << "\n2. MODIFY AN ACCOUNT";
        cout << "\n3. BALANCE ENQUIRY";
        cout << "\n4. DEPOSIT IN ACCOUNT";
        cout << "\n5. WITHDRAW FROM ACCOUNT";
        cout << "\n6. ALL ACCOUNT HOLDER LIST";
        cout << "\n7. CLOSE AN ACCOUNT";
        cout << "\n8. EXIT";

        cout << "\n\nSELECT OPTION: ";
        cin >> choice;

        SystemClear();

        switch (choice)
        {
        case '1':
            bank.WriteData();
            break;

        case '2':
            cout << "\nEnter Account Number: ";
            cin >> accountNumber;

            AccountModification(accountNumber);
            break;

        case '3':
            cout << "\nEnter Account Number: ";
            cin >> accountNumber;

            bank.DisplayIndividualRecords(accountNumber);
            break;

        case '4':
            cout << "\nEnter Account Number: ";
            cin >> accountNumber;

            DepositWithdraw(accountNumber, 1);
            break;

        case '5':
            cout << "\nEnter Account Number: ";
            cin >> accountNumber;

            DepositWithdraw(accountNumber, 2);
            break;

        case '6':
            GetAllData();
            break;

        case '7':
            cout << "\nEnter Account Number: ";
            cin >> accountNumber;

            DeleteAccount(accountNumber);
            break;

        case '8':
            cout << "\nThanks for using Banking Record System.\n";
            break;

        default:
            cout << "\nInvalid option. Please try again.\n";
        }

        cout << "\nPress Enter to continue...";
        cin.ignore(10000, '\n');
        cin.get();

    } while (choice != '8');

    return 0;
}

// ============================================================
// Clear Screen
// ============================================================

void SystemClear()
{
    system("cls");
}

// ============================================================
// Display All Account Records
// ============================================================

void GetAllData()
{
    Bank bank;

    ifstream inFile("account.dat", ios::binary);

    if (!inFile)
    {
        cout << "Unable to open account file.\n";
        return;
    }

    cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";

    cout << SEP_LINE << endl;

    cout << SEP
         << setw(MAX_NUMBER) << "A/C NO." << SEP
         << setw(MAX_NAME) << "NAME" << SEP
         << setw(TYPE_SIZE) << "TYPE" << SEP
         << setw(MAX_MONEY) << "BALANCE" << SEP
         << endl;

    cout << SEP_LINE << endl;

    while (inFile.read(reinterpret_cast<char*>(&bank), sizeof(Bank)))
    {
        bank.Report();
    }

    inFile.close();
}

// ============================================================
// Deposit / Withdraw Money
// ============================================================

void DepositWithdraw(unsigned long long number, int option)
{
    int amount;
    Bank bank;
    bool found = false;

    fstream file(
        "account.dat",
        ios::binary | ios::in | ios::out
    );

    if (!file)
    {
        cout << "Unable to open account file.\n";
        return;
    }

    while (file.read(reinterpret_cast<char*>(&bank), sizeof(Bank)))
    {
        if (bank.GetAccountNumber() == number)
        {
            found = true;

            bank.ShowAccount();

            if (option == 1)
            {
                cout << "\n\n=========== DEPOSIT ===========";
                cout << "\nEnter Amount: ";
                cin >> amount;

                if (bank.GetDeposit() + amount >= 1000000)
                {
                    cout << "\nMaximum balance is 1000000.\n";
                }
                else if (amount > 0)
                {
                    bank.DepositMoney(amount);
                }
                else
                {
                    cout << "\nInvalid amount.\n";
                }
            }
            else if (option == 2)
            {
                cout << "\n\n=========== WITHDRAW ===========";
                cout << "\nEnter Amount: ";
                cin >> amount;

                int balance = bank.GetDeposit() - amount;

                if (amount <= 0)
                {
                    cout << "\nInvalid amount.\n";
                }
                else if (
                    (balance < 500 && bank.GetType() == 'S') ||
                    (balance < 1000 && bank.GetType() == 'C')
                )
                {
                    cout << "\nInsufficient Balance.\n";
                }
                else
                {
                    bank.WithdrawMoney(amount);
                }
            }

            // Move file pointer back to current record
            file.seekp(
                -static_cast<streamoff>(sizeof(Bank)),
                ios::cur
            );

            file.write(
                reinterpret_cast<char*>(&bank),
                sizeof(Bank)
            );

            cout << "\nAccount record updated successfully.\n";
            break;
        }
    }

    file.close();

    if (!found)
    {
        cout << "\nAccount record not found.\n";
    }
}

// ============================================================
// Delete Account
// ============================================================

void DeleteAccount(unsigned long long number)
{
    Bank bank;

    ifstream inFile("account.dat", ios::binary);

    if (!inFile)
    {
        cout << "Unable to open account file.\n";
        return;
    }

    ofstream outFile("account_temp.dat", ios::binary);

    while (inFile.read(reinterpret_cast<char*>(&bank), sizeof(Bank)))
    {
        if (bank.GetAccountNumber() != number)
        {
            outFile.write(
                reinterpret_cast<char*>(&bank),
                sizeof(Bank)
            );
        }
    }

    inFile.close();
    outFile.close();

    remove("account.dat");
    rename("account_temp.dat", "account.dat");

    cout << "\nAccount record deleted successfully.\n";
}

// ============================================================
// Modify Account
// ============================================================

void AccountModification(unsigned long long number)
{
    Bank bank;
    bool found = false;

    fstream file(
        "account.dat",
        ios::binary | ios::in | ios::out
    );

    if (!file)
    {
        cout << "Unable to open account file.\n";
        return;
    }

    while (file.read(reinterpret_cast<char*>(&bank), sizeof(Bank)))
    {
        if (bank.GetAccountNumber() == number)
        {
            found = true;

            bank.ShowAccount();

            cout << "\n\n=========== MODIFY ACCOUNT ===========";
            cout << "\nEnter New Details:\n";

            bank.ModifyData();

            file.seekp(
                -static_cast<streamoff>(sizeof(Bank)),
                ios::cur
            );

            file.write(
                reinterpret_cast<char*>(&bank),
                sizeof(Bank)
            );

            cout << "\nRecord updated successfully.\n";
            break;
        }
    }

    file.close();

    if (!found)
    {
        cout << "\nAccount record not found.\n";
    }
}

