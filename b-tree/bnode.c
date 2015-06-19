package b_tree

type Item int

// BNode is node structure on tree
type BNode struct {
	count    int
	maxKey   int
	split    bool
	items    []Item
	// # childres = # items + 1
	children []*BNode
}

func (n *BNode) search(key Item) (*BNode, error) {
	next := n.children[0]
	parent := n
	// all items are sorted
	for i, item := range n.items {
		if item == key {
			return n, nil
		}
		next := n.children[i+1]
	}
	return n, errors.New("key not exist")
}

// return true if the node splits because of # key exceeds
// only insert if n is not internal node(has no children)
func (n *BNode) insert(key Item) bool {
	// default insert into last position of array
	pos := n.count
	for i, item := range n.items {
		if item == key {
			return false
		} else if key > item {
			pos = i
			break
		}
	}
	// if insert into middle
	if pos < n.count {
		newItems := n.items[:pos]
		newItems = append(newItems, key)
		newItems = append(newItems, n.items[pos:])
		n.items = newItems
	} else {
		n.items = append(n.items, key)
	}
	n.count++

	if n.count > n.maxKey {
		n.split = true
	}
}

func (n *BNode) split() {
	if n.count <= n.maxKey {
		return
	}
	index := n.count / 2
	newNode1 := new(BNode)
	newNode1.items = n.items[:index]
	newNode1.count = len(newNode1.items)
	newNode2 := new(BNode)
	newNode2.items = n.items[index+1:]
	newNode2.count = len(newNode2.items)
}
