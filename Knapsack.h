#ifndef KNAPSACK_H
#define	KNAPSACK_H

#include <iostream>
#include <string>

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
        KnapsackItem* items;
        int numberOfItems;
        
    public:
        Knapsack(string fileName);
        int maxValueFromWeight(int maxWeight, bool showTable);
        
    private:
        void generateTable(int maxWeight);
        void displayTable(int maxWeight);
                
};

#endif
