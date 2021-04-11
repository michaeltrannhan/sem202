doubleAll :: [Int] -> [Int]
doubleAll x = [2*e | e <- x]

-- doubleAll (x:[]) = 2*x
-- doubleAll (x:xs) = 2*x : doubleAll(xs)

searchL :: Int -> [Int] -> Int
searchL _ [] = 0
searchL x (l : ls) = if l == x then 0 else 1 + searchL x ls

positives:: [Integer] -> [Integer ]
positives [x] = [x|x>0]
positives (x:xs) = if x > 0 then x : positives xs else positives xs