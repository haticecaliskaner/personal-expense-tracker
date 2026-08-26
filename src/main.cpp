#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/Expense.h"

int main() {

    std::vector<Expense> expenses;

    
    std::ifstream file("data/expenses.txt");
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);

        std::string amountStr, category, description, date;

        std::getline(iss, amountStr, ',');
        std::getline(iss, category, ',');
        std::getline(iss, description, ',');
        std::getline(iss, date);

        double amount = std::stod(amountStr);

        expenses.push_back(Expense(amount, category, description, date));
    }

    file.close();

    
    while (true) {

        std::cout << "\n1. Add Expense\n";
        std::cout << "2. Show Expenses\n";
        std::cout << "3. Total Amount\n";
        std::cout << "4. Max & Min Expense\n";
        std::cout << "5. Category Totals\n";
        std::cout << "6. Average Expense\n";
        std::cout << "7. Delete Expense\n";
        std::cout << "8. Search Category\n";
        std::cout << "0. Exit\n";

        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {

        
        case 1: {
            std::string amountStr, category, description, date;

            std::cout << "Enter amount: ";
            std::getline(std::cin, amountStr);
            double amount = std::stod(amountStr);

            std::cout << "Enter category: ";
            std::getline(std::cin, category);

            std::cout << "Enter description: ";
            std::getline(std::cin, description);

            std::cout << "Enter date: ";
            std::getline(std::cin, date);

            expenses.push_back(Expense(amount, category, description, date));

            break;
        }

        
        case 2: {
            if (expenses.empty()) {
                std::cout << "No expenses!\n";
                break;
            }

            for (int i = 0; i < expenses.size(); i++) {
                std::cout << "Amount: " << expenses[i].getAmount() << "\n";
                std::cout << "Category: " << expenses[i].getCategory() << "\n";
                std::cout << "Description: " << expenses[i].getDescription() << "\n";
                std::cout << "Date: " << expenses[i].getDate() << "\n";
                std::cout << "----------------------\n";
            }

            break;
        }

        
        case 3: {
            double total = 0;

            for (int i = 0; i < expenses.size(); i++) {
                total += expenses[i].getAmount();
            }

            std::cout << "Total: " << total << "\n";
            break;
        }

        
        case 4: {
            if (expenses.empty()) {
                std::cout << "No expenses!\n";
                break;
            }

            Expense maxExpense = expenses[0];
            Expense minExpense = expenses[0];

            for (int i = 1; i < expenses.size(); i++) {
                if (expenses[i].getAmount() > maxExpense.getAmount())
                    maxExpense = expenses[i];

                if (expenses[i].getAmount() < minExpense.getAmount())
                    minExpense = expenses[i];
            }

            std::cout << "MAX: " << maxExpense.getAmount() << " " << maxExpense.getCategory() << "\n";
            std::cout << "MIN: " << minExpense.getAmount() << " " << minExpense.getCategory() << "\n";

            break;
        }

        
        case 5: {
            double food = 0, transport = 0;

            for (int i = 0; i < expenses.size(); i++) {
                if (expenses[i].getCategory() == "food")
                    food += expenses[i].getAmount();

                else if (expenses[i].getCategory() == "transport")
                    transport += expenses[i].getAmount();
            }

            std::cout << "Food total: " << food << "\n";
            std::cout << "Transport total: " << transport << "\n";

            break;
        }

        
        case 6: {
            if (expenses.empty()) {
                std::cout << "No expenses!\n";
                break;
            }

            double total = 0;

            for (int i = 0; i < expenses.size(); i++) {
                total += expenses[i].getAmount();
            }

            std::cout << "Average: " << total / expenses.size() << "\n";
            break;
        }

        
        case 7: {
            if (expenses.empty()) {
                std::cout << "No expenses!\n";
                break;
            }

            for (int i = 0; i < expenses.size(); i++) {
                std::cout << i << ": "
                          << expenses[i].getAmount() << " "
                          << expenses[i].getCategory() << " "
                          << expenses[i].getDescription() << "\n";
            }

            int index;
            std::cout << "Enter index: ";
            std::cin >> index;

            if (index < 0 || index >= expenses.size()) {
                std::cout << "Invalid index!\n";
                break;
            }

            expenses.erase(expenses.begin() + index);

            std::cout << "Deleted!\n";

            break;
        }

        
        case 8: {
            std::cout << "Enter category: ";

            std::string filter;
            std::getline(std::cin, filter);

            bool found = false;

            for (int i = 0; i < expenses.size(); i++) {
                if (expenses[i].getCategory() == filter) {
                    std::cout << expenses[i].getAmount() << " "
                              << expenses[i].getDescription() << " "
                              << expenses[i].getDate() << "\n";

                    found = true;
                }
            }

            if (!found)
                std::cout << "No results found!\n";

            break;
        }

        
        case 0: {
            std::ofstream file("data/expenses.txt");

            for (const auto& expense : expenses) {
                file << expense.getAmount() << ","
                     << expense.getCategory() << ","
                     << expense.getDescription() << ","
                     << expense.getDate() << "\n";
            }

            file.close();

            std::cout << "Saved. Bye!\n";
            return 0;
        }

        default:
            std::cout << "Invalid choice!\n";
        }
    }
}