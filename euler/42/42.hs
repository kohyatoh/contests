import Data.Char

solve = length . filter tri . map (sum . map dig)
dig c = ord c - ord 'A' + 1
tri t = t == bisect (<=t) (\x -> x*(x+1) `div` 2) 1 t
bisect p f l r
    | r - l <= 1 = f l
    | p (f mid) = bisect p f mid r
    | otherwise = bisect p f l mid
  where mid = (l+r) `div` 2

main = print . solve . read . ('[':) . (++"]") =<< getContents
