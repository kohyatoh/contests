import Data.List

solve s = maximum . map (product . map readc . take 5) $ tails (s ++ "00000")
readc c = read [c]

main = putStrLn . show . solve . concat . words =<< getContents
