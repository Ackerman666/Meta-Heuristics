#include<unordered_map>
#include<string>
#include<vector>

using namespace std;

const int RUNS = 30;
const int BASE_EVALUATION = 10000;
const vector<int> DIMENSION = {2, 10, 30};
const int POPULATION_SIZE = 64;
const int MAX_GROUP_SIZE = 8;
const int LOCAL_LIMIT = 64;
const int GLOBAL_LIMIT = 64;
const double PERTUBATION_RATE = 0.6; 

const vector<string> FUNCTION_LIST = {
    "Ackley", "Rastrigin", "HappyCat", "Rosenbrock", "Zakharov", "Michalewicz"
};
unordered_map<string, int> TEST_FUNCTION= {
    {"Ackley", 1},
    {"Rastrigin", 2},
    {"HappyCat", 3},
    {"Rosenbrock", 4},
    {"Zakharov", 5},
    {"Michalewicz", 6}
};