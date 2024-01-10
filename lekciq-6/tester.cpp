#include <iostream>
#include <cmath>

int firstDigit(int n)
{
    while (n >= 10)
    {
        n = n / 10;
    }

    return floor(n);
}

int main()
{
    int n, counter=0,i=0;
    std::cout << "Enter the number for n: ";
    std::cin >> n;


    if (n < 1)
    {
        std::cout << "try again!" << std::endl;
        return 0;
    }

    while (counter != n)
    {
        if (i ==3){
            counter++;
            
            std::cout << i << std::endl;
            i+=1;
        }
        else if (firstDigit(i) == 3 && i % 2 > 0 && i % 3 > 0 && i % 5 > 0 && i % 7 > 0)
        {
            counter++;
           
            std::cout << i << std::endl; 
            i+=1;
        }
        i+=1;
    }

    return 0;
}