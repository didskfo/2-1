interface List<E> {
    public void clear();
    public void insert(int pos, E item);
    public void append(E item);
    public void update(int pos, E item);
    public E getValue(int pos);
    public E remove(int pos);
    public int length();
    public ListIterator<E> listIterator();
}

interface ListIterator<E> {
    public boolean hasNext();
    public E next();
    public boolean hasPrevious();
    public E previous();
}

class ArrayList<E> implements List<E> {

    private int size;
    private E[] data;

    public ArrayList(int max_size) {
        data = (E[]) new Object[max_size];
        size = 0;
    }

    @Override
    public void clear() {
        size = 0;
    }

    @Override
    public void insert(int pos, E item) {
        for(int i = size; i > pos; i--) {
            data[i] = data[i-1];
        }
        data[pos] = item;
        size++;
    }

    @Override
    public void append(E item) {
        data[size++] = item;
    }

    @Override
    public void update(int pos, E item) {
        data[pos] = item;
    }

    @Override
    public E getValue(int pos) {
        return data[pos];
    }

    @Override
    public E remove(int pos) {
        E ret = data[pos];

        for (int i = pos; i < size; i++) {
            data[i] = data[i+1];
        }

        size--;

        return ret;
    }

    @Override
    public int length() {
        return size;
    }

    public void printall() {
        for (int i = 0; i < size; i++) {
            System.out.println(data[i]);
        }
    }

    @Override
    public ListIterator<E> listIterator() {
        return new ListIterator() {
            int pos = 0;
            public boolean hasNext() {
                return pos < size;
            }
            public E next() {
                return data[pos++];
            }
            public boolean hasPrevious() {
                return pos > 0;
            }
            public E previous() {
                return data[--pos];
            }
        };
    }
}

class Link<E> {

    static Link<?> freelist = null;

    static <E> Link<E> get (E item, Link<E> next) {
        if (freelist == null) {
            return Link.get(item, next);
        }

        Link<E> ret = (Link<E>) Link.freelist;
        freelist = freelist.next;

        ret.item = item;
        ret.next = next;

        return ret;
    }

    void release() {
        item = null;
        next = (Link<E>) Link.freelist;
        freelist = this;
    }

    public E item;
    public Link<E> next;
    public Link(E item, Link<E> next) {
        this.item = item;
        this.next = next;
    }
}

class LinkedList<E> implements List<E> {

    Link<E> head = new Link(null, null);
    Link<E> tail = head;
    int size;

    public void clear() {
        size = 0;
        head.next = null;
        tail = head;
    }
    public void insert(int pos, E item) {
        Link<E> curr = head;
        for (int i = 0; i < pos; i++) {
            curr = curr.next;
        }

        curr.next = new Link(item, curr.next);

        if (curr == tail) {
            tail = curr.next;
        }
        size++;
    }
    public void append(E item) {
        tail.next = new Link(item, null);
        tail = tail.next;
        size++;
    }
    public void update(int pos, E item) {
        Link<E> curr = head;
        for (int i = 0; i < pos; i++) {
            curr = curr.next;
        }

        curr.next.item = item;
    }
    public E getValue(int pos) {
        Link<E> curr = head;
        for (int i = 0; i < pos; i++) {
            curr = curr.next;
        }
        return curr.next.item;
    }
    public E remove(int pos) {
        Link<E> curr = head;
        for (int i = 0; i < pos; i++) {
            curr = curr.next;
        }

        E ret = curr.next.item;

        if (curr.next == tail) {
            tail = curr;
        }

        Link<E> tmp = curr.next;

        curr.next = curr.next.next;

        tmp.release();

        size--;

        return ret;
    }
    public int length() {
        return size;
    }
    public ListIterator<E> listIterator() {
        return new ListIterator<E>() {

            Link<E> curr = head;

            public boolean hasNext() {
                return curr != tail;
            }
            public E next() {
                curr = curr.next;
                return curr.item;
            }
            public boolean hasPrevious() {
                return curr != head;
            }
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
}

class DLink<E> {
    public DLink<E> head;
    int size;
    private E item;
    private DLink<E> next;
    private DLink<E> prev;
    public DLink(E item, DLink<E> prev, DLink<E> next) {
        this.item = item;
        this.prev = prev;
        this.next = next;
    }
    DLink<E> next() {
        return next;
    }
    DLink<E> setNext(DLink<E> next) {
        return this.next = next;
    }
    DLink<E> prev() {
        return prev;
    }
    DLink<E> setPrev(DLink<E> prev) {
        return this.prev = prev;
    }
    E item() {
        return item;
    }
    E setItem(E item) {
        return this.item = item;
    }

    public void insert(int pos, E item) {
        DLink<E> curr = head;
        for (int i = 0; i < pos; i++) {
            curr = curr.next();
        }
        curr.setNext(new DLink<E>(item, curr, curr.next()));
        curr.next().next().setPrev(curr.next());
        size++;
    }

    public E remove(int pos) {
        DLink<E> curr = head;
        for (int i = 0; i < pos; i++) {
            curr = curr.next();
        }
        E ret = curr.next().item();
        curr.next().next().setPrev(curr);
        curr.setNext(curr.next().next());
        size--;
        return ret;
    }
}

public class App {
    public static void main(String[] args) throws Exception {

        List<String> mylist = new LinkedList<String>();

        mylist.append("First");
        mylist.append("Second");
        mylist.append("Third");
        mylist.append("Fourth");
        mylist.append("Fifth");

        ListIterator<String> it = mylist.listIterator();

        System.out.println("iterate!");

        while(it.hasNext()) {
            String x = it.next();
            System.out.println(x);
        }

        System.out.println("reverse!");
        while(it.hasPrevious()) {
            String x = it.previous();
            System.out.println(x);
        }

    }
}