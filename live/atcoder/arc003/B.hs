import Control.Applicative
import Control.Monad
import Data.List

solve = map reverse . sort . map reverse

main = do
    n <- read <$> getLine
    ss <- replicateM n getLine
    forM_ (solve ss) putStrLn
