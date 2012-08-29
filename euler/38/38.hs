import Data.List

solve = maximum $ concatMap solve' [2..9]
solve' n = filter is $ map (flip cp [1..n]) [1..10^(9 `div` n + 1)]
is = (== "123456789") . sort
cp x = concatMap (show . (*x))

main = putStrLn solve
