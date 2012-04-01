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

solve :: Integer -> Integer
solve n = tri (3*n - 2) + 3 * tri (n - 1)

tri :: Integer -> Integer
tri n = (n * (n+1)) `div` 2

main = do
    [n] <- map atoi . B.words <$> B.getLine
    putStrLn . show $ solve (fromIntegral n)
