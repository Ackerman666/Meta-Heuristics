#include <iostream>
#include <fstream>
#include <chrono>
#include <map>
#include <vector>
#include <filesystem>
#include "smo.hpp"
#include "asmo.hpp"


using namespace smo;
using namespace asmo;
using namespace std;
using namespace std::chrono; 

int main(){

    std::ofstream outputFile[3];
    string folders[3] = {"smo_original/", "smo_levy/", "asmo/"};

    for (auto& folder : folders) {
        std::filesystem::create_directories(folder);
    }

    for(int i=0 ; i<FUNCTION_LIST.size() ; i++){
        for(int d=0 ; d<DIMENSION.size() ; d++){
            int dimensions = DIMENSION[d];
            int evalutions = dimensions * BASE_EVALUATION;

            for(int k=0 ; k<3 ; k++){
                outputFile[k].open(folders[k] + FUNCTION_LIST[i]+ "d" + to_string(dimensions) + ".txt");
                auto start = high_resolution_clock::now();
                
                unordered_map<int, vector<double>> record;

                for(int j=1 ; j<=RUNS ; j++){
                    switch (k)
                    {
                        // not use levy flight
                        case 0:{
                            smo::SMO smo(LOCAL_LIMIT, GLOBAL_LIMIT, POPULATION_SIZE, PERTUBATION_RATE, false);
                            double result = smo.run(FUNCTION_LIST[i], dimensions, j, evalutions, record);
                            outputFile[k] << "Run" << j <<" Result: " << result << endl;
                            break;
                        }
                        // use levy flight
                        case 1:{
                            smo::SMO smo(LOCAL_LIMIT, GLOBAL_LIMIT, POPULATION_SIZE, PERTUBATION_RATE, true);
                            double result  = smo.run(FUNCTION_LIST[i], dimensions, j, evalutions, record);
                            outputFile[k] << "Run" << j <<" Result: " << result << endl;
                            break;
                        }
                        // use ASMO (without levy flight)
                        case 2:{
                            asmo::ASMO asmo(LOCAL_LIMIT, GLOBAL_LIMIT, POPULATION_SIZE, PERTUBATION_RATE, true);
                            double result  = asmo.run(FUNCTION_LIST[i], dimensions, j, evalutions, record);
                            outputFile[k] << "Run" << j <<" Result: " << result << endl;
                            break;
                        }
                        default:
                            break;
                    }
                }

                
                for(int e=0; e<record[1].size() ; e++){
                    double acc = 0;
                    for(int j=1 ; j<=RUNS ; j++){
                        acc += record[j][e];
                    }
                    acc /= RUNS;
                    outputFile[k] << "evalution : " << (e+1) * RECORD_PER_EVALUATION << " -----> " << acc << "  (optimal value)" << endl;
                }
                
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<milliseconds>(stop - start);
                outputFile[k] << "execution time : " << duration.count() << " (milliseconds)" << endl;
                outputFile[k].close();
            }
        }
    }
    return 0;
}
