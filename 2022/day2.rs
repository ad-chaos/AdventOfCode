fn main() {
    let r: [i32; 3] = [3, 6, 0];
    let (a, x, y) = (65, 88, 89);
    let lines: (i32, i32) = include_str!("../input.txt")
        .lines()
        .map(|line| {
            if let (Some(comp), Some(me)) = (line.as_bytes().first(), line.as_bytes().last()) {
                let (me, comp) = (*me as i32, *comp as i32);
                (
                    r[(me-comp-x+a).rem_euclid(3) as usize] + me-x+1,
                    r[(me-y).rem_euclid(3) as usize] + 1 + (comp+me-y-a).rem_euclid(3)
                )
            } else {
                (0, 0)
            }
        })
        .fold((0, 0), |acc, p| (acc.0 + p.0, acc.1 + p.1));
    println!("{:#?}", lines)
}
