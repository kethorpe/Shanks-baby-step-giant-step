#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "PrimeNumGenerator.h"

using namespace std;

PrimeNumGenerator::PrimeNumGenerator(){

};


int PrimeNumGenerator::getPrime(){
  /* initialize random seed: */
    srand(time(NULL));

    int n;
    int random;
    n = rand() % 10000 + 1000;

    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }

    while(true){
      random = rand() % n;
      if(prime[random]){
        return random;
      }
    }

};

int PrimeNumGenerator::power(int x, int y, int p)
{
	int res = 1;
	x = x % p;

	while (y > 0)
	{
		if (y & 1)
			res = (res*x) % p;

		y = y>>1; // y = y/2
		x = (x*x) % p;
	}
	return res;
};

bool PrimeNumGenerator::millerRabinTest(int d, int p)
{
    int a = 2 + rand() % (p - 4);
	cout << a << endl;

    int x = power(a, d, p);

    if (x == 1  || x == p-1)
       return true;

    while (d != p-1)
    {
        x = (x * x) % p;
        d *= 2;

        if (x == 1)      return false;
        if (x == p-1)    return true;
    }

    return false;
};

bool PrimeNumGenerator::isPrime(int p, int k)
{
    if (p <= 1 || p == 4)  return false;
    if (p <= 3) return true;

    int d = p - 1;
    while (d % 2 == 0)
        d /= 2;

    for (int i = 0; i < k; i++)
         if (millerRabinTest(d, p) == false)
              return false;

    return true;
};

bool PrimeNumGenerator::QuadResidue(int n, int p){
  if (power(n, (p-1)/2, p) == 1){
    if(n!=1){
      return true;
    }
  }
  return false;
}
