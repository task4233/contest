use std::io;


fn main() {
    // read_lineしてparse
    let mut tmp: String;
    io::stdin().read_line(&mut tmp).expect("Failed to read line.");
    let n: i32 = tmp.parse().unwrap();

    // read_line
    let s: String;
    io::stdin().read_line(&mut s).expect("Failed to read line.");

    let mut sm: f32 = 0.0;
    // forループができない……
    for si in s {
        match si {
            'A' => sm += 4.0,
            'B' => sm += 3.0,
            'C' => sm += 2.0,
            'D' => sm += 1.0,
             _  => sm += 0.0,
        }
    }
    
    println!("{}", (sm / (n as f32)));
    
}
