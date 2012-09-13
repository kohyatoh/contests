import Data.List
solve = head $ filter is [1..]
is x = 1 == (length . group . sort . map (sort . show . (x*))) [1..6]

main = print solve
