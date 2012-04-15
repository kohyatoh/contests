{-# OPTIONS_GHC -O3 -fno-spec-constr-count #-}
{-# LANGUAGE BangPatterns #-}
import Control.Monad
import Control.Applicative
import Debug.Trace
import Data.Int
import qualified Data.ByteString.Char8 as B
import qualified Data.Char as C

atoi :: B.ByteString -> Integer
atoi = B.foldl' (\a c -> a*10 + fromIntegral (C.ord c) - 48) 0

solve a b c d k = 2 * (k `div` m) + 1
  where p = gcd a b
        q = gcd c d
        m = lcm p q

main = do
    t <- fromIntegral . atoi . head . B.words <$> B.getLine
    replicateM_ t $ do
        [a, b, c, d, k] <- map atoi . B.words <$> B.getLine
        putStrLn . show $ solve a b c d k
