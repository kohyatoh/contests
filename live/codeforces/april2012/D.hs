solve :: Int -> Int
solve 3 = 1
solve 1 = 2
solve 4 = 2
solve 2 = 3
solve 5 = 1

main = do
    a <- readLn
    putStrLn . show $ solve a
