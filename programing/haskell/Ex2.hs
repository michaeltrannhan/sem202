searchL :: Int -> [Int] -> Int
searchL _ [] = 0
searchL x (l : ls) = if l == x then 0 else 1 + searchL x ls