// write cpp program using recursion for fibonacci sequence
#include <iostream>

 int fib(int n) {
                if (n == 0 | n == 1) {
                    return n;
                } 
                else {
                    int num = fib(n-1) + fib(n-2);
                    return num;
                }
             }

 int main() {
   int n;
   std::cout<<"enter"<<std::endl;
   std::cin >> n ;
   int res = fib(n);
   std::cout<<res<<std::endl;

   return 0;
 }