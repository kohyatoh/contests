import Control.Monad

solve = take 10 . show . sum
main = putStrLn . solve . map read . lines =<< getContents
