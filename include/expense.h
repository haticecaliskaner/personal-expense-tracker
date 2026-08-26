#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>

class Expense {
    private:
        double amount;
        std::string category;
        std::string description;
        std::string date;       
    public:
       Expense(double amount,
                const std::string& category,
                const std::string& description,
                const std::string& date);


        double getAmount() const;
        std::string getCategory() const;
        std::string getDescription() const;
        std::string getDate() const; 
        
};
#endif