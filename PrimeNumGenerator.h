#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>

using namespace std;

class PrimeNumGenerator
{
  public:
    PrimeNumGenerator();
    int getPrime();
    int power(int x, int y, int p);
    bool isPrime(int p, int k);
    bool millerRabinTest(int d, int p);
    bool QuadResidue(int n, int p);
};
