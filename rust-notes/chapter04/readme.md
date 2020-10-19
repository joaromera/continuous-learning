# Chapter Quatre


Rust can make safety guarantees without needing a garbage collector. How? Let's see... 👀

## Ownership

In Rust memory is managed through a system of ownership with a set of rules that the compiler checks at compile time.

There's no slow down. Easy there...

### The Stack and the Heap

Stack: LIFO. Data on the stack must have a known, fixed size.

Heap: to put data on the heap, you request a certain amount of space. The memory allocator finds it, marks it as used and return a pointer to it.

The stack is faster because the allocator never has to search for a place to store new data, the location is always at the top of the stack.

Accessing data in the heap is also slower, you must follow a pointer.

Cool recap (?)

## Ownership RULES!

- Each value has a variable that is its owner.
- There can only be one owner at a time.
- When the owner goes out of scope, the value is dropped.

### Variable Scope

A variable is valid from the point at which it's declared until the end of the current scope.

### The String type

String literals are immutable and hardcoded into our programs. When we can't do with that we use a second string type: `String`.

This one is allocated on the heap, as such it can store text unknown at compile time.

```rust
let s = String::from("Immutable");

let mut mutStr = String::from("Mutable");

mutStr.push_str(" I am";
```

### Memory and Allocation

The String type, in order to suppoer a mutable, growable piece of text, needs to allocate an amount of memory on the heap. This memory is requested to the memory allocator at runtime, and we need to return it when we're done.

Once the variable that owns it goes out of scope the memory is automatically returned.

Rust calls the function `drop` to do this.

### Move

```rust
let s1 = String::from("Not a shallow copy, but a MOVE!");
let s2 = s1;
```

Only the `String` data of the stack is copied (the pointer to the actual string in the heap, among its length and capacity return by the allocator in bytes).

After trying to copy the allocated memory, Rust considers `s1` to no longer be valid, we can't use it, and Rust doesn't try to free it when it goes out of scope.

Rust performs moves on assignment.

Rust will never create deep copies, thus any copying can be assumed to be inexpensive.

### Clone

If we want to perform a deep copy of data from the heap, we can use `clone`. This copies the actual data from the heap. Clone may be expensive.

### Copy

Types such as integers that have a known size at compile times are stored entirely on the stack, so copies of the actual values are quick to make, and there's no invalidation. Types can have `traits`, the copy trait allows this behavior.

Types can't have the `Copy` trait if it already has the `Drop` trait.

As a general rule, any group of simple scalar values can be `Copy`, and nothing that requires allocation or is some form of resource is `Copy`.

### Ownership and Functions

Passing variables to functions will move or copy, as assignment does. So a `String` going into a function will have its variable invalidated in the calling scope.

### Return values and scope

Functions give ownership of a heap allocated object when returning it.

If we want to retain ownership after calling a function with a `Drop` type.

```rust
fn main() {
    let s1 = String::from("hello");

    let (s2, len) = calculate_length(s1);

    println!("The length of '{}' is {}.", s2, len);
}

fn calculate_length(s: String) -> (String, usize) {
    let length = s.len(); // len() returns the length of a String

    (s, length)
}
```

---

That came from https://doc.rust-lang.org/book/ch04-01-what-is-ownership.html
