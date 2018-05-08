#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "Shanks.h"

using namespace std;

Shanks::Shanks(int n, int p, int l){
  int m = (int)sqrt(p) + 1;
  //cout << "m is: " << m << endl;

  int g[m];
  int h[m];
  for(int i = 1; i < m; i++){
    g[i] = power(n,i,p);
  //  cout << g[i] << " ";
  }
  cout << endl;

  int inv = getInverse(n,p);
  int s = power(inv, m, p);

  //cout << "inv is: " << inv << endl << "s is: " << s << endl;

  for(int i = 1; i < m; i++){
    int mod = power(s, i, p);
    //int pw = power(inv, i, p);
    //cout << "mod = " << mod << endl;
    h[i] = l*mod % p;
    //cout << h[i] << endl;
    for(int j = 1; j < m; j++){
      if(h[i] == g[j]){
        cout << endl <<"x = " << i*m + j << " is discrete log since " << n;
        cout << "^" << j << " mod " << p << " = " << l << "*" << n << "^-" << i*m << " mod " << p << endl;
        cout << n << "^" << i*m + j << " congruent to " << l << " mod " << p << endl;
        return;
      }
    }
  }

  cout << "There is no descrete log for this problem" << endl;

}

int Shanks::power(int x, int y, int p)
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
}

int Shanks::getInverse(int n, int p){
  int m0 = p, t, q;
    int x0 = 0, x1 = 1;

    if (p == 1)
      return 0;

    while (n > 1)
    {
        q = n / p;

        t = p;

        p = n % p, n = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }

    if (x1 < 0)
       x1 += m0;

    return x1;
}
