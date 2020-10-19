# Haskell Notes and Examples

_Brushing up my Haskell skills._

## Intro

Haskell is a *purely function programming language*.

We express what things are in terms of functions.

Functions have no side effects, as everything is immutable. As a result we get _referential transparency_.

Haskell is _lazy_ and _statically typed_.

To load a file into `ghci` use the command `:l filename.hs`. You can reload it with `:r`.

## Basics

Numeric operations are as usual, with the common precedence rules and parenthesis to make it explicit or to change it. Negative numbers should be enclosed in parenthesis.

Boolean algebra and comparisons are straightforward as well.

```haskell
ghci> True && not (42 == 42)
False
```

Functions are called by writing their name, a space and then a list of space separated parameters.

```haskell
ghci> min 9 10
9
ghci> succ 8
9
```

Function application have the highest precedence:

```haskell
ghci> succ 9 + max 5 4 + 1
16
ghci> (succ 9) + (max 5 4) + 1
16
ghci> succ 9 * 10
100
ghci> succ (9 * 10)
91
```

We can infix funcitons of two parameters by using backtics: ```92 `div` 10```.

Characters go in between simple quotes, and strings are just lists of characters.

## Functions

```haskell
ghci> doubleThis x = x + x
ghci> doubleThis 42
84
ghci> superThing x = doubleThis x + doubleThis x
ghci> superThing 42
168
```

Conditionals always require an `else` clause. Because of this, they always return a value, hence conditions are _expressions_.

```haskell
absoluteValue x = if >= 0 
                    then x
                    else x * (-1)
```

Functions can't start with capital letters and if they take no parameters they are _definitions_.

## Lists

Lists are _homogenous_, all elements must be of the same type.

Nested lists can have different lengths but not different typs.

```haskell
ghci> let lostNumbers = [4,8,15,16,23,42]
ghci> lostNumbers
[4,8,15,16,23,42]
```

Concatenation of lists is done with the `++` operator. Beware of doing this with large lists -it's costly-. It works with two lists, so to add a single element, it must be enclosed in brackets.

`[1,2,3]` is syntactic sugar for `1:2:3:[]`.

Appending at the beginning is instantaneous. Use the `cons` operator `:`.

```haskell
ghci> 1:[2,3,4,5]
[1,2,3,4,5]
```

To retrieve an element we use `!!` and its index (starting at 0).

Lists are compared in lexicographical order.

Other simple functions for lists: head, tail, last, init, length, null, reverse, take, drop, maximum, minimum, sum, product, elem.

```haskell
ghci> head [1,2,3,4,5]
1
ghci> tail [1,2,3,4,5]
[2,3,4,5]
ghci> last [1,2,3,4,5]
5
ghci> init [1,2,3,4,5]
[1,2,3,4]
ghci> length [1,2,3,4,5]
5
ghci> null [1,2,3,4,5]
False
ghci> null []
True
ghci> reverse [1,2,3,4,5]
[5,4,3,2,1]
ghci> take 3 [1,2,3,4,5]
[1,2,3]
ghci> take 0 [1,2,3,4,5]
[]
ghci> drop 3 [1,2,3,4,5]
[4,5]
ghci> drop 0 [1,2,3,4,5]
[1,2,3,4,5]
ghci> drop 100 [1,2,3,4,5]
[]
ghci> maximum [1,2,3,4,5]
5
ghci> minimum [1,2,3,4,5]
1
ghci> sum [1,2,3,4,5]
15
ghci> product [1,2,3,4,5]
120
ghci> 4 `elem` [1,2,3,4,5]
True
ghci> 6 `elem` [1,2,3,4,5]
False
```

Exceptions will be raised if we try to retrieve an element that doesn't exist (as the head of an empty list).

## Ranges

Generating a list including all numbers between a and b is done with: `[a..b]`.

It also works with chars: `['a'..'b']`.

A step can also be specified. Get even numbers in a range with `[0,2..10]`

For reverse, you have to specified the reversed step: `[10,9..1]`.

Ranges can be infinite! `[1,3..]` odd numbers to infinite.

To get the first n odd numbers in a range well... `take n [1,3..]`

`cycle` takes a list and cycles it to infinite.

`repeat` takes an element and makes an infinit list of that element.

`replcate a b` gives a list of a b's.

## List comprehensions

`[x * 2 | x <- [1..10]]`

x is drawn from the range and then multiplied by 2. We can also add conditions (more than one, a returned element will have to satisfy all predicates):

```[x * 2 | x <- [1..10], x `mod` 2 == 0]```

Print odd or even according to the elements of a list

`oddOrEven xs = [ if odd x then "ODD" else "EVEN" | x <- xs]`

