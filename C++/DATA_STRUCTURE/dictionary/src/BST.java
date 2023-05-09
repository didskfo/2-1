import java.security.Key;

public class BST<K extends Comparable<K>, E> implements Dictionary<K, E> {

    class Node{
        public K key;
        public E element;

        public Node(K key, E element) {
            this.key = key;
            this.element = element;
        }
    }

    private BinNode<Node> root;
    private int size;

    public BST() {
        root = null;
        size = 0;
    }
    @Override
    public void claer() {
        root = null;
        size = 0;
    }

    public BinNode<Node> inserter(K k, E e, BinNode<Node> root) {
        if (root == null) {
            return new InternalNode<>(new Node(k, e), null, null);
        } else if (root.element().key.compareTo(k) == 0) {
            root.element().element = e;
        } else if (root.element().key.compareTo(k) > 0) {
            if (root.isLeaf()) {
                root = new InternalNode<>(new Node(root.element().key, root.element().element), null, null);
            }
            root.setLeft(inserter(k, e, root.left()));
        } else {
            if (root.isLeaf()) {
                root = new InternalNode<>(new Node(root.element().key, root.element().element), null, null);
            }
            root.setRight(inserter(k, e, root.right()));
        }
        return root;
    }

    @Override
    public void insert(K k, E e) {
        root = inserter(k, e, root);
        size++;
    }


    public BinNode<Node> remover(K k, BinNode<Node> root) {
        if (root.element().key.compareTo(k) == 0) {
            if (root.left() == null) {
                return root.right();
            } else if (root.right() == null) {
                return root.left();
            } else {
                Node smalleastleft = getSmalleastLeaf(root.right());
                root.setElement(smalleastleft);
                root.setRight(removeSmalleastLeaf(root.right()));
            }
        } else if (root.element().key.compareTo(k) > 0) {
            root.setLeft(remover(k, root.left()));
        } else {
            root.setRight(remover(k, root.right()));
        }
        if (root.isLeaf()) {
            root = new InternalNode<>(new Node(root.element().key, root.element().element), null, null);
        }
        return root;
    }

    public Node getSmalleastLeaf(BinNode<Node> root) {
        BinNode<Node> curr = root;
        while (curr.left() != null) {
            curr = curr.left();
        }
        return curr.element();
    }

    public BinNode<Node> removeSmalleastLeaf(BinNode<Node> root) {
        if (root.left() == null) {
            return root.right();
        } else {
            root.setLeft(removeSmalleastLeaf(root.left()));
            if (root.isLeaf()) {
                root = new InternalNode<>(new Node(root.element().key, root.element().element), null, null);
            }
            return root;
        }
    }

    public E finder(K k, BinNode<Node> root) {
        if (root == null) {
            return null;
        } else if (root.element().key.compareTo(k) == 0) {
            return root.element().element;
        } else if (root.element().key.compareTo(k) > 0) {
            return finder(k, root.left());
        } else {
            return finder(k, root.right());
        }
    }

    @Override
    public E remove(K k) {
        E ret = finder(k, root);
        if (ret != null) {
            root = remover(k, root);
            size--;
        }
        return null;
    }

    @Override
    public E removeAny() {
        return remove(root.element().key);
    }

    @Override
    public E find(K k) {
        return finder(k, root);
    }

    @Override
    public int size() {
        return size;
    }

    public static void main(String[] args) {
        Dictionary<String, String> dic = new BST<>();
        dic.insert("lastname", "yang");
        dic.insert("firstname", "narae");
        dic.insert("age", "21");
        System.out.println(dic.size());
        System.out.println(dic.find("age"));
        dic.remove("firstname");
        System.out.println(dic.find("firstname"));
        System.out.println(dic.size());
        dic.removeAny();
        System.out.println(dic.find("lastname"));
        System.out.println(dic.find("age"));
        System.out.println(dic.size());
        dic.claer();
        System.out.println(dic.size());
        dic.insert("height", "163");
        System.out.println(dic.find("height"));
        System.out.println(dic.size());
    }
}
