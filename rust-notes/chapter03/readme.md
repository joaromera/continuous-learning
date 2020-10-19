# Chapter 3 - Common Programming Concepts

Rust keywords:

https://doc.rust-lang.org/book/appendix-01-keywords.html

## Variables - Mutability

By default variables are immutable, once a value is bound to a name, you can't change it. We can make them mutable by adding `mut` in front of the variable name.

You can't use `mut` with constants, they are always immutable. You declare them using the keyword `const` instead of `let`, the type of the value _must_ be annotated. Constants can be declared in any scope and they have to be set to constant expressions, not the result of a function call or any other value that has to be computed at runtime.

For constants use all uppercase names, and they are valid for the entire time a program runs within the scope they were declared in.

```rust
const MAX_POINTS: u32 = 100_000;
```

### Shadowing

We can shadow variables by using the same name more than once and using the keyword `let`. This is different from re-assignment. As we are using actually declaring a new variable we can even change the type.

## Data Types

All values have a type, Rust is a _statically typed_ language, types must be known at compile time.

### Scalar Types

Represent single values, there are four scalar types: integers, floating-point numbers, Booleans, and characters.

*Integer Types*

Number without fractional component.

| Length | Signed | Unsigned |
|:------:|:------:|:--------:|
| 8-bit  |   i8   |   u8    |
| 16-bit |   i16  |   u16   |
| 32-bit |   i32  |   u32   |
| 64-bit |   i64  |   u64   |
| 128-bit|   i128 |   u128  |
| arch   |  isize |   usize |

_Signed numbers are stored using two's complement representation._

`isize` and `usize` depend on the architecture of the computer being used to run the pogram.

| Number literals | Example |
|-----------------|---------|
| Decimal | 98_222 |
| Hex | 0xff |
| Octal | 0o77 |
| Binary | 0b1111_0000 |
| Byte (u8 only) | b'A' |

You can use `_` as a visual separator, and all number literals, except `byte`, allow a type suffix such as `57u8`.

When in doubt Rust can decide, usually default integer types to `u32`. For `isize` and `usize` the usual scenario is indexing collections.

Rust will check for _integer overflow_ in debug mode. When compiling in release mode with the `--release` flag, Rust won't include checks for integer overflow, and won't panic, it will perform _two's complement wrapping_.

*Floating-Point types*

Two primitive types: `f32` and `f64`. The default is `f64` because is roughly they have the same speed on modern CPUs, but `f64` has more precision.

*Boolean Type*

Values `true` and `false`. Type is `bool`.

*Character Type*

The `char` is the most primitive alphabetic type of the language. Literals are specified using single quotes. This type is four bytes in size and represents a Unicode Scalar Value (more than ASCII).

### Compound Types

Two primitive compound types: `tuples` and `arrays`.

*Tuple Type*

Groups together a number of values with a variety of types into one compound type. They have fixed length, can't be changed once declared. To get individual values we can use pattern matching. Or using a period with the index of the value we want.

```rust
fn main() {
    let tup: (i32, f64, u8) = (500, 4.3, 1);
    let (x, y, z) = tup;
    println!("The value of y is: {}", y);
    println!("The value of z is: {}", tup.2);
}
```

*Array type*

Unlike a tuple, all elements must be of the same type, they also have fixed length.

```rust
fn main() {
    let a = [1,2,3,4,5];

    // To specify the type and size:
    let b: [i32; 5] = [1,2,3,4,5];

    // special syntax, creates the array [3,3,3,3,3]
    let c: = [3; 5];

    // Get elements with brackets
    let first = a[0];
}
```

Rust will check that the index used to access an array is within its range, if it's not, Rust will panic.

## Functions

Uses snake case as the convention for function and variable names.

Function definitions start with `fn` and have a set of parentheses after the function name for the parameter list. The body is within curly braces following the parameter list.

It doesn't matter where we define functions, as long as they are defined we can call them.

### Parameters

Parameters make up part of a function's signature. In function signatures, you _must_ declare the type of each parameter, separated by commas.

```rust
fn another_function(x: i32, y: i32) {
    println!("The value of x is: {}", x);
    println!("The value of y is: {}", y);
}
```

Function bodies contain statements (instructions that perform some action and do not return a value) and expressions (which evaluate to a resulting value). Function definitions are also statements.

As statements don't return values, you can't assign a `let` statement to another varible.

Expressions can be part of statements, the black that we use to create new scopes is an expression. The following block prints 4 as the value of `y`.

```rust
fn main() {
    let x = 5;

    let y = {
        let x = 3;
        x + 1
    };

    println!("The value of y is: {}", y);
}
```

Expressions do not include ending semicolons, if you add one, you get an statement.

### Functions with return values

We declare the return type of a function with an arrow after the parameter list, this type is synonymous with the value of the final expression in the block of the function's body. You can omit `return`, or use it, your choice...

```rust
fn five() -> i32 {
    5
}
```

## Comments! 💬

Single line comments:

```rust
// hello comment!
```

Documentation comment generates html files:

```rust
/// Just use triple slashes and markdown notation.
```

That's it!

## Control flow 🔀

### Conditions

```rust
if condition {
    println!("Condition met!");
} else {
    println!("no no noooooo!");
}
```

Blocks of code associated with the conditions in if expressions are sometimes called _arms_. The condition _must_ be a `bool`, Rust doesn't convert non-Boolean types to a Boolean.

Consider using `match` if you have many conditions.

Conditions are expressions, we can use them on the right side of a `let` assignment:

```rust
let something = if condition { 42 } else { 666 };
```

That is valid because blocks of code evaluate to the last expression in them. _Types must match in all arms_.

### 🔄

`loop` executes a block of code forever, or until told to stop with `break`. You can use `loop` to retry an operation that may fail. You can return a value after the keyword `break`.

```rust
fn main() {
    let mut counter = 0;

    let result = loop {
        counter += 1;

        if counter == 10 {
            break counter * 2;
        }
    };

    println!("The result is {}", result);
}
```

`while` loop works as expected.

For iterating containers prefer the `for` loop, as it is faster (less runtime checks for accessing elements).

```rust
for element in container.iter() {
    // do something with it
}
```

The standard library provides a range useful with for loops:

```rust
for number in (1..42).rev() {
    // backwards
}
```

---
### Next chapter:

https://doc.rust-lang.org/book/ch04-00-understanding-ownership.html
