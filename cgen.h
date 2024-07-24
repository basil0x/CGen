#ifndef _CGEN_H_
#define _CGEN_H_

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define UNFIT 0;

typedef enum{
    ONE_POINT_CRSWR,
    MUL_POINT_CRSWR,
    FLIP_ALEL,
    ALG_MOD,
    ALG_BADD,
    ALG_BAND,
    ALG_BOR,
    ALG_BXOR
}r_type;

typedef enum{
    RANKING,
    ROULETTE,
    TOURNAMENT,
    ELITISM
}s_type;

typedef struct chromosome
{
    double* gene;
    void* fitness;
    int fit_flag;
}chromosome;

typedef struct individual
{
    chromosome* chromosmes;
    void * fitness;
    int fit_flag;
}individual;

typedef struct population
{
    individual* individuals;
    int size;    
    int genes_nmemb;
    int chromosomes_nmemb;
}population;

void error();
void m_error();
void load_population(population p,FILE ** files,int num_files);
void delete_population(population p);
void flag_unfit(population p,void (*checker)(individual i,void* parameters));
void det_fitness(population p,void (*fit_function)(individual i,void* parameters));
void selection(population p,s_type t);
void reproduction(population p,r_type t);




#endif