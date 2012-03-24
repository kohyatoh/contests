{-# OPTIONS_GHC -O3 -fno-spec-constr-count #-}
{-# LANGUAGE BangPatterns #-}
import Control.Monad
import Control.Applicative
import Data.List
import qualified Data.ByteString.Char8 as B
import qualified Data.Char as C

atoi :: B.ByteString -> Int
atoi = B.foldl' (\a c -> a*10 + C.ord c - C.ord '0') 0

solve :: Int -> [Int] -> Int
solve x xs
    | xs !! m == x = 0
    | otherwise = 1 + (solve x $ insert x xs)
  where m = (length xs - 1) `div` 2

main = do
    [n, x] <- map atoi . B.words <$> B.getLine
    xs <- sort . map atoi . B.words <$> B.getLine
    putStrLn . show $ solve x xs
