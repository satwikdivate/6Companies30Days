#include<bits/stdc++.h>
using namespace std;

 int gcd(long long a,long long b){

        if(a%b==0)
            return b;
        else
            return gcd(b,a%b);

    }

    
    void bs(long long l,long long h,int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2,long long lcm,long long *ans){

        if(l<=h){

            long long m=l+(h-l)/2;

            long long a,b,c;
            a=m-(m/divisor1);
            b=m-(m/divisor2);
            // here we substract element two times sos that we can to add their lcm
            c=m-(m/divisor1)-(m/divisor2)+(m/lcm);

            if(a>=uniqueCnt1 && b>=uniqueCnt2 && a+b-c >=(uniqueCnt1+uniqueCnt2)){
                (*ans)=m;
                 bs(l,m-1,divisor1,divisor2,uniqueCnt1,uniqueCnt2,lcm,ans);
            }else
                bs(m+1,h,divisor1,divisor2,uniqueCnt1,uniqueCnt2,lcm,ans);
        }


    }


    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long g=gcd(divisor1,divisor2);
        long long lcm=(long(divisor1) * long(divisor2))/g;

        long long ans=10000000000;

        bs(2,10000000000,divisor1,divisor2,uniqueCnt1,uniqueCnt2,lcm,&ans);
        return ans;
    }