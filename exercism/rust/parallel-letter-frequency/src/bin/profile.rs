use parallel_letter_frequency as frequency;

const STAR_SPANGLED_BANNER: [&str; 8] = [
    "O say can you see by the dawn's early light,",
    "What so proudly we hailed at the twilight's last gleaming,",
    "Whose broad stripes and bright stars through the perilous fight,",
    "O'er the ramparts we watched, were so gallantly streaming?",
    "And the rockets' red glare, the bombs bursting in air,",
    "Gave proof through the night that our flag was still there;",
    "O say does that star-spangled banner yet wave,",
    "O'er the land of the free and the home of the brave?",
];

fn main() {
    let ntimes = 300;
    let mut lines = Vec::with_capacity(STAR_SPANGLED_BANNER.len() * ntimes);
    for _ in 0..ntimes {
        for line in STAR_SPANGLED_BANNER {
            lines.push(line);
        }
    }
    let _freqs = frequency::frequency(&lines[..], 2);
}
