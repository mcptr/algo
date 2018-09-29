
fn calculate_sum(mut limit: u32) -> u64
{
    let mut sum: u64 = 0;
    
    while limit > 0 {
        if limit % 3 == 0 || limit % 5 == 0 {
            sum = sum + limit as u64;
        }
        limit -= 1;
    }
    return sum;
}

fn main()
{
    let limit: u32 = 1000;
    println!("{}", calculate_sum(limit));
}
