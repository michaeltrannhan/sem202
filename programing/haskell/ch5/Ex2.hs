pyths :: Int -> [(Int, Int, Int)]
pyths num = [(x, y, z) | x <- [1 .. num], y <- [1 .. num], z <- [1 .. num], x * x + y * y == z * z]

factors :: Int -> [Int]
factors n = [x | x <- [1 .. n -1], n `mod` x == 0] -- dont count itself as a factor

perfects :: Int -> [Int]
perfects num = [x | x <- [1 .. num], x == sum (factors x)]

scalarproduct :: [Int] -> [Int] -> Int
scalarproduct xs ys = sum [x * y | (x, y) <- zip xs ys]