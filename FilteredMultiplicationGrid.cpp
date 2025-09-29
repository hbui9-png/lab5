#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int num1;
    int num2;
    int product;
    
    for (num1 = 1 ; num1 <= 12; ++num1) {
        for(num2 = 1; num2 <= 12; ++num2) {
            product = num1*num2;
            if (product > 90) break;
            
            else if (num1 == 5 or num1 == 7 or num2 == 5 or num2 ==7 )
            continue;
            
            cout << setw(2) << num1 
                 << " x " << setw(2) << num2 
                 << " = " << setw(3) << product 
                 << endl;
        }
    }
    return 0;
}
