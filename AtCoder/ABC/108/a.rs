fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).unwrap();
    let k: i32 = buf.trim().parse().unwrap();

    println!("{}", (k / 2) * (k - k / 2));
}
