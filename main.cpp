#include <iostream>
#include <fstream>
#include <chrono> 
#include "smo.hpp"


using namespace std;
using namespace std::chrono; 

int main(){

    std::ofstream outputFile[2];
    string folder[2] = {"smo_original/", "smo_levy/"};

    for(int i=0 ; i<FUNCTION_LIST.size() ; i++){
        for(int d=0 ; d<DIMENSION.size() ; d++){
            int dimensions = DIMENSION[d];
            int evalutions = dimensions * BASE_EVALUATION;

            for(int k=0 ; k<2 ; k++){
                outputFile[k].open(folder[k] + FUNCTION_LIST[i]+ "d" + to_string(dimensions) + ".txt");
                auto start = high_resolution_clock::now(); // 開始計時

                for(int j=1 ; j<=RUNS ; j++){
                    switch (k)
                    {
                        // not use levy flight
                        case 0:{
                            SMO smo(LOCAL_LIMIT, GLOBAL_LIMIT, POPULATION_SIZE, PERTUBATION_RATE);
                            double result = smo.run(FUNCTION_LIST[i], dimensions, j, evalutions);
                            outputFile[k] << "Run" << j <<" Result: " << result << endl;
                            break;
                        }
                        // use levy flight
                        case 1:{
                            SMO smo(LOCAL_LIMIT, GLOBAL_LIMIT, POPULATION_SIZE, PERTUBATION_RATE, true);
                            double result  = smo.run(FUNCTION_LIST[i], dimensions, j, evalutions);
                            outputFile[k] << "Run" << j <<" Result: " << result << endl;
                            break;
                        }
                        default:
                            break;
                    }
                }

                auto stop = high_resolution_clock::now(); // 結束計時
                auto duration = duration_cast<milliseconds>(stop - start); // 計算執行時間
                outputFile[k] << "execution time : " << duration.count() << " (milliseconds)" << endl;
                outputFile[k].close();
            }
        }
    }
    return 0;
}
