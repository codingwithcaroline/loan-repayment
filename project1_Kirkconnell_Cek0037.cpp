/*
*@author Caroline Kirkconnell
*@UserID Cek0037
*@fileName project1_Kirkconnell_Cek0037.cpp
*@compile jGRASP CSD (C++) project using
*MinGW GCC/G++ Compiler
*@references I used course notes and lectures to
*familiarize myself with ideas.
*I used tutorialspoint.com to answer basic questions
*about C++.
*I used geeksforgeeks.org when I had questions about
*coding style, syntax, and order.
*I used w3schools.com to learn about C++ while loops.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main() {
    //Initializes variables.
    float loan_amount;
    float int_rate;
    float monthly_payment;
    int num_months;
    float float_rate;
    float remaining_balance;
    float interest;
    float principal;
    float total_interest;

    //Asks for user input.
    cout << "Loan Amount: ";
    cin >> loan_amount;
    cout << "Interest Rate(% per year): ";
    cin >> int_rate;
    cout << "Monthly Payments: ";
    cin >> monthly_payment;
    cout << "\n";

    //Arithmetic 
    float_rate = int_rate / 12;
    remaining_balance = loan_amount;
    cout << left << string(60, '*') << "\n\tAmortizationTable\n"
        << string(60, '*') << setw(10) << "\nMonth" << setw(10) << "Balance"
        << setw(11) << "Payment" << setw(9) << "Rate" << setw(12) << "Interest"
        << setw(9) << "Principal\n";

    cout << showpoint << fixed << setprecision(2) << setw(9) << num_months
        << setw(1) << "$" << setw(9) << remaining_balance << setw(11)
        << "N/A" << setw(9) << "N/A" << setw(12) << "N/A" << setw(9)
        << "N/A" << "\n";

    while (remaining_balance > 0) {
        num_months++;
        interest = (float_rate / 100) * remaining_balance;
        principal = monthly_payment - interest;
        total_interest += interest;
        remaining_balance = remaining_balance - principal;

        if (remaining_balance < 0) {
            principal = remaining_balance + principal;
            remaining_balance = 0;
            monthly_payment = interest + principal;
        }

        if (monthly_payment < interest) {
            cout << "\n" << string(60, '*') << setw(60)
                << "\n\tLoan interest is higher than monthly payment."
                << "\n\tTerminating Program!\n" << string(60, '*') << "\n";
            exit(1);
        }

        cout << showpoint << fixed << setprecision(2) << setw(9) << num_months
            << setw(1) << '$' << setw(9) << remaining_balance << setw(1) << "$"
            << setw(10) << monthly_payment << setw(9) << float_rate << setw(1) << "$"
            << setw(11) << interest << setw(1)
            << '$' << setw(8) << principal << "\n";
    }

    cout << string(60, '*') << "\n\n";
    cout << "It takes " << num_months << " months to pay off the loan."
        << "\nTotal interest paid is: $" << total_interest << "\n";
}