import Data.Int (Int64)
import Data.Bits ((.&.))
import Data.Char (chr)

sample :: String
sample = take 300000 $ genSample 16

genSample :: Integer -> String
genSample r = chr (fromIntegral c) : genSample r'
  where r' = (r * 1103515245 + 12345) .&. 0xFFFFFFFF
        c = 0x61 + (26 * (r' `div` 0x10000)) `div` 0x10000

main = putStrLn sample
