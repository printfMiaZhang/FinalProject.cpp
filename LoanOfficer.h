using namespace std;

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
    
    void Caculate();
    
public:
    LoanOfficer();
    void SetNetMonthlyIncome(float set);
    void SetNetMonthlyExpenses(float set);
    void SetBorrowAmount(float set);
    string TheGetIntro();
    string GetLoanApproval();
};
