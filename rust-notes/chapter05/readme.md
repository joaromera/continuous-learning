# Chapter 5

## Structs

Custom data type to name and package together multiple related values.

### Definition

```rust
struct User {
    username: String,
    email: String,
    sign_in_count: u64,
    active: bool,
}
```

### Instantiation

```rust
let user1 = User {
    email: String::from("someone@example.com"),
    username: String::from("someusername123"),
    active: true,
    sign_in_count: 1,
};
```

We access specific values using _dot notation_.

If the instance is mutable (the entire instance must be it), we can change values as well with dot notation.

### Using the Field Init Shorthand when Variables and Fields Have the Same Name

Use _field init shorthand syntax_.

```rust
fn build_user(email: String, username: String) -> User {
    User {
        email,
        username,
        active: true,
        sign_in_count: 1,
    }
}
```

Using _struct update syntax_ we can create a new instance from another:

```rust
let user2 = User {
    email: String::from("another@example.com"),
    username: String::from("anotherusername567"),
    ..user1
};
```

You only specify those values you want to differ from the instance you're copying from.

## Tuple structs

Similar to tuples. They don't have names for each data member.

```rust
struct Color(i32, i32, i32);
```

You can also have structs without any fields. These are _unit-like structs_.

_The println! macro can do many kinds of formatting, and by default, the curly brackets tell println! to use formatting known as Display: output intended for direct end user consumption. The primitive types we’ve seen so far implement Display by default, because there’s only one way you’d want to show a 1 or any other primitive type to a user. But with structs, the way println! should format the output is less clear because there are more display possibilities: Do you want commas or not? Do you want to print the curly brackets? Should all the fields be shown? Due to this ambiguity, Rust doesn’t try to guess what we want, and structs don’t have a provided implementation of Display._

We can use an output format called `Debug`. This uses a trait that enables us to print our struct in a usefel way for debugging.

For using the Debug trait we must add the annotation `#[derive(Debug)]` before the struct definition.

```rust
#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

fn main() {
    let rect1 = Rectangle {
        width: 30,
        height: 50,
    };

    println!("rect1 is {:?}", rect1);
}
```

---

## Method Syntax

Methods are also declared with `fn`, they are pretty much like regular functions.

They are defined in the context of a struct, enum, trait object, and their first parameter is always `self`.

To define functions in the context of a struct we start with a `impl` block.

There can be more than one `impl` block.

As methods can take ownership of `self`, we have to use the `&`.

If we want to mutate self we need to pass `&mut self` as the first parameter.

There is no `->` operator in Rust. Rust has a feature called _automatic referencing and dereferencing_: when you call a method with `object.something()`, Rust adds in `&`, `&mut` or `*` so `object` matches the signature of the method.

## Associated functions

We can define functions that don't take `self` as parameter, these are associated with the struct itself.

Associated functions are usually used for constructors.
