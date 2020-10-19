# Chapter 2 and Guessing game 🎲

Use cargo to create a new project:

> $ cargo new guessing_game

Run with:

> $ cargo run

---

## Including libraries

We obtein user input with the *io* library from the *std*. We bring libraries into the scope by using the keyword *use*.

```rust
use std::io;
```

Right out of the box the things we can use come from the *prelude*.

The *prelude* is the list of things that Rust automatically imports into every Rust program. It's kept as small as possible, and is focused on things, particularly traits, which are used in almost every single Rust program.

https://doc.rust-lang.org/std/prelude/index.html

## Functions and variables

We define functions with the *fn* keyword. Our entry point is the *main* function.

Variables are introduced with the *let* statement. By default they are immutable, if we need a mutable variable we add *mut* to the declaration.

```rust
let foo = 5;        // immutable
let mut bar = 5;    // mutable
```

We can shadow the definition of variable's names. Useful when we want to convert between types.

## Strings

```rust
let mut guess = String::new();
```

*String::new*, is a function that returns a new instance of a String, a type provided by the std that is a growable, UTF-8 encoded bit of text.

With the `::` operator we use the associated function *new* of the type *String*. It is a static method.

The `.trim()` method on a string will eliminate whitespace from both beginning and end.

`.parse()` parses strings into some kind of number, we must tell to which number type as with `let guess: u32`. The colon after the variable names tells Rust we'll annotate the variable's type. This method could cause an error, because of that it returns a `Result` type, if it has an `Err` it will output the message from the `expect()`.

## Input

Without the `use std::io` line we can rewrite the input statement as `std::io::stdin`. This returns a type that represents a handle to the standard input from the termianl.

`read_line(&mut guess)` method from the standard input. We pass a reference to guess. As references are immutable by default, we need to add *mut*. This method returns an `io::Result`, these types are _enumerations_ (or enums), which are types that can have a fixed set of values called _variants_. For *Result* the variants are `Ok` and `Err`. Inside Ok you'll find the generated value, in Err you'll have information about what went wrong.

So with `Result` types you can encode error-handling information.

If the instance of `io::Result` is an `Err` value `expect` will cause the program to crash and display the message that you passed as an argument. Not using a `expect` will produce a warning on compilation.

## Printing

```rust
println!("You guessed: {}", guess);
```

The set of curly braces is a placeholder.

## Crates

Binary crates are executables, as the project we are working on. The `rand` crate, for example, is a _library crate_.

Crates are fetched from `Crates.io`.

To update crates use the command `$ cargo update`, otherwise versions will be locked to the _Cargo.lock_ file.

Documentation for each used crate can be build with `$ cargo doc --open`.

## std::cmp::Ordering

From the standard library. `Ordering` is another enum with variants: `Less`, `Greater`, `Equal`, three possible outcomes when comparing two values.

## match

This expression is made up of _arms_, which are _patterns_ and code that should be run if the value given to the `match` fits the arm's pattern.

We can use `match` instead of an `expect` to avoid crashing on error and handling it:

```rust
let guess: u32 = match guess.trim().parse() {
    Ok(num) => num,
    Err(_) => continue,
};
```

The underscore `_` is a catchall value. We don't care what error we get we just want to `continue` executing the next iteration of the loop.

## Loops

The `loop` keyword creates an infinite loop. Stop looping with `break`.

