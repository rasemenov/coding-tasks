// The code below is a stub. Just enough to satisfy the compiler.
// In order to pass the tests you can add-to or change any of this code.

#[derive(PartialEq, Debug, Copy, Clone)]
pub enum Direction {
    North,
    East,
    South,
    West,
}

const DIRECTION_MAP: [Direction; 4] = [Direction::North, Direction::East,
                                       Direction::South, Direction::West];

pub struct Robot {
    x: i32,
    y: i32,
    d: Direction,
}

impl Robot {
    pub fn new(x: i32, y: i32, d: Direction) -> Self {
        Self {
            x,
            y,
            d
        }
    }

    #[must_use]
    pub fn turn_right(self) -> Self {
        let side_code = (self.d as i8 + 1) % (Direction::West as i8 + 1);
        Self::new(self.x, self.y, Self::to_direction(side_code))
    }

    #[must_use]
    pub fn turn_left(self) -> Self {
        let side_code = (self.d as i8 - 1).rem_euclid(Direction::West as i8 + 1);
        Self::new(self.x, self.y, Self::to_direction(side_code))
    }

    #[must_use]
    pub fn advance(self) -> Self {
        let mut x = self.x;
        let mut y = self.y;
        match self.d {
            Direction::North => {y += 1},
            Direction::East => {x += 1},
            Direction::South => {y -= 1},
            Direction::West => {x -= 1},
        }
        Self::new(x, y, self.d)
    }

    #[must_use]
    pub fn instructions(self, instructions: &str) -> Self {
        let mut robot = self;
        for cmd in instructions.chars() {
            robot = match cmd {
                'L' => robot.turn_left(),
                'R' => robot.turn_right(),
                'A' => robot.advance(),
                _ => panic!("Unknown command {}", cmd),
            };
        }
        robot
    }

    pub fn position(&self) -> (i32, i32) {
        (self.x, self.y)
    }

    pub fn direction(&self) -> &Direction {
        &self.d
    }

    fn to_direction(side_code: i8) -> Direction {
        DIRECTION_MAP[side_code as usize]
    }
}
