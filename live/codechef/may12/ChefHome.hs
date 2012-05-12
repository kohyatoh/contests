{-# OPTIONS_GHC -O3 -fno-spec-constr-count #-}
{-# LANGUAGE BangPatterns #-}
import Control.Monad
import Control.Applicative
import Text.Printf
import Data.List
import Debug.Trace
import qualified Data.ByteString.Char8 as B
import qualified Data.Char as C

atoi :: B.ByteString -> Int
atoi s | B.head s == '-' = - (atoi' $ B.tail s)
       | otherwise = atoi' s

atoi' :: B.ByteString -> Int
atoi' = B.foldl' (\a c -> a*10 + C.ord c - C.ord '0') 0

solve :: [Int] -> [Int] -> Integer
solve xs ys = f xs * f ys

f :: [Int] -> Integer
f xs = fromIntegral $ (as !! (n `div` 2)) - (as !! ((n-1) `div` 2)) + 1
  where n = length xs
        as = sort xs

main = do
    [t] <- map atoi . B.words <$> B.getLine
    replicateM_ t $ do
        [n] <- map atoi . B.words <$> B.getLine
        ts <- transpose <$> replicateM n (map atoi . B.words <$> B.getLine)
        print $ solve (ts !! 0) (ts !! 1)
