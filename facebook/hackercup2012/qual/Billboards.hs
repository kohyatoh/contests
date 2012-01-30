import Control.Monad
import Control.Applicative
import Text.Printf

format :: Int -> [String] -> [[String]]
format c = snd . foldr step (0, [[]])
  where step w (len, ws:wss)
            | len + wl <= c + 1 = (len + wl, (w:ws):wss)
            | otherwise = (wl, [w]:(ws:wss))
          where wl = 1 + length w
    
fit :: Int -> Int -> [String] -> Int -> Bool
fit w h ws sz = fitWidth && fitHeight
  where fitWidth = and . map ((<= w) . (*sz) . length) $ ws
        fitHeight = sz * length (format (w `div` sz) ws) <= h

bsearch :: (Int -> Bool) -> Int -> Int -> Int
bsearch f low high
    | high - low <= 1 = low
    | f mid = bsearch f mid high
    | otherwise = bsearch f low mid
  where mid = (low + high) `div` 2

solve :: Int -> Int -> [String] -> Int
solve w h ws = bsearch (fit w h ws) 0 (h + 1)

input :: IO (Int, Int, [String])
input = do
    (w:h:ws) <- words <$> getLine
    return (read w, read h, ws)

main = do
    n <- readLn :: IO Int
    forM_ [1..n] $ \i -> do
        (w, h, ws) <- input
        let ans = solve w h ws
        printf "Case #%d: %d\n" i ans
