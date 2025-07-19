// we allocat 1 Gigs of memory and divide it we called this a heap
// each segment we divide itno 4 byte or 32 bits
// each segment we called it as words(1 word = 4 byte)
// word is smallest amount of memory we allocated
// we numbered our heap with 0 to 250k
// 8 byte = 2 words ( 1st word  is header and from second & third memory contains we can use)
// every allocation has own header
// in each word we divide it into 3 part 1st tell number of words ) and we denote this by "w"  and this has size of 30 bits 
// 2nd part is boolean with 1 bit allocated(true if allocated otherwise false)
// 3rd part is also 1 bit and this is reserved
// if another allocation happen then new header is required
// 1 word per alllocation


/*
struct packed s_header{
    word w = 30;
    bool allocated = 1;
    bool unused = 1;
}

typedef struct packed
s_header header;
*/

// if new allocation we wanted to do then check ki utna jagah aage hai ki nahi
// if not then eroor = ErrNoMem error ; return 0
// its using same syntax as malloc

/*
    int8 *str;
    str = (int8 *)alloc(12);


    allock(kb);           // for num of kb allocation
    allocm(mb);           // for num of mb allocation


*/

// we cal use realloc to change sizze of allocation

