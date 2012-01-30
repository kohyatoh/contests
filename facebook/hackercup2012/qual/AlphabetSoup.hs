import Control.Monad
import Text.Printf

count :: Char -> String -> Int
count c = length . filter (== c)

solve :: String -> String -> Int
solve s t = minimum . flip map t $ \c -> (count c s) `div` (count c t)

input :: IO String
input = getLine

main = do
    n <- readLn :: IO Int
    forM_ [1..n] $ \i -> do
        dat <- input
        let ans = solve dat "HACKERCUP"
        printf "Case #%d: %d\n" i ans
