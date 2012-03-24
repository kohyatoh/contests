{-# OPTIONS_GHC -O3 -fno-spec-constr-count #-}
{-# LANGUAGE BangPatterns #-}
import Control.Monad
import Control.Applicative
import Data.Int
import Debug.Trace
import qualified Data.ByteString.Char8 as B

solve :: Int -> B.ByteString -> Int64
solve k s
    | k == 0 = sum . map l2 . filter ((=='0') . B.head) $ B.group s
    | B.count '1' s < k = 0
    | otherwise = fst $ B.foldl' f (0, (kth, 1 + zeros kth s)) s
  where n = B.length s
        kth = (B.findIndices (== '1') s) !! (k-1)
        f (!a, (!j, !c)) d
            | d == '0' = (na, (j, c))
            | d == '1' = if j+c < n
                then (na, (j+c, 1 + zeros (j+c) s))
                else (na, (n, 0))
          where na = a + fromIntegral c


zeros :: Int -> B.ByteString -> Int
zeros i = B.length . B.takeWhile (== '0') . B.drop (i+1)

l2 :: B.ByteString -> Int64
l2 s = let l = fromIntegral $ B.length s in (l * (l+1)) `div` 2

main = do
    [k', s] <- B.words <$> B.getContents
    let k = read . B.unpack $ k'
    putStrLn . show $ solve k s
