solve = 1 + bsearch (\m -> b m * 12345 >= a m) 1 100000000000
a m = (bsearch (\x -> x*(x-1) <= m) 1 m) - 1
b m = (bsearch (\x -> (2^x)*(2^x-1) <= m) 1 100)

bsearch p l r
    | r - l <= 1 = l
    | p mid = bsearch p mid r
    | otherwise = bsearch p l mid
  where mid = (l+r) `div` 2
