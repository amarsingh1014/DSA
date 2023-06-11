#include <iostream>
#include<math.h>

int main() {
    int num1, num2;
    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter the second number: ";
    std::cin >> num2;

    int temp1 = num1;
    int temp2 = num2;
    int lcm = 1;
    int i = 2;
    while (num1 != 1 || num2 != 1) {
        int count1 = 0, count2 = 0;

        while (num1 % i == 0) {
            count1++;
            num1 /= i;
        }

        while (num2 % i == 0) {
            count2++;
            num2 /= i;
        }

        int power = (count1 >= count2) ? count1 : count2;
        lcm *= pow(i, power);

        i++;
    }

    std::cout << "LCM of " << temp1 << " and " << temp2 << " is: " << lcm << std::endl;

    return 0;
}
