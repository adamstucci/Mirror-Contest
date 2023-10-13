#include <iostream>
#include <iterator>
#include <set>
#include <cmath>

using namespace std;

typedef long long ll;

multiset<int> sizes;

int main() {
    int n;
    int s;
    int h;
    scanf("%d %d %d", &n, &s, &h);

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        sizes.insert(val);
    }

    
    while (!sizes.empty() && h > 0) {
        auto lb_iter = sizes.lower_bound(s);
        // int val = *lb_iter;
        int val;

        
        //if not at start, can walk iterator back 1
        if (lb_iter != sizes.begin()) {
            lb_iter--;
            val = *lb_iter;
            if (val >= s) break;
        }

        //otherwise nothing left we are big enough to consume
        else {
            break;
        }

        //now we have something we can consume
        s += ceil(sqrt(val));
        //remove only this copy from multiset
        sizes.erase(lb_iter);
        h--; //decrement day
    }

    printf("%d\n", s);
}