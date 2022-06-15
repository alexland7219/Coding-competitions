#include <iostream>
#include <unistd.h>
using namespace std;

bool a_is_greater_than_b()
{
    string a, b;
    cin >> a >> b;

    if (a.size() > b.size())
        return true;
    else if (a.size() < b.size())
        return false;

    for (int i = 0; i < a.size(); ++i) {
        if (a[i] > b[i])
            return true;
        else if (a[i] < b[i])
            return false;
    }

    return true;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {

        if (a_is_greater_than_b())
            printf("MMM BRAINS\n");
        else
            printf("NO BRAINS\n");
    }
}
