
#include "../include/Expense.h"
Expense::Expense(double amount,
                 const std::string& category,
                 const std::string& description,
                 const std::string& date)
   : amount(amount),
    category(category),
    description(description),
    date(date) {}

    double Expense::getAmount() const {
       return amount;
   }

    std::string Expense::getCategory() const {
        return category;
    }

    std::string Expense::getDescription() const {
        return description;
    }

    std::string Expense::getDate() const {
        return date;
    }

   