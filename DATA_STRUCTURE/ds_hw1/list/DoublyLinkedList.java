package ds_hw1.list;

public class DoublyLinkedList<E> implements List<E> {
    public DoublyLinkedList<E> head;
    int size;
    private E item;
    private DoublyLinkedList<E> next;
    private DoublyLinkedList<E> prev;
    public DoublyLinkedList(E item, DoublyLinkedList<E> prev, DoublyLinkedList<E> next) {
        this.item = item;
        this.prev = prev;
        this.next = next;
    }

    DoublyLinkedList<E> next() {
        return next;
    }

    DoublyLinkedList<E> setNext(DoublyLinkedList<E> next) {
        return this.next = next;
    }

    DoublyLinkedList<E> prev() {
        return prev;
    }

    DoublyLinkedList<E> setPrev(DoublyLinkedList<E> prev) {
        return this.prev = prev;
    }

    E item() {
        return item;
    }

    E setItem(E item) {
        return this.item = item;
    }

    @Override
    public void clear() {

    }

    public void insert(int pos, E item) {
        DoublyLinkedList<E> curr = head;
        for (int i = 0; i < pos; i++) {
            curr = curr.next();
        }
        curr.setNext(new DoublyLinkedList<E>(item, curr, curr.next()));
        curr.next().next().setPrev(curr.next());
        size++;
    }

    @Override
    public void append(E item) {

    }

    @Override
    public void update(int pos, E item) {

    }

    @Override
    public E getValue(int pos) {
        return null;
    }

    public E remove(int pos) {
        DoublyLinkedList<E> curr = head;
        for (int i = 0; i < pos; i++) {
            curr = curr.next();
        }
        E ret = curr.next().item();
        curr.next().next().setPrev(curr);
        curr.setNext(curr.next().next());
        size--;
        return ret;
    }

    @Override
    public int length() {
        return 0;
    }

    @Override
    public ListIterator<E> listIterator() {
        return null;
    }
}
