fn cell_neighbors(minefield: &[&str], height: usize, width: usize) -> Vec<(usize, usize)> {
    let row_indx = height as i32;
    let cell_indx = width as i32;
    let rows = (-1..2)
        .map(|offset| row_indx + offset)
        .filter(|indx| *indx >= 0 && *indx < minefield.len() as i32);
    let columns = (-1..2)
        .map(|offset| cell_indx + offset)
        .filter(|indx| *indx >= 0 && *indx < minefield[0].len() as i32);
    rows.flat_map(|item| std::iter::repeat(item).zip(columns.clone()))
        .map(|item| (item.0 as usize, item.1 as usize))
        .filter(|item| !(item.0 == height && item.1 == width))
        .collect()
}

pub fn annotate(minefield: &[&str]) -> Vec<String> {
    if minefield.len() == 0 {
        return Vec::new();
    }
    let mut result = Vec::new();
    for (row_indx, row) in minefield.iter().enumerate() {
        if row.len() == 0 {
            return minefield.iter().map(|s| s.to_string()).collect();
        }
        for (cell_indx, cell) in row.bytes().enumerate() {
            let mark = match cell {
                42u8 => "*".to_string(),
                _ => {
                    let mut bombs_around = 0u8;
                    let positions_to_check = cell_neighbors(minefield, row_indx, cell_indx);
                    for (r, c) in positions_to_check {
                        if let Some(row) = minefield.get(r) {
                            match row.as_bytes().get(c) {
                                Some(42u8) => {
                                    bombs_around += 1;
                                }
                                _ => continue,
                            }
                        }
                    }
                    if bombs_around > 0 {
                        format!("{}", bombs_around)
                    } else {
                        " ".to_string()
                    }
                }
            };
            result.push(mark);
        }
    }
    result
        .chunks(minefield[0].len())
        .map(|chunk| {
            chunk.iter().fold(String::new(), |mut res, item| {
                res.push_str(item);
                res
            })
        })
        .collect()
}
