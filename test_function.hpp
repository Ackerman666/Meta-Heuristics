#include <iostream>
#include <limits>
#include <cmath>
#include <vector>

using namespace std;

class TestFunctions {
private:
    
    static double Ackley(vector<double> &x, const int d);
    static double Rastrigin(vector<double> &x, const int d);
    static double HappyCat(vector<double> &x, const int d);
    static double Rosenbrock(vector<double> &x, const int d);
    static double Zakharov(vector<double> &x, const int d);
    static double Michalewicz(vector<double> &x, const int d);

public:
  
    static vector<double> get_search_bound(const int func_num);
    static double calculate_test_function(vector<double> &x, const int d, const int func_num);

};


vector<double> inline TestFunctions::get_search_bound(const int func_num)
{
    vector<double> bound;
    double upper, lower;

    switch (func_num)
    {
    case 1:
        upper = 32.768;
        lower = -32.768;
        break;
    case 2:
        upper = 5.12;
        lower = -5.12;
        break;
    case 3:
        upper = 20.0;
        lower = -20.0;
        break;
    case 4:
        upper = 10.0;
        lower = -10.0;
        break;
    case 5:
        upper = 10.0;
        lower = -10.0;
        break;
    case 6:
        upper = M_PI;
        lower = 0.0;
        break;
    default:
        std::cout << "Invalid function number" << std::endl;
        break;
    }
    bound.push_back(lower);
    bound.push_back(upper);
    return bound;
}

double inline TestFunctions::calculate_test_function(vector<double> &x, const int d, const int func_num)
{
    double f = std::numeric_limits<double>::max();
    switch (func_num)
    {
    case 1:
        f = Ackley(x, d);
        break;
    case 2:
        f = Rastrigin(x, d);
        break;
    case 3:
        f = HappyCat(x, d);
        break;
    case 4:
        f = Rosenbrock(x, d);
        break;
    case 5:
        f = Zakharov(x, d);
        break;
    case 6:
        f = Michalewicz(x, d);
        break;
    default:
        std::cout << "Invalid function number" << std::endl;
        break;
    }
    return f;
}

double inline TestFunctions::Ackley(vector<double> &x, const int d)
{
    double sum1 = 0.0, sum2 = 0.0;
    for (int i = 0; i < d; ++i)
    {
        sum1 += x[i] * x[i];
        sum2 += cos(2.0 * M_PI * x[i]);
    }
    return (-20.0) * exp(-0.2 * sqrt(sum1 / double(d))) - exp(sum2 / double(d)) + 20.0 + exp(1.0);
}

double inline TestFunctions::Rastrigin(vector<double> &x, const int d)
{
    double sum1 = 0.0;
    for (int i = 0; i < d; ++i)
    {
        sum1 += (x[i] * x[i]) - (10.0 * cos(2.0 * M_PI * x[i]));
    }
    return sum1 + 10.0 * double(d);
}

double inline TestFunctions::HappyCat(vector<double> &x, const int d)
{
    double sum1 = 0.0, sum2 = 0.0;
    for (int i = 0; i < d; ++i)
    {
        sum1 += x[i] * x[i];
        sum2 += x[i];
    }
    return pow(fabs(sum1 - double(d)), 0.25) + (0.5 * sum1 + sum2) / double(d) + 0.5;
}

double inline TestFunctions::Rosenbrock(vector<double> &x, const int d)
{
    double sum1 = 0.0;
    for (int i = 0; i < d - 1; ++i)
    {
        sum1 += 100.0 * (x[i + 1] - (x[i] * x[i])) * (x[i + 1] - (x[i] * x[i])) + ((x[i] - 1.0) * (x[i] - 1.0));
    }
    return sum1;
}

double inline TestFunctions::Zakharov(vector<double> &x, const int d)
{
    double sum1 = 0.0, sum2 = 0.0;
    for (int i = 0; i < d; ++i)
    {
        sum1 += x[i] * x[i];
        sum2 += 0.5 * (i + 1) * x[i];
    }
    return sum1 + pow(sum2, 2) + pow(sum2, 4);
}

double inline TestFunctions::Michalewicz(vector<double> &x, const int d)
{
    double sum1 = 0.0;
    for (int i = 0; i < d; ++i)
    {
        sum1 += sin(x[i]) * pow(sin((double(i + 1) * x[i] * x[i]) / M_PI), 20.0);
    }
    return sum1 * (-1);
}

