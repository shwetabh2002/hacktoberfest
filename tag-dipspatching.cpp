namespace std {
  struct input_iterator_tag { };
  struct bidirectional_iterator_tag { };
  struct random_access_iterator_tag { };

  namespace detail {
    template <class InputIterator, class Distance>
    void advance_dispatch(InputIterator& i, Distance n, input_iterator_tag) {
      while (n--) ++i;
    }

    template <class BidirectionalIterator, class Distance>
    void advance_dispatch(BidirectionalIterator& i, Distance n, 
       bidirectional_iterator_tag) {
      if (n >= 0)
        while (n--) ++i;
      else
        while (n++) --i;
    }

    template <class RandomAccessIterator, class Distance>
    void advance_dispatch(RandomAccessIterator& i, Distance n, 
       random_access_iterator_tag) {
      i += n;
    }
  }

  template <class InputIterator, class Distance>
  void advance(InputIterator& i, Distance n) {
    typename iterator_traits<InputIterator>::iterator_category category;
    detail::advance_dispatch(i, n, category);
  }
}
