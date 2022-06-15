#include <iostream>
#include <random>
#include <vector>
using namespace std;

mt19937 rng;

vector<int> snakes =
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,10, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,21, 0, 0,38, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,43, 0, 4, 0, 0, 0, 0, 0, 0,
    0, 0, 0,21, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,21, 0,
    0, 4, 0, 0,20, 0, 0, 0,19, 0 };

vector<int> ladders =
  { 0,36, 0, 0, 0, 0, 7,23, 0, 0,
    0, 0, 0, 0,11, 0, 0, 0, 0, 0,
   21, 0, 0, 0, 0, 0, 0,56, 0, 0,
    0, 0, 0, 0, 0, 8, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   16, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   20, 0, 0, 0, 0, 0, 0,20, 0, 0,
    0, 0, 0, 0, 0, 0, 7, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

int main()
{
    long int s;
    while (cin >> s) {

        rng.seed(s);
       
        int b, r, d;
        unsigned int k;
        
        b = 1;
        r = 1;
       
        bool ended = false;

        while (!ended) {

            // RED PLAYS first
    	    do {
                k = rng();
                d = k % 6 + 1;

                r += d;

                if (r == 100) {
                    // RED HAS WON
                    ended = true;
                    break;
                }
                else if (r > 100) {
                    r -= 2 * (r - 100);
                }

                if (snakes[r - 1] != 0)
                    r -= snakes[r - 1];
                else if (ladders[r - 1] != 0)
                    r += ladders[r - 1];

            } while ( d == 6 );

            if (ended) break;

            // BLUE PLAYS NEXT

            do {
                k = rng();
                d = k % 6 + 1;

                b += d;

                if (b == 100){
                    // BLUE HAS WON
                    ended = true;
                    break;
                }
                else if (b > 100){
                    b -= 2 * (b - 100);
                }

                if (snakes[b - 1] != 0)
                    b -= snakes[b - 1];
                else if (ladders[b - 1] != 0)
                    b += ladders[b - 1];

            } while ( d == 6 );
        }

        if (r == 100)
            cout << "RED" << endl;
        else
            cout << "BLUE" << endl;
    }
}
