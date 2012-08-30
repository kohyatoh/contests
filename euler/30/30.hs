f = sum . map (^5) . map (`mod` 10) . takeWhile (/= 0) . iterate (`div` 10)
solve = sum $ filter (\x -> f x == x) [2..999999]

main = print solve
