import Data.List

solve = maximum $ concatMap solve' [n | n <- [1..9], sum [1..n] `mod` 3 /= 0]
solve' n = filter isPrime $ map toInt $ permutations [1..n]
isPrime n = all ((/=0) . mod n) $ takeWhile (\x -> x*x <= n) [2..]
toInt = foldl' (\a b -> a*10+b) 0

main = print solve
