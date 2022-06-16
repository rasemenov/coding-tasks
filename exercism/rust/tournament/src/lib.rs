use std::cmp::Ordering;
use std::collections::HashMap;


fn format_row(values: &[&str]) -> String {
    let width = 2;
    format!("{:30} | {:>width$} | {:>width$} | {:>width$} \
            | {:>width$} | {:>width$}",
            values[0], values[1], values[2], values[3], values[4], values[5])
}


#[derive(Debug)]
struct TeamStat {
    name: String,
    played: i8,
    win: i8,
    loss: i8,
    draw: i8,
    points: i8,
}


impl TeamStat {
    fn new(name: &str) -> Self {
        Self {
            name: String::from(name),
            played: 0,
            win: 0,
            loss: 0,
            draw: 0,
            points: 0
        }
    }
    
    fn process_first(&mut self, result: &str) {
        self.played += 1;
        match result {
            "win" => {self.win += 1; self.points += 3},
            "loss" => self.loss += 1,
            "draw" => {self.draw += 1; self.points += 1},
            _ => panic!("Unknown option {}", result),
        }
    }
    
    fn process_second(&mut self, result: &str) {
        self.played += 1;
        match result {
            "win" => self.loss += 1,
            "loss" => {self.win += 1; self.points += 3},
            "draw" => {self.draw += 1; self.points += 1},
            _ => panic!("Unknown option {}", result),
        }
    }
}

pub fn tally(match_results: &str) -> String {
    let mut res = String::new();
    let mut stats: HashMap<&str, TeamStat> = HashMap::new();
    res.push_str(format_row(&["Team", "MP", "W", "D", "L", "P"]).as_str());
    for game in match_results.split('\n').collect::<Vec<&str>>() {
        if game.len() < 3 {
            return res;
        }
        let game_result = game.split(';').collect::<Vec<&str>>();
        stats.entry(game_result[0]).or_insert(TeamStat::new(game_result[0]))
            .process_first(game_result[2]);
        stats.entry(game_result[1]).or_insert(TeamStat::new(game_result[1]))
            .process_second(game_result[2]);
    }
    let mut sorted = stats.into_values().collect::<Vec<TeamStat>>();
    sorted.sort_by(|a, b| {
        match a.points.cmp(&b.points).reverse() {
            Ordering::Equal => a.name.cmp(&b.name),
            other => other,
        }
    });
    for team in sorted {
        res.push('\n');
        res.push_str(format_row(&[team.name.as_str(), &team.played.to_string(),
                                &team.win.to_string(), &team.draw.to_string(), 
                                &team.loss.to_string(), &team.points.to_string()]).as_str());
    }
    res
}