--They range from simple to less simple.

--import Data.Char

unoSiCero n | n == 0 = 1
            | n /= 0 = 0

unoSiCero2 0 = 1
unoSiCero2 n | n /= 0 = 0

f :: Bool -> Bool
f x = not x

f1 :: Bool -> Float
f1 x = pi

funcion3 :: Integer -> Integer -> Bool -> Bool
funcion3 x y b = b || (x > y)

doble :: Integer -> Integer
doble x = x + x

cuadruple :: Integer -> Integer
cuadruple x = doble (doble x)

dist :: Float -> Float -> Float -> Float -> Float
dist x1 y1 x2 y2 = sqrt ((x2 - x1)^2 + (y2 - y1)^2)

dist2 :: (Float, Float) -> (Float, Float) -> Float
dist2 p1 p2 = sqrt ((fst p1 - fst p2)^2 + (snd p1 - snd p2)^2)

psurfacer :: a -> (a, a)
psurfacer x = (x, x)

doble2 :: Num a => a -> a
doble2 x = x + x

crearPar :: a -> b -> (a, b)
crearPar a b = (a, b)

invertir :: (a, b) -> (b, a)
invertir par = (snd par, fst par)

vertice :: Float -> Float -> Float
vertice b a = (-1) * b / 2 * a

raiz :: Float -> Float -> Float -> Float
raiz a b c = (sqrt ((b ^ 2) - 4 * a * c)) / 2 * a

raices :: Float -> Float -> Float -> (Float, Float)
raices a b c = ((vertice b a) + (raiz a b c), (vertice b a) - (raiz a b c))

ite :: Bool -> a -> a -> a
ite True exp1 exp2 = exp1
ite False exp1 exp2 = exp2

funcionLoca x y = ite x x y

listar :: a -> a -> a -> [a]
listar a1 a2 a3 = [a1, a2, a3]

rangoDePaso :: Integer -> Integer -> Integer -> [Integer]
rangoDePaso n1 n2 n3 = [n1,(n2)+1..n3]

pendiente :: (Float, Float) -> (Float, Float) -> Float
pendiente p1 p2 = (snd p2 - snd p1) / (fst p2 - fst p1)

iniciales :: String -> String -> String
iniciales nom ape = [head nom] ++ [head ape]

inv ::  Float -> Float
inv x | x /= 0 = 1/x

consti ::  a -> Integer
consti x = 42

factorial :: Integer -> Integer
factorial n | n == 0 = 1
factorial n | n > 0 = n * factorial (n-1)

fib :: Integer -> Integer
fib n | n == 0 = 1
fib n | n == 1 = 1
fib n = fib(n-1) + fib(n-2)

par :: Integer -> Bool
par n | n == 0 = True
      | n == 1 = False
      | n > 0 = par (n-2)
      | n < 0 = par (n+2)

sumaImpares :: Integer -> Integer
sumaImpares n = n^2

multDe3 :: Integer -> Bool
multDe3 n | n == 0 = True
          | n == 1 = False
          | n == 2 = False
          | otherwise = multDe3 (n-3)

doublefact :: Integer -> Integer
doublefact 0 = 1
doublefact n | ((n `div` 2) * 2) == n = n * (doublefact (n - 2))

--combinatorio :: (Integer, Integer) -> Integer
--combinatorio x = ((factorial ((fst x) - 1)) / (factorial (snd x)) * (factorial ((fst x) - (snd x)))) + ((factorial ((fst x) - 1)) / (factorial ((snd x) - 1)) * (factorial ((fst x) - (snd x))))

recursivaNoEnd :: Integer -> Integer
recursivaNoEnd 0 = 0
recursivaNoEnd n = recursivaNoEnd (n - 1)

absoluto n | n < 0 = n * (-1)
           | otherwise = n

parConDiv x = (div x 2) * 2 == x

parConMod x = (mod x 2) == 0

yLogico True True = True
yLogico x n = False

yLogicoPosta x n = x && n

funcionLoca2 n1 n2 n3 | n2 < 10 = n1
                      | otherwise = n1 + n3

nand True True = False
nand x y = True

nor False False = True
nor x y = False

isNot x = not x

inverso :: Float -> Float
inverso x | x /= 0 = 1 / x

conste :: a -> Integer
conste x = 42

sumFirstOdds :: Int -> Int
sumFirstOdds 0 = 0
sumFirstOdds n = ((n * 2) - 1) + (sumFirstOdds (n-1))

