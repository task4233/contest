// https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
#[allow(unused_macros)]
macro_rules! input {
    (source = $s:expr, $($r:tt)*) => {
        let mut iter = $s.split_whitespace();
        let mut next = || { iter.next().unwrap() };
        input_inner!{next, $($r)*}
    };
    ($($r:tt)*) => {
        let stdin = std::io::stdin();
        let mut bytes = std::io::Read::bytes(std::io::BufReader::new(stdin.lock()));
        let mut next = move || -> String{
            bytes
                .by_ref()
                .map(|r|r.unwrap() as char)
                .skip_while(|c|c.is_whitespace())
                .take_while(|c|!c.is_whitespace())
                .collect()
        };
        input_inner!{next, $($r)*}
    };
}

#[allow(unused_macros)]
macro_rules! input_inner {
    ($next:expr) => {};
    ($next:expr, ) => {};
    
    ($next:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($next, $t);
        input_inner!{$next $($r)*}
    };
}

#[allow(unused_macros)]
macro_rules! read_value {
    ($next:expr, ( $($t:tt),* )) => {
        ( $(read_value!($next, $t)),* )
    };
    
    ($next:expr, [ $t:tt ; $len:expr ]) => {
        (0..$len).map(|_| read_value!($next, $t)).collect::<Vec<_>>()
    };
    
    ($next:expr, chars) => {
        read_value!($next, String).chars().collect::<Vec<char>>()
    };
    
    ($next:expr, bytes) => {
        read_value!($next, String).into_bytes()
    };
    
    ($next:expr, usize1) => {
        read_value!($next, usize) - 1
    };
    
    ($next:expr, $t:ty) => {
        $next().parse::<$t>().expect("Parse error")
    };
}


fn main() {
    input!{
        p: f64,
    }

    let mut l: f64 = 0.0;
    let mut r: f64 = std::f64::MAX / 10.0;

    for i in 0..100000 {
        let c1: f64 = (l * 2.0 + r) / 3.0;
        let c2: f64 = (l + r * 2.0) / 3.0;

        if f(c1, p) < f(c2, p) {
            r = c2;
        } else {
            l = c1;
        }
    }
    println!("{}", f(l, p));
}

fn f(x: f64, p: f64) -> f64 {
    x + p * (2.0_f64).powf(-x/1.5_f64)
}




