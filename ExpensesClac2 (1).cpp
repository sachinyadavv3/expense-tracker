#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Expense {
    string category;
    double amount;
};

bool sortByCategory(const Expense& a, const Expense& b) {
    return a.category < b.category;
}

bool sortByAmount(const Expense& a, const Expense& b) {
    return a.amount < b.amount;
}

double calculateTotalExpense(const vector<Expense>& expenses) {
    double total = 0.0;
    for (const Expense& expense : expenses) {
        total += expense.amount;
    }
    return total;
}

double calculateTotalPerPerson(const vector<Expense>& expenses, int numPeople) {
    double totalExpense = calculateTotalExpense(expenses);
    return totalExpense / numPeople;
}

void displayExpenses(const vector<Expense>& expenses) {
    cout << setw(15) << "Category" << setw(15) << "Amount" << endl;
    cout << setfill('-') << setw(30) << "" << setfill(' ') << endl;

    for (const Expense& expense : expenses) {
        cout << setw(15) << expense.category << setw(15) << expense.amount << endl;
    }

    cout << setfill('-') << setw(30) << "" << setfill(' ') << endl;
}

int findExpenseIndex(const vector<Expense>& expenses, const string& category) {
    for (size_t i = 0; i < expenses.size(); ++i) {
        if (expenses[i].category == category) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

void addExpense(vector<Expense>& expenses) {
    Expense expense;
    cout << "Enter expense category: ";
    cin >> expense.category;

    cout << "Enter expense amount: ";
    cin >> expense.amount;

    expenses.push_back(expense);

    cout << "Expense added successfully!\n";
}

void updateExpense(vector<Expense>& expenses) {
    string category;
    cout << "Enter the category of the expense to update: ";
    cin >> category;

    int index = findExpenseIndex(expenses, category);

    if (index != -1) {
        cout << "Enter new amount for " << category << ": ";
        cin >> expenses[index].amount;
        cout << "Expense updated successfully!\n";
    } else {
        cout << "Expense not found.\n";
    }
}

void deleteExpense(vector<Expense>& expenses) {
    string category;
    cout << "Enter the category of the expense to delete: ";
    cin >> category;

    int index = findExpenseIndex(expenses, category);

    if (index != -1) {
        expenses.erase(expenses.begin() + index);
        cout << "Expense deleted successfully!\n";
    } else {
        cout << "Expense not found.\n";
    }
}

void sortByOption(vector<Expense>& expenses) {
    char sortChoice;
    cout << "Sort by:\n";
    cout << "1. Category\n";
    cout << "2. Amount\n";
    cout << "Enter your choice (1-2): ";
    cin >> sortChoice;

    switch (sortChoice) {
        case '1':
            sort(expenses.begin(), expenses.end(), sortByCategory);
            cout << "Expenses sorted by category.\n";
            displayExpenses(expenses);
            break;
        case '2':
            sort(expenses.begin(), expenses.end(), sortByAmount);
            cout << "Expenses sorted by amount.\n";
            displayExpenses(expenses);
            break;
        default:
            cout << "Invalid choice. Expenses remain unsorted.\n";
    }
}

int main() {
    vector<Expense> expenses;
    int numPeople; // Number of people for splitting expenses
    char choice;

    cout << "Enter the number of people: ";
    cin >> numPeople;

    do {
        cout << "\nExpense Tracker Menu:\n";
        cout << "1. Add Expense\n";
        cout << "2. Update Expense\n";
        cout << "3. Delete Expense\n";
        cout << "4. Display Expenses\n";
        cout << "5. Calculate Total Expense\n";
        cout << "6. Sort Expenses\n";
        cout << "7. Calculate Total Expense Per Person\n";
        cout << "8. Exit\n";
        cout << "Enter your choice (1-8): ";
        cin >> choice;

        switch (choice) {
        case '1':
            addExpense(expenses);
            break;
        case '2':
            updateExpense(expenses);
            break;
        case '3':
            deleteExpense(expenses);
            break;
        case '4':
            displayExpenses(expenses);
            break;
        case '5':
            cout << "Total Expense: " << calculateTotalExpense(expenses) << endl;
            break;
        case '6':
            sortByOption(expenses);
            break;
        case '7':
            cout << "Total Expense Per Person: " << calculateTotalPerPerson(expenses, numPeople) << endl;
            break;
        case '8':
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 8.\n";
        }

    } while (choice != '8');

    return 0;
}
