{-# OPTIONS_GHC -O3 -fno-spec-constr-count #-}
import Control.Monad
import Control.Applicative
import Text.Printf
import Data.List
import qualified Data.ByteString.Char8 as B
import qualified Data.Char as C
import Control.Monad.ST
import Data.Array.Unboxed
import Data.Array.ST

atoi :: B.ByteString -> Int
atoi = B.foldl' (\a c -> a*10 + C.ord c - C.ord '0') 0

f :: Int -> Int -> Int
f d = foldl' step 0 . takeWhile (>0) . iterate (`div` 10)
  where step a x | x `mod` 10 == d = a + 1
                 | otherwise = a

fseq :: [Int]
fseq = scanl step 0 [1..]
  where step s x = s + f 4 x - f 7 x

maxN = 100000

sums :: UArray Int Int
sums = runSTUArray $ do
    a <- newArray (0, maxN) 0 :: ST s (STUArray s Int Int)
    cnt <- newArray (0, 20000) 0 :: ST s (STUArray s Int Int)
    writeArray cnt 0 1
    forM_ (zip [1..maxN] $ tail fseq) $ \(i, s) -> do
        pre <- readArray a (i-1)
        c <- readArray cnt s
        writeArray a i (pre+c)
        writeArray cnt s (c+1)
    return a

solve :: Int -> Int
solve n = sums ! n

main = do
    (_:xs) <- map atoi . B.words <$> B.getContents
    forM_ xs $ printf "%d\n" . solve
