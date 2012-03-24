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

solve :: Int -> Int
solve n = n

input :: IO Int
input = do
    n <- atoi . head . B.words <$> B.getLine
    return n

main = do
    n <- atoi . head . B.words <$> B.getLine
    forM_ [1..n] $ \i -> do
        n <- input
        let ans = solve n
        printf "Case #%d: %d\n" i ans
