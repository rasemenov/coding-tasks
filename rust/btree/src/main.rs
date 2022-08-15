enum BTree<T> {
    Empty,
    NonEmpty(Box<TreeNode<T>>),
}


struct TreeNode<T> {
    element: T,
    left: BTree<T>,
    right: BTree<T>,
}


impl<T: Ord> BTree<T> {
    fn add(&mut self, element: T) {
        match *self {
            BTree::Empty => {
                *self = BTree::NonEmpty(Box::new(TreeNode {
                    element: element,
                    left: BTree::Empty,
                    right: BTree::Empty
                }))
            },
            BTree::NonEmpty(ref mut node) => {
                if element <= node.element {
                    node.left.add(element);
                } else {
                    node.right.add(element);
                }
            },
        }
    }
}


#[cfg(test)]
mod tests {
    use super::*;
    use std::fmt::Debug;

    fn assert_expected_element<T>(tree: &BTree<T>, expected: T)
        where
            T: PartialEq + Debug,
    {
        match *tree {
            BTree::NonEmpty(ref node) => {
                assert_eq!(node.element, expected);
            },
            BTree::Empty => {
                panic!("Expected node to have an element!");
            },
        }
    }

    #[test]
    fn create_root() {
        let mut tree = BTree::Empty;
        tree.add("Start".to_string());
        assert_expected_element(&tree, "Start".to_string());
    }


    #[test]
    fn create_many_nodes() {
        let mut root = BTree::Empty;
        root.add(1);
        root.add(2);
        root.add(3);
        root.add(4);
        assert_expected_element(&root, 1);
    }
}


fn main() {
    println!("Hello, world!");
}
