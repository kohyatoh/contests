solve = (common ts $ common ps hs) !! 2
ts = [n*(n+1) `div` 2 | n <- [1..]]
ps = [n*(3*n-1) `div` 2 | n <- [1..]]
hs = [n*(2*n-1) | n <- [1..]]
common (a:as) (b:bs)
    | a < b = common as (b:bs)
    | a > b = common (a:as) bs
    | a == b = a : common as bs

main = print solve
