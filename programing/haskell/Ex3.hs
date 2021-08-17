length :: [a] -> Int
length [] = 0
length (_ : xs) = 1 + Main.length xs

and :: [Bool] -> Bool
and (x : []) = if x == False then False else True
and (x : xs) = if x == False then False else Main.and xs

replicate :: Int -> a -> [a]
replicate x y = if x == 1 then [y] else y : Main.replicate (x -1) y

elem :: Eq a => a -> [a] -> Bool
elem a [] = False
elem a (x : xs) = if a == x then True else Main.elem a xs

(!!) :: [a] -> Int -> a
(!!) (x : xs) 0 = x
(!!) (x : xs) n = (Main.!!) xs (n - 1)

concat :: [[a]] -> [a]
concat [] = []
concat (x : xs) = x ++ Main.concat xs

merge :: Ord a => [a] -> [a] -> [a]
merge [] y = y
merge x [] = x
merge (x:xs) (y:ys) = if x < y then x : merge xs (y:ys) else y : merge (x:xs) ys

firsthalf :: [a] -> [a]
firsthalf xs = take (Main.length xs `div` 2) xs

secondhalf :: [a] -> [a]
secondhalf xs = drop (Main.length xs `div` 2) xs

msort :: Ord a => [a] -> [a]
msort [] = []
msort [x] = [x]
msort xs = Main.merge (Main.msort (firsthalf xs)) (Main.msort (secondhalf xs))