#include "Knapsack.h"

using namespace std;

/*PUBLIC FUNCTIONS*/

Knapsack::Knapsack(string fileName)
{
    ifstream infile;
    string temp;
    
    infile.open(fileName.c_str());
    if(!infile)
    {
        cout << "cannot be opened" << endl;
    }
    
    while(getline(infile,temp))
    {
        int stringIterator = 0;
        string tempValue;
        string tempWeight;
        KnapsackItem tempItem;
        
        while(temp[stringIterator] != '.')
        {
            tempValue += temp[stringIterator];
            stringIterator++;
        }   
        stringIterator++;
        
        for(int i = stringIterator; i < temp.length(); i++)
        {
            tempWeight += temp[i];
        }
        
        tempItem.value = atoi(tempValue.c_str());
        tempItem.weight = atoi(tempWeight.c_str());
        
        itemList.push_back(tempItem);
    }
    numberOfItems = itemList.size();
}

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

