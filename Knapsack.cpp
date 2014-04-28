#include "Knapsack.h"

using namespace std;

/*NON-MEMBER FUNCTIONS*/

unsigned getNumberOfDigits(unsigned i)
{
    return i > 0 ? (int)log10((double)i) + 1 : 1;
}

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
        
        //Find Value from Line
        while(temp[stringIterator] != '.')
        {
            tempValue += temp[stringIterator];
            stringIterator++;
        }   
        stringIterator++;
        
        //Find Weight from Line
        for(int i = stringIterator; i < temp.length(); i++)
        {
            tempWeight += temp[i];
        }
        
        //Add new item to list
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

void Knapsack::generateTable(int maxWeight)
{
    maxValueTable.resize(maxWeight + 1);
    for(int i = 0; i < maxWeight + 1; i++) 
        maxValueTable[i].resize(numberOfItems + 1);
    
    //Knapsack Algorithm
    for(int i = 0; i <= maxWeight; i++)
    {
        maxValueTable[i][0] = 0;
    }
    for(int j = 1; j <= maxWeight; j++)
    {
        for(int i = 0; i <= numberOfItems; i++)
        {
            if(itemList[i].weight > j)
            {
                maxValueTable[j][i] = maxValueTable[j][i-1];
            }
            else
            {
                maxValueTable[j][i] = max(maxValueTable[j][i-1], itemList[i].value + maxValueTable[j - itemList[i].weight][i - 1]);
            }
        }
    }
}

void Knapsack::displayTable(int maxWeight)
{
    //Display Items
    for(int i = 0; i < numberOfItems; i++)
    {
         cout << "Item " << i + 1 << endl
                << "Value: " << itemList.at(i).value << endl
                << "Weight: " << itemList.at(i).weight << endl << endl;
    }
    
    //Display Table
    for(int y = 0; y < numberOfItems; y++)
    {
        for(int x = 0; x <= maxWeight; x++)
        {
            int temp = getNumberOfDigits(maxValueTable[x][y]);
        
            if(x == 0)
                cout << maxValueTable[x][y];
            else
                cout << setw(temp + 2) << maxValueTable[x][y];
        }
        cout << endl;
    }
    
    cout << endl;
}

