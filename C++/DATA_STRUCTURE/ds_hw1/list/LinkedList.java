package ds_hw1.list;

public class LinkedList<E> implements List<E> {

//    Link<E> head = new Link(null, null);
    Link<E> head = Link.get(null, null);        // freelist 적용할 때
    Link<E> tail = head;

    int size;

    @Override
    public void clear() {
        size = 0;
        head.next = null;
        tail = head;
    }

    @Override
    public void insert(int pos, E item) {
        Link<E> curr = head;
        for (int i = 0; i < pos; i++) {
            curr = curr.next;
        }

//        curr.next = new Link(item, curr.next);
        curr.next = Link.get(item, curr.next);          // freelist 적용할 때

        if (curr == tail) {
            tail = curr.next;
        }
        size++;
    }

    @Override
    public void append(E item) {
//        tail.next = new Link(item, null);
        tail.next = Link.get(item, null);   // freelist 적용할 때

        tail = tail.next;
        size++;
    }

    @Override
    public void update(int pos, E item) {
        Link<E> curr = head;
        for (int i = 0; i < pos; i++) {
            curr = curr.next;
        }

        curr.next.item = item;
    }

    @Override
    public E getValue(int pos) {
        Link<E> curr = head;
        for (int i = 0; i < pos; i++) {
            curr = curr.next;
        }
        return curr.next.item;
    }

    @Override
    public E remove(int pos) {
        Link<E> curr = head;
        for (int i = 0; i < pos; i++) {
            curr = curr.next;
        }

        E ret = curr.next.item;

        if (curr.next == tail) {
            tail = curr;
        }

        Link<E> tmp = curr.next;        // freelist 적용할 때 추가하는 코드

        curr.next = curr.next.next;

        tmp.release();                  // freelist 적용할 때 추가하는 코드

        size--;

        return ret;
    }

    @Override
    public int length() {
        return size;
    }

    @Override
    public ListIterator<E> listIterator() {

        return new ListIterator<E>() {

            Link<E> curr = head;
            @Override
            public boolean hasNext() {
                return curr != tail;
            }

            @Override
            public E next() {
                curr = curr.next;
                return curr.item;
            }

            @Override
            public boolean hasPrevious() {
                return curr != head;
            }

            @Override
            public E previous() {
                Link<E> prev = head;
                while (prev.next != curr) {
                    prev = prev.next;
                }
                curr = prev;
                return curr.next.item;
            }
        };
    }

    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();

        LinkedList<Integer> myLList = new LinkedList<>();

        for (int i = 0; i < 1000000; i++) {
            myLList.append(i);
        }

        for (int i = 0; i < 100000; i++) {
            myLList.remove(i);
        }

        for (int i = 0; i < 100000; i++) {
            myLList.append(i);
        }

//        ListIterator<Integer> Lit = myLList.listIterator();
//
//        System.out.println("iterate!");
//
//        while (Lit.hasNext()) {
//            int x = Lit.next();
//            System.out.println(x);
//        }
//
//        System.out.println("reverse!");
//
//        while (Lit.hasPrevious()) {
//            int x = Lit.previous();
//            System.out.println(x);
//        }

        long endTime = System.currentTimeMillis();

        System.out.println(String.format("Freelist를 적용했을 때의 코드 실행 시간: %20dms", endTime - startTime));

    }
}


