#include <iostream>
#include <vector>
using namespace std;

int getNumber(vector<vector<char>>& M, int x, int y, int left, char dir, int turns)
{
	// DIRECTIONS
	// X = no direction (initial)
	// N = North
	// S = South
	// E = East
	// W = West
	
	if (left == 0){
		return turns;
	}

	int maxi = -1;

	// Go north
	
	if (x - 1 >= 0 && M[x-1][y] < 2){

		++M[x-1][y];
		
		int t = 0;
		if (dir != 'N' && dir != 'X') ++t; 

		int nord = getNumber(M, x-1, y, left - 1, 'N', turns + t);

		if (nord != -1) if (maxi == -1 || nord < maxi) maxi = nord;

		--M[x-1][y];
	}

	if (x + 1 < M.size() && M[x+1][y] < 2)
	{	
		M[x+1][y]++;

		int t = 0;
		if (dir != 'S' && dir != 'X') ++t;

		int sud = getNumber(M, x+1, y, left-1, 'S', turns + t);

		if (sud != -1) if (maxi == -1 || sud < maxi) maxi = sud;

		M[x+1][y]--;
	}

	if (y - 1 >= 0 && M[x][y-1] < 2){
	
		M[x][y-1]++;

		int t = 0;
		if (dir != 'W' && dir != 'X') ++t;

		int oest = getNumber(M, x, y-1, left-1, 'W', turns+t);

		if (oest != -1) if (maxi == -1 || oest < maxi) maxi = oest;

		M[x][y-1]--;
	}

	if (y+1 < M[0].size() && M[x][y+1] < 2){
	
		M[x][y+1]++;

		int t = 0;
		if (dir != 'E' && dir != 'X') ++t;

		int est = getNumber(M, x, y+1, left-1, 'E', turns+t);

		if (est != -1) if (maxi == -1 || est < maxi) maxi = est;

		M[x][y+1]--;
	}

	return maxi;
}

int main()
{
	int n, m, x, y;
	while (cin >> n >> m >> x >> y)
	{
		--x; --y;

		vector<vector<char>> M(n, vector<char>(m, 0));
		// N rows by M columns

		cout << getNumber(M, x, y, n*m-1, 'X', 0) << endl;

	}
}