potencia :: Integer -> Integer -> Integer
potencia n 0 = 1
potencia n e = n * (potencia n (e - 1))

sumaImparesCuyoCuadSeaMenorQue :: Integer -> Integer
sumaImparesCuyoCuadSeaMenorQue umbral = sumaAuxiliar umbral 1

sumaAuxiliar :: Integer -> Integer -> Integer
sumaAuxiliar umbral num
  | num ^ 2 >= umbral = 0
  | otherwise = num + sumaAuxiliar umbral (num + 2)

divParcial :: Integer -> Integer -> [Integer]
divParcial n 1 = [1]
divParcial n m | mod n m == 0 = m : divParcial n (m - 1)
  | otherwise = divParcial n (m-1)

divisores :: Integer -> [Integer]
divisores n = divParcial n n

esPrimo :: Integer -> Bool
esPrimo n = length (divisores n) == 2

dividir :: Integer -> Integer -> (Integer, Integer)
dividir x y | x < y = (0,x)
          | otherwise = resto1 x y 0
          where resto1 x y z | x < y = (z,x)
                             | otherwise = resto1 (x - y) y (z+1)



division :: Integer -> Integer -> (Integer, Integer)
division a d | a < d = (0, a)
division a d | otherwise = (fst (division (a-d) d) + 1, snd (division (a-d) d))

division' :: Integer -> Integer -> (Integer, Integer)
division' a d | a < d = (0, a)
division' a d | otherwise = (fst qr' + 1, snd qr')
               where qr' = division' (a-d) d

suma :: [Integer] -> Integer
suma x | x == [] = 0
       | otherwise = head x + suma (tail x)

productoria :: [Integer] -> Integer
productoria x | x == [] = 1
              | otherwise = head x * productoria (tail x)

reverso :: [Integer] -> [Integer]
reverso x = reverso' [] x
            where reverso' y x | x == [] = y
                               | otherwise = reverso' (head x : y) (tail x)

reverso2 :: [Integer] -> [Integer]
reverso2 [] = []
reverso2 xs = (reverso2 (tail xs)) ++ [head xs]

sumaL :: [Integer] -> [Integer] -> [Integer]
sumaL [] [] = []
sumaL x y = sumaCoor x y ++ sumaL (tail x) (tail y)
  where sumaCoor x y = [(head x) + (head y)]

prodInterno :: [Float] -> [Float] -> Float
prodInterno [] [] = 0
prodInterno x y = producto (head x) (head y) + prodInterno (tail x) (tail y)
  where producto x y = x * y

noTiene :: Integer -> Integer -> Bool
noTiene m n | m == 1 = True
            | mod n m == 0 = False
            | otherwise = noTiene (m-1) n

esPrimo2 :: Integer -> Bool
esPrimo2 x | (abs x) == 2 = True
           | (abs x) == 1 = False
           | otherwise = noTiene ((abs x) - 1) (abs x)

esMultiploDe :: Integer -> Integer -> Bool
esMultiploDe x y | y == 0 = True
                 | y < 0 = False
                 | otherwise = esMultiploDe x (y - x)

intercalar :: [a] -> [a] -> [a]
intercalar l1 l2 | length l1 == 0 = []
                 | otherwise = [head l1] ++ [head l2] ++ intercalar (tail l1) (tail l2)

quitarTodosLos :: Integer -> [Integer] -> [Integer]
quitarTodosLos n l1 | length l1 == 0 = []
                    | otherwise = auxiliar n l1 []
                    where auxiliar n l1 l2 | length l1 == 0 = l2
                                           | (head l1) == n = auxiliar n (tail l1) l2
                                           | otherwise = auxiliar n (tail l1) (l2 ++ [head l1])

comprimir :: [Integer] -> [(Integer, Integer)]
comprimir l | length l == 1 = [((head l), 1)]
            | otherwise = [(head l, contar l 1)] ++ comprimir (tail l)
            where contar l1 n | (head l1) /= (head (tail l1)) = n
                              | (head l1) == (head (tail l1)) = contar (tail l1) (n + 1)



comprimir2 :: [Integer] -> [(Integer, Integer)]
comprimir2 l | length l == 1 = [((head l), 1)]
             | otherwise = sumemos l 1
              where sumemos l1 n | length l1 == 1 = [((head l), n)]
                                 | (head l1) == (head (tail l1)) = sumemos (tail l1) (n + 1)
                                 | otherwise = [(head l1, n)] ++ comprimir2 (tail l1)

