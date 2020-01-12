#include <iostream>
#include <cmath>
#include <sstream>
#include "MortCalc.cpp"
#include "LoanOfficer.cpp"

using namespace std;

int main()
{
    LoanOfficer LO;
    cout<<LO.TheGetIntro();
    int number;
    float income,expense,borrow;
    
    do {
        cout<<"Enter Income followed by Expenses and Borrow Amount:";
        cin>>income>>expense>>borrow;
        LO.SetNetMonthlyIncome(income);
        LO.SetNetMonthlyExpenses(expense);
        LO.SetBorrowAmount(borrow);
        cout<<LO.GetLoanApproval();
        cout<<"\n\nPress 1 To Exit Any Other to Enter Again: ";
        cin>>number;
    }
    while (number!=1);
    return 0;
    }
