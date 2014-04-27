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
        
    public:
        Knapsack(string fileName);
        void generateTable();
        void displayTable();
        int maxValue(int maxWeight);
        
    private:
        
};

#endif