pertenece :: Integer -> [Integer] -> Bool
pertenece n l | l == [] = False
              | n == (head l) = True
              | otherwise = pertenece n (tail l)

hayRepetidos :: [Integer] -> Bool
hayRepetidos l | length l == 1 = False
               | pertenece (head l) (tail l) == True = True
               | otherwise = hayRepetidos (tail l)

hayMenores :: Integer -> [Integer] -> [Integer]
hayMenores n l | length l == 0 = []
               | n > head l = [(head l)] ++ hayMenores n (tail l)
               | n <= head l = hayMenores n (tail l)

quitar :: Integer -> [Integer] -> [Integer]
quitar n l | length l == 0 = []
           | n == head l = tail l
           | n /= head l = [(head l)] ++ quitar n (tail l)

maximo :: [Integer] -> Integer
maximo l | length l == 1 = head l
         | head l > (head (tail l)) = maximo ([(head l)] ++ (tail (tail l)))
         | head l <= (head (tail l)) = maximo ([(head (tail l))] ++ (tail (tail l)))

enBase :: Integer -> Integer -> [Integer]
enBase b n | div n b == 0 = [n]
           | otherwise = enBase b (div n b) ++ [mod n b]

deBase :: Integer -> [Integer] -> Integer
deBase b n = sumas b (reverso2 n) 0
           where sumas x y z | length y == 1 = (x ^ z) * head y
                             | otherwise = (x ^ z) * (head y) + sumas x (tail y) (z + 1)

cambioDeBase :: Integer -> Integer -> [Integer] -> [Integer]
cambioDeBase b1 b2 a = enBase b2 (deBase b1 a)

capicuaPara :: [Integer] -> [Integer]
capicuaPara l1 | l1 == reverso2 (enBase 10 (deBase 10 l1)) = l1
               | otherwise = sumemos (enBase 10 (deBase 10 l1)) (reverso2 (enBase 10 (deBase 10 l1)))
               where sumemos la lb | length la == 0 = []
                                   | otherwise = capicuaPara (sumaL la lb)

noDecreciente :: [Integer] -> Bool
noDecreciente l1 | length l1 == 1 = True
               | head l1 > (head (tail l1)) = False
               | otherwise = noDecreciente (tail l1)

quitarNoUltimo :: [Integer] -> [Integer]
quitarNoUltimo l1 | length l1 == 0 = []
                  | pertenece (head l1) (tail l1) = quitarNoUltimo (tail l1)
                  | otherwise = [(head l1)] ++ quitarNoUltimo (tail l1)

quitarNoPrimero :: [Integer] -> [Integer]
quitarNoPrimero l1 | length l1 == 0 = []
                   | pertenece (head l1) (tail l1) = [(head l1)] ++ quitarNoPrimero (quitarTodosLos (head l1) (tail l1))
                   | otherwise = [(head l1)] ++ quitarNoPrimero (tail l1)

unirOrdenar :: [Integer] -> [Integer] -> [Integer]
unirOrdenar l1 l2 | length l1 == 0 = l2
                  | length l2 == 0 = l1
                  | head l1 >= head l2 = [head l2] ++ [head l1] ++ unirOrdenar (tail l1) (tail l2)
                  | head l1 < head l2 = [head l1] ++ [head l2] ++ unirOrdenar (tail l1) (tail l2)

