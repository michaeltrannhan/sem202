add :: (Int, Int) -> Int 
add (x, y) = x + y

(&&) :: Bool -> Bool  ->Bool 
True && True = True 
_    && _    = False 

tripmul :: Int -> Int -> Int -> Int 
tripmul x y z = x * y * z

tail :: [a] -> a
tail x = head (reverse x)
--  tail :: [a] -> a
--  tail(x:[]) = x
-- tail(x:xs) = Main.head(reverse x)

swap :: (b, a) -> (a, b)
swap (x,y) = (y,x)

e :: [a] -> a
e (x:[]) = x
e (x: xs) = e xs

