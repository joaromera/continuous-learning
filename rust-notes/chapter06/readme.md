# Enums and Pattern Matching

Enums allow to define types enumerating its values.

When we can enumerate all possible variants `enums` are cool.

### Definition

```rust
enum IpAddrKind {
    V4,
    V6,
}
```

### Usage

```rust
let four = IpAddrKind::V4;
let six = IpAddrKind::V6;

fn rout(ip_kind: IpAddrKind) {}

route(IpAddrKind::V4);

struct IpAddr {
    kind: IpAddrKind,
    address: String,
}

let home = IpAddr {
    kind: IpAddrKind::V4,
    address: String::from("127.0.0.1"),
}
```

We can also put data into each enum variant.

```rust
enum IpAddr {
    V4(String),
    V6(String),
}

let home = IpAddr::V4(String::from("127.0.0.1"));

let loopback = IpAddr::V6(String::from("::1"));
```

Each variant can have different types and amounts of associated data:

```rust
enum Message {
    Quit,
    Move { x: i32, y: i32 },
    Write(String),
    ChangeColor(i32, i32, i32),
}
```

Also, enums can have functions:

```rust
impl Message {
    fn call(&self) {
        // method body would be defined here
    }
}

let m = Message::Write(String::from("hello"));
m.call();
```

https://doc.rust-lang.org/book/ch06-01-defining-an-enum.html#the-option-enum-and-its-advantages-over-null-values

## Option Enum

Another enum defined by the standard library. It can hold a value or not.

The compiler will check whether you've handled all the cases you should be handling.

_Rust has no null value._

The enum that can represent the concept of a value being present or absent is:

```rust
enum Option<T> {
    Some(T),
    None,
}
```

It is included in prelude, no need to scope it explicitly. The same goes for its variants.

```rust
let some_number = Some(5);
let absent_number: Option<i32> = None;
```

To use the value of an `Option<T>` we have to convert it to `T`. see https://doc.rust-lang.org/std/option/enum.Option.html .

---

## Match control flow operator

`match` allows to compare a value against a series of patterns and then execute code based on which pattern matches.

```rust
enum Coin {
    Penny,
    Nickel,
    Dime,
    Quarter,
}

fn value_in_cents(coin: Coin) -> u8 {
    match coin {
        Coin::Penny => 1,
        Coin::Nickel => 5,
        Coin::Dime => 10,
        Coin::Quarter => 25,
    }
}
```

Each `arm` has a pattern and code. The code associated with each arm is an expression and its resulting value is what's returned from the `match` expression.

### Matching with Option<T>

```rust
fn plus_one(x: Option<i32>) -> Option<i32> {
    match x {
        None => None,
        Some(i) => Some(i + 1),
    }
}

let five = Some(5);
let six = plus_one(five);
let none = plus_one(None);
```

Matches are exhaustive, you can't ignore the `None` case above.

### The `_` placeholder

```rust
let some_u8_value = 0u8;

match some_u8_value {
    1 => println!("one"),
    3 => println!("three"),
    5 => println!("five"),
    7 => println!("seven"),
    _ => (),
}
```

We can use `_` to match any value. It will match all the cases that aren't specified before it.

---

## Control flow with `if let`

Less boilerplate code, not need to add `_ => ()` for just one variant:

```rust
if let Some(3) = some_u8_value {
    println!("three");
}
```

The `if let` pattern takes a patterna dn an expression separated by an equal sign. You lose the exhaustive checking that `match` enforces.
