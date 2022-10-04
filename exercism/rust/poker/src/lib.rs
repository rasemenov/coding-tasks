mod poker;

use self::poker::Hand;

/// Given a list of poker hands, return a list of those hands which win.
///
/// Note the type signature: this function should return _the same_ reference to
/// the winning hand(s) as were passed in, not reconstructed strings which happen to be equal.
pub fn winning_hands<'a>(hands: &[&'a str]) -> Vec<&'a str> {
    let mut players = Vec::new();
    for raw_hand in hands {
        players.push(Hand::new(raw_hand));
    }
    players.sort_by(|a, b| b.partial_cmp(a).unwrap());
    players
        .iter()
        .map_while(|item| {
            if item == &players[0] {
                return Some(item.raw);
            }
            None
        })
        .collect()
}
