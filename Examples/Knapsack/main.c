#include "cgen.h"

#define _POPULATION_IT 100
#define _DARWIN_VALUE 2000
#define _COMMON_CSV_NAME "knapsack_info.csv"
#define _NUM_FILES 1
#define _CHROMOSOME_LNGTH 7

void fit_function(individual i,int* parameters){
    int sum_weight = 0;
    int fitness = 0;
    
    for(int k=0;k<_CHROMOSOME_LNGTH;k++)
    {
        if(i.chromosmes[0].gene[k])
        {
            sum_weight+=parameters[0]; //item_weight
            fitness+=parameters[1]; //item_value
        }
    }
    if(sum_weight > _DARWIN_VALUE) 
    {
        i.fitness = UNFIT;
    }
}

void checker(individual i,int* parameters){
    return;
}


void simulate()
{
    population p;

    FILE* files[_NUM_FILES];
    files[0] = fopen(_COMMON_CSV_NAME,"r");

    load_population(p,files,_NUM_FILES);
    det_fitness(p,fit_function);
    int it = 0;
    while(it < _POPULATION_IT)
    {

        it++;
    }

    delete_population(p);
}

int main()
{
    simulate();
    return 0;
}