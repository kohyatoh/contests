solve = length . filter (>1000000) . concat . take 101 $ iterate f [1]
f xs = let ys = 0:xs in zipWith (+) ys (reverse ys)

main = print solve