When drawing from multiple lists comprehensions will produce all combinations of the given lists and join them:

`[x * y | x <- [1..10], y <- [11..20]]`

Possible implementation of `length`:

```length' xs = sum [1 | _ <- xs]```

Get even numbers from nested lists, without flattening them:

`nestedEvens xxs = [ [ x | x <- xs, even x ] | xs <- xxs ]`

## Tuples

Elements can be of different types. They can contain lists as well.

Use when you know in advance how many components should have. Each tuple size is its own type.

You can't compare two tuples of different sizes.

```haskell
ghci> fst (8,11)
8
ghci> snd ("Wow",False)
False
ghci> zip [1 .. 3] [a,b,c]
[(1,a),(2,b),(3,c)]
```

Zip will ignore extra elements in the larger list. We can zip finite lists with infinite lists.

This is a common pattern in functional programming. You take a starting set of solutions and then you apply transformations to those solutions and filter them until you get the right ones:

```haskell
let rightTriangles = [ (a,b,c) | c <- [1..10], b <- [1..c], a <- [1..b], a^2 + b^2 == c^2]
```

## Types

Haskell has a static type system and type inference.

THe type of every expression is known at compile time. Functions also have types.

Get the type of an expression using ```:t```.

We can give functions an explicit type declaration.

```haskell
removeNonUppercase :: [Char] -> [Char]
removeNonUppercase st = [ c | c <- st, c `elem` ['A'..'Z']]

addThree :: Int -> Int -> Int -> Int
addThree x y z = x + y + z
```

There is no special distinction between parameters and return type.

Return type is the last item in the declaration.

`Int` in 32-bit machines is between _-2147483648_ and _2147483647_.

`Integer` is not bounded, but less efficient.

`Float` is a real floating point with single precision. Double, is with double.

`Bool` is a boolean type, True or False.

`Char` represents a character, denoted by single quotes, a list of chars is a string.

Tuples are types but they depend on their length as well on the types of their components.

Types are written in capital case. If `:t` returns `a`, for instance, is a type variable, this means that `a` can be of any type. Functions that have type variables are called polymorphic functions.

### Typeclasses

Similar to an interface that defines behavior.

If a type is part of a typeclass, it supports its behavior.

(==) for the Eq typeclass, tests equality. Types where it makes sense should be members of the Eq class.

Ord is for types that have an ordering.

Show members can be presented as strings.

Read tries to convert a string to a type.

Enum members are sequentially ordered types, they can be enumerated.

Bounded members have upper and lower bounds.

Num is a numeric typeclass. Also Integral and Floating.

## Pattern Matching

Patterns will be checked from top to bottom.

```haskell
factorial :: (Integral a) => a -> a
factorial 0 = 1
factorial n = n * factorial (n - 1)
```

If pattern matching is non-exhaustive, an exception will be raised when an input doesn't match.

```haskell
length' :: (Num b) => [a] -> b
length' [] = 0
length' (_:xs) = 1 + length' xs
```

Using `@` between a name and a pattern you can reference the whole list.

```haskell
capital :: String -> String
capital "" = "Empty string, whoops!"
capital all@(x:xs) = "The first letter of " ++ all ++ " is " ++ [x]
```

---

## 4.2 Guards

Guards are a way of testing whether some property of a value are true or false. They are indicated by pipes that follow a function's name and its parameters. Basically they are boolean expressions. Usually, the last guard is `otherwise`.

```haskell
max' :: (Ord a) => a -> a -> a
max' a b
    | a > b     = a
    | otherwise = b
```

---

## where

The keyword `where` goes after the guards. _These are bindings, a syntactic construct, that lets you bind to variables at the end of a function and the whole function can see them, including its guards._

```haskell
initials :: String -> String -> String
initials firstname lastname = [f] ++ ". " ++ [l] ++ "."
    where (f:_) = firstname
          (l:_) = lastname
```

---

## `let` bindings

With `let` you can bind to variables anywhere, they are also expressions. They don't span across guards and can also be used for pattern matching. The names that are defined in the `let` part are accessible to the expression after the `in` part.

Difference: `let` bindings are expressions, `where` are just syntactic constructs.

```haskell
ghci> (let a = 100; b = 200; c = 300 in a*b*c, let foo="Hey "; bar = "there!" in foo ++ bar) (6000000,"Hey there!")
```

Another examples:

```haskell
calcBmis :: (RealFloat a) => [(a, a)] -> [a]
calcBmis xs = [bmi | (w, h) <- xs, let bmi = w / h ^ 2, bmi >= 25.0]
```

---

## 4.5 Case expressions

