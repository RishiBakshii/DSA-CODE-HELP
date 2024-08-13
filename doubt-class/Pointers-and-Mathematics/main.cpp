/*

// a = a+1; why not possible? also discussed
// but we can do ptr = ptr +1 because this will not change the base address of array
// pointer arithmetics also disscuused


// diff between pointer and referece variable
// pointers -> holds the address // so it has is own space and address // size -> 8 byte

// ref variable -> ref variable has no memory block // int var= 10; int &ref = var; like a nickname
// referecne vairbale has no memeory space assigned to it
// if given choice we should reference varibale because it has not assingalbel space and that is why this will not increse
// the memory right?

// we can do this int *ptr ✅ but we cannot do this int& ref;❌

// why pointer size is coming as 8?
// because pointers stores address and in a 64 bit operating sytem it takes 8 bytes to stores the address
// that is why pointer takes 8 bytes of space

// in a 32 bit os the address will be of 4 bytes that is why a pointer in a 32 bit os will be of 4 bytes

// diffrence between &arr  and *ptr = arr
// int *ptr = arr // this means that we are storing the first index adreess
// int *(p)[5] = &arr // this means that we are trying to store the address of whole arrray

// we cannot do this
// int* ptr = &arr ❌
// this will give us an error of cannot initialize a variable of type int * with an r value of type 'int (*)[5]
// &arr will return us the address of all the blocks or we can say the whole array

*/