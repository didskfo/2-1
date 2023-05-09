interface List<E> {
    public void clear();
    public void insert(int pos, E item);
    public void append(E item);
    public void update(int pos, E item);
    public E getValue(int pos);
    public E remove(int pos);
    public int length();
}

class ArrayList<E> implements List<E> {

    private int size;
    public E[] data;

    public ArrayList(int max_size) {
        data = (E[] new Object[max_size]);
        size = 0;
    }

    @Override
    public void clear() {

    }

    @Override
    public void insert(int pos, E item) {
        for (int i = size; i > pos; i--) {
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

        for (int i = pos; i < size-1; i++) {
            data[i] = data[i+1];
        }

        size--;
        return ret;
    }

    @Override
    public int length() {
        return 0;
    }
}

public class App {
    public static void main(String[] args) throws Exception {

        ArrayList<String> myList = new ArrayList<String>(20);

        myList.append("First");

        System.out.println(myList.length());
    }
}
