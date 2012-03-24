{-# OPTIONS_GHC -O3 -fno-spec-constr-count #-}
{-# LANGUAGE BangPatterns #-}
import Control.Monad
import Control.Applicative
import Text.Printf
import Debug.Trace
import Data.List
import qualified Data.ByteString.Char8 as B
import qualified Data.Char as C

atoi :: B.ByteString -> Int
atoi = B.foldl' (\a c -> a*10 + C.ord c - C.ord '0') 0

solve :: Int -> [(Int, Int)] -> Int
solve k ps = length $ filter (== p) ps
  where p = (sort ps) !! (k-1)

main = do
    [n, k] <- map atoi . B.words <$> B.getLine
    ps <- replicateM n $ do
        [x, y] <- map atoi . B.words <$> B.getLine
        return (-x, y)
    putStrLn . show $ solve k ps
