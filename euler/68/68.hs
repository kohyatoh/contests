import Data.List

glines xs = zip3 xs ys $ drop 1 $ cycle ys
  where ys = drop 5 xs
sum3 (x, y, z) = x + y + z

can gl = take 5 $ drop ix $ cycle gl
  where ix = snd $ minimum $ zip gl [0..]

isfgon = (== 1) . length . group . map sum3 . glines

fgons :: [[Int]]
fgons = filter isfgon $ permutations [1..10]

tostr :: [Int] -> String
tostr = concatMap (\(x, y, z) -> show x ++ show y ++ show z) . can . glines

solve = maximum $ filter ((== 16) . length) $ map tostr $ fgons

main = putStrLn solve
