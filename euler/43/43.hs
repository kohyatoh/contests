solve = sum $ concat [solve' [1,2,3,5,7,11,13,17] [b,a] a b |
                      a <- [0..9], b <- [0..9], a /= b]
solve' [] rs _ _ = [toi $ reverse rs]
solve' (x:xs) rs a b =
    concat [solve' xs (c:rs) b c |
            c <- [0..9], not $ elem c rs, (a*100 + b*10 + c) `mod` x == 0]
toi = foldl (\a b -> a*10+b) 0

main = print solve
