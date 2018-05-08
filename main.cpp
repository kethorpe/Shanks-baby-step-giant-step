#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include "PrimeNumGenerator.h"
#include "Shanks.h"

using namespace std;

main(int argc, char* argv[])
{
  srand(time(NULL));
  int h = 19;
  int p = 19079;
  int g = 17;
  /*PrimeNumGenerator gs;
  do{
	cout << "p is: " << p << endl;
    p = gs.getPrime();
  }while(!gs.isPrime(p, 10)); //Miller Rabin Test

  //g = rand() % p;
  */
  /*do{
    h = rand() % p;
  }while(!gs.QuadResidue(h,p)); //checks if h is a quadratic residue of p
  */

  Shanks s(g,p, h); //g^x is congruent to h % p
}
