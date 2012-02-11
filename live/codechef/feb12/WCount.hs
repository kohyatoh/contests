{-# OPTIONS_GHC -O3 #-}
import Control.Monad
import Control.Applicative
import Text.Printf
import Data.Array
import Data.List
import Data.Int (Int64)
import qualified Data.ByteString.Char8 as B
import qualified Data.Char as C

type LInt = Int64

atoi :: B.ByteString -> Int
atoi = B.foldl' (\a c -> a*10 + C.ord c - C.ord '0') 0

powMod :: LInt -> LInt -> LInt -> LInt
powMod m a 0 = 1
powMod m a n
    | n `mod` 2 == 0 = (r * r) `mod` mo
    | otherwise = (((r * r) `mod` mo) * a) `mod` mo
  where r = powMod m a (n `div` 2)

invMod :: LInt -> LInt -> LInt
invMod m a = powMod m a (m - 2)


mo = 1000000007 :: LInt
a |*| b = (a * b) `mod` mo


factor :: LInt -> LInt
factor n = foldl' (|*|) 1 [1..n]

factorInv :: LInt -> LInt
factorInv = (factorInvMemo !)
factorInvMemo = listArray (0, 15) $ map (invMod mo . factor) [0..]

solve :: B.ByteString -> LInt
solve s = foldl' (|*|) (factor len) rs
  where len = fromIntegral $ B.length s
        cs = map B.head . B.group . B.sort $ s
        rs = map (factorInv . fromIntegral . flip B.count s) cs

main = do
    (_:ws) <- B.words <$> B.getContents
    forM_ ws $ printf "%d\n" . solve