ordenar :: [Integer] -> [Integer]
ordenar l1 | length l1 == 1 = l1
           | head l1 < head (tail l1) = [head l1] ++ ordenar (tail l1)
           | otherwise = ordenar' l1
           where ordenar' la | length la == 1 = la
                             | (length la == 2) && head la > head (tail la) = [head (tail la)] ++ [head la]
                             | (length la == 2) && head la <= head (tail la) = la
                             | head la > (head (tail la)) = ordenar ([head (tail la)] ++ ordenar' ([head la] ++ tail (tail la)))
                             | head la <= (head (tail la)) = [head la] ++ ordenar (tail la)
                             | otherwise = [1000]

aver :: Integer -> a -> (a,a)
aver n l = (auxiliar n l 0, auxiliar2 n l 0)

auxiliar ns ls i | i < ns = [head ls] ++ auxiliar ns (tail ls) (i + 1)
                 | otherwise = []
auxiliar2 ns ls i | i < ns = auxiliar2 ns (tail ls) (i + 1)
                  | otherwise = ls

mcd :: Integer -> Integer -> Integer
mcd a b | abs b > abs a = mcd b a
mcd a 0 = abs a
mcd a b = mcd b (mod a b)

mcdExt :: Integer -> Integer -> (Integer , Integer , Integer)
mcdExt a b | abs b > abs a = mcdExt b a
mcdExt a 0 = (a,1,0)
mcdExt a b = (d,t,s - t * k)
  where (k,r) = (div a b, mod a b)
        (d,s,t) = mcdExt b r

first :: (a,b,c) -> a
first (x,y,z) = x

longitud :: [a] -> Integer
longitud [] = 0
longitud (x:[]) = 1
longitud (x:y:[]) = 2
longitud (x:y:z:[]) = 3
longitud (_:_:_:xs) = 3 + longitud xs

iniciales' :: [Char] -> [Char] -> [Char]
iniciales' nombre apellido = n:a:[]
    where (n:_) = nombre
          (a:_) = apellido

type Racional = (Integer, Integer)

sumaR :: Racional -> Racional -> Racional
sumaR (a,b) (c,d) = (a*d + b*c, b*d)

type Point = (Integer, Integer)

distP :: Point -> Point -> Float
distP (a,b) (c,d) = sqrt (fromInteger (((a - c) ^ 2 + (b - d) ^ 2)))

data Dia = Lunes | Martes | Miercoles | Jueves | Viernes | Sabado | Domingo deriving (Eq, Show)

esFinde :: Dia -> Bool
esFinde Sabado = True
esFinde Domingo = True
esFinde _ = False

diaHabil :: Dia -> Bool
diaHabil Sabado = False
diaHabil Domingo = False
diaHabil _ = True

soloAlgebra :: [Dia] -> [Dia]
soloAlgebra [] = []
soloAlgebra (x:xs) = if (x == Martes) || (x == Viernes) then x : soloAlgebra xs else soloAlgebra xs

tuplas :: [a] -> [b] -> [(a,b)]
tuplas x [] = []
tuplas [] y = []
tuplas (x:xs) (y:ys) = (x, y) : tuplas xs ys

potencia2 :: Racional -> Integer -> Racional
potencia2 (a,b) p = (a^p, b^p)

type Conjunto = [Integer]

union :: Conjunto -> Conjunto -> Conjunto
union x [] = x
union [] y = y
union (x:xs) y | pertenece x y = union xs y
               | otherwise = x : union xs y

interseccion :: Conjunto -> Conjunto -> Conjunto
interseccion x [] = []
interseccion [] y = []
interseccion (x:xs) y | pertenece x y = x : interseccion xs y
                      | otherwise = interseccion xs y
incluido :: Conjunto -> Conjunto -> Bool
incluido [] y = True
incluido (x:xs) (y:ys) | pertenece x (y:ys) = incluido xs (y:ys)
                       | otherwise = False

igual :: Conjunto -> Conjunto -> Bool
igual [] y = True
igual x y | length x /= length y = False
          | pertenece (head x) y = igual (tail x) (tail y)
          | otherwise = False

separar :: Integer -> Conjunto -> (Conjunto, Conjunto)
separar x y = (menores x y, mayores x y)
        where
          menores x [] = []
          menores x (y:ys) | y <= x = y : menores x ys
                           | otherwise = menores x ys
          mayores x [] = []
          mayores x (y:ys) | y > x = y : mayores x ys
                           | otherwise = mayores x ys

data Direccion = Norte | Sur | Este | Oeste deriving (Show, Eq)
type Tortuga = (Pos, Direccion)
type Pos = (Integer, Integer)

arranca :: Tortuga
arranca = ((0,0), Norte)

girarDerecha :: Tortuga -> Tortuga
girarDerecha (a,b) | b == Norte = (a, Oeste)
                   | b == Oeste = (a, Sur)
                   | b == Sur = (a, Este)
                   | b == Este = (a, Norte)

avanzar :: Tortuga -> Integer -> Tortuga
avanzar ((x,y),dir) c | dir == Norte = ((x + c,y),dir)
                      | dir == Sur = ((x - c,y),dir)
                      | dir == Oeste = ((x,y - c),dir)
                      | dir == Este = ((x,y + c),dir)

data Shape = Rectangle Float Float Float Float
            | Circle Float Float Float deriving Show

c1 :: Shape
c1 = Circle 0 0 pi

r1 :: Float -> Shape
r1 x = Rectangle 0 0 (x/ sqrt 2) (x/ sqrt 2)

surface :: Shape -> Float
surface (Rectangle x y x2 y2) = (abs(x-x2)) * (abs(y-y2))
surface (Circle x y r) = pi * r^2
