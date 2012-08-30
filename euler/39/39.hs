import Data.List
import Control.Arrow

solve = snd . maximum . map (length &&& head) . group . sort $
    [a + b + c | a <- [1..500], b <- [a..1000-a],
        let c' = sqrt $ fromIntegral (a*a+b*b), floor c' == ceiling c',
        let c = floor c', a + b + c <= 1000]

main = print solve
