import Control.Monad
import Control.Applicative
import Text.Printf

f :: [Int] -> Int -> Int
f ([a, b]) w
    | w < b = a - 1 + w
    | w - b < a - 1 = w - b
    | otherwise = w

solve :: Int -> [[Int]] -> Int
solve w xs = foldr f w xs

gcjMain f m = do
    n <- readLn
    dat <- replicateM n m
    forM_ (zip [1..n] dat) $ \(i, (w, ab)) -> do
        printf "Case #%d: %d\n" i $ solve (w-1) ab + 1

main = gcjMain solve $ do
    [m, c, w] <- map read . words <$> getLine :: IO [Int]
    ab <- replicateM c $ map read . words <$> getLine :: IO [[Int]]
    return (w, ab)

