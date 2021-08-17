concat :: [[a]] -> [a]
concat xss = [x | xs <- xss, x <- xs]

firsts :: [(a,b)]-> [a]
firsts ps = [x | (x,_) <- ps]

pairs :: [a] -> [(a,a)]
pairs xs = zip  xs (tail xs)

sorted :: Ord a => [a] -> Bool
sorted xs = and [x <= y | (x,y) <- pairs xs]

