#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

double determine_abs(vector<int>& v, long long int s)
{
    double maxi = 0.0;
    double median, avg;
   
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); ++i) {
        // We'll remove v[i]
	
	if (i < v.size() / 2) median = v[v.size() / 2];
	else		      median = v[v.size() / 2 - 1];

	avg = (double) (s - v[i]);
	avg /= (v.size() - 1);

        if (abs(median - avg) >= maxi)
            maxi = abs(median - avg);
    }

    return maxi;
}

int main()
{
    int k;
    long long int sum;
    while (cin >> k) {
        vector<int> v(k);
	sum = 0;

        for (int i = 0; i < k; ++i){
	    cin >> v[i];
	    sum += v[i];
	}

        double x = determine_abs(v, sum);

        printf("%.2f\n", x);
    }
}
