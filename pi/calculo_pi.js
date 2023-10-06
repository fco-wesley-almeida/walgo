// (1) * 4/1 + (-1) * 4/3 + (1) * 4/5

function pi (x) {
    let pi = 0;
    for(let i = 0; i < x; i++) 
    {
        pi += 4 / (2 * i + 1) * ((i & 0b1) === 0b0 ? 1 : -1);
    }
    return pi;
}
