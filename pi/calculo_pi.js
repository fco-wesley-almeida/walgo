// (1) * 4/1 + (-1) * 4/3 + (1) * 4/5

function pi (x) {
    let pi = 0;
    for(let i = 0; i < x; i++) 
    {
        let divisor = 2 * i + 1;
        if (i % 2 === 0) {
            pi += 4 / divisor;
        } else {
            pi -= 4 / divisor;
        }
    }
    return pi;
}