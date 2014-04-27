#ifndef KNAPSACK_H
#define	KNAPSACK_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

struct KnapsackItem
{
    int value;
    int weight;
};

class Knapsack
{
    private:
        int** maxValueTable;
        vector<KnapsackItem> itemList;
        int numberOfItems;
        
    public:
        Knapsack(string fileName);
        int maxValueFromWeight(int maxWeight, bool showTable);
        
    private:
        void generateTable(int maxWeight);
        void displayTable(int maxWeight);
                
};

#endif
