import Data.Char
solve = product . map (digitToInt . (d!!)) $ take 7 $ iterate (*10) 1
d = concatMap show [0..]

main = print solve
