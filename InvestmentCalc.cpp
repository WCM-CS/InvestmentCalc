#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Interest {
public:
    void calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int years);
    void calculateBalanceWithMonthlyDeposit(double initialInvestment, double interestRate, double monthlyDeposit, int years);
    void dataInputDisplay();
    void dataInputDisplay2(double a, double b, double t, int v);
    void setInitialInvestment(double x);
    double getInitialInvestment();
    void setMonthlyDeposits(double z);
    double getMonthlyDeposits();
    void setAnnualInterest(double p);
    double getAnnualInterest();
    void setNumOfYears(int y);
    int getNumOfYears();

private:
    double initialInvestment;
    double interestRate;
    double monthlyDeposits;
    int years;
};

void Interest::calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int years) {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "             Balance and interest with no monthly deposits." << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Year" << setw(30) << "Year End Balance" << setw(30) << "Interest Earned" << endl;

    double balance = initialInvestment;
    double totalInterest = 0;

    for (int i = 1; i <= years; i++) {
        double interestEarned = balance * (interestRate / 100);
        balance += interestEarned;
        totalInterest += interestEarned;

        cout << i << setw(30) << fixed << setprecision(2) << balance << setw(30) << interestEarned << endl;
    }

    cout << "Total Interest Earned: $" << fixed << setprecision(2) << totalInterest << endl;
}

void Interest::calculateBalanceWithMonthlyDeposit(double initialInvestment, double interestRate, double monthlyDeposits, int years) {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "             Balance and interest with monthly deposits." << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Year" << setw(30) << "Year End Balance" << setw(30) << "Interest Earned" << endl;

    double balance = initialInvestment;
    double totalInterest = 0;

    for (int i = 1; i <= years; i++) {
        double interestEarned = balance * (interestRate / 100);
        balance += interestEarned;
        balance += monthlyDeposits * 12;
        totalInterest += interestEarned;

        cout << i << setw(30) << fixed << setprecision(2) << balance << setw(30) << interestEarned << endl;
    }

    cout << "Total Interest Earned: $" << fixed << setprecision(2) << totalInterest << endl;
}

void Interest::dataInputDisplay() {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "      INPUT DATA       " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "Initial Investment: $";
    cin >> initialInvestment;

    cout << "Monthly Deposits: $";
    cin >> monthlyDeposits;

    cout << "Annual Interest Rate (%): ";
    cin >> interestRate;

    cout << "Number of Years: ";
    cin >> years;

    cout << endl;
}

void Interest::dataInputDisplay2(double a, double b, double t, int v) {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "      INPUT DATA       " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "Initial Investment: $" << a << endl;
    cout << "Monthly Deposits: $" << b << endl;
    cout << "Annual Interest Rate (%): " << t << endl;
    cout << "Number of Years: " << v << endl;

    cout << endl;
}

void Interest::setInitialInvestment(double x) {
    initialInvestment = x;
}

double Interest::getInitialInvestment() {
    return initialInvestment;
}

void Interest::setMonthlyDeposits(double z) {
    monthlyDeposits = z;
}

double Interest::getMonthlyDeposits() {
    return monthlyDeposits;
}

void Interest::setAnnualInterest(double p) {
    interestRate = p;
}

double Interest::getAnnualInterest() {
    return interestRate;
}

void Interest::setNumOfYears(int y) {
    years = y;
}

int Interest::getNumOfYears() {
    return years;
}

int main() {
    Interest interest;
    interest.dataInputDisplay();
    interest.dataInputDisplay2(interest.getInitialInvestment(), interest.getAnnualInterest(), interest.getMonthlyDeposits(), interest.getNumOfYears());

    interest.calculateBalanceWithoutMonthlyDeposit(interest.getInitialInvestment(), interest.getAnnualInterest(), interest.getNumOfYears());
    cout << endl;
    interest.calculateBalanceWithMonthlyDeposit(interest.getInitialInvestment(), interest.getAnnualInterest(), interest.getMonthlyDeposits(), interest.getNumOfYears());

    return 0;
}