# Chapter 4

## References and Borrowing

You can have a reference instead of taking ownership:

```rust
fn calculate_length(s: &string) -> usize {
    s.len()
}
```

The ampersand denotas a _reference_, they refer to values wihtout owning them. To call a function that takes a reference, the argument must have an ampersand as well.

We can't modify something we're borrowing.

## Mutable references

To be able to modify when borrowing, the variable itself must be mutable and the parameter of the function has to be mutable as well.

You can only have one mutable reference to a particular piece of data in a particular scope. This can prevent data races at compile time.

We can't have mutable references while we have immutable ones.

## Dangling references

In Rust the compiler guarantees that references will never be danlging references: if you have a reference to same data, the compiler will ensure that the data wil not go out of scope before the reference to the data does.

---

Source: https://doc.rust-lang.org/book/ch04-02-references-and-borrowing.html

Next:
https://doc.rust-lang.org/book/ch04-03-slices.html
