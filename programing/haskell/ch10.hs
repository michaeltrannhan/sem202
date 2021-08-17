act :: IO (Char, Char)
act = do x <- getChar
         getChar
         y <- getChar
         return (x,y)

putChar

putStr:: string -> IO ()
putStr [] = return ()
putStr (x:xs) = do putChar x
                   putStr xs

putStrLn :: String -> IO ()
putStrLn xs = do putStr xs
                 putChar '\n'

getLine :: IO String 
getLine = do x <- getChar
            if x == '\n' then 
                return []
            else
                do xs <- getLine
                    return (x, xs)

strlen :: IO()
strlen = do Main.putStr "Enter a string:"
            xs <- Main.getLine
            Main.putStr "The string has "
            Main.putStr (show(length xs))
            Main.putStrLn "characters"

sgetLine :: IO String
sgetLine = do x <- getCh
            if x == '\n' then 
                do putChar x  
                return []
            else
                do putChar '-'
                   xs <- sgetLine
                   return (x:xs)
                    
getCH :: IO Char
getCH = do hSetEcho stdin False
           x <- getChar
           hSetEcho stdin True
           return x

play :: String -> IO
play word = do putStr "? "
               guess <- getLine
               if guess == word then 
                  putStrLn "You got it!!"
               else
                  do putStrLn(match word guess)
                  play word

match :: String -> String -> String
match xs ys = [if elem x ys then x else '-' | x <- xs]

hangman :: IO ()
hangman = do putStrLn "Think of a word:"
             word <- sgetLine
             putStrLn "Try to guess it:"
             play word