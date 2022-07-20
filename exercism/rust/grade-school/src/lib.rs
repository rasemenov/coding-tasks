use std::collections::BTreeMap;

pub struct School {
    // Binary tree removes the necessity to sort grades later on.
    students: BTreeMap<u32, Vec<String>>,
}

#[allow(clippy::new_without_default)]
impl School {
    pub fn new() -> School {
        Self {students: BTreeMap::new()}
    }

    pub fn add(&mut self, grade: u32, student: &str) {
        self.students.entry(grade)
            .and_modify(|e| {
                e.push(student.to_string());
            })
            .or_insert(vec![student.to_string()]);
    }

    pub fn grades(&self) -> Vec<u32> {
        let res: Vec<u32> = self.students.keys()
            .map(|v| *v).collect();
        res
    }

    pub fn grade(&self, grade: u32) -> Vec<String> {
        match self.students.get(&grade) {
            Some(array) => {
                let mut students = array.to_vec();
                // Ensure that students are sorted by name.
                students.sort();
                students
            }
            None => Vec::<String>::new(),
        }
    }
}
