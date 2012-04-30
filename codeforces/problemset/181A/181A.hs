import Data.List
main=interact$f.drop 2.words
f s=g s++" "++g(transpose s)
g=show.(+1).head.findIndices((=="*").filter(=='*'))
