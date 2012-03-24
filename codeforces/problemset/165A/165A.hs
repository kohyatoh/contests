{-# OPTIONS_GHC -O3 -fno-spec-constr-count #-}
import Control.Monad
import Control.Applicative
import Text.Printf
import Data.List
import Debug.Trace
import qualified Data.ByteString.Char8 as B
import qualified Data.Char as C

atoi :: B.ByteString -> Int
atoi s | B.head s == '-' = - (atoi' $ B.tail s)
       | otherwise = atoi' s

atoi' :: B.ByteString -> Int
atoi' = B.foldl' (\a c -> a*10 + C.ord c - C.ord '0') 0

type P = (Int, Int)

rot :: P -> P
rot (x, y) = (y, -x)

solve :: [P] -> Int
solve ps = length $ filter (supercentral ps) ps

supercentral :: [P] -> P -> Bool
supercentral ps = all (uncurry anybelow) . flip zip rss . iterate rot
  where rss = take 4 $  iterate (map rot) ps

anybelow :: P -> [P] -> Bool
anybelow p = any (isbelow p)

isbelow :: P -> P -> Bool
isbelow (x, y) (x', y') = (x == x') && (y < y')

main = do
    n <- head . map atoi . B.words <$> B.getLine
    ps <- replicateM n $ do
        [x, y] <- map atoi . B.words <$> B.getLine
        return (x, y)
    printf "%d\n" $ solve ps
