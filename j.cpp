#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

char first[1000000];
char middle[1000000];
char last[1000000];
char L[3] = {'S', 'O', 'N'};

int main () {
    ull k;
    ull c;
    scanf("%lld %lld\n", &k, &c);
    scanf("%s %s %s", first, middle, last);

    ull first_len = strlen(first);
    ull middle_len = strlen(middle);
    ull last_len = strlen(last);

    // printf("%lld %lld\n", k, c);
    // printf("%s %lld\n", first, first_len);
    // printf("%s %lld\n", middle, middle_len);
    // printf("%s %lld\n", last, last_len);

    ull final_first_len = 3*k + first_len;
    ull first_L_len = 3*k;

    //k==1 means we won't get a front part for middle name
    //for second term 1..k-1 terms... cumsum 1L, 2L 3L, (K-1)L. L=3 for SON
    ull AL_len = k == 1 ? 0 : (k*first_len) + ((k-1)*(3 + (k-1)*3))/2;
    ull ABC_len = first_len + middle_len + last_len;
    
    //from 2..K or 1..K-1 we keep appending C string to middle name
    ull C_len = (k-1)*last_len;
    ull final_middle_len =  C_len;

    if (c < first_len) {
        printf("%c\n", first[c]);
    }
    else if ((c = c - first_len) < first_L_len) { //wiill this mutation happen in this order
        printf("%c\n", L[c%3]);
    }
    else if ((c = c - first_L_len) < AL_len) { //when al_len is 0 then false which is good
        //complex shit
        //to get to an AL k needs to be at least 2
    
        //then in the front part...do the binary search stuff
        ull lower = 1;
        ull upper = k - 2; //for the left bound...we don't need k-1 as that is everything, so k-2
        ull mid = (lower + upper) /2;

        ull lb;
        ull ub;
        while (lower <= upper) {
            mid = (lower + upper) /2;
            lb = (mid+1)*first_len + (mid*(3 + mid*3))/2;
            ub = (mid+2)*first_len + ((mid+1)*(3 + (mid+1)*3))/2;

            if (c < lb) {
                upper = mid - 1;
            } 
            else if (c >= ub) {
                lower = mid + 1;
            }
            else {
                break; //range has been found
            }
        }

        //already confirmed in this area so when binary search finishes we have found it
        //lb will have the length we need
        c = c - lb;
        if (c < first_len) {
            printf("%c\n", first[c]);
        }
        else {
            c = c - first_len;
            printf("%c\n", L[c%3]);
        }   
    }
    else if ((c = c - AL_len) < first_len) {
        printf("%c\n", first[c]);
    }
    else if ((c = c - first_len) < middle_len) {
        printf("%c\n", middle[c]);
    }
    else if ((c = c - middle_len) < last_len) {
        printf("%c\n", last[c]);
    }
    else if ((c = c - last_len) < C_len) {
        c = c % last_len;
        printf("%c\n", last[c]);
    }
    else if ((c = c - C_len) < last_len) {
        printf("%c\n", last[c]);
    }
    else {
        //error...was meant to be handled by the other stuff
    }


    return 0;
}
