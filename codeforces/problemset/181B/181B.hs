import Data.Array.Unboxed
n=3000
f m=sum[a!(x+x-z,y+y-w)|p@(x,y)<-m,q@(z,w)<-m,p<q]where a=accumArray(+)0((-n,-n),(n,n))$zip m$repeat 1::UArray(Int,Int)Int
t[x,y]=(x,y)
main=interact$show.f.map(t.map read.words).tail.lines
