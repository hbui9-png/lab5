#include <iostream>
#include <fstream> 
#include <string>
#include <iomanip>
using namespace std;
int main()
{ 
    double dailySales;
    int days_recorded;
    double totalSales;
    double currentMax = -1.0;
    double currentMin = 99999.0; ///
    days_recorded = 0;
    totalSales = 0.0;
    
    ofstream outFile;
    outFile.open("sales_report.txt"); // open file to write on
    
    if (!outFile.is_open()) {
        cout << "Could not open file" << endl;
        return 1;
    }
    do {
        cout << "Please enter today's sale or -1 to quit: " << endl;
        cin >> dailySales;
        if (dailySales == -1) {
            break; // exit input
        }
        if (dailySales < 0) {
            cout << "Invalid input, please enter a positive number or -1 to quit.\n";
            continue; 
        }
        days_recorded += 1;
        
        totalSales += dailySales;
        
        if (dailySales < currentMin)  // assign min value
            currentMin = dailySales;
        
        if (dailySales > currentMax)  // max value
            currentMax = dailySales;
            
    } while (true);
    
    

    cout << "--- Sales Report ---" << endl;
    cout << "Days recored : " << fixed << setprecision(2) << days_recorded << endl;
    cout << "Total sales : " << fixed << setprecision(2) << totalSales << endl;
    cout << "Average/day   : $" << totalSales/ days_recorded <<  endl;
    cout << "Lowest day : " << fixed << setprecision(2) << currentMin << endl;
    cout << "Highest day : " << fixed << setprecision(2) << currentMax << endl;
    
    
    outFile << "--- Sales Report ---" << endl;
    outFile << "Days recorded : "  << days_recorded << "\n";
    outFile << "Total sales   : $" << fixed << setprecision(2) << totalSales << "\n";
    outFile << "Average/day   : $" << totalSales/ days_recorded <<  endl;
    outFile << "Lowest day    : $" << currentMin <<  endl;
    outFile << "Highest day   : $" << currentMax <<  endl;
    

    outFile.close();
    
    return 0;
}