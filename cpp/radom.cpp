#include <time.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vadefs.h>


int main()
{
    srand(time(NULL));

    int i = 0;

    int key;

    bool is_sun;

    for(i = 0;i < 10;i++)
    {
        key = rand();
        if((key%100) < 45)
            is_sun = true;
        else
            is_sun = false;
    }

    if(is_sun)
        std::cout <<  "go to the sun" << std::endl;
    else
        std::cout << "don't go to the sun" << std:: endl;



    return 0;
}