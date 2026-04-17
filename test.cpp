#include <iostream>
#include <vector>
using namespace std;

class Account {
private:
    int accountNumber;
    string accountHolder;
    double balance;
    vector<string> transactions;

public:
    Account(int accNo, string name, double initialBalance) {
        accountNumber = accNo;
        accountHolder = name;
        balance = initialBalance;
        transactions.push_back("Account created with balance: " + to_string(balance));
    }

    int getAccountNumber() {
        return accountNumber;
    }

    string getName() {
        return accountHolder;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transactions.push_back("Deposited: " + to_string(amount));
            cout << "Deposit Successful!\n";
        } else {
            cout << "Invalid amount!\n";
        }
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!\n";
        } else if (amount <= 0) {
            cout << "Invalid amount!\n";
        } else {
            balance -= amount;
            transactions.push_back("Withdrawn: " + to_string(amount));
            cout << "Withdrawal Successful!\n";
        }
    }

    void transfer(Account &receiver, double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!\n";
        } else if (amount <= 0) {
            cout << "Invalid amount!\n";
        } else {
            balance -= amount;
            receiver.balance += amount;
            transactions.push_back("Transferred: " + to_string(amount) +
                                   " to Account " + to_string(receiver.accountNumber));
            receiver.transactions.push_back("Received: " + to_string(amount) +
                                            " from Account " + to_string(accountNumber));
            cout << "Transfer Successful!\n";
        }
    }

    void showDetails() {
        cout << "\nAccount Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: " << balance << endl;
    }

    void showTransactions() {
        cout << "\nTransaction History:\n";
        for (string t : transactions) {
            cout << "- " << t << endl;
        }
    }
};

int main() {
    Account acc1(101, "Adhyaan", 5000);
    Account acc2(102, "Rahul", 3000);

    int choice;
    double amount;

    do {
        cout << "\n====== BANKING SYSTEM ======\n";
        cout << "1. Deposit (Acc1)\n";
        cout << "2. Withdraw (Acc1)\n";
        cout << "3. Transfer from Acc1 to Acc2\n";
        cout << "4. Show Account Details\n";
        cout << "5. Show Transactions\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter amount: ";
                cin >> amount;
                acc1.deposit(amount);
                break;

            case 2:
                cout << "Enter amount: ";
                cin >> amount;
                acc1.withdraw(amount);
                break;

            case 3:
                cout << "Enter amount: ";
                cin >> amount;
                acc1.transfer(acc2, amount);
                break;

            case 4:
                acc1.showDetails();
                acc2.showDetails();
                break;

            case 5:
                acc1.showTransactions();
                acc2.showTransactions();
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 6);

    return 0;
}
