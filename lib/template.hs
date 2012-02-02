import Control.Monad
import Text.Printf

solve :: Int -> Int
solve n = n

input :: IO Int
input = do
    n <- readLn
    return n

main = do
    n <- readLn :: IO Int
    forM_ [1..n] $ \i -> do
        n <- input
        let ans = solve n
        printf "Case #%d: %d\n" i ans
