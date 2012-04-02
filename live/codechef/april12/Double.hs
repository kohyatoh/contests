{-# OPTIONS_GHC -O3 -fno-spec-constr-count #-}
{-# LANGUAGE BangPatterns #-}
import Control.Monad
import Control.Applicative
import Debug.Trace
import qualified Data.ByteString.Char8 as B
import qualified Data.Char as C

atoi :: B.ByteString -> Int
atoi = B.foldl' (\a c -> a*10 + C.ord c - C.ord '0') 0

readInt :: IO Int
readInt = atoi . B.takeWhile C.isDigit <$> B.getLine

solve :: Int -> Int
solve n = n - n `mod` 2

main = do
    t <- readInt
    replicateM_ t $ putStrLn . show . solve =<< readInt
