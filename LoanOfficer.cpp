#include <iostream>
#include <cmath>
#include <sstream>
#include "LoanOfficer.h"

using namespace std;
    
void LoanOfficer::Caculate()
    {
        monthly_payment=MC.getMonthlyPayment();
        netIncome = (monthly_income-monthly_expenses)*(1-0.13);
        
        if(monthly_payment + monthly_expenses<=0.5*netIncome){
            loan_Approved = true;
        }else {
            loan_Approved = false;
        }
    }

    LoanOfficer::LoanOfficer()
    {
        annual_interest_rate=0.05;
        years_of_the_loan=30;
        MC.SetInterest(annual_interest_rate);
        MC.Setyears(years_of_the_loan);
    }
    
    void LoanOfficer::SetNetMonthlyIncome(float set)
    {
        monthly_income=set;
        Caculate();
    }
    
    void LoanOfficer::SetNetMonthlyExpenses(float set)
    {
        monthly_expenses=set;
        Caculate();
    }
    
    void LoanOfficer::SetBorrowAmount(float set)
    {
        borrow_Amount=set;
        MC.SetPrinciple(borrow_Amount);
        Caculate();
    }
    
    string LoanOfficer::TheGetIntro()
    {
        stringstream ww;
        ww<<"Welcome to RBC Royal Bank!"<<"\n"<<"Interest Rate = 5.0%"<<"\n"<<"Number of years:"<<years_of_the_loan<<endl;
        return ww.str();
    }
    
    string LoanOfficer::GetLoanApproval()
    {
        if(loan_Approved==true)
        {
            string str = MC.GetFormattedString();
            
            return "Congratulations, Your Loan Has Aproved!!!\n"+str+"\nWe’re looking forward to do business with you!";
            
        }
        else{
            stringstream rr;
            float ratio;
            ratio=(monthly_payment + monthly_expenses)/netIncome;
            rr<<"The ratio of income to monthly payments and expenses is:"<<ratio<<"\n"<<"Sorry, Your monthly payment vs net Income ratio Exceeds 50% ratio";
            return rr.str();
        }
    }
    
