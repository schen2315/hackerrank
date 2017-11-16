import Text.Printf
import Data.List

solve :: [(Int, Int)] -> Double
-- solve points = fromIntegral . sum . map (\(i, j) -> i) $ points 
solve points = fromIntegral . snd . lowestPoint $ points

-- find the point with the smallest y-coordinate
lowestPoint :: [(Int, Int)] -> (Int, Int)
lowestPoint points = foldl1 (\acc p -> if snd p < snd acc then p else acc ) points
-- remove lowest point from the list
removePoint :: [(Int, Int)] -> (Int, Int) -> [(Int, Int)]
removePoint points p = foldl (\acc x -> if (fst p == fst x) && (snd p == snd x) then acc else x:acc) [] points
-- sort points in list according to angle
sortWithRespectTo :: (Int, Int) -> [(Int, Int)] -> [(Int, Int)]
sortWithRespectTo _ [] = []
sortWithRespectTo p [x] = [x]
sortWithRespectTo p (x:xs) = sortBy (\p' p'' -> ((-1)*(slope p p')) `compare` ((-1)*(slope p p''))) (x:xs)
-- use 
slope :: (Int, Int) -> (Int, Int) -> Double
slope p p' =  fromIntegral (fst p - fst p') / fromIntegral (snd p - snd p')
-- calc angle
calcAngle :: (Int, Int) -> (Int, Int) -> (Int, Int) -> Bool
calcAngle p1 p2 p3 = let x1 = fst p1
                         y1 = snd p1
                         x2 = fst p2
                         y2 = snd p2
                         x3 = fst p3
                         y3 = snd p3
                     in if (x2 - x1)*(y3 - y1) - (y2 - y1)*(x3 - x1) <= 0 then True else False
-- check next point in sorted list
	-- if forms a left turn with the head of the accum then add to acc
	-- else return the accum
grahamScan :: [(Int, Int)] -> [(Int, Int)] -> [(Int, Int)]
grahamScan accum points = foldl (\accum p -> if ( calcAngle (head accum) (head . tail $ accum) p)
                                                    then p:accum
                                                    else p:(tail accum)) accum points
dist :: (Int, Int) -> (Int, Int) -> Double
dist p p' = sqrt . fromIntegral $ (fst p - fst p')^2 + (snd p - snd p')^2
perim :: [(Int, Int)] -> (Int, Int) -> Double
perim [] _ = 0
perim (p:ps) p' = (dist p p')  + (perim ps p)

main :: IO ()
main = do
  n <- readLn :: IO Int
  content <- getContents
  let  
    points = map (\[x, y] -> (x, y)). map (map (read::String->Int)) . map words . lines $ content
    --ans = solve points
    p = lowestPoint points
    list = removePoint points (p)
    sortedList = sortWithRespectTo p list
    accum = (head sortedList):p:[]
    convexHull = grahamScan accum (tail sortedList)
    p1 = (head convexHull) 
    ans = perim ((tail convexHull) ++ [p1]) p1
  printf "%.1f\n" ans