# Chapter Cuatro

## The Slice Type

This is another type without ownership.

It references contiguous sequences of elements in a collection.

## String Slice

```rust
fn main() {
    let s = String::from("hello world");

    let hello = &s[0..5];
    let world = &s[6..11];
}
```

We create slices using a range within brackets `[starting_index...ending_index]```, the ending index must be one step after the last position in the slice.

`..` syntax:

```rust
let init = &s[..2]; // from the beginning up to 2
let tail = &s[3..];
let all  = &s[..];
```

Reference to the first word example from the book:

```rust
fn first_word(s: &String) -> &str {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[0..i];
        }
    }

    &s[..]
}
```

The compiler will ensure the reference into the String remain valid.

String literals are slices.

Slices work the same way with arrays.
