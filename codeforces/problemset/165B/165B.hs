{-# OPTIONS_GHC -O3 -fno-spec-constr-count #-}
import Control.Monad
import Control.Applicative
import Debug.Trace
import qualified Data.ByteString.Char8 as B
import qualified Data.Char as C

atoi :: B.ByteString -> Int
atoi = B.foldl' (\a c -> a*10 + C.ord c - C.ord '0') 0

bisearch :: (Int -> Bool) -> Int -> Int -> Int
bisearch p lo hi
    | lo+1 == hi = hi
    | p mid = bisearch p lo mid
    | otherwise = bisearch p mid hi
  where mid = (lo + hi) `div` 2

solve :: Int -> Int -> Int
solve n k = bisearch ((>=n) . sumline k) 0 n

sumline :: Int -> Int -> Int
sumline k = sum . takeWhile (> 0) . iterate (flip div k)

main = do
    [n, k] <- map atoi . B.words <$> B.getLine
    putStrLn . show $ solve n k
