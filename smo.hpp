#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

typedef vector<double> solution

// spider monkey optimization
class SMO
{

    private:

        // local leader limit and global leader limit 
        unsigned int     local_limit, global_limit;
        vector<solution> spider_monkeys;


     
        void initialize();


        void localPhase();
        void globalPhase();
        void globalLearning();
        void localLearning();
        void localDecision();
        void globalDecision();

        // update fitness value for each spider monkey
        void updateFitness();

};