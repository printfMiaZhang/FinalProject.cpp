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
    
    void Calculateloan();
    
public:
    MortCalc();
    
    int total_loan_cost;
    int total_interest_paid;
    
    string GetFormattedString();
    void SetPrinciple(float principle_amount);
    void Setyears(int years);
    void SetInterest(float AnualInterest);
    float getTotalLoan();
    float getTotalInterest();
    float getMonthlyPayment();
};


