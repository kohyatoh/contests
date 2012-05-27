import Control.Applicative
import Text.Printf

solve :: Int -> String -> Double
solve n s = (sum $ map f s) / fromIntegral n

f 'A' = 4.0
f 'B' = 3.0
f 'C' = 2.0
f 'D' = 1.0
f _ = 0.0

main = do
    n <- read <$> getLine
    s <- getLine
    printf "%.9f\n" $ solve n s
