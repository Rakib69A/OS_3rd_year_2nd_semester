#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int h){
    int temp;
    while(1){
        temp = a%h;
        if(temp==0)
            return h;
        a = h;
        h = temp;
    }
}
int main(){
    double p = 3;
    double q = 7;
    double n = p*q;
    double count;
    double totient = (p-1)*(q-1);

    double e = 2;
    
    while(e<totient){
        count = gcd(e,totient);
        if(count==1)
            break;
        else 
            e++;
    }
    double d, k = 2;
    d = (1+(k*totient))/e;
    double msg = 12;
    double c = pow(msg,e);
    double m = pow(c,d);
    c = fmod(c,n);
    m = fmod(m,n);

    cout<<"Message data = "<<msg<<end;
    cout<<"p = "<<p<<endl;
    cout<<"q = "<<q<<endl;
    cout<<"n = pq "<<n<<endl;
    cout<<"totient = "<<totient<<endl;
    cout<<"e = "<<e<<endl;
    cout<<"d = "<<e<<endl;
    cout<<"Encrypt data = "<<c<<end;
    cout<<"Original Message sent = "<<m<<endl;

    return 0;

}