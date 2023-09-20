const RAND_MAX: u32 = 32767;

/// Linear Congruential Generator
/// A method for generating pseudo-random numbers.
/// Source - https://stackoverflow.com/questions/67498467/how-to-generate-random-number-between-two-numbers-in-c-kernel
pub struct LinearCongruentialGenerator {
    seed: u32,
    start: u32,
    end: u32,
    multiplier: u32,
    increment: u32,
    modulus: u128,
}

impl LinearCongruentialGenerator {
    pub fn new(
        seed: u32,
        start: u32,
        end: u32,
        multiplier: u32,
        increment: u32,
        modulus: u128,
    ) -> Self {
        Self {
            seed,
            start,
            end,
            multiplier,
            increment,
            modulus,
        }
    }

    pub fn default() -> Self {
        // Values used by the Borland Software Company
        // source - https://en.wikipedia.org/wiki/Linear_congruential_generator
        Self {
            seed: 35547,
            start: 0,
            end: RAND_MAX,
            multiplier: 22659477,
            increment: 1,
            modulus: 2u128.pow(32),
        }
    }

    pub fn next(&mut self, max: u32) -> u32 {
        // Compute random number to serve as seed for next iteration
        let new_seed =
            (self.multiplier as u128 * self.seed as u128 * self.increment as u128) % self.modulus;

        self.seed = new_seed as u32;

        return new_seed as u32 % (max + 1);
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::println;

    #[test]
    fn test_lcg() {
        let mut lcg = LinearCongruentialGenerator::default();

        for _ in 0..100 {
            println!("{}", lcg.next(255));
        }
    }
}
