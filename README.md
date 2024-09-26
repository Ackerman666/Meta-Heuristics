# Spider-Monkey-Optimization-Algorithm

This project implements two algorithms in C++: Spider Monkey Optimization (SMO) and Ageist Spider Monkey Optimization (ASMO), and provides 10 test functions to evaluate their optimization capabilities.

## References

- [**Spider Monkey Optimization Algorithm for Numerical Optimization**](https://jcbansal.scrs.in/uploads/3-Spider_Monkey_Optimization.pdf)  
  Bansal, J. C., Sharma, H., Jadon, S. S., & Clerc, M. (2014).

- [**Ageist Spider Monkey Optimization Algorithm**](https://www.sciencedirect.com/science/article/pii/S2210650216000122)  
  Sharma, A., Sharma, A., Panigrahi, B. K., Kiran, D., & Kumar, R.


## Test Functions
There are 10 test functions:
- Ackley
- Rastrigin
- HappyCat
- Rosenbrock
- Zakharov
- Michalewicz
- Schwefel
- BentCigar
- DropWave
- Step

You can configure the desired dimensions in `config.hpp`.

## Prerequisites

To build and run this project, you need the following installed on your system:
- GCC or Clang (or any C++ compiler supporting C++11 or later)
- `make`

## Build Instructions

1. Clone this repository to your local machine
2. Navigate into the project directory
3. To compile the project and generate the executable run, and start testing the test functions, simply run:
```shell
make && ./run
```

Each Run has a fixed number of evaluations available to update parameters. 
It will display the minimum value found for the test function in each run and calculate the average optimal value found after n evaluations.

```
Run1 Result: 4.44089e-16
Run2 Result: 4.44089e-16
Run3 Result: 4.44089e-16
Run4 Result: 4.44089e-16
Run5 Result: 4.44089e-16
....
Run30 Result: 4.44089e-16
evalution : 200 -----> 5.18057  (optimal value)
evalution : 400 -----> 3.15087  (optimal value)
evalution : 600 -----> 0.803309  (optimal value)
evalution : 800 -----> 0.301036  (optimal value)
evalution : 1000 -----> 0.036973  (optimal value)
evalution : 1200 -----> 0.0142948  (optimal value)
evalution : 1400 -----> 0.00306729  (optimal value)
evalution : 1600 -----> 0.00163059  (optimal value)
evalution : 1800 -----> 0.000496233  (optimal value)
evalution : 2000 -----> 0.00015637  (optimal value)
evalution : 2200 -----> 8.04973e-05  (optimal value)
....
evalution : 20000 -----> 4.44089e-16  (optimal value)
```
