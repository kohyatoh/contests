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

solve :: B.ByteString -> B.ByteString -> Integer
solve s r = a + b
  where a = fromIntegral $ atoi s
        b = fromIntegral $ atoi (B.reverse r)

input :: IO Int
input = do
    [n] <- map atoi . B.words <$> B.getLine
    return n

main = do
    [a, b] <- B.words <$> B.getLine
    putStrLn . show $ solve a b
