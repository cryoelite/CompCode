#include <iostream>
// #include <bits/stdc++.h> In G++, provides all necessary headers.

int main()
{
    //std::ios::sync_with_stdio(0); unlink input and output for faster inp/out
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout); to read from file

    // \n is faster than endl;

    //long long x = 123456789123456789LL; 
    // long long a= 2*2  //casts into int then LL, which can give a wrong result, use (long long) 2*2
    //__int128_t in G++, for bigger ints.

    //17 mod 5 =2 , as 17= 3*5+2. Mod m is used to divide a big number into smaller parts,
    /*
    (a+ b) mod m = (a mod m+ b mod m) mod m
    (a- b) mod m = (a mod m - b mod m) mod m
    (a· b) mod m = (a mod m· b mod m) mod m
    */
    // m is usually 10^9 + 7 which can be written as 1e9 + 7
    
    /* We use modulo arithmetic like so,
        auto a= 1LL;
        auto m = pow(10, 9) + 7;
        for(int x=1; x< 10; ++x)
        {
            a= (a*a)%m;
        }
        if(a%m < 0) a+=m; //This ensures the number isn't -ve.
        cout<< a%m<<"\n";
    
    */

    //long double , double is 64 bit while long double is 80 bits.
    // cout.precision(int) to set precision used for displaying floats.
    //Comparing float, floats can have very small rounding errors, to accurately compare them we take a small value as margin of error, it is 10^-9 usually.
    /*
       if(abs(a-b)< 1e-9)
       {
       //a is equal to b as the difference is < 1e-9 
       }

    */

    // In CP, we use typedef or alias for shortening type names. 
    // We also use #define XY push_back where define defines a string that will be replaced by given name to shorten code.
    
    std::cout << "Hello World!\n";
}


//compile with g++ -std=c++11 -O2 -Wall test.cpp -o test
