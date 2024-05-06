#include <iostream>
#include <fstream>
#include <chrono> 
#include "smo.hpp"

using namespace std;
using namespace std::chrono; 

int main(){

    for(int i=0 ; i<FUNCTION_LIST.size() ; i++){
        for(int d=0 ; d<DIMENSION.size() ; d++){
            int dimensions = DIMENSION[d];
            std::ofstream outputFile(FUNCTION_LIST[i]+ "_維度" + to_string(dimensions) + ".txt");

            auto start = high_resolution_clock::now(); // 開始計時
            for(int j=1 ; j<=RUNS ; j++){
                

                SMO smo(LOCAL_LIMIT, GLOBAL_LIMIT, POPULATION_SIZE, PERTUBATION_RATE);
                double result = smo.run(FUNCTION_LIST[i], dimensions, j);

                outputFile << "Run" << j <<" Result: " << result << endl;
            }
            auto stop = high_resolution_clock::now(); // 結束計時
            auto duration = duration_cast<milliseconds>(stop - start); // 計算執行時間
            outputFile << "execution time : " << duration.count() << " (milliseconds)" << endl;
            outputFile.close();
        }
    }
    return 0;
}
