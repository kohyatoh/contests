{-
Copyright (c) 2012, Kohsuke Yatoh
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
-}
import Control.Monad
import System.Environment (getArgs)
import Data.List

-- take every nth element.
-- every 2 [1, 2, 3, 4, 5] = [1, 3, 5]
every :: Int -> [a] -> [a]
every n = map head . takeWhile (not . null) . iterate (drop n)

-- search t from src with fixed amount of skips, and return [pos]
searchWithSkip :: String -> String -> Int -> [Int]
searchWithSkip t src n = map fst . filter p $ zip [0..] (tails src)
  where p (_, s) = t `isPrefixOf` every n s

-- search t from src, and return sorted list of [(skip, pos)]
search :: String -> String -> [(Int, Int)]
search src t = con $ zip [1..] $ map (searchWithSkip t src) [1..length src]
  where con = concatMap $ \(i, xs) -> zip (repeat i) xs

-- take 2 strictly ascending lists and merge them, eliminating duplicates
merge :: (Ord a) => [a] -> [a] -> [a]
merge xs [] = xs
merge [] ys = ys
merge xs@(x:xs') ys@(y:ys')
    | x == y = x : merge xs' ys'
    | x < y = x : merge xs' ys
    | otherwise = y : merge xs ys'

main = do
    args <- getArgs
    if (null args) then
        putStrLn "usage: ./q03slow <keyword>"
    else do
        input <- getContents
        let keyword = head args
            rev = reverse keyword
            rs = merge (search input keyword) (search input rev)
        forM_ rs $ \(span, pos) ->
            putStrLn $ show span ++ ", " ++ show (pos+1)
