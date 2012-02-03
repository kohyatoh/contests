{-# OPTIONS_GHC -O3 #-}
import Control.Monad
import Control.Applicative
import Text.Printf
import Data.List
import qualified Data.ByteString.Char8 as B
import qualified Data.Char as C

atoi :: B.ByteString -> Int
atoi = B.foldl' (\a c -> a*10 + C.ord c - C.ord '0') 0

solve :: [Int] -> (Int, Int)
solve xs = (-nv, c)
  where (c, nv) = maximum . map toPair . group . sort $ xs
        toPair ys = (length ys, negate $ head ys)

input :: IO [Int]
input = do
    _ <- B.getLine
    map atoi <$> B.words <$> B.getLine

output :: (Int, Int) -> IO ()
output (v, c) = printf "%d %d\n" v c

main = do
    n <- atoi <$> B.takeWhile C.isDigit <$> B.getLine
    replicateM_ n $ input >>= output . solve
