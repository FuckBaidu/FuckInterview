/**
 * 13.9 in <Crack the code interview>.
 * Implement smart pointer
 */
template <class T>
class SmartPointer {
public:
    SmartPointer(T *value) : _value(value) {
        _ref = new unsigned;
        *_ref = 0;
    }

    SmartPointer(const SmartPointer<T> &other) {
        _Assign(other);
    }

    SmartPointer& operator=(const SmartPointer<T> &other) {
        if (this != &other) {
            _Assign(other);
        }
        return *this;
    }

    T *Get() {
        return _value;
    }

protected:
    void _Assign(const SmartPointer<T> &other) {
        _value = other._value;
        _ref = other.ref;
        ++*_ref;
    }

    T *_value;
    unsigned *_ref;
};

int main() {
   return 0;
}
