mySucc :: Int -> Int
mySucc n = (n + 1)

myIsNeg :: Int -> Bool
myIsNeg n | n < 0 = True
          | otherwise = False

myAbs :: Int -> Int
myAbs n | n < 0 = (n * (-1))
        | otherwise = n

myMin :: Int -> Int -> Int
myMin x y | x < y = x
          | otherwise = y

myMax :: Int -> Int -> Int
myMax x y | x > y = x
          | otherwise = y

myTuple :: a -> b -> (a, b)
myTuple a b = (a, b)

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)

myFst :: (a, b) -> a
myFst (a, b) = a

mySnd :: (a, b) -> b
mySnd (a, b) = b

mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)

myHead :: [a] -> a
myHead (a:b) = a
myHead [] = error ""

myTail :: [a] -> [a]
myTail (a:b) = b
myTail [] = error ""

myLength :: [a] -> Int
myLength (a:b) = myLength b + 1
myLength [] = 0

myNth :: [a] -> Int -> a
myNth (a:b) 0 = a
myNth (a:b) c | (c < 0) = error ""
              | (myLength b == 0) = error ""
              | otherwise = myNth b (c - 1)

myTake :: Int -> [a] -> [a]
myTake c [] = []
myTake 0 _ = []
myTake c (a:b) | (c < 0) = error ""
               | (c > 0) = a : myTake (c - 1) b

myDrop :: Int -> [a] -> [a]
myDrop c [] = []
myDrop 0 (a:b) = a:b
myDrop c (a:b) | (c < 0) = error ""
               | (c > 0) = myDrop (c - 1) b

myAppend :: [a] -> [a] -> [a]
myAppend [] [] = []
myAppend [] (a:c) = a : myAppend [] c
myAppend (a:b) c = a : myAppend b c

myReverse :: [a] -> [a]
myReverse [] = []
myReverse a = myLast a : myReverse (myInit a)

myInit :: [a] -> [a]
myInit [] = error ""
myInit a = myTake ((myLength a) - 1) a

myLast :: [a] -> a
myLast [] = error ""
myLast (a:b) | (myLength b /= 0) = myLast b
             | (myLength b == 0) = a

myZip :: [a] -> [b] -> [(a ,b)]
myZip [] b = []
myZip a [] = []
myZip (a:b) (c:d) = myTuple a c : myZip b d

myUnTupleFst :: [(a ,b)] -> [a]
myUnTupleFst [] = []
myUnTupleFst (x:xs) = myFst x : myUnTupleFst xs

myUnTupleSnd :: [(a ,b)] -> [b]
myUnTupleSnd [] = []
myUnTupleSnd (x:xs) = mySnd x : myUnTupleSnd xs

myUnzip :: [(a ,b)] -> ([a], [b])
myUnzip x = myTuple (myUnTupleFst x) (myUnTupleSnd x)

-- myUnzip2 :: [(a ,b)] -> ([a], [b])
-- myUnzip2 lst = myUnzip2' lst [] [] where
        -- myUnzip2' [] l1 l2 = (myReverse l1, myReverse l2)
        -- myUnzip2' ((a, b):xs) acc = myUnzip2' xs (a:l1, b:l2)

myUnzip2 :: [(a ,b)] -> ([a], [b])
myUnzip2 [] = ([], [])
myUnzip2 ((a,b):xs) = let (as, bs) = myUnzip2 xs in (a:as, b:bs)

myMap :: (a -> b) -> [a] -> [b]
myMap func [] = []
myMap func (x:xs) = func x : myMap func xs

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter func [] = []
myFilter func (x:xs) | ( func x == True) = x : myFilter func xs
                     | otherwise = myFilter func xs

myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl func y [] = y
myFoldl func y (x:xs) = myFoldl func (func y x) xs

myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr func y [] = y
myFoldr func y x = myFoldr func (func (myLast x) y) (myInit x)

mySubPart :: (a -> Bool) -> Bool -> [a] -> [a]
mySubPart func b [] = []
mySubPart func b (x:xs) | ( func x == b) = x : mySubPart func b xs
                        | otherwise = mySubPart func b xs

myPartition :: (a -> Bool) -> [a] -> ([a], [a])
myPartition func x = myTuple (mySubPart func True x) (mySubPart func False x)