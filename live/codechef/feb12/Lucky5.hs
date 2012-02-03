{-# OPTIONS_GHC -O3 #-}
import Control.Monad
import Control.Applicative
import Text.Printf
import qualified Data.ByteString.Char8 as B
import qualified Data.Char as C

atoi :: B.ByteString -> Int
atoi = B.foldl' (\a c -> a*10 + C.ord c - C.ord '0') 0

solve :: B.ByteString -> Int
solve = B.foldl' step 0
  where step a c | c == '4' || c == '7' || c == '\r' = a
                 | otherwise = a + 1

main = do
    n <- atoi <$> B.takeWhile C.isDigit <$> B.getLine
    replicateM_ n $ do
        s <- B.getLine
        printf "%d\n" $ solve s
