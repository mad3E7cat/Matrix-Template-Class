# Matrix Template Class

 - constructor: Matrix_Template(int _rows = 0, int _columns = 0);
 - copy constructor: Matrix_Template(Matrix_Template<T>& obj);
 - "operator=" with resizing: Matrix_Template<T>& operator=(Matrix_Template<T>& obj);
 - destructor: ~Matrix_Template();
 - getter: T& get(int i, int j); // throws non-std self-written exceptions
 - setter: void set(int i, int j, const T& val); // throws non-std self-written exceptions
 - "rotate()" working for both n*n and  n*m matrices: Matrix_Template<T>& rotate(); 
 - "transponate()": Matrix_Template<T>& transponate();
 - columns() getter: int columns();
 - rows() getter: int rows();
 - sum() method, throwing non-std self written exceptions: void sum(Matrix_Template<T>& obj);
 
 **   
  - matrix's string invert: void str_inv(T* arr, int size);
  - "operator+" for 3-d point structure(x, y, z)
  - "operator=" for 3-d point structure(x, y, z)
