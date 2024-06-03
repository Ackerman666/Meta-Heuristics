#pragma once

#include<unordered_map>
#include<string>
#include<vector>

using namespace std;

const int RUNS = 30;
const int BASE_EVALUATION = 10000;
const vector<int> DIMENSION = {2, 10, 30};
const int POPULATION_SIZE = 64;
const int MAX_GROUP_SIZE = 8;
const int LOCAL_LIMIT = 32;
const int GLOBAL_LIMIT = 32;
const double PERTUBATION_RATE = 0.5;
const double RANDOM_LOCATION_RATE = 0.8;
const int RECORD_PER_EVALUATION = 200; 

const vector<string> FUNCTION_LIST = {
    "Ackley", "Rastrigin", "HappyCat", "Rosenbrock", "Zakharov", "Michalewicz", "Schwefel", "BentCigar", "DropWave", "Step"
};
unordered_map<string, int> TEST_FUNCTION= {
    {"Ackley", 1},
    {"Rastrigin", 2},
    {"HappyCat", 3},
    {"Rosenbrock", 4},
    {"Zakharov", 5},
    {"Michalewicz", 6},
    {"Schwefel", 7},
    {"BentCigar", 8},
    {"DropWave", 9},
    {"Step", 10},
};