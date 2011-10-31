import Control.Monad
import Control.Applicative
import Text.Printf
import List (sortBy)

solve :: [(Integer, Integer, Integer)] -> Integer
solve [] = 0
solve ((s, c, t):xs) = q*s + (solve $ map cut xs)
  where q = min c t
        cut (s', c', t') = (s', c', min t' $ max t t' - q)

gcjMain f m = do
    n <- readLn
    dat <- replicateM n m
    forM_ (zip [1..n] dat) $ \(i, xs) -> do
        printf "Case #%d: %d\n" i $ solve $ sortBy (flip compare) xs

main = gcjMain solve $ do
    [n, k] <- map read . words <$> getLine :: IO [Integer]
    replicateM (fromIntegral n) $ pre . map read . words <$> getLine
  where pre [c, t, s] = (s, c, t) :: (Integer, Integer, Integer)
