import Control.Monad
import Control.Applicative
import Text.Printf

type Memo = [(Integer, Integer)]

solve :: Memo -> Integer -> (Memo, Integer)
solve m x = case lookup x m of
    Just a -> (m, a)
    Nothing -> case x `mod` 2 of
        1 -> ((x, a):m', a)
               where a = a1 + 1
        0 -> ((x, a):m'', a)
               where (m'', a2) = solve m' $ x `div` 2 - 1
                     a = max a1 $ a2 + 2
      where (m', a1) = solve m $ x `div` 2


gcjMain f m = do
    n <- readLn
    dat <- replicateM n m
    forM_ (zip [1..n] dat) $ \(i, x) -> do
        printf "Case #%d: %d\n" i $ snd $ solve [(0, 0)] x

main = gcjMain solve readLn

