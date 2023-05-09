public interface BinNode<E> {
    public E element();
    public void setElement(E v);
    public BinNode<E> left();
    public BinNode<E> right();
    public boolean isLeaf();
    public void setLeft(BinNode<E> node);
    public void setRight(BinNode<E> node);
}
