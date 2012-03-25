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

solve :: Int -> Int -> [(Int, Int)] -> [(Int, Int)] -> [(Int, Int)]
solve _ _ [] _ = []
solve _ _ _ [] = []
solve x y ps@((i, p):ps') qs@((j, q):qs')
    | q < p-x = solve x y ps qs'
    | q > p+y = solve x y ps' qs
    | otherwise = (i, j) : solve x y ps' qs'

main = do
    [_, _, x, y] <- map atoi . B.words <$> B.getLine
    ps <- (zip [1..]) . map atoi . B.words <$> B.getLine
    qs <- (zip [1..]) . map atoi . B.words <$> B.getLine
    let as = solve x y ps qs
    putStrLn . show $ length as
    forM_ as $ uncurry (printf "%d %d\n")
