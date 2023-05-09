package ds_hw1.list;

import java.util.Arrays;

public class ArrayList<E> implements List<E> {

    private int arraySize;                  // 원소 개수

    private int size;                       // 리스트 크기 지정
    private E[] data;
    public ArrayList(int size) {
        arraySize = 0;                      // 원소 개수 0
        this.size = size;                   // 리스트 크기
        data = (E[]) new Object[size];      // 리스트 만들기
    }

    @Override
    public void clear() {
        arraySize = 0;                      // 원소 개수 0
    }

    @Override
    public void insert(int pos, E item) {
        if (arraySize >= size) {                    // 원소 개수가 리스트 크기 넘어갈 때
            E[] doubling_list = (E[]) new Object[size * 2];
            for (int i = 0; i < arraySize; i++) {
                doubling_list[i] = data[i];
            }
            data = doubling_list;
            size *= 2;
        }
        for (int i = arraySize; i > pos; i--) {
            data[i] = data[i-1];
        }
        data[pos] = item;
        arraySize++;
    }

    @Override
    public void append(E item) {
        if (arraySize >= size) {
            E[] doubling_list = (E[]) new Object[size * 2];
            for(int i = 0; i < arraySize; i++) {
                doubling_list[i] = data[i];
            }
            data = doubling_list;
            size *= 2;
        }
        data[arraySize++] = item;
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

        for (int i = pos; i < arraySize; i++) {
            data[i] = data[i+1];
        }

        arraySize--;

        return ret;
    }

    @Override
    public int length() {
        return arraySize;
    }

    @Override
    public ListIterator<E> listIterator() {
        return new ListIterator<E>() {
            int pos = 0;

            @Override
            public boolean hasNext() {
                return pos < arraySize;
            }

            @Override
            public E next() {
                return data[pos++];
            }

            @Override
            public boolean hasPrevious() {
                return pos > 0;
            }

            @Override
            public E previous() {
                return data[--pos];
            }
        };
    }

    public static void main(String[] args) {
        ArrayList<String> myList = new ArrayList<>(5);
        myList.append("First");
        myList.append("Second");
        myList.insert(0, "Zero");
        myList.append("Third");
        System.out.println(myList.length());
        myList.update(3, "Third2");
        myList.append("Fourth");
        myList.append("Fifth");
        myList.append("Sixth");
        myList.append("Seventh");
        myList.append("Eighth");
        myList.append("Ninth");

        System.out.println(myList.length());

        myList.append("Over");

        System.out.println(myList.length());

        ListIterator<String> it = myList.listIterator();

        System.out.println("iterate!");

        while (it.hasNext()) {
            String x = it.next();
            System.out.println(x);
        }

        System.out.println("reverse!");

        while (it.hasPrevious()) {
            String x = it.previous();
            System.out.println(x);
        }
    }
}
