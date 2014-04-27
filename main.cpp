#include "Knapsack.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc == 2 || argc == 3)
    {
        int maxWeight;
        int maxValue;
        string fileName = argv[1];
        Knapsack runner(fileName);

        cout << "What is the maximum weight of your knapsack?" << endl;
        cin >> maxWeight;
        
        if(argc == 3)
        {
            maxValue = runner.maxValueFromWeight(maxWeight, true);
        }
        else
        {
            maxValue = runner.maxValueFromWeight(maxWeight, false);
        }
        
        cout << "The maximum value you can hold in your knapsack is " << maxValue << endl;
    }
    else
    {
        cout << "Invalid Input" << endl;
    }
    
    return 0;
}
