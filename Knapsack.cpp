#include "Knapsack.h"

using namespace std;

/*PUBLIC FUNCTIONS*/

Knapsack::Knapsack(string fileName){}

int Knapsack::maxValueFromWeight(int maxWeight, bool showTable)
{
    generateTable(maxWeight);
    
    if(showTable)
        displayTable(maxWeight);
        
    return maxValueTable[maxWeight][numberOfItems];
}

/*PRIVATE FUNCTIONS*/

void Knapsack::generateTable(int maxWeight){}

void Knapsack::displayTable(int maxWeight){}

