use itertools::Itertools;

fn main() {
    let max: Vec<i32> = include_str!("../input1.txt")
        .lines()
        .map(|line| {
            if line.is_empty() {
                0
            } else {
                line.parse().unwrap()
            }
        })
        .coalesce(|x, y| if y != 0 { Ok(x + y) } else { Err((x, y)) })
        .sorted()
        .rev()
        .collect_vec();

    println!("{:}", max.first().unwrap());
    println!("{:}", max.into_iter().take(3).sum::<i32>());
}
