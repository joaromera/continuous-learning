fn main() {
    let mut x = 1;
    println!("The value of x is: {}", x);
    x = 2;
    println!("The value of x is: {}", x);

    another_function();

    function_with_parameters(3);
}

fn another_function() {
    println!("Another function.");
}

fn function_with_parameters(x: i32) {
    println!("The value of x is: {}", x);
}