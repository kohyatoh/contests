import Control.Monad
import Text.Printf
import Data.List

merge :: String -> [Int] -> [Int] -> [Int] -> ([Int], String)
merge s as [] rs = (reverse rs ++ as, s)
merge s [] bs rs = (reverse rs ++ bs, s)
merge ('1':s) (a:as) bs rs = merge s as bs (a:rs)
merge ('2':s) as (b:bs) rs = merge s as bs (b:rs)

simulate :: String -> Int -> [Int] -> ([Int], String)
simulate s 1 xs = (xs, s)
simulate s n xs = merge t' as bs []
  where m = n `div` 2
        (as, t) = simulate s m $ take m xs
        (bs, t') = simulate t (n-m) $ drop m xs

recover :: Int -> String -> [Int]
recover n s = map snd . sort . zip (fst $ simulate s n [1..n]) $ [1..n]

checksum :: [Int] -> Int
checksum xs = foldl' step 1 xs
  where step r a = (31 * r + a) `mod` 1000003

solve :: Int -> String -> Int
solve n = checksum . recover n

input :: IO (Int, String)
input = do
    n <- readLn
    s <- getLine
    return (n, s)

main = do
    n <- readLn :: IO Int
    forM_ [1..n] $ \i -> do
        (n, s) <- input
        let ans = solve n s
        printf "Case #%d: %d\n" i ans
