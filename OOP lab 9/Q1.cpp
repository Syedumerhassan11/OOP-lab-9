#include <iostream>
#include <string>
#include <unordered_map>

class Wallet {
private:
    double balance;
    double dailyDepositTotal;
    double dailyWithdrawTotal;
    const double maxDailyDeposit = 5000.0;
    const double maxDailyWithdraw = 2000.0;

public:
    Wallet() : balance(0.0), dailyDepositTotal(0.0), dailyWithdrawTotal(0.0) {}

    bool deposit(double amount) {
        if (amount <= 0 || dailyDepositTotal + amount > maxDailyDeposit) return false;
        balance += amount;
        dailyDepositTotal += amount;
        return true;
    }

    bool withdraw(double amount) {
        if (amount <= 0 || amount > balance || dailyWithdrawTotal + amount > maxDailyWithdraw) return false;
        balance -= amount;
        dailyWithdrawTotal += amount;
        return true;
    }

    double getBalance() const {
        return balance;
    }

    void resetDailyLimits() {
        dailyDepositTotal = 0.0;
        dailyWithdrawTotal = 0.0;
    }
};

class User {
private:
    std::string userID;
    std::string name;
    Wallet wallet;

public:
    User(const std::string& id, const std::string& nm) : userID(id), name(nm) {}

    bool deposit(double amount) {
        return wallet.deposit(amount);
    }

    bool withdraw(double amount) {
        return wallet.withdraw(amount);
    }

    void showBalance() const {
        std::cout << name << "'s Balance: " << wallet.getBalance() << std::endl;
    }

    void resetLimits() {
        wallet.resetDailyLimits();
    }
};

int main() {
    User user1("001", "Umer");
    User user2("002", "Hassan");

    user1.deposit(2000);
    user1.deposit(3000);
    user1.deposit(100);
    user1.showBalance();

    user1.withdraw(500);
    user1.withdraw(1700);
    user1.withdraw(100);
    user1.showBalance();

    user2.deposit(4000);
    user2.withdraw(1500);
    user2.showBalance();

    return 0;
}

