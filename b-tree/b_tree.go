type BTree struct {
	root *BNode
}

func (t *BTree) init() {
	if t.root == nil {
		t.root = new(BNode)
		t.root.count = 0
		t.root.items := make([]Item, 3, 0)
		t.root.children := make([]Item, 4, 0)
		t.root.split = false
		t.root.maxKey = 3
	}
}

func (t *BTree) find(key Item) (*BNode, error) {
	if t.root != nil {
		return t.root.search(key)
	}
}

func (t *BTree) splitNode(n *BNode) {
	if(!n.isFull()) {
		return
	}

}

func (t *BTree) insert(key Item) {
	if t.root == nil {
		t.init()
	}
	// if key already exist, nop
	n, err := t.find(key)
	if err == nil {
		return
	}

	// how if split
	curNode.insert(key)

	for curNode := n; curNode != root; curNode = curNode.parent {
		// should split, from bottom to up
		if curNode.split {
			curNode.split = false
			n.split()
		} else {
			break
		}
}
