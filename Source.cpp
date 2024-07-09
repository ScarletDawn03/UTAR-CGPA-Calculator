#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

bool invalidInputHandler(int& value) {
    if (cin.fail() || value < 0) {
        cout << "Invalid format, please try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true;
    }
    return false;
}

bool invalidInputHandler(double& value) {
    if (cin.fail() || value < 0) {
        cout << "Invalid format, please try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true;
    }
    return false;
}

int menu() {
    int choice;
    cout << "UTAR CGPA CALCULATOR" << endl;
    cout << "This program calculates your CGPA and average GPA needed for the following trimesters to graduate first class" << endl;
    cout << "Please select from the following options:" << endl;
    cout << "1. Slow Method (CGPA Checker)" << endl;
    cout << "2. Quick Method\n\n";
    cout << "Choice: ";
    cin >> choice;

    return choice;
}

double firstClassFunction(double sum, int totalHour) {
    int hourLeft;
    while (true) {
        cout << "\nHow many credit hours do you have left? : ";
        cin >> hourLeft;
        if (!invalidInputHandler(hourLeft)) {
            break;
        }
    }
    int accumulatedHour = totalHour + hourLeft;
    double firstClass = ((3.67 * accumulatedHour) - sum) / hourLeft;
    return firstClass;
}

int main() {
    double marks = 0, sum = 0, decimal, y;
    int totalHour = 0, size, hour, accumulated;
    string grade;
    bool stop = false;

    while (!stop) {
        int option = menu();
        if (option == 1) {
            while (true) {
                cout << "Please enter the number of modules you have taken: ";
                cin >> size;
                if (!invalidInputHandler(size)) {
                    break;
                }
            }
            for (int i = 0; i < size; i++) {
                cout << "Please enter your grade for course " << i + 1 << " (e.g., A+, B, C-): ";
                cin >> grade;

                if (grade == "a+" || grade == "A+")
                    marks = 4.0;
                else if (grade == "a" || grade == "A")
                    marks = 4.0;
                else if (grade == "a-" || grade == "A-")
                    marks = 3.67;
                else if (grade == "b+" || grade == "B+")
                    marks = 3.33;
                else if (grade == "b" || grade == "B")
                    marks = 3.0;
                else if (grade == "b-" || grade == "B-")
                    marks = 2.67;
                else if (grade == "c+" || grade == "C+")
                    marks = 2.33;
                else if (grade == "c" || grade == "C")
                    marks = 2.0;
                else if (grade == "f" || grade == "F")
                    marks = 0;
                else {
                    cout << "Invalid Grade. Please try again.\n";
                    i--;
                    continue;
                }

                while (true) {
                    cout << "Please enter your course " << i + 1 << " credit hour: ";
                    cin >> hour;
                    if (!invalidInputHandler(hour)) {
                        break;
                    }
                }

                cout << endl;

                totalHour += hour;
                sum += (marks * hour);
            }

            cout << fixed << setprecision(4);
            cout << "Your CGPA is " << sum / totalHour << endl;
            cout << "Total credit hours accumulated: " << totalHour << endl;

            double x = firstClassFunction(sum, totalHour);
            cout << "In order to graduate with first class (3.67), you will need an average CGPA of: " << x << endl;
            stop = true;

        }
        else if (option == 2) {
            while (true) {
                cout << "What is your current CGPA? (4 decimal places): ";
                cin >> decimal;
                if (!invalidInputHandler(decimal)) {
                    break;
                }
            }

            while (true) {
                cout << "What is the total graded credit hours accumulated?: ";
                cin >> accumulated;
                if (!invalidInputHandler(accumulated)) {
                    break;
                }
            }

            y = firstClassFunction(decimal * accumulated, accumulated);
            cout << "In order to graduate with first class (3.67), you will need an average CGPA of: " << y << endl;
            stop = true;
        }
        else {
            cout << "Invalid Input\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return 0;
}
