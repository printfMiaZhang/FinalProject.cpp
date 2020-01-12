#include <iostream>
#include <cmath>
#include <sstream>
#include "MortCalc.h"

using namespace std;

void MortCalc::Calculateloan()
    {
        M = P*i / ( q*(1 - pow(( 1 + (i/q)),-n*q)));
        total_loan_cost=M*q*n;
        total_interest_paid=total_loan_cost-P;
    }

MortCalc::MortCalc(){
    P=0;
    i=0.05;
    n=0;
    q=12;
    Calculateloan();
}


    string MortCalc::GetFormattedString()
    {
        stringstream print;
        print<<"Loan amount:"<<P<<"\n"<<"Intereste rate:"<<annual_interest_rate<<"\n"<<"Monthly payment:"<<monthly_payment<<"\n"<<"Total loan:"<<total_loan_cost<<"\n"<<"Total interest:"<<total_interest_paid;
        return print.str();
    }
    
    void MortCalc::SetPrinciple(float principle_amount)
    {
        P = principle_amount;
        Calculateloan();
    }
    
    void MortCalc::Setyears(int years)
    {
        years_of_the_loan=years;
        Calculateloan();
    }
    
    void MortCalc::SetInterest(float AnualInterest)
    {
        annual_interest_rate=AnualInterest;
        Calculateloan();
    }
    
    float MortCalc::getTotalLoan()
    {
        return total_loan_cost;
    }
    
    float MortCalc::getTotalInterest()
    {
        return total_interest_paid;
    }
    
    float MortCalc::getMonthlyPayment()
    {
        return M;
    }
