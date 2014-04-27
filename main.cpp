#include "Knapsack.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc == 2 || argc == 3)
    {
        int maxWeight;
        string fileName = argv[1];
        Knapsack runner(fileName);
        
        runner.generateTable();
        
        if(argc == 3)
            runner.displayTable();
        
        cout << "What is the maximum weight of your knapsack?" << endl;
        cin >> maxWeight;
        
        cout << "The maximum value you can hold in your knapsack is " << runner.maxValue(maxWeight) << endl;
    }
    else
    {
        cout << "Invalid Input" << endl;
    }
    
    return 0;
}
