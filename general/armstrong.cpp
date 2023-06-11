#include <iostream>

int main() {
  int a=0, i=0, m=0 ;

  for (i=1; i<=500; i++) {
    m=i;
    a=0;
 while (m > 0 ) {
    a = a + (m%10)*(m%10)*(m%10);
    m= m/10;
 }
 if (a == i ) {
   std::cout<< a <<" ";
 }

  }  


    return 0;
}