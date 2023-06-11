#include<iostream>
#include<vector>

int fibonacci(int n) {

    std::vector<int> V(n+1, 0);
    V[0] = 0;
    V[1] = 1;

    for(int i =2; i<= n ; ++i) {
        V[i] = V[i-1] + V[i-2];
    }

  return V[n];
}

int main() {
    int n;
    std::cout<<"Enter Number Of Desired Term In Sequence de Fib :"<<std::endl;
    std::cin >> n ;
    int result = fibonacci(n);

    std::cout<< n <<"th Fibonacci Number is "<< result << std::endl;
}