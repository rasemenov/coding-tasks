use std::cmp::{Ordering, PartialOrd, PartialEq};

#[derive(Debug, PartialEq)]
pub enum CardType {
    Regular,
    Ace,
    Empty,
}

#[derive(Debug)]
pub struct Card {
    pub ctype: CardType,
    pub rank: u8,
    pub suit: char
}

impl PartialEq for Card {
    fn eq(&self, other: &Card) -> bool {
        self.rank == other.rank
    }
}

impl PartialOrd for Card {
    fn partial_cmp(&self, other: &Card) -> Option<Ordering> {
        if self.ctype == CardType::Empty || other.ctype == CardType::Empty {
            None
        } else if self.rank > other.rank {
            Some(Ordering::Greater)
        } else if self.rank < other.rank {
            Some(Ordering::Less)
        } else if self.rank == other.rank {
            Some(Ordering::Equal)
        } else {
            None
        }
    }
}

impl Card {
    pub fn new(raw: &str) -> Self {
        let mut ctype = CardType::Regular;
        let suit = raw.chars().rev().next().unwrap();
        let rank = match raw.chars().next().unwrap() {
            '1' => 10,
            num @ '2'..='9' => num.to_digit(10).unwrap() as u8,
            'J' => 11,
            'Q' => 12,
            'K' => 13,
            'A' => {
                ctype = CardType::Ace;
                14
            }
            _ => {
                ctype = CardType::Empty;
                0
            }
        };
        Card {
            ctype,
            rank,
            suit
        }
    }
}
