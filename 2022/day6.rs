use itertools::Itertools;

fn main() {
    let w = 14;
    let lines = include_str!("../input6.txt")
        .chars()
        .collect::<Vec<_>>()
        .windows(w)
        .take_while(|x| !x.iter().all_unique())
        .count() + w;
    println!("{:#?}", lines)
}
