#include <bits/stdc++.h>

using namespace std;

const long long pow_precision=30;
const long long sum_precision=10000;

long double power(long long k, long double p)
{
    long double sum=1;
    long double first_log=p*log(k), current_log=1;

    for(auto i=1; i<=pow_precision; i++)
    {
        current_log/=i;
        current_log*=first_log;
        sum+=current_log;
    }

    return sum;
}

long double sum(long double pow)
{
    long double result=0;

    for(long long i=1; i<sum_precision; i++)
    {
        long double pw=power(i, pow);
        result+=(long double)1/(i*pw);
    }

    return result;
}

int main()
{
    long double limit;
    cin>>limit;

    long double l=0.9d, r=0.999d, current_res=0;
    cout<<fixed;
    cout<<setprecision(100);

    while(abs(current_res-limit)>0.00000000000000000001d)
    {
        long double mid=(l+r)/2;
        current_res=sum(mid);

        if(current_res>limit)
            l=mid;
        else
            r=mid;

        cout<<mid<<" "<<current_res<<"\n";
    }

    return 0;
}
