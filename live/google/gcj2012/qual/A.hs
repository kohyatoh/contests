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

dat = B.pack "yhesocvxduiglbkrztnwjpfmaq"

convert :: Char -> Char
convert c
    | c == ' ' = ' '
    | otherwise = dat `B.index` (C.ord c - C.ord 'a')

solve :: B.ByteString -> String
solve = B.unpack . B.map convert

main = do
    [n] <- map atoi . B.words <$> B.getLine
    forM_ [1..n] $ \i -> B.getLine >>= printf "Case #%d: %s\n" i . solve
