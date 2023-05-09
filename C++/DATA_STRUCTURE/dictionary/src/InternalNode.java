public class InternalNode<E> implements BinNode<E> {

    private E data;
    private BinNode<E> left, right;

    public InternalNode(E data, BinNode<E> left, BinNode<E> right) {
        this.data = data;
        this.left = left;
        this.right = right;
    }
    @Override
    public E element() {
        return data;
    }

    @Override
    public void setElement(E v) {
        this.data = v;
    }

    @Override
    public BinNode<E> left() {
        return left;
    }

    @Override
    public BinNode<E> right() {
        return right;
    }

    @Override
    public boolean isLeaf() {
        return left == null && right == null;
    }

    @Override
    public void setLeft(BinNode<E> node) {
        this.left = node;
    }

    @Override
    public void setRight(BinNode<E> node) {
        this.right = node;
    }
}
