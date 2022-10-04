mod card;

use card::{Card, CardType};

use std::collections::HashMap;
use std::cmp::{Ordering, PartialOrd, PartialEq};

#[derive(Debug)]
pub struct Hand<'a> {
    hand: [Card; 5],
    pub raw: &'a str,
    is_flush: bool,
    is_straight: Option<u8>,
    pairs: Option<Vec<u8>>,
    triplets: Option<u8>,
    quads: Option<u8>,
}

impl<'a> PartialEq for Hand<'a> {
    fn eq(&self, other: &Hand) -> bool {
        self.hand == other.hand
    }
}

impl<'a> PartialOrd for Hand<'a> {
    fn partial_cmp(&self, other: &Hand) -> Option<Ordering> {
        println!("{:?}\n{:?}", self, other);
        if let Some(result) = self.compare_quad(other) {
            println!("Quad {:?}", result);
            return Some(result);
        }
        if let Some(result) = self.compare_full(other) {
            println!("Full {:?}", result);
            return Some(result);
        }
        if let Some(result) = self.compare_flush(other) {
            println!("Flush {:?}", result);
            return Some(result);
        }
        if let Some(result) = self.compare_straight(other) {
            println!("Straight {:?}", result);
            return Some(result);
        }
        if let Some(result) = self.compare_pairs(other) {
            println!("Pairs {:?}", result);
            return Some(result);
        }
        if self.hand == other.hand {
            Some(Ordering::Equal)
        } else if self.hand > other.hand {
            Some(Ordering::Greater)
        } else if self.hand < other.hand {
            Some(Ordering::Less)
        } else {
            None
        }
    }
}

impl<'a> Hand<'a> {
    pub fn new(raw: &'a str) -> Hand<'a> {
        let mut sorted_cards = Vec::with_capacity(5);
        for card in raw.split(' ') {
            sorted_cards.push(Card::new(card));
        }
        sorted_cards.sort_by(|a, b| b.partial_cmp(a).unwrap());
        let hand: [Card; 5] = sorted_cards.try_into().unwrap();
        let is_flush = Hand::is_flush(&hand);
        let is_straight = Hand::is_straight(&hand);
        let (pairs, triplets, quads) = Hand::get_combinations(&hand);
        Hand {
            hand,
            raw,
            is_flush,
            is_straight,
            pairs,
            triplets,
            quads,
        }
    }

    fn is_flush(hand: &[Card]) -> bool {
        hand.iter().all(|item| {
            item.ctype != CardType::Empty && item.suit == hand[0].suit
        })
    }

    fn is_straight(hand: &[Card]) -> Option<u8> {
        let mut slice = &hand[0..hand.len()];
        let mut highest_rank = slice[0].rank;
        if hand[0].ctype == CardType::Ace {
            let last = hand.len() - 1;
            if hand[last].ctype == CardType::Regular && hand[last].rank == 2 {
                highest_rank = slice[1].rank;
                // Treat Ace as "1" by skipping it at the end.
                slice = &hand[1..hand.len()];
            }
        }
        if slice.windows(2).all(|item| (item[0].rank - item[1].rank) == 1) {
            return Some(highest_rank);
        }
        None
    }

    fn get_combinations(hand: &[Card]) -> (Option<Vec<u8>>, Option<u8>, Option<u8>) {
        let mut combis = HashMap::new();
        let mut pairs: Option<Vec<u8>> = None;
        let mut triplets = None;
        let mut quads = None;
        for card in hand {
            let counter = combis.entry(card.rank).or_insert(0);
            *counter += 1;
            // Anything above pair assumes that the card should be removed
            // from the lower combination.
            if *counter == 4 {
                triplets = None;
                quads = Some(card.rank);
            } else if *counter == 3 {
                let mut tmp = pairs.take().unwrap();
                tmp.pop();
                if !tmp.is_empty() {
                    pairs = Some(tmp);
                }
                triplets = Some(card.rank);
            } else if *counter == 2 {
                if pairs == None {
                    pairs = Some(Vec::new());
                }
                pairs.as_mut().unwrap().push(card.rank);
            }
        }
        (pairs, triplets, quads)
    }

    fn compare_quad(&self, other: &Hand) -> Option<Ordering> {
        match (self.quads, other.quads) {
            (Some(lquad), Some(rquad)) => {
                let mut res = lquad.cmp(&rquad);
                if res == Ordering::Equal {
                    let lkicker = self.hand
                        .iter()
                        .find(|i| i.rank != lquad)
                        .unwrap();
                    let rkicker = other.hand
                        .iter()
                        .find(|i| i.rank != rquad)
                        .unwrap();
                    res = lkicker.rank.cmp(&rkicker.rank);
                }
                Some(res)
            }
            (None, Some(_)) => {
                if self.is_straight.is_some() && self.is_flush {
                    return Some(Ordering::Greater);
                }
                Some(Ordering::Less)
            }
            (Some(_), None) => {
                if other.is_straight.is_some() && other.is_flush {
                    return Some(Ordering::Less);
                }
                Some(Ordering::Greater)
            }
            _ => None,
        }
    }

    fn compare_full(&self, other: &Hand) -> Option<Ordering> {
        match ((self.triplets, self.pairs.as_ref()),
               (other.triplets, other.pairs.as_ref())) {
            ((Some(ltriplet), Some(lpair)), (Some(rtriplet), Some(rpair))) => {
                let mut res = ltriplet.cmp(&rtriplet);
                if res == Ordering::Equal {
                    res = lpair.cmp(rpair);
                }
                Some(res)
            }
            ((Some(_), Some(_)), (Some(_), _)) => Some(Ordering::Greater),
            ((Some(_), Some(_)), (None, Some(_))) => Some(Ordering::Greater),
            _ => None,
        }
    }

    fn compare_flush(&self, other: &Hand) -> Option<Ordering> {
        if let (Some(_), Some(_)) = (other.pairs.as_ref(), other.triplets) {
            return Some(Ordering::Less);
        }
        if self.is_flush && !other.is_flush {
            return Some(Ordering::Greater);
        } else if !self.is_flush && other.is_flush {
            return Some(Ordering::Less);
        }
        None
    }

    fn compare_straight(&self, other: &Hand) -> Option<Ordering> {
        match (self.is_straight, other.is_straight) {
            (Some(_), None) => Some(Ordering::Greater),
            (None, Some(_)) => Some(Ordering::Less),
            (Some(lstraight), Some(rstraight)) => Some(lstraight.cmp(&rstraight)),
            _ => None,
        }
    }

    fn compare_pairs(&self, other: &Hand) -> Option<Ordering> {
        let mut result = match (self.triplets, other.triplets) {
            (Some(_), None) => Ordering::Greater,
            (None, Some(_)) => Ordering::Less,
            _ => Ordering::Equal,
        };
        if result != Ordering::Equal {
            return Some(result);
        }
        result = match (self.pairs.as_ref(), other.pairs.as_ref()) {
            (Some(lpairs), Some(rpairs)) => {
                let mut res = lpairs.len().cmp(&rpairs.len());
                if res == Ordering::Equal {
                    res = lpairs.cmp(rpairs);
                }
                res
            }
            (Some(_), None) => Ordering::Greater,
            (None, Some(_)) => Ordering::Less,
            _ => Ordering::Equal,
        };
        if result == Ordering::Equal {
            None
        } else {
            Some(result)
        }
    }
}
