
# Chapter 1

So the book says Rust is about empowerment. About high-level ergonomics and low-level control becoming friends 😊.

*Cargo* is the dependency manager and build tool.
We have a *rustfmt* to ensure coding style across developers.

## Installing rustup on Linux or macOS

> $ curl --proto '=https' --tlsv1.2 https://sh.rustup.rs -sSf | sh

Afterwards I got all of these:

* rust-gdb
* rust-lldb
* rustc
* rustdoc
* rustfmt
* rustup

Running `rustup doc` opens the local documentation. Pretty cool.

Rust files always end with *.rs* extension. Prefer snake case for filenames with more than one word.

Our cannonical first programin Rust:

```rust
fn main() {
    println!("Hello, world!");
}
```

Compile it with `rustc main.rs`. Then run it!

Rust is an ahead-of-time compiled language, meaning you can compile a program and give the executable to someone else, and they can run it even without having Rust installed.

---

The `main` function is special, it is always the first code that runs in every executable Rust program.

Rust _style_, indent with four spaces.

`println!` is a macro! gosh! If it were a function it would be entered as `println` withouth the *!*. So macros have *!* endings.

Semicolons are used to end statements.

---

# Cargo

Cargo is Rust build system and package manager.

You can create projects with cargo: `$ cargo new hello_carto`

This also creates a *TOML* file (Tom's Obvious Minimal Language). In this file the first line `[package]` is a section heading indicating the configuration of a package. The following lines are some settings for compiling our program.

There's also a `[dependencies]` section.

_Using Cargo helps you organize your projects. There’s a place for everything, and everything is in its place._

Build a Cargo project with:

> $ cargo build

This creates an executable in:

> $ ./target/debug/hello_cargo

The first time you run `$ cargo build` creates the file `Cargo.lock`. This keeps track of dependencies versions of the project.

With `$ cargo run` we can both compile and run the project.

The command `$ cargo check` checks if the program would compile correctly. This is faster than using `$ cargo build`.

## Building for release

When the projet is ready for release you can build it with:

> $ cargo build --release

This will compile it with optimizations. The executable will be in 

> $ ./target/release/hello_cargo

---