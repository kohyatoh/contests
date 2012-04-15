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
atoi = B.foldl' (\a c -> a*10 + C.ord c - C.ord '0') 0

solve :: Int -> Int -> [Int] -> Int
solve 0 _ xs = length xs
solve 1 _ xs = length . filter (> 0) $ xs
solve p _ [] = 0
solve p s (x:xs)
    | p + (p-1) + (p-1) <= x = 1 + solve p s xs
    | s > 0 && p + (p-2) + (p-2) <= x = 1 + solve p (s-1) xs
    | otherwise = solve p s xs

main = do
    [n] <- map atoi . B.words <$> B.getLine
    forM_ [1..n] $ \i -> do
        _:s:p:xs <- map atoi . B.words <$> B.getLine
        printf "Case #%d: %d\n" i $ solve p s xs
