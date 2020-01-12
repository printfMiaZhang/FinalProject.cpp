#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

class MortCalc{
    
private:
    double P;
    float annual_interest_rate;
    float &i=annual_interest_rate=0.05;
    int years_of_the_loan;
    int &n=years_of_the_loan;
    float monthly_payment;
    float &M=monthly_payment;
    double q;
    
    void Calculateloan()
    {
        M = P*i / ( q*(1 - pow(( 1 + (i/q)),-n*q)));
        total_loan_cost=M*q*n;
        total_interest_paid=total_loan_cost-P;
    }
    
public:
    
    MortCalc(){
        P=0;
        i=0.05;
        n=0;
        q=12;
        Calculateloan();
    }
    int total_loan_cost;
    int total_interest_paid;

    string GetFormattedString()
    {
        stringstream print;
        print<<"Loan amount:"<<P<<"\n"<<"Intereste rate:"<<annual_interest_rate<<"\n"<<"Monthly payment:"<<monthly_payment<<"\n"<<"Total loan:"<<total_loan_cost<<"\n"<<"Total interest:"<<total_interest_paid;
        return print.str();
    }
    
    void SetPrinciple(float principle_amount)
    {
        P = principle_amount;
        Calculateloan();
    }
    
    void Setyears(int years)
    {
        years_of_the_loan=years;
        Calculateloan();
    }
    
    void SetInterest(float AnualInterest)
    {
        annual_interest_rate=AnualInterest;
        Calculateloan();
    }
    
    float getTotalLoan()
    {
        return total_loan_cost;
    }
    
    float getTotalInterest()
    {
        return total_interest_paid;
    }
    
    float getMonthlyPayment()
    {
        return M;
    }
};

class LoanOfficer
{
private:
    MortCalc MC;
    float annual_interest_rate;
    int years_of_the_loan;
    double monthly_income;
    double monthly_expenses;
    float borrow_Amount;
    bool loan_Approved;
    float monthly_payment;
    float netIncome;
    int total_loan_cost;
    int total_interest_paid;
    
    void Caculate()
    {
        monthly_payment=MC.getMonthlyPayment();
        netIncome = (monthly_income-monthly_expenses)*(1-0.13);
        
        if(monthly_payment + monthly_expenses<=0.5*netIncome){
            loan_Approved = true;
        }else {
            loan_Approved = false;
        }
    }
    
public:
    LoanOfficer()
    {
        annual_interest_rate=0.05;
        years_of_the_loan=30;
        MC.SetInterest(annual_interest_rate);
        MC.Setyears(years_of_the_loan);
    }
    
    void SetNetMonthlyIncome(float set)
    {
        monthly_income=set;
        Caculate();
    }
    
    void SetNetMonthlyExpenses(float set)
    {
        monthly_expenses=set;
        Caculate();
    }
    
    void SetBorrowAmount(float set)
    {
        borrow_Amount=set;
        MC.SetPrinciple(borrow_Amount);
        Caculate();
    }
    
    string TheGetIntro()
    {
        stringstream ww;
        ww<<"Welcome to RBC Royal Bank!"<<"\n"<<"Interest Rate = 5.0%"<<"\n"<<"Number of years:"<<years_of_the_loan<<endl;
        return ww.str();
    }
    
    string GetLoanApproval()
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
    
};


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


/* Muyao Zhang 0882423
Final Project
"In the class MortCalc, I declared several variables and created a Calculateloan function which contains the formula for calculating monthly payment, total loan cost and  total interest paid. In the public, I created a default constructor and declared total_loan_cost, total_interest_paid these vaviables. In the function of GetFormattedString, I mainly used output string to output a formatted string that is used to print specific information. In the three set functions, I let the variables equal to the parameters which I created and called the function of Calculateloan. For the Get function, I returned each variables to let the computer read these variables'value. "

"In the class LoanOfficer, firstly I declared several variables in the private and created a MortCalc object called MC. For the Calculate function which also in the private, I used MC to determine the monthly payment, the formula for calculating netincome, and if statement to determine whether or not the loan is approved. In the public, I created a default constructor and passed the annual interest rate and years of the loan. For the three Set functions, same way as the class MortCalc. In the TheGetIntro function, I mainly used output string to output a formatted string that is used to print specific information. In the GetLoanApproval function, I used if-else statement to determine whether the loan is approved."

"In the main function, I created one LoanOfficer object called 'LO' and used 'LO' to show the intro from the LoanOfficer. In the do while loop part, from line 170 to 175, they are about requesting information from the user and reporting loan approval status, and from line 176 to 177, I wrote them in order to be the part to continue. 'Number!=1' represents the Continuing process."

How to run the program: "When you run the code, the output will first display three statemnts and one statement which requires you to enter three numbers that are your income, expenses, and borrow amount. If the ratio of the income versus monthly payment and expenses exceed 50%, the value of ratio between income and monthly payments and expenses will be displayed and the statement of'Sorry, Your monthly payment vs net Income ratio Exceeds 50% ratio' will be printed out. If they are not exceeded, the congrats statement will be showed followed with the value of loan amount, interest rate, monthly payment, total loan, and total interest. And there is also a statement 'We’re looking forward to do business with you!' followed enter any number to continue or enter 1 to exit."

