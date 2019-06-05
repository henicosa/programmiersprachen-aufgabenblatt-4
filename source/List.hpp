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


  /* Der operator*() gibt die Referenz auf den value zurück*/
  T&  operator*()  const {
  	return node->value;
  } 

  /* Der operator->() gibt einen Pointer auf den Value zurück*/
  T* operator->() const {
  	return &(node->value);
  }

  /* Der operator++() setzt die node auf seinen Nachfolger und gibt sich selbst zurück */
  ListIterator<T>& operator++() {
    node = node->next;
  	return *this;
  } //PREINCREMENT

  /* ... */
  ListIterator<T> operator++(int) {
    Self return_iterator = ListIterator{node};
    node = node->next;
  	return return_iterator;
  } //POSTINCREMENT (signature distinguishes)

  /* Whether both Iterator point to the self node */
  bool operator==(ListIterator<T> const& x) const {
  	return node == x.node;
  }

  /* Whether both Iterator dont point to the self node */
  bool operator!=(ListIterator<T> const& x) const {
  	return !(node == x.node);
  }

  /* Gibt einen ListIterator mit dem Nachfolger von Node zurück */
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
    List(List<T> const& pattern) {
      size_ = 0;
      first_ = nullptr;
      last_ = nullptr;
      iterator i = iterator{pattern.first_};
      iterator end = iterator{};
      while(i != end) {
        push_back(T(*i));
        ++i;
      }
    }

  	/* ... */
    //TODO: Move-Konstruktor (Aufgabe 4.13)

    //TODO: Initializer-List Konstruktor (4.14)
  	/* ... */
    List(std::initializer_list<T> ini_list) {
  		//not implemented yet
    }

  	/* ... */
    //TODO: Assignment operator (Aufgabe 4.12)

  	/* Sagt ob zwei Listen gleich sind */
    bool operator== (List<T> const& rhs) {
      if(size() == rhs.size()) {
        if (size() == 0) {
          return true;
        } else {
        iterator i = iterator{first_};
        iterator j = iterator{rhs.first_};
        iterator end = iterator{};
        while(i != end) {
          if(*i == *j) {
            ++i;
            ++j;
          } else {
            return false;
          }
        }
        return true;
        }
      } else {
        return false;
      }
    }

    /* Sagt ob zwei Listen ungleich sind */
    bool operator!= (List<T> const& rhs) {
      return !(*this==rhs);
    }

    ~List() {
  		clear();
    }

  	/* Gibt einen Iterator der auf das erste Listenelement zeigt zurück */
    ListIterator<T> begin() {
      if (empty()) {
        return ListIterator<T>();
      } else{
        return ListIterator<T>{first_};
      }    	
    }

  	/* Gibt einen Iterator der auf den nullpointer zeigt zurück */
    ListIterator<T> end() {
    	return ListIterator<T>();
    }

    /* Entfernt alle Knoten aus der Liste */
    void clear() {
  		while(!empty()) {
        pop_front();
      }
    }

    /* Fügt ein neues Objekt vor dem Knoten ein, auf den der Iterator zeigt */
    iterator insert(T const obj, iterator const& succ) {
      if(succ == iterator{}) {
        push_back(obj);
        return iterator{last_};
      } else {
        if(succ == iterator{first_}) {
          push_front(obj);
          return iterator{first_};
        } else {
          ListNode<T>* in = new ListNode<T>{obj, succ.node->prev, succ.node};
          succ.node->prev->next = in;
          succ.node->prev = in;
          size_++;
          return iterator{in};
        }
      }
    }
  	/* Reiht die Listenelemente umgekehrt ein */
    //TODO: member function reverse#
    void reverse() {
      iterator i{first_};
      iterator end;
      while(i != end) {
        auto current = i++;
        auto oldprev = current.node->prev;
        current.node->prev = current.node->next;
        current.node->next = oldprev; 
      }
      auto oldfirst = first_;
      first_ = last_;
      last_ = oldfirst;
    }

    /* Fügt am Anfang der Liste ein Element an */
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

    /* Fügt am Ende der Liste ein Element an */
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

    /* Löscht das erste Element der Liste */
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

    /* Löscht das letzte Element der Liste */
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

  	/* Gibt das erste Element der Liste zurück */
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
template <typename T>
List<T> reverse(List<T> org) {
  org.reverse();
  return org;
}; 

/* ... */
//TODO: Freie Funktion operator+ (4.14)


#endif // # define BUW_LIST_HPP