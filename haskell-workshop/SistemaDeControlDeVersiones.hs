--El objetivo del TP era realizar una especie de sistema de control de versiones muy sencillo,
--utilizando el algoritmo de distancia de Levenshtein.

-- DATOS Y SHOW

data Modificacion = Insertar Integer Char | Borrar Integer | Substituir Integer Char deriving (Show, Eq)

type PaqueteModificaciones = [Modificacion]

data Archivo = ArchivoVacio | NuevaVersion PaqueteModificaciones Archivo
instance Show Archivo where
    show ArchivoVacio = "Archivo vacio"
    show file = "Archivo: " ++ obtenerUltimaVersion file

data SCV = NuevoSCV | AgregarArchivo Archivo SCV
instance Show SCV where
    show NuevoSCV = "SCV vacio"
    show scv = verArchivos scv

verArchivos :: SCV -> String
verArchivos NuevoSCV = ""
verArchivos (AgregarArchivo file scv) = "- " ++ (show file) ++ "\n" ++ (verArchivos scv)

-- EJERCICIOS

-- Ejercicio 1/8
aplicarModificacion :: String -> Modificacion -> String
aplicarModificacion str (Insertar 0 z) = z : str
aplicarModificacion (x:xl) (Insertar n z) = x : aplicarModificacion xl (Insertar (n - 1) z)
aplicarModificacion (x:xl) (Borrar 1) = xl
aplicarModificacion (x:xl) (Borrar n) = x : aplicarModificacion xl (Borrar (n - 1))
aplicarModificacion str (Substituir n z) = aplicarModificacion (aplicarModificacion str (Insertar n z)) (Borrar n)

-- Ejercicio 2/8
aplicarPaqueteModificaciones :: String -> PaqueteModificaciones -> String
aplicarPaqueteModificaciones str [] = str
aplicarPaqueteModificaciones str (x:xl) = aplicarPaqueteModificaciones (aplicarModificacion str x) xl

-- Ejercicio 3/8
obtenerUltimaVersion :: Archivo -> String
obtenerUltimaVersion ArchivoVacio = ""
obtenerUltimaVersion (NuevaVersion xlm file) = aplicarPaqueteModificaciones (obtenerUltimaVersion file) xlm

-- Ejercicio 4/8
cantVersiones :: Archivo -> Integer
cantVersiones ArchivoVacio = 0
cantVersiones (NuevaVersion _ file) = 1 + cantVersiones file

-- Ejercicio 5/8
obtenerVersion :: Integer -> Archivo -> String
obtenerVersion 0 _ = ""
obtenerVersion n (NuevaVersion xlm f0)  | n == cantVersiones f1 = obtenerUltimaVersion f1
                                        | otherwise = obtenerVersion n f0
                                        where f1 = NuevaVersion xlm f0

-- Ejercicio 6/8
levenshtein :: String -> String -> Integer --PaqueteModificaciones
levenshtein str1 str2   | min (length str1) (length str2) == 0 = max (len str1) (len str2)
                        | last str1 == last str2 = levenshtein (init str1) (init str2)
                        | otherwise = minimum [1 + levenshtein (init str1) str2,
                                               1 + levenshtein str1 (init str2),
                                               1 + levenshtein (init str1) (init str2)]

-- Ejercicio 7/8
levenshtein2 :: String -> String -> PaqueteModificaciones
levenshtein2 str1 str2  | (length str1, length str2) == (0, 0) = []
                        | length str1 == 0 = Insertar 0 (last str2) : levenshtein2 str1 (init str2)
                        | length str2 == 0 = Borrar (len str1) : levenshtein2 (init str1) str2
                        | last str1 == last str2 = levenshtein2 (init str1) (init str2)
                        | otherwise = minLength [Borrar (len str1) : levenshtein2 (init str1) str2,
                                                 Insertar (len str1) (last str2) : levenshtein2 str1 (init str2),
                                                 Substituir (len str1) (last str2) : levenshtein2 (init str1) (init str2)]

minLength :: [PaqueteModificaciones] -> PaqueteModificaciones
minLength (x:xl) | xl == [] = x
                 | length x <= length (minLength xl) = x
                 | otherwise = minLength xl

-- Ejercicio 8/8
agregarVersion :: String -> Archivo -> Archivo
agregarVersion "" ArchivoVacio = ArchivoVacio
agregarVersion str file = NuevaVersion (levenshtein2 (obtenerUltimaVersion file) str) file

len :: [a] -> Integer
len xs = fromIntegral (length xs)


mostrarPaq (NuevaVersion paq arc) = paq

--MiniTest
archivo1 = NuevaVersion [Insertar 0 'd', Insertar 1 'a', Insertar 2 't',Insertar 3 'o'] ArchivoVacio
archivo2 = NuevaVersion [Insertar 0 'n'] archivo1
archivo3 = NuevaVersion [Insertar 0 'a'] archivo2
archivo4 = NuevaVersion [Insertar 0 'm'] archivo3
archivo5 = NuevaVersion [Insertar 7 's'] archivo4
archivo6 = NuevaVersion [Substituir 1 'c', Substituir 6 'd'] archivo5
archivo7 = NuevaVersion [Borrar 1, Borrar 1, Borrar 1, Substituir 1 'g', Borrar 5, Substituir 3 't'] archivo6