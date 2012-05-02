{-# OPTIONS_GHC -O3 -fno-spec-constr-count #-}
{-# LANGUAGE BangPatterns #-}
import Control.Monad
import Control.Applicative
import qualified Data.ByteString.Char8 as B

unique :: B.ByteString -> [Char]
unique = map B.head . B.group . B.sort

solve :: B.ByteString -> B.ByteString -> Int
solve j s = sum $ map (flip B.count s) $ unique j

main = do
    t <- read . B.unpack . head . B.words <$> B.getLine
    replicateM_ t $ do
        j <- head . B.words <$> B.getLine
        s <- head . B.words <$> B.getLine
        print $ solve j s
