solve = maximum $ factors 600851475143
factors = factors' 2
factors' m x
    | m*m > x = [x]
    | x `mod` m == 0 = m : factors' m (x `div` m)
    | otherwise = factors' (m+1) x

main = print solve
