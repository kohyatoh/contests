{-# OPTIONS_GHC -O3 -fno-spec-constr-count #-}
{-# LANGUAGE BangPatterns #-}
import Control.Monad
import Control.Applicative
import Data.List
import Data.Int
import Data.Array.Unboxed
import qualified Data.ByteString.Char8 as B
import qualified Data.Char as C

atoi :: B.ByteString -> Int
atoi = B.foldl' (\a c -> a*10 + C.ord c - C.ord '0') 0

type Mat = UArray (Int, Int) Int64

n = 4 :: Int
eye = listArray ((0, 0), (n-1, n-1))
        [if i==j then 1 else 0 | i<-[0..n-1], j<-[0..n-1]]

mul :: Mat -> Mat -> Mat
mul a b = listArray (bounds a) [at i j | i<-[0..n-1], j<-[0..n-1]]
  where at i j = (sum xs) `mod` 1000000007
          where xs = [a!(i, k) * b!(k, j) | k<-[0..n-1]]

pow :: Mat -> Int -> Mat
pow a n
    | n == 0 = eye
    | n `mod` 2 == 1 = a `mul` pow a (n-1)
    | otherwise = let a2 = pow a (n `div` 2) in a2 `mul` a2

solve :: Int -> Int
solve x = fromIntegral $ (pow a x) ! (0, 0)
  where a = listArray (bounds eye)
              [if i==j then 0 else 1 | i<-[0..3], j<-[0..3]]

main = do
    [n] <- map atoi . B.words <$> B.getLine
    putStrLn . show $ solve n
