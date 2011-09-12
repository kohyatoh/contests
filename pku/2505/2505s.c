unsigned i,n,a[99]={9};main(){while(n<16)a[n+1]=a[n]*(n++%2?9:2);a[n]=-1;while(i||~scanf("%u",&n))if(n<=a[i++])puts(i%2?"Stan wins.":"Ollie wins."),i=0;}
