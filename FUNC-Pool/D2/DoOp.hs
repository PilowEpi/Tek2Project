import Data.Char

myElem :: Eq a => a -> [a] -> Bool
myElem eq [] = False
myElem eq (x:xs) | (eq == x) = True
                 | otherwise = myElem eq xs

safeDiv :: Int -> Int -> Maybe Int
safeDiv i 0 = Nothing
safeDiv i x = Just (div i x)

safeNth :: [a] -> Int -> Maybe a
safeNth (x:xs) 0 = Just x
safeNth [] _ = Nothing
safeNth (x:xs) c | (c < 0) = Nothing
                 | otherwise = safeNth xs (c - 1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc = fmap (+1)

myLookup :: Eq a => a -> [(a,b)] -> Maybe b
myLookup _ [] = Nothing
myLookup n ((a,b):xs) | (n == a) = Just b
                      | otherwise = myLookup n xs

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo _ _ Nothing = Nothing
maybeDo _ Nothing _ = Nothing
maybeDo func (Just a) (Just b) = Just (func a b)

checkAllDigits :: [Char] -> Bool
checkAllDigits [] = True
checkAllDigits (x:xs) | (isDigit x == False) = False
                      | otherwise = checkAllDigits xs

readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt lst | (checkAllDigits lst) = Just (read lst :: Int)
            | otherwise = Nothing

getLineLength :: IO Int
getLineLength = do 
    line <- getLine
    return (length line)

printAndGetLength :: String -> IO Int
printAndGetLength line = do
    putStrLn line
    return (length line)
