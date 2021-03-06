#include<iostream>
#include<string>
#include<ctime>
#include<sstream>
#include<stdlib.h>

#include"testingAux.h"
#include"Histogram.hpp"

int main(int argc, char const *argv[])
{
    //std::cout << "Hello, world!" << std::endl;
    
    long dataSize = 20;
    bool isDebugEnabled = false;

    if(argc > 1)
    {
        dataSize = atoi(argv[1]);
    }

    if(argc > 2)
    {
        long temp = atoi(argv[2]);
        
        if(temp == 1)
            isDebugEnabled = true;
    }

    Histogram test;


    for (long i = 0; i < 256; i++)
    {
        test.AddRange((double)i);
    }

    std::vector<double> data;
    srand(500);
    const long formattedDataSize = dataSize * 4;

    for (size_t i = 0; i < formattedDataSize; i++)
    {
        data.push_back((double) (rand() % 256));
    }

    clock_t startTime = clock();
    test.Analyze(data.data(), data.size());
    clock_t endTime = clock();

    double processDuration = (double)(endTime - startTime)/ CLOCKS_PER_SEC;

    std::stringstream results;
    results << std::fixed << formattedDataSize << " , " << processDuration << " , " << "SERIAL , 1" << std::endl;

    if(isDebugEnabled)
    {
        std::cout << test << std::endl;
        std::cout << results.str() << std::endl;
    }

    TestingAux::WriteToResults(results);

    return 0;
}
