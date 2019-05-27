#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP
#include <cassert>
#include <cstddef>  //ptrdiff_t
#include <iterator> //std::bidirectional_iterator_tag
#include <iostream>

#include <initializer_list>

template <typename T>
class List;

template <typename T>
struct ListNode {
  T         value = T ();
  ListNode* prev = nullptr;
  ListNode* next = nullptr;
};

template <typename T>
struct ListIterator {
  using Self              = ListIterator<T>;
  using value_type        = T;
  using pointer           = T*;
  using reference         = T&;
  using difference_type   = ptrdiff_t;
  using iterator_category = std::bidirectional_iterator_tag;


  /* Der operator*()  */
  T&  operator*()  const {
  	//not implemented yet
  	return {};
  } 

  /* DESCRIPTION  operator->() */
  T* operator->() const {
  	//not implemented yet
  	return nullptr;
  }

  /* DESCRIPTION  operator++() */
  ListIterator<T>& operator++() {
  	//not implemented yet
  	return {};
  } //PREINCREMENT

  /* ... */
  ListIterator<T> operator++(int) {
  	//not implemented yet
  	return {};
  } //POSTINCREMENT (signature distinguishes)

  /* ... */
  bool operator==(ListIterator<T> const& x) const {
  	//not implemented yet
  }

  /* ... */
  bool operator!=(ListIterator<T> const& x) const {
  	//not implemented yet
  }

  /* ... */
  ListIterator<T> next() const {
    if (nullptr != node) {
      return ListIterator{node->next};
    } else {
      return ListIterator{nullptr};
    }
  }


  ListNode <T>* node = nullptr;
};



template <typename T>
class List {
  public:
    using value_type      = T;
    using pointer         = T*;
    using const_pointer   = T const*;
    using reference       = T&;
    using const_reference = T const&;
    using iterator        = ListIterator<T>;

    // not implemented yet
    // do not forget about the initialiser list !
  	/* ... */
    List() : size_{0}, first_{nullptr}, last_{nullptr}  {
    }

    /* ... */
    //TODO: Copy-Konstruktor using Deep-Copy semantics (Aufgabe 4.8)

  	/* ... */
    //TODO: Move-Konstruktor (Aufgabe 4.13)

    //TODO: Initializer-List Konstruktor (4.14)
  	/* ... */
    List(std::initializer_list<T> ini_list) {
  		//not implemented yet
    }

  	/* ... */
    //TODO: Assignment operator (Aufgabe 4.12)

  	/* ... */
    //TODO: operator== (Aufgabe 4.7)

  	/* ... */
    //TODO: operator!= (Aufgabe 4.7)

  	/* ... */
    ~List() {
  		//TO IMPLEMENT PROPERLY
    }

  	/* ... */
    ListIterator<T> begin() {
    	assert(!empty());
  		////not implemented yet
    	return ListIterator<T>{};
    }

  	/* ... */
    ListIterator<T> end() {
    	assert(!empty());

  		////not implemented yet
    	return ListIterator<T>{};
    }

    /* ... */
    void clear() {
  		////not implemented yet
    }

    /* ... */
    //TODO: member function insert
  	/* ... */
    //TODO: member function reverse

    /* ... */
    void push_front(T const& element) {
  		if(size_ == 0) {
        first_ = new ListNode<T>{element};
        last_ = first_;
      } else {
        first_ = new ListNode<T>{element, nullptr, first_};
        first_->next->prev = first_;
      }
      size_++;
    }

    /* ... */
    void push_back(T const& element) {
  		if(size_ == 0) {
        first_ = new ListNode<T>{element};
        last_ = first_;
      } else {
        last_ = new ListNode<T>{element, last_, nullptr};
        last_->prev->next = last_;
        }
      size_++;
    }

    /* ... */
    void pop_front() {
    	assert(!empty());
  		if(empty()) {
        std::cout << "Die Liste ist leer, sie kann nichts mehr löschen.";
      } else if (size_ == 1) {
        size_--;
        ListNode<T>* oldfirst = first_;
        first_ = nullptr;
        last_ = nullptr;
        delete oldfirst;
      } else {
        size_--;
        ListNode<T>* oldfirst = first_;
        first_ = first_->next;
        first_->prev = nullptr;
        delete oldfirst;
      }
    }

    /* ... */
    void pop_back() {
    	assert(!empty());
  		if(empty()) {
        std::cout << "Die Liste ist leer, sie kann nichts mehr löschen.";
      } else if (size_ == 1) {
        size_--;
        ListNode<T>* oldlast = first_;
        first_ = nullptr;
        last_ = nullptr;
        delete oldlast;
      } else {
        size_--;
        ListNode<T>* oldlast = last_;
        last_ = last_->prev;
        last_->next = nullptr;
        delete oldlast;
      }
    }

  	/* ... */
    T& front() {
    	assert(!empty());
      if (!empty()) {
        return first_->value;
      } else {
        std::cout<< "Die Liste ist leer.";
        
      }
    }

  	/* ... */
    T& back() {
    	assert(!empty());
      if (!empty()) {
        return last_->value;
      } else {
        std::cout<< "Die Liste ist leer.";
        
      }
    }

  	/* gibt zurück, ob die Liste leer ist */
    bool empty() const {
      return size_ == 0;
    };

    /* gibt die size zurück */
    std::size_t size() const{
      return size_;
    };


  private:
    std::size_t size_;
    ListNode<T>* first_;
    ListNode<T>* last_;
};

/* ... */
//TODO: Freie Funktion reverse

/* ... */
//TODO: Freie Funktion operator+ (4.14)

#endif // # define BUW_LIST_HPP