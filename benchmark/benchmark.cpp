#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>


class Benchmark
{
private:
    int IterationCount = 0;
    double ExecuteTime = 0;

public:
    void SetIterationCount(int count)
    {
        IterationCount = count;
    }
    void SetTestCode(std::function<void()> callback)
    {
        clock_t starttime = clock();
        for (int i = 0; i < IterationCount; ++i)
        {
            callback();
        }
        clock_t endtime = clock();
        
        ExecuteTime = static_cast<double>(endtime - starttime);
        
    }
    double run()
    {
        return ExecuteTime;
    }

    bool operator>(Benchmark benchmark)
    {
        return run() > benchmark.run();
    }
    bool operator<(Benchmark benchmark)
    {
        return run() < benchmark.run();
    }
    bool operator==(Benchmark benchmark)
    {
        return run() == benchmark.run();
    }
    bool operator!=(Benchmark benchmark)
    {
        return run() != benchmark.run();
    }
};

void func(std::vector<int>& vec)
{
    for (auto it : vec)
        std::cout << it << " ";
}

int main()
{

    Benchmark benchmark;
    Benchmark benchmark1;
    /*
    benchmark.SetIterationCount(100000);
    benchmark.SetTestCode([]
    ()
        { std::string name = "vasya"; }
    );



    benchmark1.SetIterationCount(100000);
    benchmark1.SetTestCode([]
    ()
        { char name[6]; strcpy_s(name, "vasya"); }
    );

    benchmark1.SetTestCode(func);

    std::cout << benchmark.run()<<std::endl;
    std::cout << benchmark1.run();
    std::cout << std::boolalpha<< std::endl;
    std::cout << (benchmark > benchmark1) << std::endl;
    std::cout << (benchmark < benchmark1) << std::endl;
    std::cout << (benchmark == benchmark1) << std::endl;
    std::cout << (benchmark != benchmark1) << std::endl;
    */

    std::vector<int> vec {1, 2, 3 };
    std::vector<int> vec1 {1, 2, 3 };

    benchmark.SetIterationCount(1000);
    benchmark.SetTestCode([&](){for (auto it : vec)
        std::cout << it << " "; });

    benchmark1.SetIterationCount(1000);
    benchmark1.SetTestCode([&]() {auto print = [](const int& n) { std::cout << n << ' '; };

    std::for_each(vec1.begin(), vec1.end(), print); });

    std::cout << benchmark.run() << std::endl;
    std::cout << benchmark1.run();




    return 0;
}

