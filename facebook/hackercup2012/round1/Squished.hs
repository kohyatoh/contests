import Control.Monad
import Control.Applicative
import Text.Printf
import Data.Char (digitToInt)

digits :: String -> [Int]
digits = tail . scanl step 0
  where step a c = a * 10 + digitToInt c

dp :: Int -> String -> [Integer]
dp _ [] = [1]
dp n s@(c:cs) = a:rs
  where rs = dp n cs
        len = length . takeWhile (<=n) $ digits s
        a = if c == '0'
              then 0
              else (sum . take len $ rs) `mod` 4207849484

solve :: Int -> String -> Integer
solve n s = head $ dp n s

parse :: [String] -> [(Int, String)]
parse (a:b:rs) = (read a, b) : parse rs
parse _ = []

main = do
    xs <- parse . tail . words <$> getContents :: IO [(Int, String)]
    forM_ (zip [1..] xs) $ \(i, (n, s)) -> do
        printf "Case #%d: %d\n" (i::Int) $ solve n s
