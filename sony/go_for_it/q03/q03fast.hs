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
import qualified Data.ByteString.Char8 as S

-- check that the 2nd argument is a prefix of src[x, x+y, x+y*2...].
check src [] _ _ = True
check src (c:cs) x y =
    x < S.length src && c == src `S.index` x && check src cs (x+y) y

-- search string from src, and return sorted list of [(skip, pos)]
search :: S.ByteString -> String -> [(Int, Int)]
search src [] = []
search src [c] = zip (repeat 1) $ S.elemIndices c src
search src (c1:c2:cs) = sort rs
  where xs = S.elemIndices c1 src
        ys = S.elemIndices c2 src
        rs = [(y-x, x) | x <- xs, y <- ys,
                x < y, check src cs (x+(y-x)*2) (y-x)]

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
        putStrLn "usage: ./q03fast <keyword>"
    else do
        input <- S.getContents
        let keyword = head args
            rev = reverse keyword
            rs = merge (search input keyword) (search input rev)
        forM_ rs $ \(span, pos) ->
            putStrLn $ show span ++ ", " ++ show (pos+1)
