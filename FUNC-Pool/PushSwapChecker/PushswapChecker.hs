import Text.Read
import System.Environment
import System.Exit


-- Parse Args

verifyMaybe :: [String] -> Maybe [Int]
verifyMaybe = mapM readMaybe

pushSwap' :: [String] -> [Int] -> [Int] -> Maybe ([Int], [Int])
pushSwap' [] la lb = Just (la, lb)
pushSwap' ("pa":next) la lb = pushSwap next (pFunction la lb) (ppFunction lb)
pushSwap' ("pb":next) la lb = pushSwap next (ppFunction la) (pFunction lb la)
pushSwap' ("rra":next) la lb = pushSwap next (rrFunction la) (lb)
pushSwap' ("rrb":next) la lb = pushSwap next (la) (rrFunction lb)
pushSwap' ("rrr":next) la lb = pushSwap next (rrFunction la) (rrFunction lb)
pushSwap' (_:_) _ _ = Nothing

pushSwap :: [String] -> [Int] -> [Int] -> Maybe ([Int], [Int])
pushSwap [] la lb = Just (la, lb)
pushSwap ("sa":next) la lb = pushSwap next (sFunction la) (lb)
pushSwap ("sb":next) la lb = pushSwap next (la) (sFunction lb)
pushSwap ("sc":next) la lb = pushSwap next (sFunction la) (sFunction lb)
pushSwap ("ra":next) la lb = pushSwap next (rFunction la) (lb)
pushSwap ("rb":next) la lb = pushSwap next (la) (rFunction lb)
pushSwap ("rr":next) la lb = pushSwap next (rFunction la) (rFunction lb)
pushSwap lst la lb = pushSwap' lst la lb

-- Pushswap Funct

pFunction :: [Int] -> [Int] -> [Int]
pFunction lst [] = lst
pFunction la (x:xs) = (x:la)

ppFunction :: [Int] -> [Int]
ppFunction [] = []
ppFunction (x:[]) = []
ppFunction (x:xs) = xs

rrFunction :: [Int] -> [Int]
rrFunction [] = []
rrFunction lst = (last lst:init lst)

sFunction :: [Int] -> [Int]
sFunction [] = []
sFunction (x:y:xs) = (y:x:xs)
sFunction (x:xs) = (x:xs)

rFunction :: [Int] -> [Int]
rFunction [] = []
rFunction (x:xs) = reverse (x:reverse xs)

-- Final Verification
 
isSorted :: [Int] -> Bool
isSorted [] = True
isSorted [_] = True
isSorted (x:y:xs)
        | x < y = isSorted (y:xs)
        | otherwise = False

showKo :: ([Int], [Int]) -> IO ()
showKo tpl = putStrLn ("KO "++show tpl)

checkSort :: ([Int], [Int]) -> IO ()
checkSort ([], []) = putStrLn "OK"
checkSort (x, []) | (isSorted x) = putStrLn "OK"
                  | otherwise = showKo (x, [])
checkSort (a, b) = showKo (a, b)

-- Get Line parsing

splitSpaceLine :: [Char] -> [String]
splitSpaceLine [] = []
splitSpaceLine lst = words lst

getInstruction :: IO [String]
getInstruction = getLine >>= return . splitSpaceLine

-- Main loop

sortingSwap :: [Int] -> IO ()
sortingSwap array = getInstruction >>= sortingSwap' where
    sortingSwap' lst = case pushSwap lst array [] of
        Nothing -> exitWith (ExitFailure 84)
        Just a -> checkSort a

main :: IO ()
main = getArgs >>= main' where
    main' args = case verifyMaybe args of
        Nothing -> exitWith (ExitFailure 84)
        Just lst -> sortingSwap lst