class PeekingIterator implements Iterator<Integer> {

    Iterator<Integer> mIterator;

    Integer mPeeked = null;

    public PeekingIterator(Iterator<Integer> iterator) {
        mIterator = iterator;
    }

    public Integer peek() {
        if (mPeeked != null) {
            return mPeeked;
        }
        if (hasNext()) {
            mPeeked = next();
            return mPeeked;
        } else {
            return null;
        }
    }

    @Override
    public boolean hasNext() {
        return mPeeked != null || mIterator.hasNext();
    }

    @Override
    public Integer next() {
        Integer value;
        if (mPeeked != null) {
            value = mPeeked;
            mPeeked = null;
        } else {
            value = mIterator.next();
        }
        return value;
    }
}
